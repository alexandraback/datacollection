import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class test {
	public static void main(String[] args) throws NumberFormatException,
			IOException {
		BufferedReader buf = new BufferedReader(new FileReader("A-small-attempt0.in"));
		PrintWriter writer = new PrintWriter(new File("A.out"));
		int tcase = Integer.parseInt(buf.readLine().trim());
		for (int i = 1; i <= tcase; i++) {
			StringTokenizer str = new StringTokenizer(buf.readLine());

			long r = Long.parseLong(str.nextToken());
			long t = Long.parseLong(str.nextToken());
			int cnt = 0;
			int j = 1;
			while (t > 0) {
				t -= j * j + 2 * r * j;
				long k = j - 1;
				t += (2 * k * r + k * k);
				if (t >= 0)
					cnt++;
				j += 2;
			}
			writer.printf("Case #%d: %d\n", i, cnt);
		}
		writer.close();
	}
}
