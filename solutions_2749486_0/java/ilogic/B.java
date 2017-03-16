import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;
import java.util.Stack;

public class B {
	private int hop = 1;
	int x;
	int y;

	int cx = 0;
	int cy = 0;

	String N = "N";
	String E = "E";
	String S = "S";
	String W = "W";

	Stack<int[]> sx = new Stack<int[]>();

	public StringBuilder path = new StringBuilder();

	public B(int x, int y) {

		this.x = x;
		this.y = y;

		if (x < 0) {
			this.x = x * -1;
			E = "W";
			W = "E";
		}
		if (y < 0) {
			this.y = y * -1;
			N = "S";
			S = "N";
		}

		if (this.y < this.x) {
			int tempx = this.x;
			this.x = this.y;
			this.y = tempx;

			String tempN = N;
			String tempS = S;

			N = E;
			S = W;

			E = tempN;
			W = tempS;
		}

		solve();
	}

	private void hopx(boolean east) {
		if (east) {
			cx += hop++;
			path.append(E);
		} else {
			cx -= hop++;
			path.append(W);
		}
	}

	private void hopy(boolean north) {
		if (north) {
			cy += hop++;
			path.append(N);
		} else {
			cy -= hop++;
			path.append(S);
		}
	}

	private void solve() {
		int distx = x - cx;
		int disty = y - cy;

		while (distx >= hop) {
			hopx(true);
			distx = x - cx;
		}

		while (cx != x) {
			if (hop == disty) {
				hopy(true);
			} else {
				hopx(false);
				hopx(true);
			}
		}

		while (cy != y) {
			disty = y - cy;
			if (disty >= hop)
				hopy(true);
			else {

				if (cy < y) {
					hopy(false);
					hopy(true);
				} else {
					hopy(true);
					hopy(false);
				}
			}

		}
	}


	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(new FileReader("input"));
		PrintWriter pw = new PrintWriter(new FileWriter("output"));

		int testCases = sc.nextInt();

		for (int t = 0; t < testCases; t++) {
			int x = sc.nextInt();
			int y = sc.nextInt();

			B b = new B(x, y);
			pw.println("Case #" + (t + 1) + ": " + b.path.toString());
			pw.flush();
		}

		pw.close();
		sc.close();
	}
}
