import java.io.File;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class RecycledNumbers {
	public static void main(String[] args) {
		try {
			System.setOut(new PrintStream(new FileOutputStream("output.txt")));
			Scanner scanner = new Scanner(new File(args[0]));
			int testsNum = scanner.nextInt();
			
			String solution;
			for (int i=1; i<=testsNum; i++) {
				solution = solve(scanner);
				System.out.println("Case #"+i+": "+solution);
				System.err.println("Case #"+i+": "+solution);
			}
		} catch (Exception e) {e.printStackTrace();}
	}
	
	static class Pair {
		private int n;
		private int m;
		public Pair(int n, int m) {this.n=n; this.m=m;}
		public int hashCode() {return n^m;}
		public boolean equals(Object o) {
			if (!(o instanceof Pair)) return false;
			Pair p = (Pair)o;
			return n==p.n && m==p.m;
		}
		
	}
	
	private static String solve(Scanner scanner) {
		int A = scanner.nextInt();
		int B = scanner.nextInt();
		
		int ret=0;
		int r;

		int digits;
		Set<Pair> pairs = new HashSet<Pair>();
		Pair pair;
		for (int n=A; n<=B; n++) {
			digits = (int)Math.ceil(Math.log10(n));
			if (n>10) {
				for (int d=1; d<digits; d++) {
					r = rotate(n,d);
					if (n<r && r<=B) {
						pair = new Pair(n,r);
						if (!pairs.contains(pair)) {
							pairs.add(new Pair(n,r));
							ret++;
						}
					}
				}
			}
		}
		return ""+ret;
	}
	
	private static int rotate(int n, int pos) {
		return n%(int)Math.pow(10,pos)*(int)Math.pow(10, Math.ceil(Math.log10(n))-pos)+n/(int)Math.pow(10, pos);
	}
}
