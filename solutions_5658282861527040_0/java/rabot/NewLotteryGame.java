package gcj2014r1b;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.StringTokenizer;

public class NewLotteryGame {
	public static void main(String[] args) throws Exception {
		String fileName = args[0];
		NewLotteryGame obj = new NewLotteryGame();
		obj.solve(fileName);
	}

	public void solve(String fileName) throws Exception {
		BufferedReader br = new BufferedReader(new FileReader(fileName));
		BufferedWriter bw = new BufferedWriter(
				new FileWriter(fileName + ".out"));

		int T = Integer.parseInt(br.readLine());
		for (int i = 0; i < T; i++) {
			String str = br.readLine();
			StringTokenizer token = new StringTokenizer(str, " ");
			int A = Integer.parseInt(token.nextToken());
			int B = Integer.parseInt(token.nextToken());
			int K = Integer.parseInt(token.nextToken());

			long cnt = 0;
			for (int a = 0; a < A; a++) {
				for (int b = 0; b < B; b++) {
					if ((a & b) < K) {
						cnt++;
					}
				}
			}

			bw.write("Case #" + (i + 1) + ": " + cnt);
			bw.write("\r\n");
		}
		bw.close();
		br.close();
	}
}
