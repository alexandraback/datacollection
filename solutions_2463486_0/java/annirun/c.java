import java.util.Scanner;

public class c {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int cases = in.nextInt();
		for (int i = 0; i < cases; i++) {
			int a = in.nextInt();
			int b = in.nextInt();
			
			int count = 0;
			for (int c = a; c <= b; c++) {
				if (!isPal(c)) {
					continue;
				} 
				int s = (int) Math.sqrt(c);
				if (!(s*s == c && isPal(s))) {
					continue;
				}
				count++;
			}
			
			System.out.printf("Case #%d: %d\n", i+1, count);
		}
	}

	private static boolean isPal(int c) {
		char[] s = ("" + c).toCharArray();
		int mid = s.length/2;
		int last = s.length-1;
		for (int i = 0; i < mid; i++) {
			if (s[i] != s[last-i])
				return false;
		}
		return true;
	}
}
