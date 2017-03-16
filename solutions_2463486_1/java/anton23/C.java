import java.util.Scanner;
import java.util.TreeSet;


public class C {
	
	public static boolean isPalindrome(long n) {
		String sn = n + "";
		char[] a = sn.toCharArray();
		for (int i = 0; i < a.length / 2; i++) {
			if (a[i] != a[a.length - 1 - i]) {
				return false;
			}
		}
		return true;
	}
	
	public static void main(String[] args) {
		
		TreeSet<Integer> all = new TreeSet<Integer>();
		for (int i = 1; i <= 10000000; i++) {
			if (isPalindrome(i) && isPalindrome(i*i))  {
				all.add(i*i);
			}
		}		
		Scanner sc = new Scanner(System.in);
		
		long T = sc.nextLong();
		for (int i = 0; i < T; i++) {
			long A = sc.nextLong();
			long B = sc.nextLong();
			int res = 0;
			for (Integer n : all) {
				if (n >= A && n <= B) res++;
			}
			System.out.println("Case #" + (i+1) + ": " + res);
		}
		
	}

}
