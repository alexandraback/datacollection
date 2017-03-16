import java.io.*;
import java.util.*;

public class A {
	public static void main(String args[]) {
		try {
			InputStreamReader isr = null;
			try {
				isr = new InputStreamReader(System.in, "UTF-8");
				BufferedReader br = null;
				try {
					br = new BufferedReader(isr);
					new A().go(br);
				} finally {
					if (br != null) br.close();
				}
			} finally {
				if (isr != null) isr.close();
			}
		} catch (Exception ex) {
			ex.printStackTrace();
		}
	}

	public void go(BufferedReader br) throws Exception {
		int num = Integer.parseInt(br.readLine());
		for (int n = 1; n <= num; n++) {
			solve(n, br);
			br.readLine();
		}
	}

	public void solve(int num, BufferedReader br) throws Exception {
		char base[][] = new char[4][4];
		String line = null;
		boolean finished = true;
		for (int i = 0; i < 4; i++) {
			line = br.readLine();
			for (int j = 0; j < 4; j++) {
				base[i][j] = line.charAt(j);
				if (base[i][j] == '.')
					finished = false;
			}
		}

		int xyoko[] = new int[4];
		int xtate[] = new int[4];
		int xback = 0;
		int xslash = 0;

		int oyoko[] = new int[4];
		int otate[] = new int[4];
		int oback = 0;
		int oslash = 0;

		String kekka = null;
		if (calc(base, 'X'))
			kekka = "X won";
		else if (calc(base, 'O'))
			kekka = "O won";
		else if (finished)
			kekka = "Draw";
		else
			kekka = "Game has not completed";

		System.out.println("Case #" + num + ": " + kekka);
	}

	public boolean calc(char base[][], char c) {
		int yoko[] = new int[4];
		Arrays.fill(yoko, 0);
		int tate[] = new int[4];
		Arrays.fill(tate, 0);
		int back = 0;
		int slash = 0;

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (base[i][j] == c || base[i][j] == 'T')
					yoko[i]++;
			}
		}

//		System.out.print(c + " yoko=");
//		for (int j = 0; j < 4; j++) {
//			System.out.print(yoko[j]);
//			System.out.print(' ');
//		}
//		System.out.println();

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (base[j][i] == c || base[j][i] == 'T')
					tate[i]++;
			}
		}

//		System.out.print(c + " tate=");
//		for (int j = 0; j < 4; j++) {
//			System.out.print(tate[j]);
//			System.out.print(' ');
//		}
//		System.out.println();

		for (int i = 0; i < 4; i++)
			if (base[i][i] == c || base[i][i] == 'T')
				back++;
//		System.out.println(c + " back=" + back);

		for (int i = 0; i < 4; i++)
			if (base[i][3 - i] == c || base[i][3 - i] == 'T')
				slash++;
//		System.out.println(c + " slash=" + slash);

		return yoko[0] == 4 || yoko[1] == 4 || yoko[2] == 4 || yoko[3] == 4 || 
			tate[0] == 4 || tate[1] == 4 || tate[2] == 4 || tate[3] == 4 || 
			back == 4 || slash == 4;
	}
}
