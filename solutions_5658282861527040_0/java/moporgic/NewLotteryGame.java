import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.Scanner;

public class NewLotteryGame {

	static {
		try {
			String input = "B-small-attempt0.in";
			String output = input.substring(0, input.lastIndexOf('.')) + ".out";
			System.setIn(new FileInputStream(input));
			System.setOut(new PrintStream(new FileOutputStream(output), true));
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(0);
		}
	}

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		for (int t = 1, T = input.nextInt(); t <= T; t++) {
			int A = input.nextInt();
			int B = input.nextInt();
			int K = input.nextInt();
			int x = 0;
			for (int k = 0; k < K; k++) {
				for (int a = 0; a < A; a++) {
					for (int b = 0; b < B; b++) {
						if ((a & b) == k)
							x++;
					}
				}
			}
			System.out.printf("Case #%d: %d\n", t, x);
		}
		input.close();
	}

}
