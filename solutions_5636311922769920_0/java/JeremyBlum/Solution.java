import java.util.Scanner;


public class Solution {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		
		for (int i = 1; i <= t; i++) {
			int k = sc.nextInt();
			int c = sc.nextInt();
			int s = sc.nextInt();
			
			System.out.print("Case #" + i + ":");
			if (s * c < k) {
				System.out.println(" IMPOSSIBLE");
			}
			else if (k == 1) {
				System.out.println(" 1");
			}
			else {
				System.out.println(solve(k, c));
			}
		}
	}
	
	public static String solve(long k, long c) {
		StringBuffer sb = new StringBuffer();
		
		for (int i = 0; i < k; i += c) {
			long intervalLength = (long) Math.pow(k, (c-1));
			int p = i;
			long position = 1;
			while (intervalLength > 0 && p < k) {
				position += p * intervalLength;
				//System.out.println("p = " + p + " position = " + position + " length = " + intervalLength);
				p = p + 1;
				intervalLength = intervalLength / k;
			}
			sb.append(" ");
			sb.append(position);
		}
		
		
		return sb.toString();
	}
}
