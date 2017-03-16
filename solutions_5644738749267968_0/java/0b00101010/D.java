import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class D {
	private static PrintStream outfile;
	public static void main(String[] args) throws FileNotFoundException {
		Scanner scan = new Scanner(System.in);
		outfile = new PrintStream("D-small.out.txt");

		ArrayList<Double> naomi = new ArrayList<Double>();
		ArrayList<Double> ken = new ArrayList<Double>();
		
		int cases = scan.nextInt();
		int n, normal, deceitful, i, j;
		for (int c = 1; c <= cases; c++) {
			naomi.clear();
			ken.clear();
			n = scan.nextInt();
			for (i = 0; i < n; i++)
				naomi.add(scan.nextDouble());
			for (i = 0; i < n; i++)
				ken.add(scan.nextDouble());
			
			Collections.sort(naomi);
			Collections.sort(ken);
			for (i = 0, j = 0; j < n; i++, j++) {
				while (j < n && naomi.get(i) > ken.get(j)) {
					j++;
				}
			}
			normal = j - i;
			
			deceitful = 0;
			for (j = n-1; j >= 0; j--) {
				if (naomi.remove(0) > ken.get(0)) {
					deceitful++;
					ken.remove(0);
				} else {
					ken.remove(j);
				}
			}
			
			println("Case #" + c + ": " + deceitful + " " + normal);
		}
		outfile.close();
	}
	
	private static void println(String str) {
		outfile.println(str);
		System.out.println(str);
	}
}
