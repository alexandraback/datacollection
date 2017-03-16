import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;

public class C1 {
	public static void main(String[] args) throws FileNotFoundException {
		Scanner console = new Scanner(new File("C-large.in"));
		PrintStream output = new PrintStream(new File("c1.txt"));
		long caseNum = console.nextLong();
		for (long i = 1; i <= caseNum; i++) {
			long length = console.nextLong();
			long times = console.nextLong();
			String circle = console.next();
				output.println("Case #" + i + ": "
						+ result(length, times, circle));
		
		}
	}

	public static String result(long length, long times, String circle) {
		long fin = 1;
		for (long i = 0; i < circle.length(); i++) {
			fin = result(fin, convert(circle.charAt((int) i)));
		}
		if (fin == 1) {
			return "NO";
		}
		if (fin == -1) {
			if (times % 2 == 0) {
				return "NO";
			}
			return test(length,times, circle + circle+circle + circle);
		}
		if (times == 1) {
			return "NO";
		}
		if (times % 4 != 2) {
			return "NO";
		} else {
			return test(length,times, circle + circle+circle + circle);
		}
	}

	public static String test(long length, long times,String circle) {
		long first = 1;
		long third = 1;
		long a = 0;
		long b = circle.length();
		long c = 0;
		while (first != 2&& a < circle.length()) {
			first = result(first, convert(circle.charAt((int) a)));
			a++;
		}
		while (third != 4 && b > 0) {
			third = result(convert(circle.charAt((int) (b-1))), third);
			b--;
			c++;
		}
		if (times*circle.length()/4>=a+c&&first==2&&third==4) {
			return "YES";
		}
		return "NO";
	}

	public static int convert(char a) {
		if (a == 'i') {
			return 2;
		}
		if (a == 'j') {
			return 3;
		}
		if (a == 'k') {
			return 4;
		}
		return 1;
	}

	public static long result(long a, long b) {
		if (a < 0) {
			return -1 * result(-a, b);
		}
		if (b < 0) {
			return -1 * result(a, -b);
		}
		if (a == 1) {
			return b;
		}
		if (b == 1) {
			return a;
		}
		if (a == b) {
			return -1;
		}
		if (a > b) {
			return -1 * result(b, a);
		}
		if (a == 2 && b == 3) {
			return 4;
		}
		if (a == 2 && b == 4) {
			return -3;
		}
		if (a == 3 && b == 4) {
			return 2;
		}
		return 0;
	}

}



