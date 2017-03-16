package round1;

import java.awt.Point;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Scanner;

public class ProblemC {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int T = s.nextInt();
		for (int i = 0; i < T; i++) {
			int N = s.nextInt();
			HashMap<Integer, Integer> map = new HashMap<>();
			int[] array = new int[N];
			int n = N;
			int count = 0;
			while (n > 0) {
				int curr = s.nextInt();
				map.put(count + 1, curr);
				array[count] = curr;
				n--;
				count++;
			}
			int maxFalse = 0;
			int maxTrue = 0;
			for (int j = 0; j < N; j++) {
				Type aux = tryWith(j, N, array, map);
				if (aux.isRecip) {
					maxTrue += aux.count;
				} else {
					if (maxFalse < aux.count) {
						maxFalse = aux.count;
					}
				}
			}
			int max = maxTrue / 2 > maxFalse ? maxTrue / 2 : maxFalse;
			System.out.println("Case #" + (i + 1) + ": " + max);
		}
		s.close();

	}

	private static Type tryWith(int j, int N, int[] array,
			HashMap<Integer, Integer> map) {
		int count = 1;
		int curr = array[j] - 1;
		if (reciproc(curr, j, array, map, N)) {
			count += friendsOfMe(curr, j, array, map, N);
			count += friendsOfMe(j, curr, array, map, N);
			return new Type(count - 1, new Point(curr, j), true);
		}
		while (curr != j && count <= N) {
			count++;
			curr = array[curr] - 1;
		}
		if (curr == j) {
			return new Type(count, null, false);
		} else {
			return new Type(-1, null, false);
		}
	}

	private static int friendsOfMe(int curr, int before, int[] array,
			HashMap<Integer, Integer> map, int n) {
		int aux = 0;
		int max = 0;
		List<Integer> l = getList(curr + 1, array);
		for (Integer integer : l) {
			if (integer - 1 != before) {
				aux = friendsOfMe(integer - 1, curr, array, map, n);
				if (aux > max) {
					max = aux;
				}
			}
		}
		return max + 1;
	}

	private static List<Integer> getList(int i, int[] array) {
		List<Integer> l = new ArrayList<>();
		for (int j = 0; j < array.length; j++) {
			if (array[j] == i) {
				l.add(j + 1);
			}
		}
		return l;
	}

	private static boolean reciproc(int curr, int j, int[] array,
			HashMap<Integer, Integer> map, int n) {
		return (array[curr] - 1) == j;
	}

	private static class Type {
		int count;
		boolean isRecip;
		Point reciproc;

		public Type(int count, Point reciproc, boolean is) {
			super();
			this.count = count;
			this.reciproc = reciproc;
			this.isRecip = is;
		}

	}
}
