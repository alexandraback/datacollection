import java.io.*;
import java.util.Arrays;
import java.util.Scanner;

public class roundb1_1 {
	public static PrintStream out = new PrintStream(new BufferedOutputStream(System.out));;
	public static Scanner sc = new Scanner(System.in);
	public static long motes[];
	public static long n;
	public static long dp(int index, long num) {
		if (index >= n)
			return 0;
		long ret = 0;
		long i = 0;
		if (num <= motes[index]) {
			ret = 1;
			for (i = 2*num-1; i <= motes[index]; i+=i-1) {
				if (i <= num) {
					ret = 0;
					break;
				}
				ret++;
			}
			if (ret > 0)
				ret = Math.min(ret+dp(index+1, i+motes[index]), dp(index+1, num)+1);
			else
				ret = dp(index+1, num)+1;
		}
		else {
			ret = dp(index+1, num+motes[index]);
		}
		return ret;
	}
	public static void main(String[] args) {
		long cases = sc.nextInt();
		for (int casenum = 1; casenum <= cases; casenum++) {
			long a = sc.nextLong();
			n = sc.nextLong();
			long operations = 0;
			motes = new long[(int)n];
			for (int ctr = 0; ctr < n; ctr++) {
				motes[ctr] = sc.nextLong();
			}
			Arrays.sort(motes);
			operations = dp(0, a);
			
			out.printf("Case #%d: %d\n", casenum, operations);
		}
		out.flush();
	}
}
