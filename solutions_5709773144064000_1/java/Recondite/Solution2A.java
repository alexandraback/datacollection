package practice;

import genericSolver.ISolver;
import genericSolver.Reader;

import java.io.IOException;

public class Solution2A implements ISolver {

	public static void main(String[] args) {
		ISolver Solution = new Solution2A();
		Reader s;
		try {
			s = new Reader(Solution, "B-Large", "out");
			s.solveCases(false);
			s.finish();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	static int MAX = 10000;

	/**
	 * @param args
	 */
	@Override
	public String solve(Reader reader) {
		double Cost = reader.returnDouble();
		double CPS = reader.returnDouble();
		double Goal = reader.returnDouble();

		double rate = 2;
		double time = Goal / rate;

		double tTot = Cost / rate;
		rate += CPS;

		while ((Goal / rate + tTot) < time) {
			time = tTot + Goal / rate;
			tTot += Cost / rate;
			rate += CPS;
		}

		return " " + String.format("%.7f",time);
	}
}
