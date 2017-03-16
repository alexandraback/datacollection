import java.util.HashSet;
import java.util.Scanner;

public class B {
	private static int count;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for (int i = 1; i <= T; i++) {
			String[] N = new String[sc.nextInt()];
			for (int j = 0; j < N.length; j++) {
				N[j] = sc.next();
			}
			count = 0;
			perm(N, 0);
			System.out.printf("Case #%d: %d\n", i, count);
		}
		sc.close();
	}

	private static void perm(String[] N, int index) {
		if (N.length == index) {
			if (check(N)) {
				count++;
			}
		} else {
			for (int i = index; i < N.length; i++) {
				String temp = N[i];
				N[i] = N[index];
				N[index] = temp;
				perm(N, index + 1);
				temp = N[i];
				N[i] = N[index];
				N[index] = temp;
			}
		}
	}

	private static boolean check(String[] N) {
		StringBuffer s = new StringBuffer("");
		for (int i = 0; i < N.length; i++) {
			s.append(N[i]);
		}
		HashSet<Character> set = new HashSet<Character>();
		set.add(s.charAt(0));
		for (int i = 1; i < s.length(); i++) {
			if (s.charAt(i) != s.charAt(i - 1)) {
				if (set.contains(s.charAt(i))) {
					return false;
				} else {
					set.add(s.charAt(i));
				}
			}
		}
		return true;
	}
}