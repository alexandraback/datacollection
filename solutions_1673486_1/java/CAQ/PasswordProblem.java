import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Scanner;

public class PasswordProblem {
	final static String FILENAME = "A-large";

	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(new FileReader("/home/workshop/Documents/"
				+ FILENAME + ".in"));
		BufferedWriter bw = new BufferedWriter(new FileWriter(
				"/home/workshop/Documents/" + FILENAME + ".out"));
		int T = sc.nextInt();
		for (int ttt = 0; ttt < T; ttt++) {
			double minexp = -1.0;

			int A = sc.nextInt();
			int B = sc.nextInt();
			if (A == 0) { // haven't input yet
				minexp = 1.0 + B;
			} else {
				double[] p = new double[A], firstnnowrong = new double[A + 1];
				firstnnowrong[0] = 1.0;
				for (int aaa = 0; aaa < A; aaa++) {
					p[aaa] = sc.nextDouble();
					firstnnowrong[aaa + 1] = firstnnowrong[aaa] * p[aaa];
				}
				double[] strategies = new double[A + 2];
				// go ahead
				strategies[0] = firstnnowrong[A] * (B - A + 1)
						+ (1 - firstnnowrong[A]) * (B - A + 1 + B + 1);
				for (int deln = 1; deln <= A; deln++) {
					// press backspace n times
					strategies[deln] = firstnnowrong[A - deln]
							* (deln + deln + B - A + 1)
							+ (1 - firstnnowrong[A - deln])
							* (deln + deln + B - A + 1 + B + 1);
				}
				if (A == B) {
					// press enter, A == B
					strategies[A + 1] = firstnnowrong[A] * 1
							+ (1 - firstnnowrong[A]) * (B - A + 1 + B + 1);
				} else {
					// press enter, A < B
					strategies[A + 1] = 1.0 + B + 1;
				}
				for (int sttg = 0; sttg <= A + 1; sttg++) {
					if (minexp < 0 || strategies[sttg] < minexp)
						minexp = strategies[sttg];
				}
			}

			bw.write("Case #" + (ttt + 1) + ": " + minexp);
			bw.newLine();
		}
		bw.close();
		sc.close();
	}
}
