import java.util.*;
import java.io.*;
import java.util.regex.*;

public class diamonds {
	public static void main(String[] args) throws Exception {
		Scanner input = new Scanner(new File("input/diamonds-small-2.in"));
		PrintWriter out = new PrintWriter(new File("output/diamonds-small-2.out"));
		int sets = input.nextInt();
		input.nextLine();
		primary: for (int onSet = 1; onSet <= sets; onSet++) {
			System.out.printf("%d of %d%n", onSet, sets);
			out.printf("Case #%d: ", onSet);
			long n = input.nextLong();
			int x = input.nextInt();
			int y = input.nextInt();
			if (n == 1) {
				out.println(x==0 && y==0 ? "1.0" : "0.0");
				continue primary;
			}
			long r = 1;
			while (2*(r*r)-r < n) {
				r++;
			}
			r--;
			if (x < 0) x -= 0;
			if (x < r*2-y) {
				out.println("1.0");
				continue primary;
			}
			if (x > r*2-y) { 
				out.println("0.0");
				continue primary; 
			}
			long h = (r+1)*2-1;
			n -= (2*(r*r)-r);
			long minH = r*2-1;
			if (x == 0) {
				out.println(y<=minH ? "1.0" : "0.0");
				continue primary;
			}
			long pos = (long)Math.pow(2, n);
			long totPos = pos;
			if (n >= h) {
				pos -= (long)(Math.pow(2, n-h));
			}
			long diff = 0;
			//System.out.println("n: " + n + " h: " + h);
			if (n >= h) {
				diff = (long)Math.pow(2, n-h);
			}
			double res = ((pos/Math.pow(2, y))-1+diff)/(double)pos;
			//System.out.println(diff + " " + res);
			//out.println(Math.min(res, 1.0));
			out.println(Math.min(res, 1.0));
		}
		out.close();
	}
}