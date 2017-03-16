import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;


public class A {

	static long paintRequired(long r, long n) {
		return 2*n*r + n*(2*n-1);
	}

	static long solve(long r, long t) {
		long n = 1;
		while (paintRequired(r, n) <= t) n *= 2;
		long upper = n;
		long lower = n/2;
		while (upper-lower > 1) {
			long mid = lower + (upper-lower)/2;
			if (paintRequired(r, mid) <= t) {
				lower = mid;
			} else {
				upper = mid;
			}
		}
		while (paintRequired(r, upper) > t) upper--;
		return upper;
	}

	public static void main(String[] args) {
		try {
			File fin = new File("A-small-attempt0.in");
			Scanner sc = new Scanner(fin);
			File fout = new File("A-small-out.txt");
			PrintWriter pw = new PrintWriter(fout);
			//PrintWriter pw = new PrintWriter(System.out);
			int T = sc.nextInt();
			for (int cn=1; cn<=T; cn++) {
				long r = sc.nextLong();
				long t = sc.nextLong();
				pw.write("Case #" + cn + ": " + solve(r, t) + "\n");
			}
			pw.flush();
			pw.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

}
