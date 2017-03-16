import java.io.IOException;
import java.io.InputStreamReader;
import java.io.LineNumberReader;

public class HallOfMirrors {
	public static void main(String[] args) throws IOException {
		LineNumberReader in = new LineNumberReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(in.readLine());
		for (int a = 1; a <= n; a++) {
			String[] p = in.readLine().split(" ");
			int h = Integer.parseInt(p[0]);
			int w = Integer.parseInt(p[1]);
			int d = Integer.parseInt(p[2]);
			
			boolean[][] full = new boolean[w][h];
			int px = 0;
			int py = 0;
			for (int y = 0; y < h; y++) {
				String l = in.readLine();
				for (int x = 0; x < w; x++) {
					char c = l.charAt(x);
					if (c == 'X') {
						px = x;
						py = y;
					} else
					if (c == '#') {
						full[x][y] = true;
					}
				}
			}
			
			System.out.println("Case #" + a + ": " + solve(w, h, full, px, py, d));
		}
	}
	
	static int solve(int w, int h, boolean[][] full, int px, int py, int d) {
		return solveStraight(w, h, full, px, py, d) + solveDiag(w, h, full, px, py, d);
	}
	
	static int[][] stDir = {
		{ 0, 1 },
		{ 0, -1 },
		{ 1, 0 },
		{ -1, 0 }
	};
	
	static int solveStraight(int w, int h, boolean[][] full, int px, int py, int d) {
		int res = 0;
		
		for (int[] dir : stDir) {
			int posx = px;
			int posy = py;
			int dist = 0;
			while (true) {
				posx += dir[0];
				posy += dir[1];
				if (full[posx][posy])
					break;
				dist++;
			}
			
			if (2 * dist + 1 <= d)
				res++;
		}
		
		return res;
	}
	
	//      dx, dy,    adx, ady,   bdx, bdy,   cdx, cdy,   reverse,   flipx,   flipy
	static int[][] diDirs = {
		{  1,  1,   1,  1,   1,  0,   0,  1,   3, 2, 1 },
		{  1, -1,   1, -2,   1, -1,   0, -2,   2, 3, 0 },
		{ -1,  1,  -2,  1,  -2,  0,  -1,  1,   1, 0, 3 },
		{ -1, -1,  -2, -2,  -2, -1,  -1, -2,   0, 1, 2 }
	};
	
	static int solveDiag(int w, int h, boolean[][] full, int px, int py, int d) {
		int res = 0;
		
		px = 2 * px + 1;
		py = 2 * py + 1;
		for (int sx = 1; sx <= d; sx++) {
			for (int sy = 1; sy <= d; sy++) {
				if (gcd(sx, sy) > 1)
					continue;
					
				int maxSteps = (int) (2 * d / Math.sqrt(1.0 / (sx * sx) + 1.0 / (sy * sy)));
				if (maxSteps < 1)
					continue;
				
				for (int dir = 0; dir < 4; dir++) {
					if (comesBack(full, px * sx, py * sy, maxSteps, dir, 2 * sx, 2 * sy))
						res++;
				}
			}
		}
		
		return res;
	}
	
	static boolean comesBack(boolean[][] full, final int px, final int py, int steps, int dir, int sx, int sy) {
		int x = px;
		int y = py;
		while (steps-->0) {
			int[] data = diDirs[dir];
			
			boolean a = full[(x + data[2]) / sx][(y + data[3]) / sy];
			boolean b = full[(x + data[4]) / sx][(y + data[5]) / sy];
			boolean c = full[(x + data[6]) / sx][(y + data[7]) / sy];
			
			if (a && !(b || c))
				return false;
			
			x += data[0];
			y += data[1];
			
			if (a && b && c) {
				dir = data[8];
			} else
			if (a && b) {
				dir = data[9];
			} else
			if (a && c) {
				dir = data[10];
			}
			
			if (x == px && y == py)
				return true;
		}
		return false;
	}
	
	static int gcd(int a, int b) {
		while (true) {
			if (b == 0)
				return a;
			
			int t = a % b;
			a = b;
			b = t;
		}
	}
}
