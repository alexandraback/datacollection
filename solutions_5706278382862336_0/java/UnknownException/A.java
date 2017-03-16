import java.io.File;
import java.io.FileNotFoundException;
import java.math.BigInteger;
import java.util.Scanner;

public class A {
	public static void main(String[] args) {
		Scanner in = null;
		try {
			File f = new File("./a.txt");
			in = new Scanner(f);
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		int T = in.nextInt();
		in.nextLine();
		// System.out.println(in.nextLine());
		for (int caseNo = 1; caseNo <= T; caseNo++) {
			String pq[] = in.nextLine().split("/");
			BigInteger P = new BigInteger(pq[0]);
			BigInteger Q = new BigInteger(pq[1]);
			// System.out.println("p:" + P + ",q:" + Q);
			BigInteger t40 = new BigInteger("2").pow(40);
			// System.out.println("t40:" + t40);

			BigInteger[] divs = P.multiply(t40).divideAndRemainder(Q);

			if (divs[1].longValue() != 0)
				System.out.format("Case #%d: impossible\n", caseNo);
			else {
				long r = divs[0].longValue();
				int cnt = -1;
				while (r > 0) {
					cnt++;
					r = r / 2;
				}
				System.out.format("Case #%d: %d\n", caseNo, 40 - cnt);
			}
		}
	}
}
