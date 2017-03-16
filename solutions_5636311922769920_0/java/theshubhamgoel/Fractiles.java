import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Fractiles {

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(System.out);
		int t, k, c, s;
		StringTokenizer st;
		t = Integer.parseInt(br.readLine());
		for (int i = 0; i < t; i++) {
			st = new StringTokenizer(br.readLine());
			k = Integer.parseInt(st.nextToken());
			c = Integer.parseInt(st.nextToken());
			s = Integer.parseInt(st.nextToken());

			if (s == k) {
				pw.print("Case #" + (i + 1)+":");
				for (int j = 0; j < k; j++) {
					pw.print(" " + (j + 1));
				}
				pw.println();
			}
		}
		pw.flush();
	}
}
