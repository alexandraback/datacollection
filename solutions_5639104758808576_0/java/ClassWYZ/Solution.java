import java.util.Scanner;


public class Solution {
	public static int Stand(String s) {
		int res = 0;
		int length = s.length();
		int[] count = new int[length];
		if (length > 1) count[1] = s.charAt(0) - '0';
		for (int i = 2; i < length; ++i) {
			count[i] = count[i - 1] + (s.charAt(i - 1) - '0');
		}
		for (int i = length - 1; i > 0; --i) {
			while ((count[i] + res) < i) res++;
		}
		
		return res;
	}
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int num = in.nextInt();
		in.nextLine();
		for (int i = 0; i < num; ++i) {
			in.nextInt();
			String s = in.nextLine();
			System.out.println("Case #" + (i + 1) + ": " + Stand(s.substring(1)));
		}
		in.close();
	}

}
