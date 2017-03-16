import java.io.BufferedReader;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Fractiles {

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new FileReader("D-large.in"));
		PrintWriter pw = new PrintWriter("D-large.out");
		
		int t = Integer.parseInt(br.readLine());
		
		for (int test = 1; test <= t; test++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			
			int k = Integer.parseInt(st.nextToken());
			int c = Integer.parseInt(st.nextToken());
			int s = Integer.parseInt(st.nextToken());

			pw.printf("Case #%d:", test);
			
			if (k > s * c) {
				pw.print(" IMPOSSIBLE");
			} else {
				long pos = 0;
				
				for (int i = 0; pos < k && i < s; i++) {
					long[] coords = new long[c];
					for (int j = 0; j < c; j++) {
						coords[j] = pos;
						pos++;
					}
					pw.print(" " + getPos(coords, k));
				}
			}
			pw.println();
		}
		
		br.close();
		pw.close();
	}
	
	public static long getPos(long[] coords, long k) {
		long ans = 0;
		for (int i = 0; i < coords.length; i++) {
			long r = Math.min(k - 1, coords[i]);
			ans += r * Math.pow(k, coords.length - i - 1);
		}
		return ans + 1;
	}
}
