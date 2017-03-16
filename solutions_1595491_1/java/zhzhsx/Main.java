import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for (int ti = 0; ti < t; ti++) {
			int n = sc.nextInt();
			int s = sc.nextInt();
			int p = sc.nextInt();
			int result = 0;
			List<Integer> list = new ArrayList<Integer>();
			for (int i = 0; i < n; i++)
				list.add(sc.nextInt());
			Collections.sort(list);

			int ns = n - s;

			for (int k = 0; k <= ns; k++) {
				int tr = 0;
				int j = 0;
				for (; j < k; j++) {
					int tmp;
					if (list.get(j) <= 1)
						tmp = list.get(j);
					else
						tmp = (list.get(j) - 1) / 3 + 1;
					if (tmp >= p)
						break;
				}
				tr += k - j;
				for (j = list.size() - (ns - k); j < list.size(); j++) {
					int tmp;
					if (list.get(j) <= 1)
						tmp = list.get(j);
					else
						tmp = (list.get(j) - 1) / 3 + 1;
					if (tmp >= p)
						break;
				}
				tr += list.size() - j;
				for (j = k; j < list.size() - (ns - k); j++) {
					int tmp;
					if (list.get(j) <= 1)
						tmp = -100;
					else
						tmp = (list.get(j) - 2) / 3 + 2;
					if (tmp >= p)
						break;
				}
				tr += list.size() - (ns - k) - j;
				result = Math.max(result, tr);
			}
			System.out.printf("Case #%d: %d%n", ti + 1, result);
		}
	}
}
