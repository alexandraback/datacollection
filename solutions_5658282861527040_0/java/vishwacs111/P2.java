import java.io.*;
import java.util.*;

public class P2 {
	public static void main (String[] args) throws FileNotFoundException {
//		Scanner sc = new Scanner (System.in);
//		PrintStream op = System.out;
		Scanner sc = new Scanner (new FileInputStream ("D:\\Internet\\B-small-attempt0.in"));
		PrintStream op = new PrintStream ("output.txt");
		int T = sc.nextInt();
		for (int t = 1; t <= T; t++) {
			int A = sc.nextInt(), B = sc.nextInt(), K = sc.nextInt(), count = 0;
			for (int i = 0; i < A; i++) {
				for (int j = 0; j < B; j++) {
					int val = i & j;
					if (val < K)
						count++;
				}
			}
			op.println("Case #" + t + ": " + count);
		}
	}
}