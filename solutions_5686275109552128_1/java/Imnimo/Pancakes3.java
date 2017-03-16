import java.io.File;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;


public class Pancakes3 {
	public static void main(String[] args) throws Exception {
			
		Scanner s = new Scanner(new File("B-large.in"));
		
		int numCases = Integer.parseInt(s.nextLine());
		for(int currentCase = 1;currentCase<=numCases;currentCase++) {
			int numDiners = Integer.parseInt(s.nextLine());
			String plateSizes = s.nextLine();
			String[] platesStrings = plateSizes.split("\\s+");
			ArrayList<Integer> plates = new ArrayList<Integer>();
			for(int i = 0;i<numDiners;i++) {
				plates.add(Integer.parseInt(platesStrings[i]));
			}
			//System.out.println(plates);
			System.out.println("Case #" + currentCase + ": " + solve(plates));
		}
		

	}
	public static int solve(ArrayList<Integer> plates) {
		Collections.sort(plates);
		int largest = plates.get(plates.size()-1);
		int best = Integer.MAX_VALUE;
		for(int max = largest;max>=1;max--) {
		//	System.out.println("Splitting to less than or equal to " + max);
			int splits = 0;
			for(Integer i : plates) {
				splits+=Math.ceil(i/(max+0.0))-1;
			}
			//System.out.println("Takes " + splits + " splits");
			int total = splits + max;
			if(total<best) best = total;
		}
		return best;
	}
}
