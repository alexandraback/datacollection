import java.util.Scanner;

public class B {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int numCases = scan.nextInt();
		for (int caseNum = 1; caseNum <= numCases; caseNum++) {
			System.out.println("Case #" + caseNum + ": " + solveProblem(scan));
		}
	}

	private static double solveProblem(Scanner scan) {
		long n = scan.nextLong();
		long x = scan.nextLong();
		int y = scan.nextInt();
		long whichTri = (Math.abs(x) + Math.abs(y));
		long triCost = whichTri * (whichTri - 1) / 2;
		long numChances = n - triCost;
		if (whichTri + y + 1 <= numChances)
			return 1D;
		else if (numChances < y + 1 || x == 0) {
			return 0D;
		} else {
			double totProb = chooseO2pn(numChances, y + 1);
			double curProb = totProb;
			for (int i = y + 2; i <= numChances; i++) {
				curProb = curProb * (numChances - (i - 1)) / (double) i;
				totProb += curProb;
				if (curProb < 1E-8) {
					break;
				}
			}
			return totProb;
		}
	}

	private static double chooseO2pn(long n, int k) {
		double res = 1;
		for (int i = 0; i < k; i++) {
			res *= (n - i) / (2D * (i + 1));
		}
		for (int i = k; i < n; i++) {
			res /= 2;
		}
		return res;
	}
}
