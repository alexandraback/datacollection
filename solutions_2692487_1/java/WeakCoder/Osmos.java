package Round_1_B;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class Osmos {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Scanner in = null;
		PrintWriter out = null;
		try {
			in = new Scanner(new File("A-large.in"));
			out = new PrintWriter(new File("a_large.out"));
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		int cases = in.nextInt();
		for (int cas = 1; cas <= cases; cas++) {
			long A = in.nextLong();
			int N = in.nextInt();
			int[] motos = new int[N];
			for (int i=0; i<N; i++)
				motos[i] = in.nextInt();
			Arrays.sort(motos);
			out.println("Case #"+cas+": " + work(motos, 0, A));
			out.flush();
		}
	}

	public static int work(int[] motos, int start, long A) {
		if (start >= motos.length)
			return 0;
		for (int i=start; i<motos.length; i++) {
			//System.out.println(A);
			if (motos[i] < A) {
				A += motos[i];
			} else {
				long add = A-1;
				int remove_count = motos.length - i;
				if (add <= 0)
					return remove_count;
				else {
					//System.out.println(distance + "  to add " + (add * add_number));
					return Math.min(remove_count, 1 + work(motos, i, A+add));
				}
			}
		}
		return 0;
	}
}
