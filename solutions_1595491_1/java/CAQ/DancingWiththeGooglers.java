import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Scanner;

public class DancingWiththeGooglers {
	final static String FILENAME = "B-large";

	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(new FileReader("/home/workshop/Documents/"
				+ FILENAME + ".in"));
		BufferedWriter bw = new BufferedWriter(new FileWriter(
				"/home/workshop/Documents/" + FILENAME + ".out"));
		int T = sc.nextInt();
		sc.nextLine();
		for (int ttt = 0; ttt < T; ttt++) {
			int N = sc.nextInt();
			int S = sc.nextInt();
			int p = sc.nextInt();

			int s = S, count = 0;
			for (int n = 0; n < N; n++) {
				int t = sc.nextInt();
				switch (t % 3) {
				case 0:
					int z = t / 3; // z, z, z
					if (z >= p)
						count++;
					else if (s > 0 && z + 1 >= p && z - 1 >= 0 && z + 1 <= 10) {
						// z-1, z, z+1 (*)
						count++;
						s--;
					}
					break;
				case 1:
					int x = (t - 1) / 3; // x, x, x+1
					if (x + 1 >= p)
						count++;
					break;
				case 2:
					int y = (t - 2) / 3; // y, y+1, y+1
					if (y + 1 >= p)
						count++;
					else if (s > 0 && y + 2 >= p && y + 2 <= 10) {
						// y, y, y+2 (*)
						count++;
						s--;
					}
					break;
				}
			}

			bw.write("Case #" + (ttt + 1) + ": " + count);
			bw.newLine();
		}
		bw.close();
		sc.close();
	}

}
