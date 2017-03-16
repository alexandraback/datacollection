import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;

public class D1 {

	public static void main(String[] args) throws Exception {

		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));

		int T = Integer.parseInt(in.readLine());
		for (int t = 1; t <= T; t++) {
			String[] data = in.readLine().split(" ");
			int X = Integer.parseInt(data[0]);
			int R = Integer.parseInt(data[1]);
			int C = Integer.parseInt(data[2]);
			boolean win = firstPlayerWin(X, R, C);
			out.println("Case #" + t + ": " + (win ? "RICHARD" : "GABRIEL"));
		}
		out.close();
	}
	
	// X, R, C <= 4
	private static boolean firstPlayerWin(int X, int R, int C) {
		
		int a = Math.min(R, C);
		int b = Math.max(R, C);
		
		// check area
		if ((a * b) % X != 0)
			return true;
		
		// easy cases
		if (X <= 2)
			return false;
		if (X == 3)
			return a == 1;
		
		// 4-ominoes
		if (X == 4) {
			if (a <= 2)
				return true;
			else if (a == 3 && b == 3)
				return true;
			else if (a == 3 && b == 4)
				return false;
			else if (a == 4 && b == 4)
				return false;
		}
		return false;
	}
	
}
