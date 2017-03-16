import java.util.*;
public class C1 {
	static boolean is_palindrome(long n) {
		String s = n+"";
		return s.equals(new StringBuffer(s).reverse().toString());
	}
	public static void main(String[] args) {
		TreeMap<Long, Integer> M = new TreeMap<Long, Integer>();
		M.put(0L, 0);
		int cnt = 0;
		long L = 1000*1000*10;
		for(long i=1; i<=L; i++)
			if(is_palindrome(i) && is_palindrome(i*i)) {
				M.put(i*i, ++cnt);
			}
		
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		for(int cas=1; cas<=T; cas++) {
			long A = in.nextLong();
			long B = in.nextLong();
			long ans = M.floorEntry(B).getValue()-M.lowerEntry(A).getValue();
			System.out.printf("Case #%d: %d\n", cas, ans);
		}
	}
}
