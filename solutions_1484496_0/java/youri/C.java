import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.HashSet;

public class C {

	public static void main(String[] args) {

		BufferedReader f = null;
		PrintWriter out = null;
		try {
			f = new BufferedReader(new FileReader("in.txt"));
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		try {
			out = new PrintWriter(new BufferedWriter(new FileWriter("out.txt")));
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		try {

			// SOLUTION STARTS HERE

			int T = new Integer(f.readLine());
			for (int k = 1; k <= T; k++) {
				HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
				String s = f.readLine();
				String num[] = s.split(" ");
				int N = new Integer(num[0]);
				int con[] = new int[num.length - 1];
				for (int i = 1; i < num.length; i++)
					con[i - 1] = new Integer(num[i]);

				boolean found = false;
				int mask_s = 1 << N;
				for (int i = 0; i < mask_s; i++) {
					int m = i;
					int st = calc(m, con);
					if (map.containsKey(st)) {
						out.write("Case #" + k + ":\n");
						System.out.print("Case #" + k + ":\n");

						print(m, con, out);
						out.write("\n");
						System.out.println();
						
						print(map.get(st), con, out);

						//
						//
						out.write("\n");
						System.out.println();
						found = true;
						break;
					} else
						map.put(st, m);
					// System.out.println(st);

				}
				if (!found) {

					out.write("Case #" + k + ": \nImpossible");
					System.out.print("Case #" + k + ":\nImpossible");

					out.write("\n");
					System.out.println();
				}

			}

			// SOLUTION ENDS HERE

			out.flush();
			out.close();
			f.close();

		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

	}

	private static void print(int m, int[] con, PrintWriter out) {
		int k = 0;
		do {
			if ((m & 1) == 1) {
				System.out.print(con[k] + " ");
				out.write(con[k] + " ");
			}
			k++;
			m >>= 1;
		} while (m > 0);

	}

	private static int calc(int m, int[] con) {
		int sum = 0;
		int k = 0;
		do {
			if ((m & 1) == 1) {
				sum += con[k];
			}

			k++;
			m >>= 1;
		} while (m > 0);

		return sum;
	}
}
