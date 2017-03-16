import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class A {

	public static void main(String[] args) throws IOException {
		
		Scanner in = new Scanner (new File ("A-small-attempt0.in"));
		PrintWriter out = new PrintWriter (new FileWriter ("A-small.txt"));
		int T = in.nextInt();
		for (int test = 1; test <= T; test++) {
			int N = in.nextInt();
			if (N == 0)
				out.println("Case #" + test + ": INSOMNIA");
			else {
				boolean[] seen = new boolean[10];
				Arrays.fill(seen, false);
				int i = 1;
				for (int count = 0; count < 10; i++) {
					long number = i * N;

					while (number > 0) {
						int digit = (int)(number % 10);
						if (!seen[digit]) {
							seen[digit] = true;
							count++;
						}
						number = number / 10;
					}
				}
				int ans = (i-1)* N;
				out.println("Case #" + test + ": " + ans);
			}
		}
		out.close();
	}

}
