package qual2013;

import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;
import java.util.SortedSet;
import java.util.TreeSet;

public class C
{

	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(System.in);
		//PrintWriter out = new PrintWriter(System.out);
		PrintWriter out = new PrintWriter(new File("C.out"));
	
		for (int t = Integer.valueOf(in.nextLine()), cs = 1; t > 0; t--, cs++) {
			out.print("Case #" + cs + ": ");
			long a = in.nextLong(), b = in.nextLong();
			out.println(set.headSet(b+1).size() - set.headSet(a).size());
		}
		
		out.flush();
	}
	
	static final long MAX = 100000000000000L;
	static final SortedSet<Long> set = new TreeSet<Long>();
	static {
		for (long i = 1; i*i <= MAX; i++) {
			if (isPal(i) && isPal(i*i)) {
				//System.out.println(i + " " + i*i);
				set.add(i*i);
			}
		}
	}

	static boolean isPal(long x) {
		char[] s = (x+"").toCharArray();
		for (int i = 0, j = s.length-1; i < j; i++, j--)
			if (s[i] != s[j]) return false;
		return true;
	}
}
