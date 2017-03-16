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
		Scanner r = new Scanner(new FileReader("C-small-attempt0 (2).in"));
		PrintWriter pw = new PrintWriter("C1.out");
		
		int cases = 0;
		int t = r.nextInt();
		while (t-- > 0) {
			int a = r.nextInt();
			int b = r.nextInt();
			
			int res = 0;
			for (int i = a; i <= b; i++) {
				if (is("" + i) && isPalin("" + i)) {
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
