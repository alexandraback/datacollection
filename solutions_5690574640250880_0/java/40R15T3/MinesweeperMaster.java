package gcj;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.util.Arrays;
import java.util.Scanner;

public class MinesweeperMaster {
	public static void main(String[] args) throws Exception {
		String name = "C-small";
		Scanner scanner = new Scanner(new File("C:\\Users\\m\\Desktop\\training\\"+name+".in"));
		final long len = scanner.nextInt() + 1;
		FileWriter fw = new FileWriter("C:\\Users\\m\\Desktop\\training\\"+name+".out");
		BufferedWriter out = new BufferedWriter(fw);
		for (int n = 1; n < len; n++) {
			MineField mf = new MineField(scanner.nextInt(), scanner.nextInt(), scanner.nextInt());
			String str = "Case #" + n + ":\n" + mf.answer();
			System.out.println(str);
			out.write(str);
			out.newLine();
		}
		out.flush();
		out.close();
	}
}

final class MineField {
	final int R;
	int offsetR = 0;
	final int C;
	int offsetC = 0;
	final int M;
	int remainingM;
	final int[][] TABLE;
	boolean failed = false;
	MineField(int R, int C, int M) {
		this.R = R;
		this.C = C;
		this.M = M;
		remainingM = M;
		TABLE = new int[R][C];
		for (int i = 0; i < R; i++) {
			Arrays.fill(TABLE[i], -2);
		}
		fill1();
		if (remainingM != 0) {
		    System.out.println("using 2nd way to fill mines");
			fill2();
			System.out.println("after 2nd way mines left: " + remainingM);
		}
		if (remainingM != 0) {
			failed = true;
		} else {
			failed = check();
		}
	}
	private boolean check() {
		int rows = rows();
		int cols = cols();
		if (rows == 1 && cols == 1) {
			return false;
		}
		if (rows == 1 && R != 1) {
			return true;
		}
		if (cols == 1 && C != 1) {
			return true;
		}
		return false;
	}
	private void fill2() {
		do {
			int rows = rows();
			int cols = cols();
			boolean moreRows = rows > cols;
			int fill = moreRows ? rows : cols;
			if (fill <= 2) {
				return;
			}
			if (moreRows) {
				for (int i = cols - 1; i >= 2; i--) {
					TABLE[rows - 1][i] = -1;
					remainingM--;
					if (remainingM == 0) {
						return;
					}
				}
				//Arrays.fill(TABLE[rows - 1], -1);
				//remainingM -= cols;
				offsetR++;
			} else {
				for (int i = rows - 1; i >= 2; i--) {
					TABLE[i][cols - 1] = -1;
					remainingM--;
					if (remainingM == 0) {
						return;
					}
				}
				offsetC++;
			}
		} while (true);
	}
	private void fill1() {
		do {
			int rows = rows();
			int cols = cols();
			boolean moreRows = rows > cols;
			int fill = moreRows ? cols : rows;
			if (remainingM < fill || remainingM == 0) {
				break;
			}
			if (moreRows) {
				Arrays.fill(TABLE[rows - 1], -1);
				remainingM -= cols;
				offsetR++;
			} else {
				for (int i = 0; i < rows; i++) {
					TABLE[i][cols - 1] = -1;
				}
				remainingM -= rows;
				offsetC++;
			}
		} while (true);
	}
	private int rows() {
		return R - offsetR;
	}
	private int cols() {
		return C - offsetC;
	}
	public String answer() {
		if (failed) {
			return "Impossible";
		}
		StringBuffer sb = new StringBuffer();
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (i == 0 && j == 0) {
					sb.append('c');
				} else {
					if (TABLE[i][j] == -1) {
						sb.append('*');
					} else {
						sb.append('.');
					}
				}
			}
			if (i != R - 1) {
				sb.append('\n');
			}
		}
		return sb.toString();
		//return "Impossible";
	}
}
