package codeJam3;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.LinkedList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
	
	public static int getRev(int x) {
		String t = String.valueOf(x);
		StringBuilder y = new StringBuilder("");
		for (int i = t.length() - 1; i >= 0; i--) {
			y.append(t.charAt(i));
		}
		return Integer.valueOf(y.toString());
	}
	
	public static int check(int a[][], int r, int c) {
		int sum = 0; int i1 = 0; int j1 = 0;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				i1 = i + 1; j1 = j;
				if (i1 < r && a[i][j] + a[i1][j1] == 2) sum++;
				i1 = i; j1 = j + 1;
				if (j1 < c && a[i][j] + a[i1][j1] == 2) sum++;
			}
		}
		return sum;
	}
	
	public static int find(int i, int j, int n, int a[][], int r, int c) {
		if (n == 0) {
			return check(a, r, c);
		}
		if (j == c) {
			return find(i + 1, 0, n, a, r, c);
		}
		if (i == r) {
			return Integer.MAX_VALUE / 2;
		}
		// no
		int answer = find(i, j + 1, n, a, r, c);
		a[i][j] = 1; n--;
		answer = Math.min(answer, find(i, j + 1, n, a, r, c));
		a[i][j] = 0; n++;
		return answer;
	}
	
	public static class Hiker {
		public double d;
		public double m;
		public Hiker(double d, double m) {
			this.d = d;
			this.m = m;
		}
	}
	
	public static double getTime(Hiker k) {
		double d = 360 - k.d;
		return k.m * (d*1.0 / 360);
	}
	/*
	public static int getEnc(Hiker k, Hiker kk) {
		int enc = 0;
		if (k.m == kk.m) {
			return 0;
		}
		if (k.d == kk.d) {
			enc++;
		}
		double time1 = getTime(k);
		if (k.m < kk.m) {
			if (kk.d <= k.d) {
				return enc;
			}
			double time2 = getTime(kk);
			if (time2 - time1 > 0.000000001) { 
				enc++;
			} 
			return enc;
		}
		
		boolean flag = false;
		while (!flag) {
			double v1 = (1.0 * 360) / k.m;
			double v2 = (1.0 * 360) / kk.m;
			double l = 0;
			if (k.d > kk.d) {
				l = k.d - kk.d;
			}
			if (k.d == kk.d) {
				l = 360;
			}
			if (k.d < kk.d) {
				l = 360 - (kk.d - k.d);
			}
			double time = l / (v2 - v1);
			
		}
	}
	*/
	public static void main(String[] args) throws FileNotFoundException {
		 InputReader in = new InputReader(new FileInputStream(new File("src/input.txt")));
		 PrintWriter out = new PrintWriter(new File("src/output.txt"));
		 double distC = 0; 
		 double distC2 = 0; 
		 double distZ = 0; 
		 double time1 = 0; 
		 double eps = 0.0000000;
		 double time2 = 0; 
		 
		 int t = in.nextInt();
		 for (int j = 0; j < t; j++) {
			 int n = in.nextInt();
			 int d[] = new int[n];
			 int h[] = new int[n];
			 int m[] = new int[n];
			 List<Hiker> hikers = new LinkedList<Hiker>();
			 for (int i = 0; i < n; i++) {
				 d[i] = in.nextInt();
				 h[i] = in.nextInt();
				 m[i] = in.nextInt();
				 for (int hh = 0; hh < h[i]; hh++) {
					 hikers.add(new Main.Hiker(d[i], m[i] + hh));
				 }
			 }
			 int answer = 0;
			 if (hikers.size() == 2) {
				 double d1 = hikers.get(0).d;
				 double m1 = hikers.get(0).m;
				 double d2 = hikers.get(1).d;
				 double m2 = hikers.get(1).m;
				 if (d1 > d2) {
					 double tt = d1; d1 = d2; d2 = tt;
					 tt = m1; m1 = m2; m2 = tt;
				 }
				 if (m1 == m2) {
					answer = 0; 
				 }  else {
					 if (m1 > m2) {
						 time1 = m1 * ((360 - d1) / 360);
						 double l  = 360 - (d2 - d1);
						 double v1 = 360 / m1;
						 double v2 = 360 / m2;
						 double vv = v2 - v1;
						 time2 = l / vv;
						 if (time2 - time1 > eps) {
							 answer = 0;
						 } else {
							 answer = 1;
						 }
					 } else {
						 time1 = m1 * ((360 - d1) / 360);
						 time2 = m2 * ((360 - d2) / 360);
						 if (time1 - time2 > eps) {
							 answer = 0;
						 } else {
							 double v1 = 360 / m1;
							 double v2 = 360 / m2;
							 double vv = v1 - v2;
							 double l = d2 - d1;
							 time1 = l / vv;
							 double dd = d1 + time1 * v1;
							 d1 = dd; d2 = dd;
							 
							 time1 = m1 * (1 + (360 - d1) / 360);
							 time2 = m2 * ((360 - d2) / 360);
							 
							 if (time1 - time2 > eps) {
								 answer = 0;
							 } else {
								 answer = 1;
							 }
						 }
					 }
				 }
			 }
			 out.println("Case #" + (j + 1) + ": " + answer);	
		 }
		 out.close();
	}	
}

class InputReader {
	public BufferedReader reader;
	public StringTokenizer tokenizer;

	public InputReader(InputStream stream) {
		reader = new BufferedReader(new InputStreamReader(stream));
		tokenizer = null;
	}
	public String nextLine() throws IOException {
		return reader.readLine();
	}
	public String next() {
		while (tokenizer == null || !tokenizer.hasMoreTokens()) {
			try {
				tokenizer = new StringTokenizer(reader.readLine());
			} catch (IOException e) {
				throw new RuntimeException(e);
			}
		}
		return tokenizer.nextToken();
	}
	
	public double nextDouble() {
		return Double.parseDouble(next());
	}
	
	public long nextLong() {
		return Long.parseLong(next());
	}

	public int nextInt() {
		return Integer.parseInt(next());
	}
}