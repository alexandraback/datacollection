import java.io.BufferedInputStream;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;
import java.util.Scanner;

public class P1 {

	public static void main(String[] args) throws IOException {
		Scanner scanner = new Scanner(new File("A-small-attempt2.in"));
		//BufferedInput input = new BufferedInputStream(new FileReader("p1.in"));
		BufferedWriter output = new BufferedWriter(new FileWriter("A-small-attempt2.out"));
		int T = scanner.nextInt();
		for (int Test = 1; Test <= T; Test++) {
			int ans = 0;
			int s = scanner.nextInt();
			int n = scanner.nextInt();
			int[] d = new int[n];
			for (int i = 0; i < n; i++) {
				d[i] = scanner.nextInt();
			}
			Arrays.sort(d);
			ans = n;
			if (s == 1) {
				ans = n;
			} else {
				int tmp = 0;
				for (int i = 0; i < n; i++) {
					ans = Math.min(ans, tmp + n - i);
					while (s <= d[i]) {
						s = (s << 1) - 1;
						tmp++;
					}
					s += d[i];
				}
				ans = Math.min(ans, tmp);
			}	
			output.write("Case #" + Test + ": " + ans + "\n");
		}
		scanner.close();
		output.close();
	}

}
