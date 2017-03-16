import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class C {

	private void work() throws IOException {

		// Scanner sc = new Scanner(new FileReader("c.in"));
		// PrintWriter pw = new PrintWriter(new FileWriter("c.out"));
		Scanner sc = new Scanner(new FileReader("C-small-attempt0.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("C-small-attempt0.out"));
		// Scanner sc = new Scanner(new FileReader("c.in"));
		// PrintWriter pw = new PrintWriter(new FileWriter("c.out"));
		long[] all = { 1L, 4L, 9L, 121L, 484L, 10201L, 12321L, 14641L, 40804L,
				44944L, 1002001L, 1234321L, 4008004L, 100020001L, 102030201L,
				104060401L, 121242121L, 123454321L, 125686521L, 400080004L,
				404090404L, 10000200001L, 10221412201L, 12102420121L,
				12345654321L, 40000800004L, 1000002000001L, 1002003002001L,
				1004006004001L, 1020304030201L, 1022325232201L, 1024348434201L,
				1210024200121L, 1212225222121L, 1214428244121L, 1232346432321L,
				1234567654321L, 4000008000004L, 4004009004004L, };
		int nc = sc.nextInt();
		for (int tc = 1; tc <= nc; tc++) {
			long a = sc.nextLong();
			long b = sc.nextLong();
			int res = 0;
			for (int i = 0; i < all.length; i++) {
				if (all[i] < a)
					continue;
				if (all[i] > b)
					break;
				res++;
			}
			pw.printf("Case #%d: %d\n", tc, res);
		}
		pw.close();

		// long[] all = new long[1000];
		// int n = 0;
		// for (long i = 1; i <= 10000000; i++) {
		// if (isPali(i) && isPali(i * i)) {
		// System.out.println(i + " " + i * i);
		// all[n++] = i * i;
		// }
		// }
		// System.out.println(n);
		// System.out.print("long[] all = {");
		// for (int i = 0; i < n; i++) {
		// System.out.print(all[i] + "L, ");
		// }
		// System.out.println("};");
	}

	private boolean isPali(long l) {
		if (l < 10)
			return true;
		char[] ca = Long.toString(l).toCharArray();
		for (int i = 0; i < ca.length / 2; i++) {
			if (ca[i] != ca[ca.length - 1 - i])
				return false;
		}
		return true;
	}

	public static void main(String[] args) throws IOException {
		new C().work();
	}

}
