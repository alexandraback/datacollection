import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;

public class RevPancakes {

	public static void main(String[] args) {
		Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
		int testCount = in.nextInt();
		
		for (int test = 0; test < testCount; test++) {
			String s = in.next();
			boolean[] stack = new boolean[s.length()];
			for (int i = 0; i < s.length(); i++) {
				stack[i] = s.charAt(i) == '+' ? true : false;
			}
			
			solveCase(test, stack);
		}
		
		in.close();
	}
	
	private static void solveCase(int test, boolean[] stack) {
		int count = 0;
		for (int i = stack.length - 1; i >= 0; i--) {
			if (!stack[i]) {
				int j;
				for (j = 0; j < i; j++) {
					if (!stack[j]) {
						break;
					}
				}
				if (j > 0) {
					count++;
					flipGroup(stack, j - 1);
				}
				count++;
				flipGroup(stack, i);
			}
		}
		
		System.out.println("Case #" + (test + 1) + ": " + count);
	}
	
	private static void flipGroup(boolean[] group, int end) {
		for (int ri = end; ri >= 0; ri--) {
			group[ri] = !group[ri];
		}
		for (int si = end; si > end/2; si--) {
			boolean b = group[si];
			group[si] = group[end - si];
			group[end - si] = b;
		}
	}
}
