import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class MainClass {

	/**
	 * @param args
	 */
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(new File("C-small-attempt0.in"));
		PrintWriter out = new PrintWriter(new File("RecycledNumbers.out"));

		int N = sc.nextInt();
		for (int i = 0; i < N; i++) {
			int A = sc.nextInt();
			int B = sc.nextInt();
			String s1, s2;
			int count = 0;
			for (int j = B; j > A; j--) {
				for (int k = A; k < j; k++) {
					s1 = "" + k;
					s2 = "" + j;
					s1 = s1 + s1;
					if (s1.contains(s2)) {
						count++;
					}

				}
			}
			out.println("Case #" + (i + 1) + ": " + count);
		}
		out.close();

	}

}
