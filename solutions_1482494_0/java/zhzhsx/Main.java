import java.util.Arrays;
import java.util.Scanner;

class Level implements Comparable<Level> {
	public int no, a, b;

	public int compareTo(Level o) {
		if (b != o.b)
			return b - o.b;
		else
			return a - o.a;
	}
}

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int tn = sc.nextInt();
		for (int ti = 0; ti < tn; ti++) {
			int n = sc.nextInt();
			Level[] ls = new Level[n];
			for (int i = 0; i < n; i++) {
				ls[i] = new Level();
				ls[i].no = i;
				ls[i].a = sc.nextInt();
				ls[i].b = sc.nextInt();
			}
			int[] flag = new int[n];
			Arrays.sort(ls);
			int stars = 0;
			int cnt = 0;
			out: for (int i = 0; i < ls.length;) {
				while (stars >= ls[i].b) {
					stars += 2 - flag[ls[i].no];
					flag[ls[i].no] = 2;
					cnt++;
					i++;
					if (i >= ls.length)
						break out;
				}
				for (int j = ls.length - 1; j >= i; j--) {
					if (ls[j].a <= stars && flag[ls[j].no] == 0) {
						stars++;
						flag[ls[j].no] = 1;
						cnt++;
					}
					if (stars >= ls[i].b)
						break;
				}
				if (stars < ls[i].b)
					break;
			}
			boolean all = true;
			for (int i = 0; i < flag.length; i++) {
				if (flag[i] != 2) {
					all = false;
					break;
				}
			}
			if (all)
				System.out.printf("Case #%d: %d%n", ti + 1, cnt);
			else
				System.out.printf("Case #%d: Too Bad%n", ti + 1);
		}
	}
}
