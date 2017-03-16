import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.io.StreamTokenizer;
import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;
import java.util.List;

public class War {

	public static void main(String[] args) throws Exception {
		War object = new War();
		object.work();
	}

	private void work() throws Exception {
		StreamTokenizer st = new StreamTokenizer(new BufferedReader(
				new FileReader(this.getClass().getSimpleName() + ".in")));
		PrintWriter pw = new PrintWriter(new FileWriter(this.getClass()
				.getSimpleName() + ".out"));

		st.nextToken();
		int tcases = (int) st.nval;

		for (int tc = 1; tc <= tcases; tc++) {
			st.nextToken();
			int n = (int) st.nval;

			List<Double> naomi = new ArrayList<>();

			for (int i = 0; i < n; i++) {
				st.nextToken();
				naomi.add(st.nval);
			}

			List<Double> ken = new ArrayList<>();

			for (int i = 0; i < n; i++) {
				st.nextToken();
				ken.add(st.nval);
			}

			pw.write("Case #" + tc + ": " + solveNew(naomi, ken) + " "
					+ solveOld(naomi, ken) + "\r\n");
		}

		pw.close();
	}

	private int solveOld(List<Double> naomi1, List<Double> ken1) {

		List<Double> naomi = new ArrayList<>();
		for (double n : naomi1)
			naomi.add(n);

		Collections.sort(naomi);
		Collections.reverse(naomi);

		List<Double> ken = new LinkedList<>();
		for (double k : ken1)
			ken.add(k);

		Collections.sort(ken);

		int count = 0;
		int start = ken.size() - 1;

		for (int i = 0; i < naomi.size(); i++) {
			boolean foundBetter = false;

			for (int j = start; j >= 0; j--) {
				if (ken.get(j) > naomi.get(i)
						&& ((j == 0) || (ken.get(j - 1) < naomi.get(i)))) {
					// found one
					foundBetter = true;

					ken.remove(j);
					start = Math.min(j, ken.size() - 1);

					break;
				}
			}

			if (!foundBetter) {
				ken.remove(0);
				start = Math.min(start, ken.size() - 1);

				count++;
			}

		}

		return count;
	}

	private int solveNew(List<Double> naomi1, List<Double> ken1) {

		List<Double> naomi = new ArrayList<>();
		for (double n : naomi1)
			naomi.add(n);

		Collections.sort(naomi);

		List<Double> ken = new LinkedList<>();
		for (double k : ken1)
			ken.add(k);

		Collections.sort(ken);

		int count = 0;

		while (!naomi.isEmpty()) {

			if (naomi.get(0) > ken.get(0)) {
				// we take this point
				count++;

				naomi.remove(0);
				ken.remove(0);

				continue;
			} else {
				naomi.remove(0);
				ken.remove(ken.size() - 1);
			}
		}

		return count;
	}

}
