import java.io.IOException;
import java.io.InputStreamReader;
import java.io.LineNumberReader;


public class Recycled {
	static int n = 1;
	
	static void solve(int A, int B) {
		int len = ("" + A).length();
		int min = 1;
		for (int a = 1; a < len; a++)
			min *= 10;
		
		int res = 0;
		
		int[] seen = new int[len];
		int nseen;
		
		for (int n = A; n < B; n++) {
			int m = n;
			nseen = 0;
			for (int a = 1; a < len; a++) {
				m = (m / 10) + (m % 10) * min;
				if (m >= min && n < m && m <= B) {
					boolean already = false;
					for (int b = 0; b < nseen; b++)
						if (seen[b] == m)
							already = true;
					if (!already) {
						res++;
						seen[nseen++] = m;
					}
				}
			}
		}
		
		System.out.println("Case #" + (n++) + ": " + res);
	}
	
	public static void main(String[] args) throws IOException {
		LineNumberReader in = new LineNumberReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(in.readLine().trim());
		
		for (int a = 0; a < n; a++) {
			String[] l = in.readLine().trim().split(" ");
			solve(Integer.parseInt(l[0]), Integer.parseInt(l[1]));
		}
	}
}
