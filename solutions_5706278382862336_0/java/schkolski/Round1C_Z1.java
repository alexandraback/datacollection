import java.awt.Point;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Round1C_Z1 {
	static StringTokenizer st;
	static BufferedReader in = new BufferedReader(new InputStreamReader(
			System.in));
	static StringBuilder out;

	public static void main(String[] args) throws NumberFormatException,
			IOException {

		int T = Integer.parseInt(in.readLine());

		for (int i = 1; i <= T; i++) {
			out = new StringBuilder();
			out.append(print(i));

			String elf[] = in.readLine().split("/");
			int im = Integer.parseInt(elf[0]);
			int br = Integer.parseInt(elf[1]);

			for (int j = im; j >= 1; j--) {
				if (im % j == 0 && br % j == 0) {
					im /= j;
					br /= j;
				}
			}

			if (!stepenNaDva(br)) {
				out.append("impossible");
			} else {

				int step = 0;
				while (br % 2 == 0 && br >= im) {
					br /= 2;
					step++;
				}
				out.append(step);

			}
			System.out.println(out.toString());
		}

	}

	static boolean stepenNaDva(int x) {
		while (x % 2 == 0)
			x /= 2;
		if (x == 1)
			return true;
		return false;
	}

	static String print(int x) {
		return "Case #" + x + ": ";
	}
}
