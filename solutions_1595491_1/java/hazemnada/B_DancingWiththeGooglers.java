import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class B_DancingWiththeGooglers {
	public static void main(String[] args) throws FileNotFoundException {
		Scanner sc = new Scanner(new File("file2.in"));
		PrintWriter writer = new PrintWriter(new File("file2.out"));
		int t = sc.nextInt();
		for (int i = 1; i <= t; i++) {
			int n = sc.nextInt();
			int s = sc.nextInt();
			int p = sc.nextInt();
			int[] a = new int[n];
			for (int j = 0; j < n; j++)
				a[j] = sc.nextInt();

			int min1 = p - 1 + p - 1 + p;
			int min2 = p - 2 + p - 1 + p - 1;
			int count = 0;
			for (int j = 0; j < n; j++)
				if (a[j] >= p) {
					if (a[j] >= min1)
						count++;
					else {
						if (a[j] >= min2 && s > 0) {
							s--;
							count++;
						}
					}
				}
			writer.println("Case #" + i + ": " + count);
		}
		writer.close();
	}
}
