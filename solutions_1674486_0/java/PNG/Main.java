import java.io.*;
import java.util.*;

public class Main {

	public static void main(String[] args) throws Exception {
		Scanner s = new Scanner(new File("input"));
		BufferedWriter w = new BufferedWriter(new FileWriter(new File("output")));
		int cases = s.nextInt();
		s.nextLine();

		for (int i = 1; i <= cases; i++) {
			w.write("Case #");
			w.write(String.valueOf(i));
			w.write(": ");

			boolean ans = solve(s, w);
			w.write(ans ? "Yes" : "No");

			w.write("\n");
		}
		w.close();
	}

	static class Clazz {
		List<Integer> children = new ArrayList<Integer>();
	}

	private static boolean solve(Scanner s, BufferedWriter w) throws Exception {
		int N = s.nextInt();
		Clazz[] classes = new Clazz[N];
		for (int i = 0; i < N; i++) {
			classes[i] = new Clazz();
		}
		for (int i = 0; i < N; i++) {
			int M = s.nextInt();
			for (int j = 0; j < M; j++) {
				classes[s.nextInt() - 1].children.add(i);
			}
		}

		for (int j = 0; j < N; j++) {
			Clazz clazz = classes[j];
			//HashMap<Integer, Boolean> covered = new HashMap<Integer, Boolean>();
			boolean[] covered = new boolean[N];
			if (recurse(clazz, classes, covered)) {
				return true;
			}
//			boolean found = check(clazz, classes);
//			if (found) {
//				return true;
//			}
//			List<Integer> children = clazz.children;
//			for (Integer integer : children) {
//				if (covered.)
//			}
		}

		return false;
	}

	private static boolean recurse(
			Clazz clazz,
			Clazz[] classes,
			boolean[] covered) {
		for (int i : clazz.children) {
			if (covered[i]) {
				return true;
			} else {
				covered[i] = true;
				if (recurse(classes[i], classes, covered)) {
					return true;
				}
			}
		}
		return false;
	}

}
