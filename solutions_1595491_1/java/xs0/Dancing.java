import java.io.IOException;
import java.io.InputStreamReader;
import java.io.LineNumberReader;


public class Dancing {
	public static void main(String[] args) throws IOException {
		LineNumberReader in = new LineNumberReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(in.readLine().trim());
		for (int a = 1; a <= N; a++) {
			String[] tmp = in.readLine().trim().split(" ");
			int n = Integer.parseInt(tmp[0]);
			int s = Integer.parseInt(tmp[1]);
			int p = Integer.parseInt(tmp[2]);
			
			int minNormal, minSurprising;
			if (p < 2) {
				minNormal = minSurprising = p;
			} else {
				minNormal = 3 * p - 2;
				minSurprising = 3 * p - 4;
			}
			
			int res = 0;
			for (int b = 0; b < n; b++) {
				int val = Integer.parseInt(tmp[3 + b]);
				
				if (val >= minNormal) {
					res++;
				} else
				if (val >= minSurprising && s > 0) {
					res++;
					s--;
				}
			}
			
			System.out.println("Case #" + a + ": " + res);
		}
	}
}
