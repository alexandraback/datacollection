import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;

import com.google.common.collect.Multimap;


public class C {
	
	private static final String NAME = "A-small";

	public static void main(String[] args) throws Exception {
		BufferedReader reader = new BufferedReader(new FileReader("in/" + NAME + ".in"));
		BufferedWriter writer = new BufferedWriter(new FileWriter("out/" + NAME + ".out"));
		try {
			int t = Integer.parseInt(reader.readLine());
			for (int i = 0; i < t; ++i) {
				int n = Integer.parseInt(reader.readLine());
				int[][] p = new int[n][n];
				for (int j = 0; j < n; ++j) {
//					p[j][j] = 1;
				}
				
				for (int j = 0; j < n; ++j) {
					String[] inp = reader.readLine().split(" ");
					int m = Integer.parseInt(inp[0]);
					for (int k = 0; k < m; ++k) {
						int to = Integer.parseInt(inp[k + 1]) - 1;
						p[j][to] = 1;
					}
				}
				
				for ( int k = 0; k < n; k++ )
					for ( int a = 0; a < n; a++ )
						for ( int b = 0; b < n; b++ )
							p[a][b] +=  p[a][k] * p[k][b];
				
				boolean diamond = false;
				
				for ( int a = 0; a < n; a++ )
					for ( int b = 0; b < n; b++ )
						if (p[a][b] > 1) {
							diamond = true;
						}
				writer.write("Case #" + (i + 1) + ": ");
				if (diamond) {
					writer.write("Yes");
				} else {
					writer.write("No");
				}
				writer.newLine();
			}
		} finally {
			reader.close();
			writer.close();
		}
	}
}
