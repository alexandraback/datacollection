import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.Scanner;

public class ProblemB {
	public static void main(String[] args) throws FileNotFoundException {
		PrintStream out = new PrintStream(new FileOutputStream(new File(
				"b-large.out")));
		Scanner in = new Scanner(new File("B-large.in"));

		int T = in.nextInt();

		for (int i = 1; i <= T; i++) {
			int N = in.nextInt();
			int S = in.nextInt();
			int p = in.nextInt();

			int defCount = 0;
			int surpCount = 0;
			for (int j = 0; j < N; j++) {
				int t = in.nextInt();

				if (t % 3 == 0) { // (1,1,1) <-> (0,1,2)
					if (t / 3 >= p)
						defCount++;
					else if (t / 3 >= p - 1 && t / 3 >= 1) // (0,0,0) cannot change
						surpCount++;
				}
				if(t % 3 == 1){ // (0,0,1) -> no way to increase max score
					if(t / 3 >= p - 1) // int div
						defCount++;
				}
				if(t % 3 == 2){ // (0,1,1) <-> (0,0,2)
					if(t / 3 >= p - 1) // int div
						defCount++;
					else if(t / 3 >= p - 2)
						surpCount++;
				}
				
				//System.out.printf("total: %d, avg: %d, dC: %d, sC: %d\n", t, t/3, defCount, surpCount);
			}
			
			out.printf("Case #%d: %d\n", i, defCount + Math.min(surpCount, S));
			
			//System.out.printf("\n\n");
		}

		in.close();
		out.close();
	}
}
