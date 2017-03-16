import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.StringTokenizer;

public class ProblemB {

	private static final String OUT = "C:/workspaces/tc/CodeJam/src/B.out";
	private static final String IN = "D:/downloads/B-large.in";

	public static boolean canHaveScoreWithoutSurprise(int score, int requiredScore) {
		if (requiredScore == 0) {
			return true;
		}
		return Math.max(0, requiredScore - 1) * 3 + 1 <= score;
	}

	public static boolean canHaveScoreWithSurprise(int score, int requiredScore) {
		return Math.max(0, requiredScore - 2) * 3 + 2 <= score;
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new FileReader(IN));
		BufferedWriter bw = new BufferedWriter(new FileWriter(OUT));
		int T = Integer.parseInt(br.readLine());
		for (int i = 0; i < T; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int N = Integer.parseInt(st.nextToken());
			int S = Integer.parseInt(st.nextToken());
			int p = Integer.parseInt(st.nextToken());
			int[] t = new int[N];
			for (int j = 0; j < N; j++) {
				t[j] = Integer.parseInt(st.nextToken());
			}
			int withoutSurpriseTotal = 0;
			int withSurpriseTotal = 0;
			for (int score : t) {
				if (canHaveScoreWithoutSurprise(score, p)) {
					withoutSurpriseTotal++;
				} else {
					if (canHaveScoreWithSurprise(score, p)) {
						withSurpriseTotal++;
					}
				}
			}
			int res = withoutSurpriseTotal + Math.min(withSurpriseTotal, S);
			bw.write("Case #" + (i + 1) + ": " + res + "\n");
		}
		bw.close();
	}

}
