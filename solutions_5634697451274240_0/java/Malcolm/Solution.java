import java.lang.*;
import java.util.*;
import java.io.*;

public class Solution {
	public static int solve(boolean[] pancakes, int n, boolean goal) {
		if (n == 0) { return 0; }
		if (pancakes[n - 1] == goal) {
			return solve(pancakes, n - 1, goal);
		}
		return 1 + solve(pancakes, n - 1, !goal);
	}

	public static void main(String[] args) {
		try (Scanner scanner = new Scanner(new BufferedReader(new InputStreamReader(System.in)))) {
			int t = scanner.nextInt();
			for (int i = 1; i <= t; i++) {
				String line = scanner.next();
				int n = line.length();
				boolean[] pancakes = new boolean[n];
				for (int c = 0; c < line.length(); c++) {
					pancakes[c] = line.charAt(c) == '+';
				}
				System.out.println("case #" + i + ": " + solve(pancakes, n, true));
			}
		}
	}
}
