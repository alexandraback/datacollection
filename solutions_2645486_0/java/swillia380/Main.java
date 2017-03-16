import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class Main {
	public static int max(int[] L) {
		int m = 0;
		boolean done = true;
		for (int i = 0; i < L.length; i++) {
			if (L[i]>L[m]) m = i;
			if (L[i]!=0) done = false;
		}
		if (done) {
			return -1;
		} else return m;
	}
	public static String solve(Scanner f) {
		String ss = new String();
		int E = f.nextInt();
		int R = f.nextInt();
		int N = f.nextInt();
		int[] v = new int[N];
		for (int i = 0; i < N; i++) {
			v[i] = f.nextInt();
		}
		Integer sum = new Integer(0);
		if (R>=E) {
			for (int i = 0; i < N; i++) {
				sum = sum + (v[i]*E);
			}
		} else {
			int Energy = E;
			while (max(v)!=-1) {
				int j = max(v);
				sum = sum + (v[j]*Energy);
				v[j] = 0;
				Energy = R;
				for (int i = j; i>=0&&i!=max(v)&&Energy<R; i--) {
					Energy+=R;
				}
			}
		}
		return sum.toString();
	}
	
	public static void main(String[] args) {
		try {
		Scanner in = new Scanner(new File("/home/steven/workspace/Codejam/Ain"));
		PrintWriter out = new PrintWriter(new FileWriter("/home/steven/workspace/Codejam/Bout")); 
		int cases;
		cases = in.nextInt();
		for (int i = 0; i < cases; i++) {
			System.out.println("Trying case "+(i+1)+"...");
			out.println("Case #"+(i+1)+": "+solve(in));
			System.out.println("Success!");
		}
		in.close();
		out.close();
		} catch (IOException e) {
			System.out.println("IO Problems");
		}
		System.out.println("Done!");
	}
}

