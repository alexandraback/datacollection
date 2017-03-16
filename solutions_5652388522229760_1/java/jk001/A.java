import java.io.*;
import java.util.*;

public class A {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int TC = sc.nextInt();
		for (int i = 1; i <= TC; i++) {
			int N = sc.nextInt();
			String ans = "";
			if (N == 0) {
				ans = "INSOMNIA";
			} else {
				HashMap<Character, Integer> ticked = new HashMap<Character, Integer>();
				int counter = 1;
				int next = 0;
				while (ticked.size() != 10) {
					next = N * counter++;
					String num = String.valueOf(next);

					for (char c : num.toCharArray()) {
						if (!ticked.containsKey(c)) {
							ticked.put(c, 1);
						}
					}
				}

				ans = String.valueOf(next);
			}

			System.out.println("CASE #" + i + ": " + ans);
		}
	}

}
