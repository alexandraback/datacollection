import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintStream;
import java.util.Set;
import java.util.TreeSet;

public class RecycledNumbers {

	public static void main(String[] args) throws IOException {
		System.setErr(new PrintStream("qualification/C-small-attempt1.out"));
		FileReader reader = new FileReader("qualification/C-small-attempt1.in");
		BufferedReader br = new BufferedReader(reader);
		int tc = Integer.parseInt(br.readLine());
		for (int t = 0; t < tc; t++) {
			String[] nums = br.readLine().split("\\s");
			String a = nums[0];
			String b = nums[1];
			int min = Integer.parseInt(a);
			int max = Integer.parseInt(b);
			int answer = 0;
			for (int i = min; i < max; i++) {
				String n = String.valueOf(i);
				Set<String> set = new TreeSet<String>();
				for (int j = 0; j < n.length(); j++) {
					set.add(n.substring(j) + n.substring(0, j));
				}
				for (String s : set) {
					if (n.compareTo(s) < 0 && b.compareTo(s) >= 0) {
						answer++;
					}
				}
			}
			System.out.printf("Case #%d: %d\n", t + 1, answer);
			System.err.printf("Case #%d: %d\n", t + 1, answer);
		}
	}

}
