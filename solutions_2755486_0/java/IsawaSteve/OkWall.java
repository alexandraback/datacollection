import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;


/**
 * for the great Wall challenge.
 * Google code jam 2013 round 1c.
 * @author Jay
 *
 */
public class OkWall {
	public class Tribe {
		double d;
		double n;
		double w;
		double e;
		double s;
		double delta_d;
		double delta_p;
		double delta_s;
		Tribe(double ind, double inn, double inw, double ine, double ins,double indd,double indp,double inds) {
			d = ind;
			n=inn;
			w=inw;
			e=ine;
			s=ins;
			delta_d=indd;
			delta_p = indp;
			delta_s = inds;
		}
		public boolean willAttack(long day) {
			return n > 0 && day >= d;
		}
		
		public HashMap<Double, Double> attack() {
			HashMap<Double, Double> ret = new HashMap<Double, Double>();
			for (double i = w; i <= e; i += .5) {
				ret.put(i, s);
			}
			cleanUp();//System.out.println(ret);
			return ret;
		}
		public void cleanUp() {
			d += delta_d;
			n--;
			s += delta_s;
			w += delta_p;
			e += delta_p;
		}
	}
	
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
			String size = sc.nextLine();
			String[] sizeArr = size.split(" ");
			double tribes = Double.parseDouble(sizeArr[0]);
			OkWall temp = new OkWall();
			int unblocked = 0;
			ArrayList<Tribe> allTribes = new ArrayList<Tribe>();
			for (int t=0;t<tribes;t++) {
				String tribeLine = sc.nextLine();
				String[] tribeArr = tribeLine.split(" ");
				double ind = Double.parseDouble(tribeArr[0]);
				double inn = Double.parseDouble(tribeArr[1]);
				double inw = Double.parseDouble(tribeArr[2]);
				double ine = Double.parseDouble(tribeArr[3]);
				double ins = Double.parseDouble(tribeArr[4]);
				double indd = Double.parseDouble(tribeArr[5]);
				double indp = Double.parseDouble(tribeArr[6]);
				double inds = Double.parseDouble(tribeArr[7]);
				
				allTribes.add(temp.new Tribe(ind, inn, inw, ine, ins,indd,indp,inds));
			}
			
			unblocked = processAttacks(allTribes);
			theWall = new HashMap<Double, Double>();
			System.out.println("Case #"+pos+": "+unblocked);
		}
	}
	
	private static int processAttacks(ArrayList<Tribe> allTribes) {
		int day = 0;
		int hits = 0;
		while (!allTribes.isEmpty()) {//System.out.println("DAY "+day);
			ArrayList<Tribe> doneTribes = new ArrayList<Tribe>();
			ArrayList<HashMap<Double, Double>> dailyAttacks = new ArrayList<HashMap<Double, Double>>();
			for (Tribe t: allTribes) {
				if (t.willAttack(day)) {
					HashMap<Double, Double> attack = t.attack();
					dailyAttacks.add(attack);//System.out.println(theWall);
					if (!handleAttack(attack)) {//System.out.println("Battleship");
						hits++;
					}
				}
				if (t.n <= 0) {
					doneTribes.add(t);
				}
			}
			rebuild(dailyAttacks);
			for (Tribe t: doneTribes) {
				allTribes.remove(t);
			}
			
			day++;
		}
		return hits;
	}
	static HashMap<Double, Double> theWall = new HashMap<Double, Double>();
	private static void rebuild(ArrayList<HashMap<Double, Double>> dailyAttacks) {
		for (HashMap<Double, Double> attack: dailyAttacks) {
			for (Double pos: attack.keySet()) {
				if (vulnerable(pos, attack.get(pos))) {
					theWall.put(pos, attack.get(pos));
				}
			}
		}
	}
	private static boolean vulnerable(Double pos, Double strength) {
		return null == theWall.get(pos) || theWall.get(pos) < strength;
	}

	private static boolean handleAttack(HashMap<Double, Double> attack) {
		for (Double pos: attack.keySet()) {
			if (vulnerable(pos,attack.get(pos))) {
				return false;
			}
		}
		return true;
	}
}
