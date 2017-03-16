package y2012.round1;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class C {
	public static void main(String[] args) throws FileNotFoundException {
		String testName = "C";
		Scanner in = new Scanner(new File("d:\\Downloads\\" + testName + ".in"));
		PrintWriter out = new PrintWriter(new File("d:\\Downloads\\" + testName
				+ ".out"));
		int nTestCase = Integer.parseInt(in.nextLine());
		for (int testCase = 1; testCase <= nTestCase; testCase++) {
			int n = Integer.parseInt(in.nextLine());
			int[] s = new int[n];
			int[] v = new int[n];
			int[] p = new int[n];

			int pocetniStatus = 0;
			for (int i = 0; i < n; i++) {
				String str = in.nextLine();
				char ch = str.charAt(0);
				if (ch == 'L')
					s[i] = 0;
				else if (ch == 'R')
					s[i] = 1;
				else
					System.err.println("GRESKA!!");
				pocetniStatus |= s[i] << i;
				v[i] = Integer.parseInt(str.split(" ")[1]);
				p[i] = Integer.parseInt(str.split(" ")[2]);
			}

			ArrayList<Moment> moments = new ArrayList<Moment>();
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					if (i != j && v[i] != v[j])
						if (v[i] < v[j]) {
							double d = p[i] - p[j] - 5;
							if (d >= 0)
								moments.add(new Moment(d
										/ (double) (v[j] - v[i]), i, j, true));
						} else {
							double d = p[j] - p[i] + 5;
							if (d >= 0)
								moments.add(new Moment(d
										/ (double) (v[i] - v[j]), i, j, false));
						}
			Collections.sort(moments);

			boolean[][] morajuSuprotno = new boolean[n][n];
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					if (i != j)
						morajuSuprotno[i][j] = Math.abs(p[i] - p[j]) < 5 ? true
								: false;
					else
						morajuSuprotno[i][j] = false;

			int i = 0;
			boolean[] moze = new boolean[1 << n];
			odrediSveMogucnosti(pocetniStatus, morajuSuprotno, moze);
			for (int j = 0; j < moze.length; j++)
				if (moze[j])
					System.out.println(Integer.toString(j, 2));

			while (i < moments.size()) {
				Moment m = moments.get(i);
				System.out.println(m.t);
				morajuSuprotno[m.i][m.j] = m.isStart;
				morajuSuprotno[m.j][m.i] = m.isStart;

				boolean[] stariMoze = moze;
				moze = new boolean[stariMoze.length];
				for (int j = 0; j < stariMoze.length; j++)
					if (stariMoze[j])
						odrediSveMogucnosti(j, morajuSuprotno, moze);

				boolean imaResenja = false;
				for (int j = 0; j < moze.length; j++)
					if (moze[j]) {
						imaResenja = true;
						if (n>2)
						System.out.println("\t" + Integer.toBinaryString(j)
								+ " " + morajuSuprotno[0][1] + " "
								+ morajuSuprotno[0][2]+ " " + morajuSuprotno[1][2]);
					}
				if (!imaResenja)
					break;
				i++;
			}

			if (i < moments.size())
				out.printf("Case #%d: %.5f\n", testCase, moments.get(i).t);
			else
				out.println("Case #" + testCase + ": Possible");
			System.out.println("-------------");
		}
		in.close();
		out.close();
	}

	static void odrediSveMogucnosti(int status, boolean[][] morajuSuprotno,
			boolean[] moze) {
		boolean[] mozeDaPromeni = new boolean[morajuSuprotno.length];
		for (int i = 0; i < morajuSuprotno.length; i++) {
			mozeDaPromeni[i] = true;
			for (int j = 0; j < morajuSuprotno.length; j++)
				if (morajuSuprotno[i][j])
					mozeDaPromeni[i] = false;
		}
		for (int i = 0; i < moze.length; i++) {
			boolean t = true;
			for (int j = 0; j < morajuSuprotno.length; j++)
				if (!mozeDaPromeni[j] && (status & (1 << j)) != (i & (1 << j)))
					t = false;
			// System.out.println("\t" + Integer.toBinaryString(i)+" "+t);
			for (int j1 = 0; j1 < morajuSuprotno.length; j1++)
				for (int j2 = 0; j2 < morajuSuprotno.length; j2++)
					if (morajuSuprotno[j1][j2]
							&& ((i & (1 << j1))>>j1) == ((i & (1 << j2))>>j2))
						t = false;
			// System.out.println("\t" + Integer.toBinaryString(i)+" "+t);
			if (t)
				moze[i] = true;
		}
	}

	static class Moment implements Comparable<Moment> {
		double t;
		int i, j;
		boolean isStart;
		public Moment(double t, int i, int j, boolean isStart) {
			this.t = t;
			this.i = Math.min(i, j);
			this.j = Math.max(i, j);
			this.isStart = isStart;
		}
		@Override
		public int compareTo(Moment m) {
			// if (Math.abs (t-m.t)<0.0000000001)
			return t < m.t ? -1 : 1;
		}
	}
}
