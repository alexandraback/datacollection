import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
	static ArrayList<BigInteger> ansSet = new ArrayList<BigInteger>();
	
	static boolean judge(String s) {
		for (int i = 0, j = s.length() - 1; i < j; i++, j--) {
			if (s.charAt(i) != s.charAt(j)) {
				return false;
			}
		}
		return true;
	}
	
	static void dfs(String s) {
		if (s.length() > 50) {
			return;
		}
		dfs('0' + s + '0');
		for (char i = '1'; i <= '2'; i++) {
			BigInteger temp = new BigInteger(i + s + i);
			if (judge(temp.multiply(temp).toString())) {
				ansSet.add(temp.multiply(temp));
				dfs(i + s + i);
			}
		}
	}
	
	public static void main(String[] args) {
		ansSet.add(new BigInteger("1"));
		ansSet.add(new BigInteger("4"));
		ansSet.add(new BigInteger("9"));
		dfs("");
		dfs("0");
		dfs("1");
		dfs("2");
		dfs("3");
		Object[] ans = ansSet.toArray();
		Arrays.sort(ans);
		Scanner input = new Scanner(System.in);
		int T = input.nextInt();
		for (int ca = 1; ca <= T; ca++) {
			BigInteger a = new BigInteger(input.next()), b = new BigInteger(input.next());
			int l = Arrays.binarySearch(ans, a);
			if (l < 0) {
				l = -(l + 1);
			}
			int r = Arrays.binarySearch(ans, b);
			if (r < 0) {
				r = -(r + 1);
			} else {
				r++;
			}
			System.out.println("Case #" + ca + ": " + (r - l));
		}
		input.close();
	}
}
