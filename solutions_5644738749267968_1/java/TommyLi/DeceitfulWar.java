package qualification;

import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.NavigableSet;
import java.util.Scanner;
import java.util.TreeSet;

public class DeceitfulWar {

	public static void main(String[] args) {
		
		//tool.SubmissionHelper.injectIO("D-large");
		
		Scanner scanner = new Scanner(System.in);
		
		int numberOfCases = scanner.nextInt();
		
		for (int c = 0; c < numberOfCases; c++) {
			System.out.print("Case #" + (c+1) + ": ");
			
			int N = scanner.nextInt();
			TreeSet<Double> naomiSet = new TreeSet<Double>();
			TreeSet<Double> kenSet = new TreeSet<Double>();
			
			for (int n = 0; n < N; n++) {
				naomiSet.add(scanner.nextDouble());
			}
			for (int n = 0; n < N; n++) {
				kenSet.add(scanner.nextDouble());
			}
			
			int naomiNormalScore = 0;
			
			@SuppressWarnings("unchecked")
			NavigableSet<Double> kenSetNormal = (NavigableSet<Double>) kenSet.clone();
			for (double naomi : naomiSet) {
				if (naomi > kenSetNormal.last()) {
					naomiNormalScore++;
					double ken = kenSetNormal.first();
					kenSetNormal.remove(ken);
				} else {
					for (double ken : kenSetNormal) {
						if (ken > naomi) {
							kenSetNormal.remove(ken);
							break;
						}
					}
				}
			}
			
			int naomiCheatScore = 0;
			@SuppressWarnings({ "unchecked" })
			NavigableSet<Double> kenSetCheat = (NavigableSet<Double>) kenSet.clone();
			for (double naomi : naomiSet) {
				if (naomi < kenSetCheat.first()) {
					kenSetCheat.remove(kenSetCheat.last());
				} else {
					kenSetCheat.remove(kenSetCheat.first());
					naomiCheatScore++;
				}
				/*for (double ken : kenSetCheat) {
					if (naomi > ken) {
						naomiCheatScore++;
						break;
					}
				}*/
				
			}
			
			//System.out.println();
			//System.out.println(naomiSet);
			//System.out.println(kenSet);
			System.out.print(naomiCheatScore + " " + naomiNormalScore);
			System.out.println();
		}
	}

}
