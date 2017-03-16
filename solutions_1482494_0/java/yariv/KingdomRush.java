package round1A;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class KingdomRush {

	/**
	 * @param args
	 */
	public static void main(String[] args) throws IOException {
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(reader.readLine());
		for (int i=1; i<=T; i++) {
			String line = reader.readLine();
			StringTokenizer tok = new StringTokenizer(line);
			int N = Integer.parseInt(tok.nextToken());
			int[] As = new int[N];
			int[] Bs = new int[N];
			for (int j=0; j<N; j++) {
				line = reader.readLine();
				tok = new StringTokenizer(line);
				As[j] = Integer.parseInt(tok.nextToken());
				Bs[j] = Integer.parseInt(tok.nextToken());
			}
			int[] done = new int[N];
			int count = 0;
			int stars = 0;
			while (stars != 2*N) {
				int chosen = -1;
				int highestB = -1;
				for (int j=0; chosen == -1 && j<N; j++) {
					if (Bs[j] <= stars && done[j] < 2) {
						chosen = j;
					}
					else {
						if (As[j] <=stars && done[j] < 1 && (highestB == -1 || Bs[highestB] < Bs[j])) {
							highestB = j;
						}
					}
				}
				if (chosen == -1) chosen = highestB;
				if (chosen == -1) break;
				if (Bs[chosen] <= stars) {
					stars += 2-done[chosen];
					done[chosen] = 2;
				}
				else {
					stars++;
					done[chosen] = 1;
				}
				count++;
			}
			if (stars == 2*N) System.out.printf("Case #%d: %d\n", i, count);
			else System.out.printf("Case #%d: Too Bad\n", i);
		}
	}

}
