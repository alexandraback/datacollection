package gcj2013;
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

public class R1BA2013 {

	public static void main(String[] args) throws Exception {
		new R1BA2013();
	}
	
	static final String filename = "R1B/A-small-attempt0";
	int testcases;
	
	public R1BA2013() throws Exception {
		FileReader ifile = new FileReader(filename+".in");
		Scanner scanner = new Scanner(ifile);
		testcases = (scanner.nextInt());
		FileWriter ofile = new FileWriter(filename+".out");
		for (int i = 1; i <= testcases; i++) {
            System.out.println("Case "+i);
			ofile.write("Case #"+i+": "+solve(scanner)+(i != testcases ? "\n" : ""));
		}
		ofile.close();
		System.out.println("Finished");
	}
	
	private String solve(Scanner scanner) throws Exception {
        int A = scanner.nextInt();
        int N = scanner.nextInt();
        int[] list = new int[N];
        for (int i = 0; i < N; i++) {
            list[i] = scanner.nextInt();
        }
        Arrays.sort(list);
        return ""+recSolve(list, 0, A, N);
    }
    
    private int recSolve(int[] list, int i, int A, int N) {
        if (i == N) {
            return 0;
        }
        if (A > list[i]) {
            System.out.println("1");
            return recSolve(list, i+1, A+list[i], N);
        }
        else {
            System.out.println("2");
            int itt = 0;
            while (A <= list[i] && itt < N-i) {
                A += A-1;
                itt++;
            }
            if (itt == N-i)
                return N-i; //might as well just remove
            int addone = recSolve(list, i, A, N) + itt;
            int remove = N-i;
            return Math.min(addone, remove);
        }
    }
	
}
