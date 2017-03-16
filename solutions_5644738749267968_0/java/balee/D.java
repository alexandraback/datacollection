import java.io.FileInputStream;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Locale;
import java.util.Scanner;

// Deceitful War
// https://code.google.com/codejam/contest/2974486/dashboard#s=p3

public class D {

	private static String process(Scanner in) {
		int N = in.nextInt();
		//System.out.println("N: " + N);
		in.useLocale(Locale.US);
		ArrayList<Double> naomi = new ArrayList<Double>();
		ArrayList<Double> ken = new ArrayList<Double>();
		for(int i = 0; i < N; i++)
			naomi.add(in.nextDouble());		
		for(int i = 0; i < N; i++)
			ken.add(in.nextDouble());
		Collections.sort(naomi);
		Collections.sort(ken);
		//System.out.println(Util.dump(naomi));
		//System.out.println(Util.dump(ken));
		ArrayList<Double> kenSave = new ArrayList<Double>(ken);
		int naomiWarScore = 0;
		int naomiDecitfulScore = 0;
		// war
		for(int step = 0; step < N; step++) {
			double n = naomi.get(step);
			for(int i = 0; i < ken.size(); i++) {
				if ( ken.get(i) > n ) {
					ken.remove(i);
					n = -1;
					break;
				}
			}
			if ( n > 0 ) {
				ken.remove(0);
				naomiWarScore++;
			}
		}
		// decitful
		ken = kenSave;
		for(int step = 0; step < N; step++) {
			if ( naomi.get(0) < ken.get(0) ) {
				ken.remove(ken.size() - 1);
				naomi.remove(0);
			} else {
				naomiDecitfulScore++;
				ken.remove(0);
				naomi.remove(0);
			}
		}
		return Integer.toString(naomiDecitfulScore) + " " + Integer.toString(naomiWarScore);
	}

	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(System.in.available() > 0 ? System.in : 
			new FileInputStream(Thread.currentThread().getStackTrace()[1].getClassName() + ".practice.in"));
		int T = in.nextInt();
		for(int i = 1; i <= T; i++) 
			System.out.format("Case #%d: %s\n", i, process(in));
	}
}
