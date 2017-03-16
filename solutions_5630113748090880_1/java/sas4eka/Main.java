import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.StringTokenizer;

public class Main {
	static BufferedReader reader;
	static PrintWriter writer;
	static String name = "B-large";
	static String fin = name + ".in";
	static String fout = name + ".out";

	public static void main(String[] args) throws NumberFormatException, IOException {
		reader = new BufferedReader(new InputStreamReader(new FileInputStream(fin)));
		writer = new PrintWriter(fout);
		banana();
		reader.close();
		writer.close();
	}

	static void banana() throws NumberFormatException, IOException {
		int n = Integer.parseInt(reader.readLine());
		for (int i = 0; i < n; i++) {
			writer.print("Case #" + (i + 1) + ": ");
			solve();
		}
	}

	static void solve() throws IOException {
		int n = Integer.parseInt(reader.readLine());
		ArrayList<Row> a = new ArrayList<>();
		for (int i = 0; i < 2 * n - 1; i++) {
			String s = reader.readLine();
			StringTokenizer st = new StringTokenizer(s);
			Row r = new Row(n);
			int k = 0;
			while (st.hasMoreTokens()) {
				r.m[k++] = Integer.parseInt(st.nextToken());
			}
			a.add(r);
		}
		Collections.sort(a, new Cmp1());
		int[][] mas = new int[n][n];
		int[] x = new int[n];
		int[] y = new int[n];

		if (a.get(0).m[0] == a.get(1).m[0]) {
			Row r1 = a.get(0);
			Row r2 = a.get(1);
			a.remove(r1);
			a.remove(r2);
			for (int i = 0; i < n; i++) {
				mas[0][i] = r1.m[i];
				mas[i][0] = r2.m[i];
				x[0] = 1;
				y[0] = 1;
			}
		} else {
			Collections.sort(a, new Cmp2());
			Row r1 = a.get(0);
			Row r2 = a.get(1);
			a.remove(r1);
			a.remove(r2);
			for (int i = 0; i < n; i++) {
				mas[n - 1][i] = r1.m[i];
				mas[i][n - 1] = r2.m[i];
				x[n - 1] = 1;
				y[n - 1] = 1;
			}
		}

		while (true) {
			boolean bFound = false;
			Row mb = null;
			int mbx = -1;
			int mby = -1;
			for (Row r : a) {
				int xp = -1;
				int yp = -1;
				for (int i = 0; i < n; i++) {
					if (x[i] == 0) {
						boolean bFail = false;
						for (int j = 0; j < n; j++) {
							if (mas[i][j] != 0) {
								if (r.m[j] != mas[i][j]) {
									bFail = true;
									break;
								}
							}
						}
						if (!bFail) {
							xp = i;
							break;
						}
					}
				}
				for (int j = 0; j < n; j++) {
					if (y[j] == 0) {
						boolean bFail = false;
						for (int i = 0; i < n; i++) {
							if (mas[i][j] != 0) {
								if (r.m[i] != mas[i][j]) {
									bFail = true;
									break;
								}
							}
						}
						if (!bFail) {
							yp = j;
							break;
						}
					}
				}
				if (xp == -1) {
					if (yp == -1) {
						System.out.println("OMG!");
						for (int i = 0; i < n; i++) {
							for (int j = 0; j < n; j++) {
								System.out.print(mas[i][j] + " ");
							}
							System.out.println();
						}
						writer.println("skip");
						return;
					} else {
						// apply yp
						for (int i = 0; i < n; i++) {
							mas[i][yp] = r.m[i];
						}
						y[yp] = 1;
						a.remove(r);
						bFound = true;
						break;
					}
				} else {
					if (yp == -1) {
						// apply xp
						for (int j = 0; j < n; j++) {
							mas[xp][j] = r.m[j];
						}
						x[xp] = 1;
						a.remove(r);
						bFound = true;
						break;
					} else {
						// everything fits, okaay
						mb = r;
						mbx = xp;
						mby = yp;
					}
				}
			}
			if (!bFound) {
				if (mb == null) {
					break;
				} else {
					// apply xp
					if (Math.random() < 0.5) {
						int xp = mbx;
						Row r = mb;
						for (int j = 0; j < n; j++) {
							mas[xp][j] = r.m[j];
						}
						x[xp] = 1;
						a.remove(r);
					} else {
						int yp = mby;
						Row r = mb;
						for (int j = 0; j < n; j++) {
							mas[j][yp] = r.m[j];
						}
						y[yp] = 1;
						a.remove(r);
					}
				}
			}
		}

		if (a.size() > 0) {
			System.out.println("We have some!");
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					System.out.print(mas[i][j] + " ");
				}
				System.out.println();
			}
			return;
		}

		for (int i = 0; i < n; i++) {
			if (x[i] == 0) {
				for (int j = 0; j < n; j++) {
					if (j > 0) {
						writer.print(" ");
					}
					writer.print(mas[i][j]);
				}
			}
			if (y[i] == 0) {
				for (int j = 0; j < n; j++) {
					if (j > 0) {
						writer.print(" ");
					}
					writer.print(mas[j][i]);
				}
			}
		}
		writer.println();
	}
}

class Cmp1 implements Comparator<Row> {
	@Override
	public int compare(Row o1, Row o2) {
		for (int i = 0; i < o1.m.length; i++) {
			int x = o1.m[i];
			int ox = o2.m[i];
			if (x != ox) {
				return Integer.compare(x, ox);
			}
		}
		return 0;
	}
}

class Cmp2 implements Comparator<Row> {
	@Override
	public int compare(Row o1, Row o2) {
		for (int i = o1.m.length - 1; i >= 0; i--) {
			int x = o1.m[i];
			int ox = o2.m[i];
			if (x != ox) {
				return Integer.compare(ox, x);
			}
		}
		return 0;
	}
}

class Row {
	int[] m;

	public Row(int n) {
		m = new int[n];
	}

	// @Override
	// public int compareTo(Row o) {
	// for (int i = 0; i < m.length; i++) {
	// int x = m[i];
	// int ox = o.m[i];
	// if (x != ox) {
	// return Integer.compare(x, ox);
	// }
	// }
	// return 0;
	// }
}