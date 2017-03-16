
import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.InputStreamReader;
import java.text.DecimalFormat;

public class Solve2014R0C {
	private static String filePath = "C-small-attempt4.in";

	private static int T = 0;       //     1 ≤ T ≤ 230  /  1 ≤ T ≤ 140
	private static int[] Rs = null; // [T] 1 ≤ R ≤ 5    /  1 ≤ R ≤ 50
	private static int[] Cs = null; // [T] 1 ≤ C ≤ 5    /  1 ≤ C ≤ 50
	private static int[] Ms = null; // [T] 0 ≤ M < R * C

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		long startDatetime = System.currentTimeMillis();
		try {
			input();

			StringBuffer answer = new StringBuffer();
			for (int x = 0; x < T; x++) {
				answer.append("Case #" + (x+1) + ":\n");
				System.out.print("Case #" + (x+1) + ":\n");

				int R = Rs[x];
				int C = Cs[x];
				int M = Ms[x];
				char[][] board = new char[R][C];
				for (int i = 0; i < R; i++)
					for (int j = 0; j < C; j++)
						board[i][j] = '*';
				boolean impossible = false;
				int blankCnt = R * C - M;
				// R == 1 || C == 1 => OK
				// blankCnt = 2, 3, 5, 7 => ng
				if (blankCnt == 1) {
					board[0][0] = 'c';
				} else if (R == 1) {
					board[0][0] = 'c';
					for (int i = 1; i < blankCnt; i++) board[0][i] = '.';
				} else if (C == 1) {
					board[0][0] = 'c';
					for (int i = 1; i < blankCnt; i++) board[i][0] = '.';
				} else if (blankCnt == 2 || blankCnt == 3 || blankCnt == 5 || blankCnt == 7) {
					impossible = true;
				} else if (blankCnt % 2 == 0) {
					// 4, 6, 8, 10, 12, 14, ...
					int a = blankCnt / 2;
					if (a <= C) {
						for (int i = 0; i < a; i++) {
							board[0][i] = '.';
							board[1][i] = '.';
						}
					} else {
						for (int i = 0; i < C; i++) {
							board[0][i] = '.';
							board[1][i] = '.';
						}
						blankCnt -= 2 * C;
						int row = 2;
						int col = 0;
						while (blankCnt > 0) {
							blankCnt -= 2;
							if (col + 1 >= C) {
								row++;
								col = 0;
								if (C % 2 == 1 && row % 2 == 0) {
									board[row-2][C-1] = '.';
									board[row-1][C-1] = '.';
									continue;
								}
							}
							board[row][col++] = '.';
							board[row][col++] = '.';
						}
					}
					board[0][0] = 'c';
				} else {
					// 9, 11, 13, 15, ...
					if (R == 2 || C == 2) impossible = true;
					else {
						for (int i = 0; i < 3; i++)
							for (int j = 0; j < 3; j++)
								board[i][j] = '.';
						blankCnt -= 9;
						int a = blankCnt / 2;
						if (a <= C - 3) {
							for (int j = 0; j < a; j++) {
								board[0][3+j] = '.';
								board[1][3+j] = '.';
							}
						} else {
							for (int j = 3; j < C; j++) {
								board[0][j] = '.';
								board[1][j] = '.';
							}
							blankCnt -= 2 * (C-3);
							int row = 2;
							int col = 3;
							while (blankCnt > 0 && col + 1 < C) {
								board[row][col++] = '.';
								board[row][col++] = '.';
								blankCnt -= 2;
							}
							row = 3;
							col = 0;
							if (C % 2 == 1) {
								while (blankCnt > 0) {
									blankCnt -= 2;
									if (col + 1 >= C) {
										row++;
										col = 0;
										if (row % 2 == 1) {
											board[row-2][C-1] = '.';
											board[row-1][C-1] = '.';
											continue;
										}
									}
									board[row][col++] = '.';
									board[row][col++] = '.';
								}
							} else {
								while (blankCnt > 0) {
									blankCnt -= 2;
									if (col + 2 >= C) {
										board[row-1][C-1] = '.';
										board[row][col] = '.';
										row++;
										col = 0;
										continue;
									}
									board[row][col++] = '.';
									board[row][col++] = '.';
								}
							}
						}
						board[0][0] = 'c';
					}
				}

				StringBuffer y = new StringBuffer();
				if (impossible) y.append("Impossible\n");
				else {
					for (int i = 0; i < R; i++) {
						for (int j = 0; j < C; j++)
							y.append(board[i][j]);
						y.append("\n");
					}
				}

				answer.append(y);
				System.out.print(y);
			}
			output(answer);
		} catch (Exception e) {
			e.printStackTrace();
		}
		long tm = System.currentTimeMillis() - startDatetime;
		long tms = tm / 1000;
		System.out.println("The process time: " + tms + "s " + (tm%1000) + "ms");
	}

	/**
	 * read data from a file
	 * @param path : the data file's path
	 */
	private static void input() throws Exception {
		BufferedReader br = null;
		String line = null;
		if (filePath == null) br = new BufferedReader(new InputStreamReader(System.in));
		else br = new BufferedReader(new InputStreamReader(new FileInputStream(filePath)));

		T = Integer.parseInt(br.readLine());

		Rs = new int[T];
		Cs = new int[T];
		Ms = new int[T];
		for (int x = 0; x < T;) {
			if ( (line = br.readLine()) == null) { throw new Exception("wrong! Case #" + (x+1)); }
			if (line.equals("")) continue;
			String[] sts = line.split(" ");
			Rs[x] = Integer.parseInt(sts[0]);
			Cs[x] = Integer.parseInt(sts[1]);
			Ms[x] = Integer.parseInt(sts[2]);
			x++;
		}
		br.close();
		br = null;

		// Confirm
//		System.out.println(T);
//		for (int x = 0; x < T; x++) {
//			System.out.println(Rs[x] + " " + Cs[x] + " " + Ms[x]);
//		}
	}

	private static void output(StringBuffer answer) throws Exception {
		String outPath = "answer.out";
		if (filePath != null) outPath = filePath.substring(0, filePath.length()-2) + "out";
		FileOutputStream fos = new FileOutputStream(outPath, false);
		fos.write(answer.toString().getBytes());
		fos.close();
		fos = null;
	}
}
