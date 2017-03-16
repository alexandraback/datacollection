import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.StreamTokenizer;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;

public class Police {

	public static void main(String[] args) throws Exception {
		Police object = new Police();
		String className = object.getClass().getSimpleName();

		FileReader fileReader = new FileReader(new File(className.toLowerCase() + ".in"));
		StreamTokenizer st = new StreamTokenizer(new BufferedReader(fileReader));

		FileWriter wr = new FileWriter(className.toLowerCase() + ".out");

		st.nextToken();
		int testCases = (int) st.nval;

		HashMap<String, String> solved = new HashMap<>();

		for (int tc = 1; tc <= testCases; tc++) {

			System.out.println("At test " + tc + "/" + testCases);

			st.nextToken();
			int J = (int) st.nval;

			st.nextToken();
			int P = (int) st.nval;

			st.nextToken();
			int S = (int) st.nval;

			st.nextToken();
			int K = (int) st.nval;

			String result = object.solve(J, P, S, K);

			wr.write("Case #" + tc + ": " + result.trim() + "\r\n");
		}

		wr.close();
	}

	int max = 0;
	String result = "0";

	List<String> options = new ArrayList<>();
	Map<String, Integer> count = new HashMap<>();

	int used;
	int K;
	String[] taken = new String[30];

	Set<String> visited = new HashSet<>();

	public String solve(int J, int P, int S, int K) {

		options = new ArrayList<>();
		count = new HashMap<>();

		taken = new String[30];

		max = 0;
		result = "0";

		for (int j = 1; j <= J; j++)
			for (int p = 1; p <= P; p++)
				for (int s = 1; s <= S; s++) {
					options.add(j + "" + p + "" + s);

					count.put("JP-" + j + p, 0);
					count.put("JS-" + j + s, 0);
					count.put("PS-" + p + s, 0);
				}

		System.out.println(options);

		used = 0;
		this.K = K;
		visited = new HashSet<>();
		generate(0, 0);
		return result;
	}

	private void generate(int current, int state) {

		

		if (visited.contains(current + "#" + state)) {
			return;
		}

		visited.add(current + "#" + state);

		if (used + (options.size() - current) < max) {
			return;
		}

		if (current >= options.size()) {
			if (used > max) {
				max = used;

				result = max + "\n";

				for (int t = 0; t < max; t++)
					result += taken[t] + "\n";
			}

			return;
		}
				

		// take it
		String next = options.get(current);
		int j = next.charAt(0) - '0';
		int p = next.charAt(1) - '0';
		int s = next.charAt(2) - '0';

		int success = 0;
		success += increase(count, "JP-" + j + p, 1);
		success += increase(count, "JS-" + j + s, 1);
		success += increase(count, "PS-" + p + s, 1);

		if (success != 3) {
			increase(count, "JP-" + j + p, -1);
			increase(count, "JS-" + j + s, -1);
			increase(count, "PS-" + p + s, -1);
		} else {

			taken[used] = split(next);
			used++;
			generate(current + 1, state + (1 << current));

			used--;
			increase(count, "JP-" + j + p, -1);
			increase(count, "JS-" + j + s, -1);
			increase(count, "PS-" + p + s, -1);
		}

		// don't take it
		generate(current + 1, state);
	}

	private String split(String string) {
		return string.replace("", " ").trim();
	}

	private int increase(Map<String, Integer> map, String key, int value) {
		map.put(key, map.get(key) + value);

		if (map.get(key) > K) {
			return 0;
		}

		return value;
	}
}
