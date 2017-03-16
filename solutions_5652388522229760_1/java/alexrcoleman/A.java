import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Scanner;

public class A {
	public static void main(String[] args) throws FileNotFoundException {
		Scanner scan = new Scanner(new FileInputStream(new File("A.in")));
		PrintWriter out = new PrintWriter(new FileOutputStream(new File("A.out")));
		int T = scan.nextInt();
		for (int t = 1; t <= T; t++) {
			long n = scan.nextInt();
			String ans = "INSOMNIA";
			if (n != 0) {
				boolean[] visited = new boolean[10];
				long cur = n;
				for (int iter = 0; iter <= 100_000; iter++) {
					cur = n * (iter + 1);
					while (cur > 0) {
						visited[(int) (cur % 10)] = true;
						cur /= 10;
					}
					boolean done = true;
					for (int i = 0; i < visited.length; i++) {
						if (!visited[i]) {
							done = false;
							break;
						}
					}
					if (done) {
						ans = (n * (iter + 1)) + "";
						break;
					}
				}
			}

			out.printf("Case #%d: %s%n", t, ans);
		}
		scan.close();
		out.close();
	}
}
