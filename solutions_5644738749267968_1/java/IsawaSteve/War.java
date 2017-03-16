import java.io.File;
import java.io.FileNotFoundException;
import java.util.PriorityQueue;
import java.util.Scanner;
import java.util.TreeSet;

/**
 * For Google Code Jam Qualification Round.
 * @author Jay
 *
 */
public class War {


	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Scanner sc;
		try {
			sc = new Scanner(new File(args[0]));
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
			return;
		}
		String totalProblems = sc.nextLine();
		int total = Integer.parseInt(totalProblems);
		int pos = 1;
		for (;pos <= total;pos++) {
			String weights = sc.nextLine();
			String line = sc.nextLine();
			String[] naomi = line.split(" ");
			String line2 = sc.nextLine();
			String[] ken = line2.split(" ");

			int deceitful = deceitfulWar(Integer.parseInt(weights), naomi, ken);
			int war = war(Integer.parseInt(weights), naomi, ken);

			
			System.out.println("Case #"+pos+": "+deceitful+" "+war);
		}
	}

	private static int war(int count, String[] naomi, String[] ken) {
		int wins = 0;
		TreeSet<Double> enemyWeights = processKen(ken);
		for (String nValue: naomi) {
			double value = Double.parseDouble(nValue);
			Double beater = enemyWeights.ceiling(value);
			if (null == beater) {
				wins++;
				double smallest = enemyWeights.ceiling(0.0);
				enemyWeights.remove(smallest);
			} else {
				enemyWeights.remove(beater);
			}
		}
		return wins;
	}

	private static TreeSet<Double> processKen(String[] ken) {
		TreeSet<Double> ret = new TreeSet<Double>();
		for (String value: ken) {
			ret.add(Double.parseDouble(value));
		}
		return ret;
	}

	private static int deceitfulWar(int count, String[] naomi, String[] ken) {
		int wins = 0;
		PriorityQueue<Double> enemyWeights = kenQueue(ken);
		 TreeSet<Double> weights = processKen(naomi);
		for (double k: enemyWeights) {
			Double n = weights.ceiling(k);
			if (null != n) {
				wins++;
				weights.remove(n);
			}
		}
		return wins;
	}

	private static PriorityQueue<Double> kenQueue(String[] ken) {
		PriorityQueue<Double> ret = new PriorityQueue<Double>();
		for (String value: ken) {
			ret.add(Double.parseDouble(value));
		}
		return ret;
	}

	
}
