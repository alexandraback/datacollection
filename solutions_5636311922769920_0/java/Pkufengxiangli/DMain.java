import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;

public class DMain {
	public static void main(String[] args) {
		Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
		int t = in.nextInt();  // Scanner has functions to read ints, longs, strings, chars, etc.
		for (int i = 1; i <= t; ++i) {
			int k = in.nextInt();
			int c = in.nextInt();
			int s = in.nextInt();

			if ((c == 1 && s < k) || (c!= 1 && s < k - 1)) {
				System.out.println("Case #" + i + ": " + "IMPOSSIBLE");
			}else if (c == 1) {
				System.out.print("Case #" + i + ": ");
				for (int j = 0; j < k-1; j++) {
					System.out.print((j + 1) + " ");
				}
				System.out.println(k);
			}else{
				System.out.print("Case #" + i + ": ");
				for (int j = 0; j < k-2; j++) {
					System.out.print((j+2) + " ");
				}
				System.out.println(k);
			}
		}
	}
}
