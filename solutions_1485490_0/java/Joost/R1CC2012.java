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

public class R1CC2012 {

	public static void main(String[] args) throws Exception {
		new R1CC2012();
	}
	
	static final String filename = "R1C/C-small-attempt0";
	int testcases;
	
	public R1CC2012() throws Exception {
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
	
	private String solve(Scanner scanner) throws Exception {
		int N = scanner.nextInt();
		int M = scanner.nextInt();
		long[] An = new long[N];
		int[] At = new int[N];
		long[] Bn = new long[M];
		int[] Bt = new int[M];
		for (int i = 0; i < N; i++) {
			An[i] = scanner.nextLong();
			At[i] =scanner.nextInt();
		}
		for (int i = 0; i < M; i++) {
			Bn[i] = scanner.nextLong();
			Bt[i] =scanner.nextInt();
		}
		return Long.toString(recsolve(0, An, At, 0, Bn, Bt));
	}
	
	private long recsolve(int a, long[] sAn, int[] At, int b, long[] sBn, int[] Bt) {
		if (a == sAn.length || b == sBn.length)
			return 0;
		long dn;
		if (At[a] == Bt[b]) {
			long[] An = sAn.clone();
			long[] Bn = sBn.clone();
			if (An[a] < Bn[b]) {
				dn = An[a]; 
				Bn[b] -= An[a];
				return dn + recsolve(a+1, An, At, b, Bn, Bt);
			}
			else if (An[a] > Bn[b]){
				dn = Bn[b]; 
				An[a] -= Bn[b];
				return dn + recsolve(a, An, At, b+1, Bn, Bt);
			}
			else {
				return An[a] + recsolve(a+1, An, At, b+1, Bn, Bt);
			}
		}
		else {
			return Math.max(recsolve(a+1, sAn, At, b, sBn, Bt), recsolve(a, sAn, At, b+1, sBn, Bt));
		}
	}
	
	public class Pair {
		public Pair(long a, int b) {
			n = a;
			b = t;
		}
		long n;
		int t;
	}
	
}
