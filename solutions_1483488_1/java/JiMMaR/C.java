import java.awt.Point;
import java.io.File;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class C {
	public static Set<Point> set;

	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(new File("input.in"));
		int n, a, b;
		n = in.nextInt();

		for (int tc = 1; tc <= n; tc++) {
			a = in.nextInt();
			b = in.nextInt();
			set = new HashSet<Point>();
			finder(a, b);
			System.out.println("Case #" + tc + ": " + set.size() / 2);
		}

	}

	public static void finder(int a, int b) {
		int temp;
		int ans = 0;
		for (int i = a; i <= b; i++) {
			for (int j = 1;; j++) {
				temp = moveDigits(i, j);
				if (temp == -1)
					break;
				if (temp != i && temp >= a && temp <= b) {
					// System.out.println("Output :" + i + "  " + temp);
					set.add(new Point(i, temp));
					ans++;
				}
			}

		}
	}

	public static int moveDigits(int num, int moveBy) {
		String s = Integer.toString(num);
		int size = s.length();
		if (moveBy >= s.length())
			return -1;
		s = s.substring(moveBy) + s.substring(0, moveBy);
		if (Integer.toString((Integer.parseInt(s))).length() != size)
			return 0;
		return Integer.parseInt(s);
	}

}
