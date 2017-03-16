import java.util.Scanner;


public class Solution {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int t = sc.nextInt();
		
		for (int i = 1; i <= t; i++) {
			char[] stack = sc.next().toCharArray();
			
			System.out.println("Case #" + i + ": " + solve(stack));
		}
	}
	
	public static long solve(char[] stack) {
		long flips = 0;
		
		while (!ready(stack)) {
			flips++;
			if (stack[0] == '-') {
				int i = 0;
				while (i < stack.length && stack[i] == '-') {
					i++;
				}
				flip(stack,i);
			}
			else {
				int i = 0;
				while (i < stack.length && stack[i] == '+') {
					i++;
				}
				flip(stack,i);
			}
		}
		
		return flips;
	}
	
	public static boolean ready(char[] stack) {
		for (int i = 0; i < stack.length; i++) {
			if (stack[i] == '-') return false;
		}
		return true;
	}
	
	public static void flip(char[] stack, int i) {
		//System.out.println("flipping " + getString(stack) + " 0.." + (i-1));
		for (int p = 0; p < (i+1) / 2; p++) {
			char tmp = stack[p];
			stack[p] = stack[i-p-1] == '+'?'-':'+';
			stack[i - p - 1] = tmp == '+'?'-':'+';
		}
		//System.out.println("  after flip " + getString(stack) );
	}
	
	public static String getString(char[] stack) {
		StringBuffer sb = new StringBuffer(stack.length);
		for (int i = 0; i < stack.length; i++) {
			sb.append(stack[i]);
		}
		return sb.toString();
	}
}
