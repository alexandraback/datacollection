package round1b;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Osmos {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(reader.readLine());
		for (int i=1; i<=T; i++) {
			String line = reader.readLine();
			StringTokenizer tok = new StringTokenizer(line);
			int A = Integer.parseInt(tok.nextToken());
			int N = Integer.parseInt(tok.nextToken());
			int[] motes = new int[N];
			line = reader.readLine();
			tok = new StringTokenizer(line);
			for (int j = 0; j < N; j++) {
				motes[j] = Integer.parseInt(tok.nextToken());
			}
			Arrays.sort(motes);
			int num = Integer.MAX_VALUE;
			int totalAdded = 0;
			int totalSize = A;
			if (A>1) {
				for (int j=0; j<N; j++) {
					if (totalSize > motes[j]) {
						totalSize+=motes[j];
					}
					else {
						num = Math.min(num, totalAdded + N-j);
						while (totalSize <= motes[j]) {
							totalSize = 2*totalSize - 1;
							totalAdded++;
						}
						totalSize+=motes[j];
					}
				}
				num = Math.min(num, totalAdded);
			}
			else {
				num = N;
			}
			System.out.printf("Case #%d: %d\n", i, num);
		}
	}
}
