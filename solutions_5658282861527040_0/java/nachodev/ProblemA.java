package Round1B;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class ProblemA {


	public static void main(String[] args) throws IOException {
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

		int T = Integer.parseInt(reader.readLine());
		for (int t=1; t <= T; t++) {
			String[] parts = reader.readLine().split(" ");
			int A = Integer.parseInt(parts[0]);
			int B = Integer.parseInt(parts[1]);
			int K = Integer.parseInt(parts[2]);

			int count = 0;
			for (int i=0; i < A; i++) {
				for (int j=0; j < B; j++) {
					if ((i & j) < K) {
						count++;
					}
				}
			}

			System.out.println("Case #" + t + ": " + count);
		}
	}
}
