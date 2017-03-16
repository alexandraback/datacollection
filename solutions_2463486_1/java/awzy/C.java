import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;
import java.util.TreeSet;

public class C {
	public static void main(String[] args) throws IOException {
		String name = "C-large-1";
		Scanner sc = new Scanner(new File(name + ".in"));
		//Scanner sc = new Scanner(System.in);
		PrintWriter out = new PrintWriter(new FileWriter(name + ".out"));
		TreeSet<Long> ts = new TreeSet<Long>();
		
		for(long a = 1; a < 10000; a++) {
			long x1 = pal(a,true);
			long x2 = pal(a,false);
			long x1s = x1 * x1;
			long x2s = x2 * x2;
			if(x1s == rev(x1s)) ts.add(x1s);
			if(x2s == rev(x2s)) ts.add(x2s);
		}
		System.out.println(ts.toString());
		
		int n = sc.nextInt();
		for (int c = 1; c <= n; c++) {
			long A = sc.nextLong();
			long B = sc.nextLong();
			int ans = ts.subSet(A, B+1).size();
			out.println("Case #" + c + ": " + ans);
			//System.out.println("Case #" + c + ": " + ans);
		}
		out.close();
		sc.close();
	}
	public static long pal(long a, boolean repeat) {
		long b = rev(a);
		int length = (int)(Math.log10(a)+1);
		b += (repeat ? a : a/10)*((long) Math.pow(10, length));
		return b;
	}
	
	public static long rev(long a) {
		long b = 0, c = a;
		while(c > 0) {
			b *= 10;
			b += c%10;
			c /= 10;
		}
		return b;
	}

}
