import java.io.File;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Iterator;
import java.util.Scanner;
import java.util.TreeSet;

public class DeceitfulWar {

	/**
	 * @param args
	 */
	public static void main(String[] args) throws Exception {
		Scanner scan = new Scanner(new File("war.in"));
		PrintWriter out = new PrintWriter(new FileWriter("war.out"));
		int tests = scan.nextInt();
		for (int main = 1; main <= tests; main++) {

			TreeSet<Double> wnaomi = new TreeSet<Double>();
			TreeSet<Double> dnaomi = new TreeSet<Double>();
			TreeSet<Double> wken = new TreeSet<Double>();
			TreeSet<Double> dken = new TreeSet<Double>();

			int n = scan.nextInt();
			Double db = null;
			for (int i = 0; i < n; i++) {
				db = scan.nextDouble();
				wnaomi.add(db);
				dnaomi.add(db);
			}
			for (int i = 0; i < n; i++) {
				db = scan.nextDouble();
				wken.add(db);
				dken.add(db);
			}
			//System.out.println(wnaomi);
			//System.out.println(wken);
			int w = war(wnaomi, wken);
			int d = deceitfulWar(dnaomi, dken);
			
			System.out.println("Case #" + main + ": " + d + " " + w);
			out.println("Case #" + main + ": " + d + " " + w);
		}

		out.close();
	}

	private static int war(TreeSet<Double> naomi, TreeSet<Double> ken) {
		Iterator<Double> nit = naomi.iterator();
		int score = 0;
		Double n = null;
		while (nit.hasNext()) {
			n = nit.next();
			// System.out.print("n: "+n);
			try {
				// System.out.println(" ken - k: "+ken.ceiling(n));
				ken.remove(ken.ceiling(n));
			} catch (NullPointerException nie) {
				// System.out.println(" naomi - k: "+ken.first());
				ken.pollFirst();
				score++;
			}
			nit.remove();
		}
		return score;
	}

	private static int deceitfulWar(TreeSet<Double> naomi, TreeSet<Double> ken) {
		while (naomi.size() > 0 && !didWin(naomi, ken)) {
			naomi.pollFirst();
			ken.pollLast();
		}
		return naomi.size();
	}
	
	private static boolean didWin(TreeSet<Double> naomi, TreeSet<Double> ken) {
		Double[] naomiarr = naomi.toArray(new Double[naomi.size()]);
		Double[] kenarr = ken.toArray(new Double[ken.size()]);
		boolean didWin = true;
		for(int i = 0; i < naomi.size(); i++)
			if(naomiarr[i] < kenarr[i]) {
				didWin = false;
				break;
			}
		return didWin;
	}

}
