import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;


public class B {
	public static final String FILENAME = "B-small-attempt0";
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new FileReader("src/"+FILENAME+".in"));
		BufferedWriter out = new BufferedWriter(new FileWriter("src/"+FILENAME+".out"));
		Scanner s = new Scanner(in);
		int T = s.nextInt();
		for(int i = 1; i <= T; i++) {
			int E = s.nextInt();
			int R = Math.min(E, s.nextInt());
			int N = s.nextInt();
			long[] v = new long[N];
			for (int j = 0; j < v.length; j++) {
				v[j] = s.nextInt();
			}
			long[] g = new long[E+1];
			long[] go = new long[E+1];
			for (int j = N-1; j >= 0; j--) {
				System.out.println(j);
				for (int k = R; k <= E; k++) {
					for (int x = Math.max(0, k+R-E); x <= k; x++) {
						g[k] = Math.max(g[k], go[k-x+R]+x*v[j]);
					}
				}
				for (int k = R; k <= E; k++) {
					go[k] = g[k];
				}
			}
			out.write("Case #"+i+": "+g[E]+"\n");
		}
		in.close();
		out.close();
	}
}
