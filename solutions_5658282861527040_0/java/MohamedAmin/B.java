import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;

public class B {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new FileReader(new File(
				"B-small-attempt0.in")));
		PrintWriter out = new PrintWriter(new File("out.out"));

		String[] sp;

		int T = Integer.parseInt(br.readLine());
		int a, b, k;

		for (int i = 0; i < T; i++) {
			sp = br.readLine().split(" ");
			a = Integer.parseInt(sp[0]);
			b = Integer.parseInt(sp[1]);
			k = Integer.parseInt(sp[2]);
			int cur = 0;
			int min = Math.min(a, b);
			int max = Math.max(a, b);
			for (int j = 0; j < min	; j++) {
				for (int l = 0; l < max; l++) {
					if((j & l) < k)
						cur++;
				}
			}
			
			out.println("Case #" + (i + 1) + ": " + cur);

		}
		

		br.close();
		out.close();

	}
}
