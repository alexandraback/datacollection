import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Scanner;

public class R1CA2012 {

	public static void main(String[] args) throws Exception {
		new R1CA2012();
	}
	
	static final String filename = "R1C/A-large";
	int testcases;
	
	public R1CA2012() throws Exception {
		FileReader ifile = new FileReader(filename+".in");
		Scanner scanner = new Scanner(ifile);
		testcases = (scanner.nextInt());
		FileWriter ofile = new FileWriter(filename+".out");
		for (int i = 1; i <= testcases; i++) {
			ofile.write("Case #"+i+": "+solve(scanner)+(i != testcases ? "\n" : ""));
		}
		ofile.close();
		System.out.println("Finished");
	}
	
	public Node[] Nodes;
	public Integer[][] pathsCache;
	
	private String solve(Scanner scanner) throws Exception {
		int N = scanner.nextInt();
		Nodes = new Node[N];
		pathsCache = new Integer[N][N];
		for (int i = 0; i < N; i++) {
			Nodes[i] = new Node();
			int M = scanner.nextInt();
			Nodes[i].inherited = new int[M];
			for (int j = 0; j < M; j++) {
				Nodes[i].inherited[j] = scanner.nextInt() - 1;
			}
		}
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (j != i) {
					if (paths(i, j) > 1)
						return "Yes";
				}
			}
		}
		return "No";
	}
	
	private int paths(int from, int to) {
		if (pathsCache[from][to] != null)
			return pathsCache[from][to];
		int pathsums = 0;
		for (int i : Nodes[from].inherited) {
			if (i == to)
				pathsums += 1;
			else
				pathsums += paths(i, to);
		}
		pathsCache[from][to] = pathsums;
		return pathsums;
	}

	public static class Node {
		
		int[] inherited;
		
	}
	
}
