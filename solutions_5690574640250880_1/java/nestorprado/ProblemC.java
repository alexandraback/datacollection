import java.io.*;
import java.util.*;

public class ProblemC {

	private static void fill(char[][] arr, int r, int c, int m) {
		int lenX = arr[0].length - c;
		int lenY = arr.length - r;
		if (m > 0) {
			if ((lenX >= lenY)) {
				k: for (int j = 0; j < lenY - 2; j++) {
					for (int i = 0; i < lenX - 2; i++) {
						arr[r + j][c + i] = '*';
						m--;
						if (m == 0)
							break k;
					}
				}
			} else {
				k: for (int i = 0; i < lenX - 2; i++) {
					for (int j = 0; j < lenY - 2; j++) {
						arr[r + j][c + i] = '*';
						m--;
						if (m == 0)
							break k;
					}
				}
			}
		}

		if ((m == 0)
				&& (arr[arr.length - 2 > 0 ? arr.length - 2 : 0][arr[0].length - 1] != '*')
				&& (arr[arr.length - 1][arr[0].length - 2 > 0 ? arr[0].length - 2 : 0] != '*'))
			arr[arr.length - 1][arr[0].length - 1] = 'c';
		else
			arr[arr.length - 1][arr[0].length - 1] = 'i';
		return;
	}

	private static void solve(char[][] arr, int r, int c, int m) {
		int lenX = arr[0].length - c;
		int lenY = arr.length - r;
		if ((lenX <= lenY) && (lenX <= m)) {
			for (int i = 0; i < lenX; i++)
				arr[r][c + i] = '*';
			solve(arr, r + 1, c, m - lenX);
		} else if ((lenX >= lenY) && (lenY <= m)) {
			for (int i = 0; i < lenY; i++) {
				arr[r + i][c] = '*';
			}
			solve(arr, r, c + 1, m - lenY);
		} else
			fill(arr, r, c, m);
	}

	private static String myWrite(char arr[][]) {
		int lenX = arr[0].length;
		int lenY = arr.length;
		if (arr[lenY - 1][lenX - 1] == 'i') {
			return "\nImpossible";
		}
		String res = "";
		for (int i = 0; i < lenY; i++) {
			res += '\n';
			for (int j = 0; j < lenX; j++) {
				res += arr[i][j] == 0 ? '.' : arr[i][j];
			}
		}
		return res;
	}
	
	
	private static String myWriteS(char arr[][]) {
		int lenX = arr[0].length;
		int lenY = arr.length;
		arr[lenY - 1][lenX - 1] = 'c';
		String res="";
		for (int i = 0; i < lenY; i++) {
			res += '\n';
			for (int j = 0; j < lenX; j++) {
				res += arr[i][j] == 0 ? '*' : arr[i][j];
			}
		}
		return res;
	}
	

	private static String solve(Scanner in) {
		int R = in.nextInt();
		int C = in.nextInt();
		int M = in.nextInt();
		char[][] mx = new char[R][C];
		if(R*C==M+1) return myWriteS(mx);
		solve(mx, 0, 0, M);
		String res = myWrite(mx);
		return res;
	}

	public static void main(String[] args) {
		String file = "Qualification\\ProblemClarge";
		try {
			System.out.println(file);
			Scanner in = new Scanner(new File(file + ".in"));
			PrintWriter out = new PrintWriter(new File(file + ".out"));
			int T = in.nextInt();
			in.nextLine();
			for (int i = 1; i <= T; i++) {
				String s = "Case #" + i + ":" + ProblemC.solve(in);
				out.println(s);
				System.out.println(s);
			}
			out.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}