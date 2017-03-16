import java.io.BufferedReader;
import java.io.File;
import java.io.InputStreamReader;
import java.io.PrintWriter;


public class CodeJam14_1C_3 {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter out = new PrintWriter(new File("output"));
		int t = Integer.parseInt(br.readLine());

		for (int tc = 1; tc <= t; tc++) {
			String[] line = br.readLine().split("\\s+");
			int n = Integer.parseInt(line[0]);
			int m = Integer.parseInt(line[1]);
			int k = Integer.parseInt(line[2]);
			
			int min = k;
			if (k > 4) {
				for (int i = 1; i < n - 1; i++) {
					for (int j = 1; j < m - 1; j++) {
						int ans = (i + 2) * (j + 2) - 4;
						int cur = 2 * i + 2 * j + (k > ans ? (k - ans) : 0);
						min = cur < min ? cur : min;
					}
				}
				
				if (min == Integer.MAX_VALUE)
					min = k;
			}
			
			out.print("Case #" + tc + ": ");
			out.println(min);
		}
		out.close();
	}
}
