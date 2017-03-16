import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

public class Inheritence {

	static String ans = "No";
	static int x[];

	public static void main(String[] args) throws Exception {
		String sb = null;
int tt;
		BufferedReader is = new BufferedReader(new FileReader(new File(
				"D:\\A-large (1).in")));
		BufferedWriter os = new BufferedWriter(new FileWriter("D:\\out.txt"));
		os.flush();
		int T = Integer.parseInt(is.readLine());

		for (int i = 0; i < T; i++) {
			sb = is.readLine();

			int N = Integer.parseInt(sb);

			HashMap<Integer, TreeNode> map = new HashMap<Integer, TreeNode>();

			for (int j = 0; j < N; j++) {
				map.put(j + 1, new TreeNode(j + 1));
			}

			for (int j = 0; j < N; j++) {
				sb = is.readLine();
				String num[] = sb.split(" ");

				int M = Integer.parseInt(num[0]);

				for (int k = 1; k <= M; k++) {
					int t = Integer.parseInt(num[k]);
					TreeNode tree = map.get(t);
					tree.node.add(map.get(j + 1));
				}

			}

			// state
			// 0 not reached
			// 1 processing
			// 2 processed
			ans = "No";
			int[] xx = new int[N];
			for (int j = 0; j < N; j++) {
				xx[j] = 0;
			}

			for (int j = 0; j < N; j++) {
				ans = "No";
				x = new int[N];
				for (int k = 0; k < N; k++) {
					x[k] = 0;
				}
				process(map.get(j + 1));
				if (ans.equals("Yes")) {
					break;
				}
			}

			os.write("Case #" + (i + 1) + ": " + ans);
			os.write("\n");
			os.flush();
		}

	}

	public static void process(TreeNode root) {

		if (ans.equals("Yes"))
			return;

		if (root.node.size() == 0) {
			x[root.value - 1] = 2;
			return;
		}

		x[root.value - 1] = 1;
		for (TreeNode t : root.node) {
			if (x[t.value - 1] > 0) {
				ans = "Yes";
				return;
			}
			process(t);
		}

		x[root.value - 1] = 2;

	}
}

class TreeNode {
	public int value;
	public List<TreeNode> node = new ArrayList<TreeNode>();

	TreeNode(int x) {
		value = x;
	}
}