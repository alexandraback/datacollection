import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashSet;

public class Diamond {

	private static BufferedReader bufferedReader = new BufferedReader(
			new InputStreamReader(System.in));

	public static void main(String[] args) throws IOException {
		String line = bufferedReader.readLine();
		int cases = Integer.parseInt(line);

		for (int i = 1; i <= cases; i++) {
			line = bufferedReader.readLine();

			int classes = Integer.parseInt(line);
			ArrayList<ArrayList<Integer>> neighbourList = new ArrayList<ArrayList<Integer>>();

			for (int j = 0; j < classes; j++) {
				neighbourList.add(new ArrayList<Integer>());
				line = bufferedReader.readLine();
				String[] split = line.split(" ");
				int neighbours = Integer.parseInt(split[0]);
				// System.err.println("Node " + j + " has " + neighbours
				// + " neighbours");
				for (int k = 0; k < neighbours; k++) {
					neighbourList.get(j)
							.add(Integer.parseInt(split[k + 1]) - 1);
				}
			}

			boolean diamond = solve(neighbourList, classes);

			if (diamond) {
				System.out.println("Case #" + i + ": Yes");
			} else {
				System.out.println("Case #" + i + ": No");
			}
		}
	}

	private static boolean solve(ArrayList<ArrayList<Integer>> neighbourList,
			int classes) {
		for (int i = 0; i < classes; i++) {
			ArrayList<ArrayList<Integer>> allPaths = getAllPaths(
					new ArrayList<ArrayList<Integer>>(),
					new ArrayList<Integer>(), i, neighbourList);

			// System.err.println("Found " + allPaths.size()
			// + " paths with start on node " + i);
			HashSet<Integer> uniqueNodesOnPath = new HashSet<Integer>();

			for (ArrayList<Integer> path : allPaths) {
				/*
				 * System.err.println("Printing path from node " + i); for
				 * (Integer integer : path) { System.err.print(integer +
				 * " -> "); } System.err.println();
				 */
				int node = path.get(path.size() - 1); // Last node
				if (uniqueNodesOnPath.contains(node) && node != i) {
					// System.err.println("Node: " + node
					// + " already found, returning true");
					return true;
				} else {
					uniqueNodesOnPath.add(node);
				}
			}
		}
		return false;
	}

	private static ArrayList<ArrayList<Integer>> getAllPaths(
			ArrayList<ArrayList<Integer>> answer, ArrayList<Integer> arrayList,
			int start, ArrayList<ArrayList<Integer>> neighbourList) {
		arrayList.add(start);
		answer.add((ArrayList<Integer>) arrayList.clone());

		/*
		 * System.err.println(arrayList.size() + " is depth, current node: " +
		 * start);
		 */
		for (int i = 0; i < neighbourList.get(start).size(); i++) {
			getAllPaths(answer, arrayList, neighbourList.get(start).get(i),
					neighbourList);
		}
		return answer;
	}

}
