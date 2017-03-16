import java.util.HashSet;
import java.util.Scanner;

public class problemC {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner cin = new Scanner(System.in);
		int t = cin.nextInt(), a, b, c, i, ten, len, q, j = 0, ans, ts, k = 0;
		while (t > 0) {
			t--;
			k++;
			ten = 1;
			len = 1;
			a = cin.nextInt();
			b = cin.nextInt();
			c = a;
			ans = 0;
			while (c > 9) {
				c /= 10;
				ten *= 10;
				len++;
			}
			HashSet<Integer> hash = new HashSet<Integer>();
			for (i = a; i <= b; i++) {
				if (!hash.contains(i)) {
					hash.add(i);
					ts = 1;
					j = i;
					for (q = 0; q < len; q++) {
						j = (j % ten) * 10 + j / ten;
						if (j >= a && j <= b && !hash.contains(j)) {
							ts++;
							hash.add(j);
						}
					}
					ans += ts * (ts - 1) / 2;
				}
			}
			System.out.println("Case #" + k + ": " + ans);
		}
	}
}
