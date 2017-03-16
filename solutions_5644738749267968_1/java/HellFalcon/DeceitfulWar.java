import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Scanner;

public class DeceitfulWar {
	public static void main(String[] args) {
		try {
			Scanner in = new Scanner(new BufferedReader(new FileReader(new File("D-large.in")), 256 << 10));
			PrintStream out = new PrintStream(new File("output.txt"));

			int testsNumber = in.nextInt();
			for (int testId = 1; testId <= testsNumber; testId++) {
				out.print("Case #" + testId + ": ");
				int n = in.nextInt();
				double[] naomi = new double[n];
				double[] ken = new double[n];
				for (int i = 0; i < n; i++) naomi[i] = Double.parseDouble(in.next());
				for (int i = 0; i < n; i++) ken[i] = Double.parseDouble(in.next());
				Arrays.sort(naomi);
				Arrays.sort(ken);

				int warScore = 0;
				for (int i = 0, j = 0; i < n & j < n; i++, j++) {
					while (j < n && naomi[i] > ken[j]) {
						warScore++;
						j++;
					}
				}
				
				int deceitfulWarScore = 0;
				for (int i = 0, j = 0; i < n; i++)
					if (naomi[i] > ken[j]) {
						deceitfulWarScore++;
						j++;
					}
				out.println(deceitfulWarScore+ " " + warScore);
			}
			in.close();
			out.close();
		}
		catch (Exception e) {
			System.err.println("Error:" + e.getMessage());
		}
	}

}
