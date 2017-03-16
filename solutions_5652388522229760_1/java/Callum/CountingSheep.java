import java.io.BufferedReader;
import java.io.FileReader;
import java.io.PrintWriter;

public class CountingSheep {

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new FileReader("A-large.in"));
		PrintWriter pw = new PrintWriter("A-large.out");
		
		int t = Integer.parseInt(br.readLine());
		
		for (int test = 1; test <= t; test++) {
			int n = Integer.parseInt(br.readLine());

			boolean[] seen = new boolean[10];
			int s = 0;
			
			if (n == 0) {
				pw.printf("Case #%d: INSOMNIA%n", test);
			} else {
				int current = n;
				while (s < 10) {
					int q = current;
					while (q != 0) {
						int p = q % 10;
						if (!seen[p]) {
							seen[p] = true;
							s++;
						}
						q /= 10;
					}
					current += n;
				}
				
				pw.printf("Case #%d: %d%n", test, current - n);
			}
		}
		
		br.close();
		pw.close();
	}
}