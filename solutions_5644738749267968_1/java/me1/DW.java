import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Scanner;
import java.util.TreeSet;

public class DW {

	public static void main(String[] args) throws FileNotFoundException {
		PrintStream out = new PrintStream("output.txt");
//		PrintStream out = System.out;

		Scanner scanner = new Scanner(new File("D-large.in"));

		int cases = scanner.nextInt();
		for (int casen = 1; casen <= cases; casen++) {
			out.print("Case #" + casen + ": ");

			int n = scanner.nextInt();
			TreeSet<Double> A = new TreeSet<Double>();
			TreeSet<Double> B = new TreeSet<Double>();
			TreeSet<Double> A2 = new TreeSet<Double>();
			TreeSet<Double> B2 = new TreeSet<Double>();
			
			for (int i=0;i<n;i++) {
				double tmp = scanner.nextDouble();
				A.add(tmp);
				A2.add(tmp);
			}
			for (int i=0;i<n;i++) {
				double tmp = scanner.nextDouble();
				B.add(tmp);
				B2.add(tmp);
			}
			
			int score2 = 0; 
			for (int i=0;i<n;i++) {
				if (A2.last() > B2.last()) {
					score2++;
					A2.remove(A2.last());
					B2.remove(B2.first());
				} else {
					A2.remove(A2.last());
					B2.remove(B2.last());
				}
			}
			
			int score = 0;
			for (int i=0;i<n;i++) {
				if (A.last() < B.last()) {
					A.remove(A.first());
					B.remove(B.last());
				} else {
					score++;					
					A.remove(A.last());
					B.remove(B.last());
				}
			}
				
			out.print(score+" "+score2);
			
			out.println();
		}
		scanner.close();
	}

}