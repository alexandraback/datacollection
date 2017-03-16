import static java.lang.Integer.parseInt;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;

public class Lucky {
	public static void main(String[] args) throws NumberFormatException, IOException {
		HashMap<Integer, HashSet<String>> mem = new HashMap<Integer, HashSet<String>>();
		for (int i = 2; i <= 5; i++) {
			for (int k = 2; k <= 5; k++) {
				for (int j = 2; j <= 5; j++) {
					put(mem, 1, "" + i + j + k);
					put(mem, i, "" + i + j + k);
					put(mem, j, "" + i + j + k);
					put(mem, k, "" + i + j + k);
					put(mem, i * j, "" + i + j + k);
					put(mem, i * k, "" + i + j + k);
					put(mem, j * k, "" + i + j + k);
					put(mem, i * k * j, "" + i + j + k);
				}
			}
		}
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = parseInt(br.readLine());
		String[] s = br.readLine().split(" ");
		int r = parseInt(s[0]), n = parseInt(s[1]), m = parseInt(s[2]), k = parseInt(s[3]);
		System.out.println("Case #1:");
		for (int i = 0; i < r; i++) {
			s = br.readLine().split(" ");
			HashSet<String> arr0 = mem.get(parseInt(s[0]));
			for (int j = 1; j < k; j++) {
				HashSet<String> arr1 = mem.get(parseInt(s[j]));
				HashSet<String> newArr = new HashSet<String>();
				for (String ss : arr0) {
					if (arr1.contains(ss)) {
						newArr.add(ss);
					}
				}
				arr0 = newArr;
			}
			for (String ss : arr0) {
				System.out.println(ss);
				break;
			}
		}
	}

	private static void put(HashMap<Integer, HashSet<String>> map, int n, String s) {
		if (map.containsKey(n)) {
			map.get(n).add(s);
			return;
		}
		HashSet<String> arr = new HashSet<String>();
		arr.add(s);
		map.put(n, arr);
	}
}
