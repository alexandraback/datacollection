import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;


public class FallingDiamonds {
	
	public static boolean checkP(int x, int y, int[] dx, int[] dy, int maxIndex) {
		for (int i = 0; i < maxIndex; i++) {
			if (dx[i] == x && dy[i] == y) {
				return true;
			}
		}
		return false;
	}
	
	public static double handler(int N, int i, int[] dx, int[] dy, int maxY, int x, int y, double possibility, int pX, int pY) {
		if (y == 0) {
			dx[i] = x;
			dy[i] = y;
			if (y > maxY)
				maxY = y;
			if (x == pX && y == pY) {
				return possibility;
			}
			else {
				if (i < N - 1)
					return handler(N, i + 1, dx, dy, maxY, 0, maxY + 2, possibility, pX, pY);
				else
					return 0.0f;
			}
		}
		boolean bLeft = checkP(x - 1, y - 1, dx, dy, i);
		boolean bBot = checkP(x, y - 2, dx, dy, i);
		boolean bRight = checkP(x + 1, y - 1, dx, dy, i);
		/*System.out.println("curP: (" + x + ", " + y + ") " + bLeft + " " + bBot + " " + bRight);
		for (int index = 0; index < i; index++) {
			System.out.print("(" + dx[index] + ", " + dy[index] + ") ");
		}
		System.out.println();*/
		if (!(bLeft || bBot || bRight))
			return handler(N, i, dx, dy, maxY, x, y - 1, possibility, pX, pY);
		if (bLeft && bRight) {
			dx[i] = x;
			dy[i] = y;
			if (y > maxY)
				maxY = y;
			if (x == pX && y == pY) {
				return possibility;
			}
			else {
				if (i < N - 1)
					return handler(N, i + 1, dx, dy, maxY, 0, maxY + 2, possibility, pX, pY);
				else
					return 0.0f;
			}
		}
		if (bLeft) {
			return handler(N, i, dx, dy, maxY, x + 1, y - 1, possibility, pX, pY);
		}
		if (bRight) {
			return handler(N, i, dx, dy, maxY, x - 1, y - 1, possibility, pX, pY);
		}
		if (bBot) {
			double leftPossibility = handler(N, i, dx, dy, maxY, x - 1, y - 1, possibility * 0.5, pX, pY);
			double rightPossibility = handler(N, i, dx, dy, maxY, x + 1, y - 1, possibility * 0.5, pX, pY);
			return leftPossibility + rightPossibility;
		}
		System.out.println("curP: (" + x + ", " + y + ") " + bLeft + " " + bBot + " " + bRight);
		return 0.0f;
	}

	public static void main(String[] args) {
		try {
			BufferedReader in = new BufferedReader(new FileReader(args[0]));
			BufferedWriter out = new BufferedWriter(new FileWriter(args[1]));
			int cases = Integer.valueOf(in.readLine());
			String line;
			String[] tmp;
			int N, X, Y;
			int[] dx, dy;
			double possibility;
			for (int c = 1; c <= cases; c++) {
				line = in.readLine();
				tmp = line.split(" ");
				N = Integer.valueOf(tmp[0]);
				X = Integer.valueOf(tmp[1]);
				Y = Integer.valueOf(tmp[2]);
				dx = new int[N];
				dy = new int[N];
				System.out.println("C#" + c + ": " + line);
				possibility = handler(N, 0, dx, dy, -2, 0, 0, 1.0f, X, Y);
				System.out.println(possibility);
				out.write("Case #" + c + ": " + possibility + "\n");
			}
			in.close();
			out.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

}
