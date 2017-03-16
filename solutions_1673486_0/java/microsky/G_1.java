import java.io.*;
import java.util.*;
import java.util.Map.Entry;

public class G_1 {

	public static void main(String[] args) throws Exception {
		G_1 instance = new G_1();
		instance.func();
	}

	static int A, B;
	static HashMap<String, Integer> map;

	public void func() throws Exception {
		PrintWriter bw = new PrintWriter(new FileWriter("1.txt"));
		Scanner scan = new Scanner(System.in);
		int T = scan.nextInt();
		for (int i = 0; i < T; i++) {
			A = scan.nextInt();
			B = scan.nextInt();
			double min = B + 2;
			double p = 1;
			double b = A;
			for (int j = 0; j < A; ++j) {
				p = p * scan.nextDouble();
				double x = (b + 1 + B - A) * p + (b + 1 + B - A + B + 1)
						* (1 - p);

				if (x < min) {
					min = x;
				}
				b--;
			}
			double x = (b + 1 + B - A) * p + (b + 1 + B - A + B + 1) * (1 - p);

			if (x < min) {
				min = x;
			}
			System.out.println(String.format("Case #%d: %.6f", (i + 1), min));
			bw.write(String.format("Case #%d: %.6f\n", (i + 1), min));
		}
		bw.flush();
		bw.close();
	}
}
