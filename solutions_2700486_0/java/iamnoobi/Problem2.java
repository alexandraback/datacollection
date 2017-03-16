import java.io.BufferedReader;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.PrintStream;
import java.util.Scanner;

public class Problem2 {
	public static int Pyramid(int k) {
		return (2 + 4 * k) * (k + 1) / 2;
	}

	static int binomial(final int N, final int K) {
		int ret = 1;
		for (int k = 0; k < K; k++) {
			ret = ret * (N - k) / (k + 1);

		}
		return ret;
	}

	public static void main(String[] args) {
		FileReader input;
		try {
			input = new FileReader("B-small-attempt1.in.txt");
			BufferedReader reader = new BufferedReader(input);
			PrintStream out = new PrintStream(
					new FileOutputStream("output.txt"));
			int test = Integer.parseInt(reader.readLine());
			for (int k = 1; k <= test; k++) {
				// Solution here
				double result = 0;
				Scanner scanner = new Scanner(reader.readLine());
				int N = scanner.nextInt();
				int X = scanner.nextInt();
				int Y = scanner.nextInt();
				int K = (Math.abs(X) + Y) / 2;
				if (K == 0) {
					result = 1;
				} else if (N >= Pyramid(K)) {
					result = 1;
				} else if (N <= Pyramid(K - 1)) {
					result = 0;
				} else if (X == 0 && N < Pyramid(K)) {
					result = 0;
				} else {
					int extras = N - Pyramid(K - 1);
					double lala = Math.pow(0.5, extras);
					for (int i = 0; i <= extras; i++) {
						if(((extras - i > 2*K) && (extras - 2*K >= Y+1))|| i >= Y+1) result = result + lala * binomial(extras, i);
					}
			 
				}

				out.println("Case #" + k + ": " + result);
			}
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}
