import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class C {

	private static final String path = "/home/tolstov.a.a/codejam/c/";

	private static final String problem = "C-small";

	Scanner in;

	PrintWriter out;

	int field[][];

	final int goX[] = { 0, 0, -1, 1 };

	final int goY[] = { -1, 1, 0, 0 };

	boolean couldWith(int mask, int take, int sizeX, int sizeY) {
		for (int ar[] : field) {
			Arrays.fill(ar, 0);
		}
		for (int x = 0; x < 1 + sizeX + 1; x++) {
			field[0][x] = 2;
			field[1 + sizeY][x] = 2;
		}
		for (int y = 0; y < 1 + sizeY + 1; y++) {
			field[y][0] = 2;
			field[y][1 + sizeX] = 2;
		}

		for (int posY = 0; posY < sizeY; posY++) {
			for (int posX = 0; posX < sizeX; posX++) {
				int mul = 1 << (posY * sizeX + posX);

				if ((mask & mul) == mul) {
					field[1 + posY][1 + posX] = 1;
				}

			}
		}

		for (int posY = 0; posY <= sizeY + 1; posY++) {
			for (int posX = 0; posX <= sizeX + 1; posX++) {
				if (field[posY][posX] == 2) {
					Queue<Pos> q = new LinkedList<Pos>();
					q.add(new Pos(posX, posY));

					while (!q.isEmpty()) {
						Pos curr = q.poll();
						for (int i = 0; i < 4; i++) {
							int nx = curr.x + goX[i];
							int ny = curr.y + goY[i];
							if (0 < nx && nx <= sizeX) {
								if (0 < ny && ny <= sizeY) {
									if (field[ny][nx] == 0) {
										field[ny][nx] = 3;
										q.add(new Pos(nx, ny));
									}
								}
							}
						}
					}
				}
			}
		}
		int enclosed = 0;
		for (int posY = 0; posY <= sizeY; posY++) {
			for (int posX = 0; posX <= sizeX; posX++) {
				if (field[posY][posX] < 2) {
					enclosed++;
				}
			}
		}
		return enclosed >= take;
	}

	void solveOne() {
		int sizeX = in.nextInt();
		int sizeY = in.nextInt();
		int k = in.nextInt();

		int max = sizeX * sizeY;

		field = new int[1 + sizeY + 1][1 + sizeX + 1];
		int bestUsed = Integer.MAX_VALUE;

		for (int i = 0; i < (1 << max); i++) {
			int used = 0;
			for (int posY = 0; posY < sizeY; posY++) {
				for (int posX = 0; posX < sizeX; posX++) {
					int mul = 1 << (posX * sizeY + posY);
					if ((i & mul) == mul) {
						used++;
					}
				}
			}
			if (used < bestUsed && couldWith(i, k, sizeX, sizeY)) {
				bestUsed = Math.min(used, bestUsed);
			}
		}

		out.print(bestUsed);
		out.flush();
	}

	static class Pos {

		int x;

		int y;

		Pos(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}

	void solve() {
		int nTests = in.nextInt();
		for (int i = 1; i <= nTests; i++) {
			out.print("Case #" + i + ": ");
			solveOne();
			out.println();
			out.flush();
		}
	}

	void run() {
		try {
			in = new Scanner(new FileReader(path + problem + ".in"));
			out = new PrintWriter(path + problem + ".out");
		} catch (IOException e) {
			in = new Scanner(System.in);
			out = new PrintWriter(System.out);
			out.println("cmd>");
			out.flush();
		}
		try {
			solve();
		} finally {
			out.close();
		}
	}

	public static void main(String[] args) {
		new C().run();
	}
}
