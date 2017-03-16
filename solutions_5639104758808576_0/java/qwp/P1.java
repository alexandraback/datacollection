import java.util.*;

public class P1 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int num = Integer.parseInt(in.nextLine());
		for (int i = 0; i < num; i++) {
			String line = in.nextLine();
			int n = Integer.parseInt("" + line.charAt(0));
			int[] arr = new int[n + 1];
			for (int j = 0; j <= n; j++) {
				arr[j] = Integer.parseInt("" + line.charAt(j + 2));
			}
			int res = solve(arr);
			System.out.println("Case #" + (i+1) + ": " + res);
		}
	}
	
	public static int solve(int[] arr) {
		int sum = arr[0];
		int add = 0;
		int cur = sum + add;  // number currently standing
		for (int i = 1; i < arr.length; i++) {
			if (arr[i] == 0) {
				continue;
			} else if (cur >= i) {
				sum += arr[i];
				cur = sum + add;
			} else {
				add += i - cur;
				sum += arr[i];
				cur = sum + add;
			}
		}
		return add;
	}
}
