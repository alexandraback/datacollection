package gcj2012.round1C;

import java.io.BufferedReader;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * 2012 Code Jam Round 1C
 * 
 * @author kawabon
 * 
 */
public class C {
	public static void main(String[] args) throws Exception {
		C main = args.length > 0 ? new C(args[0]) : new C(C.class.getSimpleName() + ".in");
		main.solve();
	}

	private final BufferedReader in;

	public C(String input) throws Exception {
		in = new BufferedReader(new FileReader(this.getClass().getResource(input).getFile()));
	}

	private void solve() throws Exception {
		int T = getInt();
		for (int c = 1; c <= T; c++) {
			double[] n = getDbls();
			double ans = solveOne(n[0], n[1]);
			System.out.println("Case #" + c + ": " + String.format("%.0f", ans));
		}
	}

	class FLine {
		double count;
		double type;

		FLine(double count, double type) {
			this.count = count;
			this.type = type;
		}

		@Override
		public String toString() {
			return "{count:" + count + ",type:" + type + "}";
		}
	}

	private double solveOne(double N, double M) throws Exception {
		double[] a = getDbls();// {num type}{1..}
		double[] b = getDbls();// {num type}{1..}

		double maxComp = 0;

		// greedy based on boxLine
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				double comp = getComp(i, j, getLine(N, a), getLine(M, b), true);
				if (comp > maxComp) {
					maxComp = comp;
				}
			}
		}
		if (N == 3) {
			for (int j = 0; j < M; j++) {
				List<FLine> nonMid = getLine(N, a);
				nonMid.remove(1);
				double comp = getComp(0, j, nonMid, getLine(M, b), true);
				if (comp > maxComp) {
					maxComp = comp;
				}
			}
		}

		// greedy based on boxLine
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				double comp = getComp(i, j, getLine(N, a), getLine(M, b), false);
				if (comp > maxComp) {
					maxComp = comp;
				}
			}
		}
		if (N == 3) {
			for (int j = 0; j < M; j++) {
				List<FLine> nonMid = getLine(N, a);
				nonMid.remove(1);
				double comp = getComp(0, j, nonMid, getLine(M, b), false);
				if (comp > maxComp) {
					maxComp = comp;
				}
			}
		}

		return maxComp;
	}

	List<FLine> getLine(double M, double[] b) {
		List<FLine> fline = new ArrayList<FLine>();
		for (int i = 0; i < M; i++) {
			fline.add(new FLine(b[i * 2], b[i * 2 + 1]));
		}
		return fline;
	}

	private double getComp(int base, int j, List<FLine> boxLine, List<FLine> toyLine, boolean nongreed) {
		double count = boxLine.get(base).count;
		int offset = j;
		double comp = 0;

		while (base < boxLine.size() && offset < toyLine.size()) {
			boolean typeFound = false;
			for (int tgt = offset; tgt < toyLine.size(); tgt++) {
				if (toyLine.get(tgt).type == boxLine.get(base).type) {
					offset = tgt;
					typeFound = true;
					break;
				}
			}

			if (typeFound) {
				// System.out.println("" + comp + " >> " + base + ":" + boxLine.get(base) + ", " + offset + ":"
				// + toyLine.get(offset));
				if (count == toyLine.get(offset).count) {
					comp += count;
					base++;
					if (base < boxLine.size()) {
						count = boxLine.get(base).count;
					}
					offset++;
				} else if (count > toyLine.get(offset).count) {
					comp += toyLine.get(offset).count;
					count -= toyLine.get(offset).count;
					offset++;
					if (nongreed) {
						base++;
						if (base < boxLine.size()) {
							count = boxLine.get(base).count;
						}
					}
				} else if (count < toyLine.get(offset).count) {
					comp += count;
					base++;
					if (base < boxLine.size()) {
						count = boxLine.get(base).count;
					}
				}
				// System.out.println("" + comp + " << ");
			} else {
				base++;
				if (base < boxLine.size()) {
					count = boxLine.get(base).count;
				}
			}
		}
		// System.out.println(">>>>>>>>>>>>>" + comp + " << ");

		return comp;
	}

	/*
	 * File processing
	 */
	private int getInt() throws Exception {
		return Integer.valueOf(in.readLine()).intValue();
	}

	private double[] getDbls() throws Exception {
		List<Double> ints = getDoubles();
		double[] i = new double[ints.size()];
		for (int j = 0; j < ints.size(); j++) {
			i[j] = ints.get(j);
		}
		return i;
	}

	private List<Double> getDoubles() throws Exception {
		List<Double> list = new ArrayList<Double>();
		for (String s : getStrs()) {
			list.add(Double.valueOf(s));
		}
		return list;
	}

	private List<String> getStrs() throws Exception {
		return Arrays.asList(in.readLine().split(" "));
	}

}
