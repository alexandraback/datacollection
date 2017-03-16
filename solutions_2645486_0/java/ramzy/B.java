package codejam.y2013.round1A;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.Scanner;


public class B {
	
	private static int E,R;
	public static void main(String[] args) throws Exception {
		Scanner input = new Scanner(new FileReader("inputs/1A/B.in"));
		PrintWriter output = new PrintWriter("inputs/1A/B.out");

		String out;
		int T = input.nextInt();
		for(int c = 1; c <= T; c++) {
			E = input.nextInt();
			R = input.nextInt();
			int N = input.nextInt();
			int[] act = new int[N];
			int[] arr = new int[N];
			for(int i = 0; i < N; i++) {
				act[i] = input.nextInt();
			}
			
			out = "Case #" + c + ": " + solve(act, 0, arr, E);
			output.println(out);
			System.out.println(out);
		}
		input.close();
		output.close();
	}
	
	private static int solve(int[] act, int index, int[] arr, int e) {
		if(index == act.length) {
			int sum = 0;
			for(int i = 0; i < act.length; i++) {
				sum += act[i]*arr[i];
			}
//			if(sum == 15)
//				System.out.println("a");
			return sum;
		}
		
		int m = 0;
		for(int i = 0*(E-e+R); i <= e; i++) {
			arr[index] = i;
			m = Math.max(m, solve(act, index+1, arr, Math.min(E,e-i+R)));
		}
		return m;
	}
	
}

