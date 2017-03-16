package round1A;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class ProblemB {

	/**
	 * @param args
	 * @throws FileNotFoundException 
	 */
	public static void main(String[] args) throws FileNotFoundException {
		Scanner sc = new Scanner(new File("round1A/B-small-attempt2.in"));
		PrintWriter out = new PrintWriter(new File("round1A/out.txt"));
		
		int T = sc.nextInt();
		sc.nextLine();
		
		for (int tc = 1; tc <= T; tc++) {
			
			int E = sc.nextInt();
			int R = sc.nextInt();
			int N = sc.nextInt();
			int[] v = new int[N];
			
			for (int i=0; i<N; i++) {
				v[i] = sc.nextInt();
			}
			
			int current = E;
			
			
			printSolution(out, tc, ""+backTrack(E, 0, v, R, E));
		}
		out.close();
		sc.close();
	}

	public static int backTrack(int energy, int i, int[] v, int R, int E) {
		int value = 0;
		
		if (i == v.length)
			return 0;
		
		energy += R;
		if (energy > E)
			energy = E;
		
		for (int j=0; j<=energy; j++) {
			int temp = v[i]*j+backTrack(energy-j, i+1, v, R, E);
			//System.out.println(i+" "+energy+" "+j+" "+temp);
			if (temp > value)
				value = temp;
		}
		return value;
	}
	public static void printSolution(PrintWriter out, int tc, String soln) {
		out.println("Case #"+tc+": "+soln);
		out.flush();
		System.out.println("Case #"+tc+": "+soln);
		
	}
}