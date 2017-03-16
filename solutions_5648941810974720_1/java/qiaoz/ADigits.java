import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class ADigits {
	static Scanner sc;
	static ArrayList<Integer> ans;
	static int[] c;
	
	public static void main(String[] args) {
		sc = new Scanner(System.in);
		int T = sc.nextInt();
		for (int t = 1; t <= T; t++) {
			String s = sc.next();
			c = new int[26];
			for (char a: s.toCharArray()) {
				c[a - 'A']++;
			}
			ans = new ArrayList<>();
			fun(c);
			Collections.sort(ans);
			System.out.printf("Case #%d: ", t);
			for (int b: ans) {
				System.out.print(b);
			}
			System.out.println();
		}
		
		sc.close();
	}
	
	public static void fun(int[] c) {
		remove(0, "ZERO", 'Z');
		remove(6, "SIX", 'X');
		remove(2, "TWO", 'W');
		remove(4, "FOUR", 'U');
		remove(5, "FIVE", 'F');
		remove(7, "SEVEN", 'S');
		remove(8, "EIGHT", 'G');
		remove(9, "NINE", 'I');
		remove(1, "ONE", 'O');
		remove(3, "THREE", 'R');
	}
	
	public static void remove (int num, String word, char a) {
		while (c[a- 'A'] > 0) {
			for (char d: word.toCharArray()) {
				c[d - 'A'] --;
			}
			ans.add(num);
		}
	}
}
