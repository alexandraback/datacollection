import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Lawnmower {
	public static void main(String[] args) throws NumberFormatException,
			IOException {
		BufferedReader buf = new BufferedReader(new FileReader("B-small-attempt0.in"));
		PrintWriter writer = new PrintWriter(new File("B.out"));
		int t = Integer.parseInt(buf.readLine().trim());
		for (int i = 1; i <= t; i++) {
			StringTokenizer str = new StringTokenizer(buf.readLine());
			int n = Integer.parseInt(str.nextToken());
			int m = Integer.parseInt(str.nextToken());
			int[][] a = new int[n][m];
			for (int j = 0; j < n; j++) {
				str = new StringTokenizer(buf.readLine());
				for (int k = 0; k < m; k++) {
					a[j][k] = Integer.parseInt(str.nextToken());
				}
			}
			boolean check = true;
			for (int j = 0; j < n && check; j++)
				for (int k = 0; k < m && check; k++) {
					boolean check1 = true;
					boolean check2 = true;
					for (int l = 0; l < m && check1; l++)
						if (a[j][l] > a[j][k])
							check1 = false;
					for (int l = 0; l < n && check2; l++)
						if (a[l][k] > a[j][k])
							check2 = false;
					if (check1 == false && check2 == false)
						check = false;
				}
			if (check)
				writer.printf("Case #%d: YES\n", i);
			else
				writer.printf("Case #%d: NO\n", i);
		}
		writer.close();
	}

}
