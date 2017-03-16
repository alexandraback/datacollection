
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;

public class CJ_2016_R1A_A {

	private static String[] words = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
	private static int[] order = {0, 2, 8, 6, 3, 4, 1, 5, 7, 9};
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int nT = Integer.parseInt(in.readLine());
		for (int t = 1; t <= nT; t++) {
			String s = in.readLine();
			int[] c = new int[26];
			for (int i = 0; i < s.length(); i++)
				c[s.charAt(i) - 'A']++;
			System.out.print("Case #" + t + ": ");
			ArrayList<Integer> ans = new ArrayList<Integer>();
			for (int i : order)
				while (canRemove(i, c)) {
					remove(i, c);
					ans.add(i);
				}
			Collections.sort(ans);
			for (int i: ans)
				System.out.print(i);
			System.out.println();
		}
	}
	
	private static boolean canRemove(int n, int[] c) {
		int[] c1 = Arrays.copyOf(c, c.length);
		for (int i = 0; i < words[n].length(); i++) {
			c1[words[n].charAt(i) - 'A']--;
			if (c1[words[n].charAt(i) - 'A'] < 0)
				return false;
		}
		return true;
	}
	
	private static void remove(int n, int[] c) {
		for (int i = 0; i < words[n].length(); i++)
			c[words[n].charAt(i) - 'A']--;
	}

}
