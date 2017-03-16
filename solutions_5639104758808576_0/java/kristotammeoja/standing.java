import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class standing {

	public static void main(String[] args) throws Exception {
		BufferedReader in = new BufferedReader(new FileReader("A-small-attempt0.in"));
		PrintWriter out = new PrintWriter(new FileWriter("out.txt"));

		int N = Integer.parseInt(in.readLine());
		for (int i = 1; i <= N; ++i) {
			String line = in.readLine();
			StringTokenizer st = new StringTokenizer(line);

			int S_max = Integer.parseInt(st.nextToken());
			String data = st.nextToken();

			int result = findNumFriends(data);
			out.println("Case #" + i + ": " + result);
		}
		
		out.close();
		in.close();
	}

	private static int findNumFriends(String data) {
		int friends_needed = 0;
		int already_standing = 0;
		for (int level = 0; level < data.length(); level++) {
			int num_on_level = Integer.parseInt("" + data.charAt(level));
			if (num_on_level > 0) {
				if (already_standing < level) {
					int need_more = level - already_standing;
					friends_needed += need_more;
					already_standing = level;
				}
				// after those guys stand up
				already_standing += num_on_level;
			}
		}
		return friends_needed;
	}

}
