import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.Scanner;

public class C1 {

	public static boolean is(String s) {
		long n = Long.parseLong(s);
		double nn = Math.sqrt(n);
		if (nn == (long) nn) {
			if (isPalin("" + (long) nn)) {
				return true;
			}
		}
		return false;
	}

	public static boolean isPalin(String s) {
		int n = s.length();
		for (int i = 0; i < n / 2; i++) {
			if (s.charAt(i) != s.charAt(n - i - 1))
				return false;
		}
		return true;
	}

	public static void main(String[] args) throws FileNotFoundException {
		Scanner r = new Scanner(new FileReader("C-large-1 (2).in"));
		PrintWriter pw = new PrintWriter("C1.out");

		long[] ps = { 1L, 100000020000001L, 1000002000001L, 10000200001L,
				100020001L, 1002001L, 1002003002001L, 100220141022001L,
				1004006004001L, 10201L, 102012040210201L, 102030201L,
				1020304030201L, 10221412201L, 1022325232201L, 102234363432201L,
				1024348434201L, 104060401L, 121L, 121000242000121L,
				1210024200121L, 12102420121L, 1212225222121L, 121242121L,
				121242363242121L, 1214428244121L, 12321L, 123212464212321L,
				1232346432321L, 1234321L, 123454321L, 12345654321L,
				1234567654321L, 123456787654321L, 125686521L, 14641L, 4L,
				400000080000004L, 4000008000004L, 40000800004L, 400080004L,
				4004009004004L, 4008004L, 404090404L, 40804L, 44944L, 484L, 9L };

		int cases = 0;
		int t = r.nextInt();
		while (t-- > 0) {
			long a = r.nextLong();
			long b = r.nextLong();

			int res = 0;
			for (int i = 0; i < ps.length; i++) {
				if (ps[i] >= a && ps[i] <= b) {
					res++;
				}
			}

			pw.printf("Case #%d: ", ++cases);
			pw.println(res);
		}
		pw.flush();
		pw.close();
	}
}
