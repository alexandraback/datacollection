import java.util.*;

public class a {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);

		int T = in.nextInt();
		for (int t = 1; t <= T; t++) {
			// TODO

			int k = in.nextInt();
			String s = in.nextLine().substring(1);
			int sum = 0;
			int need = 0;
			for (int i = 0; i < s.length(); i++) {
				int a = Character.getNumericValue(s.charAt(i));
				if (i > sum + need)
					need = i - sum;
				sum += a;
			}

			System.out.printf("Case #%d: %d\n", t, need);
		}
	}
}