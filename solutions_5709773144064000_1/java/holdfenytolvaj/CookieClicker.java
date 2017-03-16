package gcjpractice.qualification2014;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintWriter;
import java.math.BigDecimal;
import java.util.Scanner;

public class CookieClicker {

	public static void main(String[] args) {
		String base = "/home/radicsge/gcj2014/qualification/";
		String input = base + "b1.in";
		String output = base + "b1.out";

		try {
			Scanner sc = new Scanner(new FileReader(input));
			PrintWriter pw = new PrintWriter(output);

			int n = sc.nextInt();
			sc.nextLine();
			for (int i = 0; i < n; i++) {
				System.out.print("Test case " + (i + 1) + "...");
				pw.print("Case #" + (i + 1) + ": ");

				BigDecimal c = sc.nextBigDecimal();
				BigDecimal f = sc.nextBigDecimal();
				BigDecimal x = sc.nextBigDecimal();
				sc.nextLine();

				String solution = solve(c, f, x);
				System.out.println(solution);
				pw.println(solution);

			}
			pw.println();
			pw.flush();
			pw.close();
			sc.close();
		} catch (FileNotFoundException ex) {
			ex.printStackTrace();
		}
	}

	private static String solve(BigDecimal farmCost, BigDecimal farmIncome, BigDecimal target) {
		BigDecimal income = BigDecimal.valueOf(2);

		BigDecimal timeToSolveTheProblem = target.divide(income, 7, BigDecimal.ROUND_HALF_UP);
		BigDecimal timeToBuyNextFarm = farmCost.divide(income, 7, BigDecimal.ROUND_HALF_UP);
		BigDecimal timeToSolveTheProblemWithNewFarm = timeToBuyNextFarm.add(target.divide(income.add(farmIncome), 7, BigDecimal.ROUND_HALF_UP));

		BigDecimal timeSpent = BigDecimal.ZERO;
		while (timeToSolveTheProblem.compareTo(timeToSolveTheProblemWithNewFarm) > 0) {
			timeSpent = timeSpent.add(timeToBuyNextFarm);
			income = income.add(farmIncome);

			timeToSolveTheProblem = target.divide(income, 7, BigDecimal.ROUND_HALF_UP);
			timeToBuyNextFarm = farmCost.divide(income, 7, BigDecimal.ROUND_HALF_UP);
			timeToSolveTheProblemWithNewFarm = timeToBuyNextFarm.add(target.divide(income.add(farmIncome), 7, BigDecimal.ROUND_HALF_UP));
		}

		return timeSpent.add(timeToSolveTheProblem).setScale(7, BigDecimal.ROUND_HALF_UP).toPlainString();
	}
}
