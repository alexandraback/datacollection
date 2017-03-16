import java.io.*;
import java.util.*;

public class P3 {

	public static void main(String[] args) throws Exception {
		Scanner scan = new Scanner(new File("in.txt"));
		PrintWriter w = new PrintWriter("out.txt");

		int cases = scan.nextInt();

		for (int i = 0; i < cases; i++) {
			int ans = 0;

			int c = scan.nextInt();
			int d = scan.nextInt();
			int v = scan.nextInt();

			ArrayList<Integer> ds = new ArrayList<Integer>();

			for (int j = 0; j < d; j++) {
				ds.add(scan.nextInt());
			}

			for (int k = 1; k <= v; k++) {
				int now = 0;
				for (int j = ds.size() - 1; j >= 0; j--) {
					int get = ds.get(j);
					if (get <= k - now) {
						now += get;
					}
					if (now == k) {
						break;
					}
				}

				if (now != k) {
					boolean added = false;
					for (int j = ds.size() - 1; j >= 0; j--) {
						int get = ds.get(j);
						if (get < k) {
							ds.add(j + 1, k);
							ans++;
							added = true;
							break;
						}
					}
					if (!added) {
						ans++;
						ds.add(0, k);
					}

				}

			}

			w.print("Case #");
			w.print(i+1);
			w.print(": ");
			w.print(ans);
			w.println();
		}

		scan.close();
		w.close();
	}

}
