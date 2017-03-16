package round1A;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;

class Level {
	int one, two;

	@Override
	public String toString() {
		return "(" + one + "," + two + ")";
	}
}

class LevelComparator implements Comparator<Level> {
	public int compare(Level arg0, Level arg1) {
		if (arg0.two > arg1.two)
			return 1;
		else if (arg0.two < arg1.two)
			return -1;
		else
			return 0;
	}
}

public class P2 {
	static Scanner sc;
	static FileWriter fw;

	public static boolean check(boolean[] t) {
		for (boolean b : t) {
			if (!b)
				return false;
		}
		return true;
	}

	public static void main(String[] args) throws IOException {
		sc = new Scanner(new FileReader("B-large.in"));
		fw = new FileWriter("out.txt");
		int T = sc.nextInt();
		for (int c = 1; c <= T; ++c) {
			int n = sc.nextInt();
			ArrayList<Level> levels = new ArrayList<Level>();
			boolean[] o = new boolean[n], t = new boolean[n];
			for (int i = 0; i < n; ++i) {
				Level l = new Level();
				l.one = sc.nextInt();
				l.two = sc.nextInt();
				levels.add(l);
				o[i] = false;
				t[i] = false;
			}
			Collections.sort(levels, new LevelComparator());

			int star = 0, step = 0;
			while (!check(t)) {
				boolean up = false;
				for (int i = 0; i < levels.size(); ++i) {
					Level l = levels.get(i);
					if (l.two <= star && t[i] == false) {
						t[i] = true;
						if (o[i] == true)
							star++;
						else
							star += 2;
						step++;
						up = true;
					}
				}

				if (up)
					continue;

				int max = -1, index = -1;
				for (int i = 0; i < levels.size(); ++i) {
					Level l = levels.get(i);
					if (t[i] == false && l.one <= star && o[i] == false) {
						if (l.two > max) {
							max = l.two;
							index = i;
						}
					}
				}

				if (index == -1) {
					fw.append("Case #" + c + ": Too Bad\n");
					break;
				} else {
					o[index] = true;
					star++;
					step++;
				}
			}

			if (check(t)) {
				fw.append("Case #" + c + ": " + step + "\n");

			}

		}
		sc.close();
		fw.close();
	}
}
