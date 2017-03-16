import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class SafetyInNumbers {

	static final String input_path = "data/input.txt";
		
	/**
	 * Good luck, Wash :)
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new FileReader(input_path)); 
		String intext = in.readLine();
		int T = Integer.parseInt(intext);
		for (int caseIter = 0; caseIter < T; caseIter ++) {
			String line = in.readLine();
			String[] parts = line.split(" ");
			int N = Integer.parseInt(parts[0]);
			int[] S = new int[N];
			for (int i = 1; i <= N; i ++) 
				S[i - 1] = Integer.parseInt(parts[i]);
			
			double[] ans = solve(N, S);
			System.out.print(String.format("Case #%d:", caseIter + 1));
			for (int i = 0; i < N; i ++) 
				System.out.print(String.format(" %.6f", ans[i]));
			System.out.println();
		}
		in.close();
	}

	private static double[] solve(int n, int[] s) {
		double[] ans = new double[n];
		int X = 0;
		for (int i = 0; i < n; i++)
			X += s[i];
		
		double sum = (double)X * 2;
		double avg = sum / (double)n;
		int nn = n;
		
		boolean flag = true;
		boolean[] mark = new boolean[n];
				
		while (true) {
			flag = true;
			for (int i = 0; i < n; i ++) {
				if (mark[i]) {
					ans[i] = 0;
					continue;
				}
				
				ans[i] = 100 * (avg - s[i]) / X;
				if (ans[i] < 0) {
					nn -= 1;
					sum -= s[i];
					flag = false;
					mark[i] = true;
					break;
				}
			}
			
			if (flag)
				break;
			else {
				avg = sum / (double)nn;
			}
		}
		return ans;
	}

}
