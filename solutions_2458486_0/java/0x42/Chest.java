import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.StreamTokenizer;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Queue;

public class Chest {

	public static void main(String[] args) throws Exception {
		Chest object = new Chest();
		String className = object.getClass().getSimpleName();

		FileReader fileReader = new FileReader(new File(className.toLowerCase()
				+ ".in"));
		StreamTokenizer st = new StreamTokenizer(new BufferedReader(fileReader));

		FileWriter wr = new FileWriter(className.toLowerCase() + ".out");

		st.nextToken();
		int testCases = (int) st.nval;

		for (int tc = 1; tc <= testCases; tc++) {
			st.nextToken();
			int k = (int) st.nval;

			st.nextToken();
			int n = (int) st.nval;

			ArrayList<Integer> keys = new ArrayList<Integer>();
			for (int i = 0; i < k; i++) {
				st.nextToken();
				keys.add((int) st.nval);
			}

			int chestT[] = new int[n];
			int chestK[] = new int[n];
			int chestKeys[][] = new int[n][50];

			for (int i = 0; i < n; i++) {
				st.nextToken();
				chestT[i] = (int) st.nval;

				st.nextToken();
				chestK[i] = (int) st.nval;

				for (int jj = 0; jj < chestK[i]; jj++) {
					st.nextToken();
					chestKeys[i][jj] = (int) st.nval;
				}
			}

			String output = object.solve(keys, chestT, chestK, chestKeys);
			wr.write("Case #" + tc + ": " + output + "\r\n");
		}

		wr.close();
	}

	private String solve(ArrayList<Integer> keys, int[] chestT, int[] chestK,
			int[][] chestKeys) {

		Queue<Integer> q = new LinkedList<Integer>();
		HashSet<Integer> visited = new HashSet<Integer>();
		HashMap<Integer, String> path = new HashMap<Integer, String>();

		q.add(0);
		visited.add(0);
		path.put(0, "");

		int n = chestT.length;

		while (!q.isEmpty()) {
			int elem = q.poll();

			String curPath = path.get(elem);

			if (elem == ((1 << n) - 1))
				return curPath;

			ArrayList<Integer> keysWeHave = new ArrayList<Integer>();

			for (int key : keys)
				keysWeHave.add(key);

			for (int i = 0; i < n; i++)
				if (((1 << i) & elem) > 0) {
					for (int z = 0; z < chestK[i]; z++)
						keysWeHave.add(chestKeys[i][z]);
				}

			// remove what we used to open doors with
			for (int i = 0; i < n; i++)
				if (((1 << i) & elem) > 0) {
					for (int j = 0; j < keysWeHave.size(); j++)
						if (keysWeHave.get(j) == chestT[i]) {
							keysWeHave.set(j, -1);
							break;
						}
				}

			// ok, try to move from here
			for (int i = 0; i < n; i++)
				if (((1 << i) & elem) == 0) // not visited
					if (keysWeHave.contains(chestT[i])) {
						// we can go there
						int next = elem;
						next |= (1 << i);

						if (visited.contains(next))
							continue;

						q.add(next);
						visited.add(next);

						path.put(next, (curPath + " " + (i + 1)).trim());
					}
		}

		return "IMPOSSIBLE";
	}

}
