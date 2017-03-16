package round1c;

import java.io.File;
import java.io.PrintStream;
import java.util.Scanner;

public class B {
	public static Scanner in;
	public static PrintStream out;

	public static void main(String[] args) throws Exception {
		in = new Scanner(new File("in.txt"));
		out = new PrintStream(new File("out.txt"));

		int T = in.nextInt();
		in.nextLine();
		for (int t = 1; t <= T; t++) {
			out.print("Case #" + t + ": ");
			solve();
			out.println();
		}
	}

	static class Point {
		double x;
		double y;

		public Point(double x, double y) {
			this.x = x;
			this.y = y;
		}
	};

	static class Line {
		Point st;
		Point end;

		public Line(Point st, Point end) {
			super();
			this.st = st;
			this.end = end;
		}

	};

	static double multiply(Point p1, Point p2, Point p0) {
		return ((p1.x - p0.x) * (p2.y - p0.y) - (p2.x - p0.x) * (p1.y - p0.y));
	}

	static boolean iscross(Line L1, Line L2) {
		return ((Math.max(L1.st.x, L1.end.x) >= Math.min(L2.st.x, L2.end.x)) && (Math.max(L2.st.x, L2.end.x) >= Math.min(L1.st.x, L1.end.x))
				&& (Math.max(L1.st.y, L1.end.y) >= Math.min(L2.st.y, L2.end.y)) && (Math.max(L2.st.y, L2.end.y) >= Math.min(L1.st.y, L1.end.y))
				&& (multiply(L2.st, L1.end, L1.st) * multiply(L1.end, L2.end, L1.st) >= 0) && (multiply(L1.st, L2.end, L2.st) * multiply(L2.end, L1.end, L2.st) >= 0));
	}

	public static void solve() {
		Double D;
		int N, A;

		D = in.nextDouble();
		N = in.nextInt();
		A = in.nextInt();

		double[][] other = new double[N][2];
		for (int i = 0; i < N; i++) {
			other[i][0] = in.nextDouble();
			other[i][1] = in.nextDouble();
		}

		if (N == 2) {

			Point start = new Point(other[0][0], other[0][1]);
			//Point end = new Point(other[1][0], other[1][1]);

			double a = (other[0][1] - other[1][1]) / (other[0][0] - other[1][0]);
			double b = (other[1][1] - a * other[1][0]);
			
			Point end = new Point((D - b) / a, D);
			
			
			Line line1 = new Line(start, end);

			for (int i = 0; i < A; i++) {
				double x = in.nextDouble();

				start = new Point(0, 0);
				end = new Point(Math.sqrt(2 * D / x), D);
				Line line2 = new Line(start, end);

				if (!iscross(line1, line2)) {
					out.println();
					out.print( Math.sqrt(2 * D / x));
				} else {
					out.println();
					out.print((D - b) / a);
					// System.out.println(Math.sqrt(2 * D / x));
				}
			}

		} else {
			for (int i = 0; i < A; i++) {
				double x = in.nextDouble();
				out.println();
				out.print(Math.sqrt(2 * D / x));
			}
		}

	}
}
