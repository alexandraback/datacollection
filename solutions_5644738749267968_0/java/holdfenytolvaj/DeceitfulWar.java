package gcjpractice.qualification2014;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintWriter;
import java.math.BigDecimal;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class DeceitfulWar {
	private static final BigDecimal EPSILON = new BigDecimal("0.0001");

	public static void main(String[] args) {
		String base = "/home/radicsge/gcj2014/qualification/";
		String input = base + "d1.in";
		String output = base + "d1.out";

		try {
			Scanner sc = new Scanner(new FileReader(input));
			PrintWriter pw = new PrintWriter(output);

			int n = sc.nextInt();
			sc.nextLine();
			for (int i = 0; i < n; i++) {
				System.out.print("Case #" + (i + 1) + ": ");
				pw.print("Case #" + (i + 1) + ": ");

				int numberOfWeights = sc.nextInt();
				sc.nextLine();

				List<BigDecimal> naomiList = getList(sc, numberOfWeights);
				List<BigDecimal> kenList = getList(sc, numberOfWeights);

				String solution = solve(naomiList, kenList);
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

	private static String solve(List<BigDecimal> naomiList, List<BigDecimal> kenList) {
		Collections.sort(naomiList);
		Collections.sort(kenList);
		System.out.println(Arrays.deepToString(naomiList.toArray()));
		System.out.println(Arrays.deepToString(kenList.toArray()));

		int warResult = getScoreOfWar(new ArrayList<>(naomiList), new ArrayList<>(kenList));
		int deceitfulWar = getScoreOfDeceitfulWar(new ArrayList<>(naomiList), new ArrayList<>(kenList));

		return "" + deceitfulWar + " " + warResult;
	}

	private static int getScoreOfWar(List<BigDecimal> naomiList, List<BigDecimal> kenList) {
		int score = 0;
		for (int i = 0; i < naomiList.size(); i++) {
			score += getAnswer(naomiList.get(i), kenList);
		}
		return score;
	}

	private static int getAnswer(BigDecimal naomiSay, List<BigDecimal> kenList) {
		for (int i = 0; i < kenList.size(); i++) {
			if (kenList.get(i).compareTo(naomiSay) > 0) {
				kenList.remove(i);
				return 0;
			}
		}
		kenList.remove(0);
		return 1;
	}

	private static int getScoreOfDeceitfulWar(ArrayList<BigDecimal> naomiList, ArrayList<BigDecimal> kenList) {
		int score = 0;
		for (int i = 0; i < naomiList.size(); i++) {
			if (naomiList.get(i).compareTo(kenList.get(0)) > 0) {
				score += getAnswer(kenList.get(kenList.size() - 1).add(EPSILON), kenList);
			} else if (naomiList.get(i).compareTo(kenList.get(kenList.size() - 1)) < 0) {
				score += getAnswer(kenList.get(kenList.size() - 1).subtract(EPSILON), kenList);
			} else {
				score += naomiList.size() - i;
				break;
			}
		}
		return score;

	}

	private static List<BigDecimal> getList(Scanner sc, int numberOfWeights) {
		List<BigDecimal> l = new ArrayList<>(numberOfWeights);
		for (int i = 0; i < numberOfWeights; i++) {
			l.add(sc.nextBigDecimal());
		}
		sc.nextLine();
		return l;
	}
}
