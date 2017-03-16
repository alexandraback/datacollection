import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.util.Scanner;

public class B {
	// static PrintStream writer = System.out;
	public static int[][] a;
	public static int[] count;
	public static int n;

	public static void main(String[] args) throws FileNotFoundException, UnsupportedEncodingException {
		Scanner sc = new Scanner(new File("./src/B-small-attempt1.in"));
		int t = sc.nextInt();
		PrintWriter writer = new PrintWriter("./src/B-small-attempt1.out", "UTF-8");

		for (int k = 1; k <= t; k++) {
			a = new int[60][120];
			count = new int[3000];
			for (int i = 0; i < 3000; i++)
				count[i] = 0;
			writer.print("Case #" + k + ":");
			n = sc.nextInt();
			for (int i = 0; i < 2 * n - 1; i++) {
				for (int j = 0; j < n; j++) {
					a[i][j] = sc.nextInt();
					count[a[i][j]]++;
				}
			}
			for (int i = 0; i < 3000; i++)
				if (count[i] % 2 == 1)
					writer.print(" " + i);
			writer.println();
		}

		writer.close();
		sc.close();
	}

	private static void swap(int x, int y) {
		// TODO Auto-generated method stub
		for (int i = 0; i < n; i++) {
			int tmp = a[x][i];
			a[x][i] = a[y][i];
			a[y][i] = tmp;
		}
	}
}
