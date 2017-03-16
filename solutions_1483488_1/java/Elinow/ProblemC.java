import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Set;
import java.util.StringTokenizer;

public class ProblemC {

	private static final String OUT = "C:/workspaces/tc/CodeJam/src/C.out";
	private static final String IN = "D:/downloads/C-large.in";

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new FileReader(IN));
		BufferedWriter bw = new BufferedWriter(new FileWriter(OUT));
		int T = Integer.parseInt(br.readLine());
		for (int i = 0; i < T; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			String num = st.nextToken();
			int k = num.length();
			int A = Integer.parseInt(num);
			int B = Integer.parseInt(st.nextToken());
			int res = 0;
			int mult = 1;
			for (int j = 0; j < k - 1; j++) {
				mult *= 10;
			}
			Map<Integer, Set<Integer>> map = new HashMap<Integer, Set<Integer>>(2000000);
			for (int j = A; j <= B; j++) {
				int t = j;
				for (int l = 0; l < k - 1; l++) {
					int rem = t % 10;
					t = rem * mult + t / 10;
					if (t > j && t <= B && t >= A) {
						Set<Integer> set = map.get(j);
						if (set == null) {
							set = new HashSet<Integer>(6);
						}
						set.add(t);
						map.put(j, set);
					}
				}
			}
			for (Entry<Integer, Set<Integer>> entry : map.entrySet()) {
				res += entry.getValue().size();
			}
			bw.write("Case #" + (i + 1) + ": " + res + "\n");
		}
		bw.close();
	}
}
