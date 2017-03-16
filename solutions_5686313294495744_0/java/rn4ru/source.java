import java.util.ArrayList;
import java.util.HashSet;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int T = scanner.nextInt();
		for (int i = 1; i <= T; i++) {
			int N = scanner.nextInt();
			String[][] s = new String[N][2];
			for (int j = 0; j < N; j++) {
				s[j][0] = scanner.next();
				s[j][1] = scanner.next();
			}
			System.out.print("Case #" + i + ": ");
			System.out.println(new Solver().solve(s));
		}
	}
}

class Solver {

	public String solve(String[][] s) {
		HashSet<String> set = new HashSet<>();
		HashSet<String> set2 = new HashSet<>();
		HashSet<String> dup1 = new HashSet<>();
		HashSet<String> dup2 = new HashSet<>();
		for (String[] str : s) {
			if (set.contains(str[0])) {
				dup1.add(str[0]);
			}
			if (set2.contains(str[1])) {
				dup2.add(str[1]);
			}
			set.add(str[0]);
			set2.add(str[1]);
		}

		ArrayList<String[]> list = new ArrayList<>();
		for (String[] str : s) {
			if (dup1.contains(str[0]) && dup2.contains(str[1])) {
				list.add(str);
			}
		}

		return String.valueOf(list.size());
	}

}
