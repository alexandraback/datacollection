import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class B {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader buf = new BufferedReader(new FileReader("B-small-attempt0.in"));
		PrintWriter writer = new PrintWriter("B.out");
		int tCases = Integer.parseInt(buf.readLine());
		for (int t = 1; t <= tCases; t++) {
			StringTokenizer str = new StringTokenizer(buf.readLine());
			int A = Integer.parseInt(str.nextToken());
			int B = Integer.parseInt(str.nextToken());
			int K = Integer.parseInt(str.nextToken());
			int cnt = 0;
			for (int i = 0; i < A; i++)
				for (int j = 0; j < B; j++) {
					if ((i & j) < K)
						cnt++;
				}
			writer.printf("Case #%d: %d\n", t, cnt);
		}
		writer.close();
	}
}
