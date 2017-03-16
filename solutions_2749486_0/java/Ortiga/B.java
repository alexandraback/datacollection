import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class B {

	public int dp(int i, int j, int step, int cost) {

		int e = dp(i, j + step, step + 1, cost + 1);
		int w = dp(i, j - step, step + 1, cost + 1);
		int n = dp(i + step, j, step + 1, cost + 1);
		int s = dp(i - step, j, step + 1, cost + 1);

		return 0;
	}

	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(
				new FileInputStream("B.txt")));
		PrintWriter out = new PrintWriter("Bo.txt");
		int t = Integer.parseInt(in.readLine());
		for (int i = 1; i <= t; i++) {
			StringTokenizer to = new StringTokenizer(in.readLine(), " ");
			int x = Integer.parseInt(to.nextToken());
			int y = Integer.parseInt(to.nextToken());
			StringBuilder val = new StringBuilder();
			while (x != 0)
				if (x > 0) {
					val.append("WE");
					x--;
				} else {
					val.append("EW");
					x++;
				}
			while (y != 0)
				if (y > 0) {
					val.append("SN");
					y--;
				} else {
					val.append("NS");
					y++;
				}
			out.println("Case #" + i + ": " + val);
		}
		in.close();
		out.close();
	}

}
