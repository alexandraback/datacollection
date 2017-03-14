package qualification;

import java.io.*;
import java.util.Scanner;

/**
 * @author Roman Elizarov
 */
public class D {
	public static void main(String[] args) throws IOException {
		new D().go();
	}

	Scanner in;
	PrintWriter out;

	private void go() throws IOException  {
		in = new Scanner(new File("src\\qualification\\d.in"));
		out = new PrintWriter(new File("src\\qualification\\d.out"));
		int t = in.nextInt();
		for (int tn = 1; tn <= t; tn++) {
			System.out.println("Case #" + tn);
			out.println("Case #" + tn + ": " + solveCase());
		}
		in.close();
		out.close();
	}

	int h;
	int w;
	int d;
	char[][] c;

	int a00 = 1;
	int a01;
	int a10;
	int a11 = 1;
	int b0;
	int b1;

	char get(int x, int y) {
		return c[a00 * x + a01 * y + b0][a10 * x + a11 * y + b1];
	}

	void printC() {
		System.out.println("--- C ---");
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++)
				System.out.print(c[i][j]);
			System.out.println();
		}
	}

	void printV(String hdr) {
		System.out.println("--- " + hdr + " ---");
		for (int y = 3; y >= -4; y--) {
			System.out.print(y == 0 ? "_" : " ");
			for (int x = 0; x <= 5; x++)
				try {
					System.out.print(get(x, y));
				} catch (ArrayIndexOutOfBoundsException e) {
					System.out.print('?');
				}
			System.out.println();
		}
	}

	// Rotate 90 deg ccw around point (0.5, 0.5)
	void rotateCCW() {
		int d00 = -a01;
		int d01 = a00;
		int d10 = -a11;
		int d11 = a10;
		a00 = d00;
		a01 = d01;
		a10 = d10;
		a11 = d11;
	}

	// Rotate 90 deg cw around point (0.5, 0.5)
	void rotateCW() {
		int d00 = a01;
		int d01 = -a00;
		int d10 = a11;
		int d11 = -a10;
		a00 = d00;
		a01 = d01;
		a10 = d10;
		a11 = d11;
	}

	// Mirror around x = p
	void mirrorX(int p) {
		b0 += a00 * (2 * p - 1);
		b1 += a10 * (2 * p - 1);
		a00 = -a00;
		a10 = -a10;
	}

	// Mirror around y = q
	void mirrorY(int q) {
		b0 += a01 * (2 * q - 1);
		b1 += a11 * (2 * q - 1);
		a01 = -a01;
		a11 = -a11;
	}

	// Mirror around y = 0.5
	void mirrorYC() {
		a01 = -a01;
		a11 = -a11;
	}

	private int solveCase() {
		h = in.nextInt();
		w = in.nextInt();
		d = in.nextInt();
		c = new char[h][];
		for (int i = 0; i < h; i++) {
			c[i] = in.next().toCharArray();
			assert c[i].length == w;
		}
		printC();
	find:
		for (b0 = 0; b0 < h; b0++)
			for (b1 = 0; b1 < w; b1++)
				if (c[b0][b1] == 'X')
					break find;
		int cnt = 0;
		for (int i = 0; i < 4; i++) {
			cnt += solveRay(1, 1);
			cnt += solveRangeX(1, 1, -1, 1, 1);
			rotateCCW();
		}
		return cnt;
	}

	// (0.5, 0.5) -> (x, y)
	int solveRay(int x, int y) {
		int cnt = 0;
		if (y <= 0) {
			mirrorYC();
			cnt = solveRay(x, -y + 1);
			mirrorYC();
			return cnt;
		}
		if (!possible(x, y))
			return 0;
		assert x > 0;
		switch (get(x, y)) {
		case '#':
			char c1 = get(x - 1, y);
			char c2 = get(x, y - 1);
			if (c1 == '#' && c2 == '#') {
				// reflected straight back
				if (good2(x, y))
					cnt++;
			} else if (c1 == '#') {
				mirrorY(y);
				cnt = solveRay(x, y);
				mirrorY(y);
			} else if (c2 == '#') {
				mirrorX(x);
				cnt = solveRay(x, y);
				mirrorX(x);
			} // otherwise -> destroyed
			break;
		case 'X':
			if (x == y) {
				if (good(x, y))
					cnt++;
				break;
			}
			// fall-through
		case '.':
			if (x < y)
				cnt = solveRay2(2 * x - 1, 2 * y - 1, x, y + 1);
			else if (x > y)
				cnt = solveRay2(2 * x - 1, 2 * y - 1, x + 1, y);
			else // x == y
				cnt = solveRay(x + 1, y + 1);
			break;
		default:
			assert false;
		}
		return cnt;
	}

	int solveRay2(int x0, int y0, int x, int y) {
		if (!possible(x, y))
			return 0;
		int cnt = 0;
		int ccw;
		switch (get(x, y)) {
		case '#':
			ccw = ccw(x0, y0, 2 * x - 1, 2 * y - 1);
			if (ccw > 0) {
				mirrorY(y);
				cnt = solveRay2(x0, y0, x, y);
				mirrorY(y);
			} else if (ccw < 0) {
				mirrorX(x);
				cnt = solveRay2(x0, y0, x, y);
				mirrorX(x);
			} else
				cnt = solveRay(x, y); // hit corner
			break;
		case 'X':
			if (ccw(x0, y0, x, y) == 0) {
				if (good(x, y))
					cnt++;
				break;
			}
		case '.':
			ccw = ccw(x0, y0, 2 * x + 1, 2 * y + 1);
			if (ccw > 0)
				cnt = solveRay2(x0, y0, x + 1, y);
			else if (ccw < 0)
				cnt = solveRay2(x0, y0, x, y + 1);
			else
				cnt = solveRay(x + 1, y + 1); // hit corner
			break;
		default:
			assert false;
		}
		return cnt;
	}

	// (0.5, 0.5) -> (p, y') between (x0, y0) and (x1, y1) vectors
	int solveRangeX(int p, int x0, int y0, int x1, int y1) {
		//printV("solveRangeX(" + p + "," + x0 + "," + y0 + "," + x1 + "," + y1 + ")");
		assert ccw(x0, y0, x1, y1) > 0;
		if (p > d)
			return 0;
		int q = projectRay(p, x0, y0);
		assert ccw(2 * p - 1, 2 * q - 1, x0, y0) >= 0;
		assert ccw(x1, y1, 2 * p - 1, 2 * q + 1) >= 0;
		int cnt = 0;
		switch (get(p, q)) {
		case '#':
			mirrorX(p);
			cnt += solveRangeX(p, x0, y0, x1, y1);
			mirrorX(p);
			break;
		case 'X':
			if (ccw(x0, y0, p, q) > 0 && ccw(p, q, x1, y1) > 0) {
				if (good(p, q))
					cnt++;
				cnt += solveRangeX(p, x0, y0, p, q);
				cnt += solveRangeX(p, p, q, x1, y1);
				break;
			}
			// fall-through
		case '.':
			if (q <= 0 && ccw(x0, y0, 2 * p + 1, 2 * q - 1) > 0) {
				if (ccw(2 * p + 1, 2 * q - 1, x1, y1) > 0) {
					cnt += solveRangeY(q, x0, y0, 2 * p + 1, 2 * q - 1);
					cnt += solveRay(p + 1, q);
					x0 = 2 * p + 1;
					y0 = 2 * q - 1;
				} else {
					cnt += solveRangeY(q, x0, y0, x1, y1);
					break;
				}
			}
			if (q >= 0 && ccw(2 * p + 1, 2 * q + 1, x1, y1) > 0) {
				if (ccw(x0, y0, 2 * p + 1, 2 * q + 1) > 0) {
					cnt += solveRangeY(q + 1, 2 * p + 1, 2 * q + 1, x1, y1);
					cnt += solveRay(p + 1, q + 1);
					x1 = 2 * p + 1;
					y1 = 2 * q + 1;
				} else {
					cnt += solveRangeY(q + 1, x0, y0, x1, y1);
					break;
				}
			}
			cnt += solveRangeX(p + 1, x0, y0, x1, y1);
			break;
		default:
			assert false;
		}
		return cnt;
	}

	private boolean possible(int x, int y) {
		return sqr(2 * x - 1) + sqr(2 * y - 1) <= sqr(2 * d);
	}

	private boolean good(int x, int y) {
		return sqr(x) + sqr(y) <= sqr(d);
	}

	boolean good2(int x, int y) {
		return sqr(2 * x - 1) + sqr(2 * y - 1) <= sqr(d);
	}

	int solveRangeY(int q, int x0, int y0, int x1, int y1) {
		//printV("solveRangeY(" + q + "," + x0 + "," + y0 + "," + x1 + "," + y1 + ")");
		int cnt;
		if (q <= 0) {
			rotateCCW();
			cnt = solveRangeX(-q + 1, -y0, x0, -y1, x1);
			rotateCW();
		} else {
			rotateCW();
			cnt = solveRangeX(q, y0, -x0, y1, -x1);
			rotateCCW();
		}
		return cnt;
	}

	static int projectRay(int p, int x0, int y0) {
		return div(x0 + y0 * (2 * p - 1), 2 * x0);
	}

	static int div(int a, int b) {
		assert b > 0;
		return a >= 0 ?  a / b : -((-a + b - 1)/ b);
	}

	static int ccw(int x0, int y0, int x1, int y1) {
		return x0 * y1 - x1 * y0;
	}

	static int sqr(int x) {
		return x * x;
	}
}
