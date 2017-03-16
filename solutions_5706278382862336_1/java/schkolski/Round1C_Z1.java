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
			long im = Long.parseLong(elf[0]);
			long br = Long.parseLong(elf[1]);

			long j = gcd(im, br);
			while(j != 1) {
				im /= j;
				br /= j;
				
				j = gcd(im,br);
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
	static long gcd(long a, long b)
	{
	  if(a == 0 || b == 0) return a+b; // base case
	  return gcd(b,a%b);
	}
	static boolean stepenNaDva(long x) {
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
