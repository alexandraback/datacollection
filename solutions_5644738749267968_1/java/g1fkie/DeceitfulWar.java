package codejam2014;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class DeceitfulWar {

	public static void main(String[] args) {

		File file = new File("C:\\Users\\Marco\\Desktop\\D-large.in");
		Scanner sc = null;
		int numCases = 0;

		try {
			sc = new Scanner(file);
			numCases = sc.nextInt();
		} catch (FileNotFoundException e) {
			System.out.println("Fehler beim Einlesen!");
			e.printStackTrace();
		}

		for (int caseNum = 1; caseNum <= numCases; caseNum++) {

			int N = Integer.parseInt(sc.next());
			double[] naomiMasses = new double[N];
			double[] kenMasses = new double[N];
			ArrayList<Double> forSort = new ArrayList<Double>();

			for (int i = 0; i < N; i++) {
				forSort.add(Double.parseDouble(sc.next()));
			}
			Collections.sort(forSort);
			int pnt = 0;
			for (Double d : forSort) {
				naomiMasses[pnt] = d;
				pnt++;
			}
			forSort.clear();

			for (int i = 0; i < N; i++) {
				forSort.add(Double.parseDouble(sc.next()));
			}
			Collections.sort(forSort);
			pnt = 0;
			for (Double d : forSort) {
				kenMasses[pnt] = d;
				pnt++;
			}

			int naomiWarPoints = 0;
			int naomiPnt = N-1;
			int kenPnt = N-1;
			int prev = 0;

			while (true) {

				if (naomiPnt < 0 || kenPnt < 0)
					break;
				
				if (naomiMasses[naomiPnt] > kenMasses[kenPnt]) {
					naomiPnt--;
					if (prev > 0)
						prev--;
					else 
						naomiWarPoints++;
				} else {
					kenPnt--;
					prev++;
				}
			}
			
			int naomiDWarPoints = 0;
			naomiPnt = 0;
			int kenFrontPnt = 0;
			int kenBackPnt = N-1;
			
			for (int i = 0; i < N; i++) {
				
				if (naomiMasses[naomiPnt] < kenMasses[kenFrontPnt]) {
					kenBackPnt--;
					naomiPnt++;
				} else {
					kenFrontPnt++;
					naomiPnt++;
					naomiDWarPoints++;
				}
			}
			
			System.out.println("Case #" + caseNum + ": " + naomiDWarPoints + " " + naomiWarPoints);
		}
	}
}
