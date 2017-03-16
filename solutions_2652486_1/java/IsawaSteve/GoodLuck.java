import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;


/**
 * for the Good Luck! challenge.
 * Google code jam 2013 round 1a.
 * @author Jay
 *
 */
public class GoodLuck {


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
			int r = Integer.parseInt(sizeArr[0]);
			int n = Integer.parseInt(sizeArr[1]);
			int m = Integer.parseInt(sizeArr[2]);
			int k = Integer.parseInt(sizeArr[3]);
			System.out.println("Case #"+pos+": ");
			for (int i = 0; i < r; i++){
				String nextLine = sc.nextLine();
				String[] rows = nextLine.split(" ");
				ArrayList<Double> products = new ArrayList<Double>();
				for (int j = 0; j < k;j++) {
					products.add(Double.parseDouble(rows[j]));
				}
				String guesses = makeGuesses(n, m, products);
				System.out.println(guesses);
			}
		}
	}

	private static String makeGuesses(int n, int m, ArrayList<Double> products) {
		ArrayList<String> potentials = new ArrayList<String>();
		String checkOn;
		String checkOn2;
		String checkOn3;
		for (int i = 0; i < products.size();i++) {
			checkOn = decompose(products.get(i), m);
			checkOn2 = decompose2(products.get(i), m);
			checkOn3 = decompose3(products.get(i), m);
			if (n == checkOn.length()) {
				return checkOn;
			}
			if (n == checkOn2.length()) {
				return checkOn2;
			}
			if (n == checkOn3.length()) {
				return checkOn3;
			}
			potentials.add(checkOn);
			potentials.add(checkOn2);
			potentials.add(checkOn3);
		}
		return findPotential(potentials,n);
	}

	private static String findPotential(ArrayList<String> potentials, int n) {
		String best = "";
		for (int i = 0; i < potentials.size(); i++) {
			String checkOn = potentials.get(i);
			if (n == checkOn.length()) {
				return checkOn;
			}
//			best = composeBest(best, checkOn);
//			if (n > checkOn.length() && checkOn.length() > best.length()) {
			if ("".equals(best) || Math.random() > .5) {//going for random luck now. hasn't worked so far :(   //Magic++ XXX
				best = checkOn;
			}
		}
		for (int i = best.length(); i < n; i++) {
			best += "2";
		}
		return best;
	}

	private static String composeBest(String best, String checkOn) {
		int add7 = countDiff(7,best,checkOn);
		int add5 = countDiff(5, best, checkOn);
		int add8 = countDiff(8, best, checkOn);
		int add6 = countDiff(6, best, checkOn);
		for (int i = 0; i < add7;i++) {
			best += "7";
		}
		for (int i = 0; i < add5;i++) {
			best += "5";
		}
		for (int i = 0; i < add6;i++) {
			best += "6";
		}
		for (int i = 0; i < add8;i++) {
			best += "8";
		}
		return best;
	}

	private static int countDiff(int i, String best, String checkOn) {
		int countBest = countAppear(i, best);
		int countCheck = countAppear(i, checkOn);
		return countCheck - countBest;
	}

	private static int countAppear(int i, String checkOn) {
		if (null == checkOn) return 0;
		int ret = 0;
		for (int j = 0; j < checkOn.length();j++) {
			if (i == Integer.parseInt(checkOn.charAt(j)+"")) {
				ret++;
			}
		}
		return ret;
	}

	private static String decompose(Double integer, int m) {
		if (integer < 2) 
		return "";
		for (int i = m; i > 2; i--) {
			if (0 == integer % i) {
				return i+""+nextdecompose(integer/i, m);
			}
		}
		return "2";
	}

	private static String decompose2(Double integer, int m) {
		if (integer < 2) 
		return "";
		for (int i = 3; i < m; i++) {
			if (0 == integer % i) {
				return i+""+nextdecompose(integer/i, m);
			}
		}
		return "2";
	}

	private static String nextdecompose(double d, int m) {
		if (Math.random() > .5) {
			return decompose(d,m);
		}
		return decompose2(d,m);
	}

	private static String decompose3(Double integer, int m) {
		if (integer < 2) 
		return "";
		for (int i = m-1; i > 2; i--) {
			if (0 == integer % i) {
				return i+""+decompose3(integer/i, m);
			}
		}
		return "2";
	}
	
}
