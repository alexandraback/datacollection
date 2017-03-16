import java.util.List;
import java.util.Scanner;
import java.math.BigInteger;

public class TrainCars { 
	public static void main(String[] arguments) {
		Scanner sc = new Scanner(System.in);
		
		int t = sc.nextInt();

		for (int i = 0; i < t; i++) {
			int n = sc.nextInt();
			sc.nextLine();

			String[] line = sc.nextLine().split(" ");

			int count = 0;

			for (String[] stringz : Permutations.permutation(line)) {
				
				String perm = "";
				for (String str : stringz) {
					perm += str;
				}
				
				if (isValid(perm)) {
					count++;
				}

			}

			System.out.printf("Case #%d: %d\n", i + 1, count);
		}		
	}

	public static boolean isValid(String perm) {
		boolean[] marked = new boolean[26];
		int length = perm.length();
		char prev = perm.charAt(0);
		marked[prev - 'a'] = true;
		char c;
		for (int i = 1; i < length; i++) {
			c = perm.charAt(i);
			if (c == prev) {
				;
			} else if (marked[c - 'a'] == false) {
				marked[c - 'a'] = true;
			} else {
				return false;
			}
			prev = c;
		}
		return true;
	}
}