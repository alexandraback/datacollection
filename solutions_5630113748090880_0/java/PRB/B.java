import java.util.Arrays;
import java.util.HashMap;
import java.util.Scanner;

public class B {

	private String getList(int[][] lists, int N) {
		HashMap<Integer, Integer> map = new HashMap<>();
		int[] result = new int[N];
		StringBuilder res = new StringBuilder();
		int pivot = 0;
		for (int j = 0; j < lists.length; j++) {
			for (int k = 0; k < N; k++) {
				if (map.containsKey(lists[j][k])) {
					int count = map.get(lists[j][k]);
					map.put(lists[j][k], count + 1);
				} else {
					map.put(lists[j][k], 1);
				}
			}
		}
		for (Integer key : map.keySet()) {
			int count = map.get(key);
			if (count % 2 != 0) {
				result[pivot] = key;
				pivot++;
			}
		}
		Arrays.sort(result);
		for (int i = 0; i < N; i++) {
			res.append(" " + result[i]);
		}
		return res.toString();
	}

	public static void main(String[] args) {
		Scanner in = null;
		B b = new B();
		try {
			in = new Scanner(System.in);
			int count = in.nextInt();
			for (int test = 1; test <= count; test++) {
				int N = in.nextInt();
				int[][] lists = new int[2 * N - 1][N];
				for (int j = 0; j < 2 * N - 1; j++) {
					for (int k = 0; k < N; k++) {
						lists[j][k] = in.nextInt();
					}
				}
				String result = b.getList(lists, N);
				System.out.println("Case #" + test + ":" + result);
			}
			in.close();
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}
