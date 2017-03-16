import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;


public class Q2DancingWithGooglers {

	public static void main(String[] args) throws IOException {
		
		Scanner scanner = new Scanner(new File("q2.input"));
		
		FileWriter writer = new FileWriter("q2.output");
		
		int cases = scanner.nextInt();
		
		for (int i = 1; i <= cases; i++) {
			
			int n = scanner.nextInt();
			int s = scanner.nextInt();
			final int p = scanner.nextInt();
			
			List<Integer> cantBeSurprising = new ArrayList<Integer>(n);
			List<Integer> canBeSurprising = new ArrayList<Integer>(n);
			
			for (int j = 0; j < n; j++) {
				int t = scanner.nextInt();
				if (canBeSurprising(t)) {
					canBeSurprising.add(t);
				} else {
					cantBeSurprising.add(t);
				}
			}
			
			Collections.sort(canBeSurprising, new Comparator<Integer>() {

				@Override
				public int compare(Integer o1, Integer o2) {
					return getPriority(o1).compareTo(getPriority(o2));
				}

				private Integer getPriority(Integer o1) {
					if (getSurprisingP(o1) >= p && getNormalP(o1) < p) {
						return 0;
					}
					
					if (getSurprisingP(o1) >= p) {
						return 1;
					}
					
					return 2;
				}
			});
			
			int response = 0;
			
			for (int j = 0; j < s; j++) {
				if (getSurprisingP(canBeSurprising.get(j)) >= p) {
					response++;
				}
			}
			
			for (int j = s; j < canBeSurprising.size(); j++) {
				if (getNormalP(canBeSurprising.get(j)) >= p) {
					response++;
				}
			}
			
			for (Integer t : cantBeSurprising) {
				if (getNormalP(t) >= p) {
					response++;
				}
			}
			
			writer.write("Case #" + i + ": " + response + "\n");
		}
		
		writer.close();
		
	}
	
	
	
	private static boolean canBeSurprising(int n) {
		if (n == 30 || n == 0 || n == 29) {
			return false;
		}
		return true;
	}
	
	private static Integer getSurprisingP(int n) {
		if (n % 3 <= 1) {
			return n / 3 + 1;
		}
		if (n % 3 == 2) {
			return n / 3 + 2;
		}
		
		return 0;
	}
	
	private static Integer getNormalP(int n) {
		if (n % 3 == 0) {
			return n / 3;
		}
		return n / 3 + 1;
	}
	
}
