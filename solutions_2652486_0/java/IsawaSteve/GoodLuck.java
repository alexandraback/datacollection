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
				ArrayList<Integer> products = new ArrayList<Integer>();
				for (int j = 0; j < k;j++) {
					products.add(Integer.parseInt(rows[j]));
				}
				String guesses = makeGuesses(n, m, products);
				System.out.println(guesses);
			}
		}
	}

	private static String makeGuesses(int n, int m, ArrayList<Integer> products) {
		ArrayList<String> potentials = new ArrayList<String>();
		String checkOn;
		for (int i = 0; i < products.size();i++) {
			checkOn = decompose(products.get(i), m);
			if (n == checkOn.length()) {
				return checkOn;
			}
			potentials.add(checkOn);
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
			if (n > checkOn.length()) {
				best = checkOn;
			}
		}
		for (int i = best.length(); i < n; i++) {
			best += "2";
		}
		return best;
	}

	private static String decompose(Integer integer, int m) {
		if (integer < 2) 
		return "";
		for (int i = m; i > 2; i--) {
			if (0 == integer % i) {
				return i+""+decompose(integer/i, m);
			}
		}
		return "2";
	}
	
}
