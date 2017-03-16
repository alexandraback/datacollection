import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.HashMap;
import java.util.Map;

public class EqualSums {

	/**
	 * @param args
	 * @throws IOException
	 * @throws NumberFormatException
	 */
	public static void main(String[] args) throws NumberFormatException,
			IOException {
		new EqualSums().solve();
	}

	private void solve() throws NumberFormatException, IOException {
		BufferedReader reader = new BufferedReader(new FileReader("C-small-attempt0.in"));
		int T = Integer.parseInt(reader.readLine());
		for (int i = 0; i < T; i++) {
			String[] split = reader.readLine().split("\\s+");
			int N = Integer.parseInt(split[0]);
			int s[] = new int[N];
			for (int j = 1; j < N + 1; j++) {
				s[j - 1] = Integer.parseInt(split[j]);
			}
			Map<Integer, Integer> sums = new HashMap<Integer, Integer>();
			boolean exist = false;
			System.out.printf("Case #%d:", i + 1);
			for (int j = 1; j < 1 << 20; j++) {
				int csum = 0;
				for (int k = 0; k < 20; k++) {
					if ((j & (1 << k)) != 0) {
						csum += s[k];
					}
				}

				if (sums.containsKey(csum)) {
					exist = true;
					System.out.println();
					StringBuilder sb = new StringBuilder();
					for (int k = 0; k < 20; k++) {
						if ((j & (1 << k)) != 0) {
							sb.append(String.format("%d%s", s[k], " "));
						}
					}
					sb.deleteCharAt(sb.length() - 1);
					System.out.println(sb.toString());
					int set = sums.get(csum);
					sb.setLength(0);
					for (int k = 0; k < 20; k++) {
						if ((set & (1 << k)) != 0) {
							sb.append(String.format("%d%s", s[k], " "));
						}
					}
					sb.deleteCharAt(sb.length() - 1);
					System.out.println(sb.toString());
					break;
				} else {
					sums.put(csum, j);
				}
			}
			if (!exist) {
				System.out.println("Impossible");
			}
		}
	}

}
