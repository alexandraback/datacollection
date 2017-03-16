import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

/**
 * For Google Code Jam Qualification Round.
 * @author Jay
 *
 */
public class MineSweeper {


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
			String line = sc.nextLine();
			String[] values = line.split(" ");
			String r = values[0];
			String c = values[1];
			String m = values[2];
			
			String choice = placeMines(Integer.parseInt(r), Integer.parseInt(c), Integer.parseInt(m));

			
			System.out.print("Case #"+pos+":\n"+choice);
		}
	}

	private static String placeMines(int r, int c, int m) {
		//special cases first
		if (0 == m) {
			return noMines(r,c);
		}
		if (m == (r*c)-1) {
			return allMines(r, c);
		}
		if (1 == r || 1 == c) {
			return oneLineMines(r,c,m);
		}
		int unmined = (r*c) - m;
		if (2 == unmined || 3 == unmined || 5 == unmined ||  7 == unmined || (1 == (unmined % 2) && (2== r || 2 == c))) {
			return "Impossible\n";
		}
		if (1 == (unmined % 2) && unmined < 2 * c) {
			return generateSpecialMap(r, c, m);
		}
		if (unmined < 2 *c) {
			return generateTwoRowMineMap(r, c, m);
		}
		return generateMineMap(r, c, m);
	}

	private static String generateTwoRowMineMap(int r, int c, int m) {
		String ret = "c";
		final int unmined = r*c - m;
		String add = ".";
		int i = 0;
		boolean once = true;
		boolean doubler = true;
		for (int row = 0; row < r; row++) {
			for (int col = 0; col < c; col++) {
				if (2 == (unmined - i) && col == c - 1) {
					ret += "*";
					continue;
				}
				if (!once) {
					ret += add;
				}
				once = false;
				i += 2;
				if (unmined == i) {
					add = "*";
				}
			}
			if (doubler) {
				ret += "\n"+ret.replaceAll("c", ".");
				row++;
				doubler = false;
			}
			ret+="\n";
		}
		return ret;
	}

	private static String generateSpecialMap(int r, int c, int m) {
		String ret = "c";
		final int unmined = r*c - m - 3;
		String add = ".";
		int i = 0;
		boolean once = true;
		boolean doubler = true;
		for (int row = 0; row < r; row++) {
			for (int col = 0; col < c; col++) {
				if (col < 3 && 2 == row) {
					ret += ".";
				} else if (!once) {
					ret += add;
				}
				once = false;
				i += 2;
				if (unmined == i) {
					add = "*";
				}
			}
			if (doubler) {
				ret += "\n"+ret.replaceAll("c", ".");
				row++;
				doubler = false;
			}
			ret+="\n";
		}
		return ret;
	}

	private static String generateMineMap(int r, int c, int m) {
		String ret = "c";
		final int unmined = r*c - m;
		String add = ".";
		int i = 0;
		boolean once = true;
		for (int row = 0; row < r; row++) {
			for (int col = 0; col < c; col++) {
				if (2 == (unmined - i) && col == c - 1) {
					if (1 == row) {
						ret = ret.replaceAll(".\n", "*\n");
						i--;
					}
					ret += "*";
					continue;
				}
				if (!once) {
					ret += add;
				}
				once = false;
				i++;
				if (unmined == i) {
					add = "*";
				}
			}
			ret+="\n";
		}
		return ret;
	}

	private static String oneLineMines(int r, int c, int m) {
		String ret = "c";
		final int unmined = r*c - m;
		String add = ".";
		int i = 0;
		boolean once = true;
		for (int row = 0; row < r; row++) {
			for (int col = 0; col < c; col++) {
				if (!once) {
					ret += add;
				}
				once = false;
				i++;
				if (unmined == i) {
					add = "*";
				}
			}
			ret+="\n";
		}
		return ret;
	}

	private static String allMines(int r, int c) {
		return allOne(r, c, "*");
	}

	private static String noMines(int r, int c) {
		return allOne(r, c, ".");
	}
	private static String allOne(int r, int c, String add) {
		String ret = "c";
		boolean once = true;
		for (int row = 0; row < r; row++) {
			for (int col = 0; col < c; col++) {
				if (!once) {
					ret += add;
				}
				once = false;
			}
			ret+="\n";
		}
		return ret;
	}

	
}
