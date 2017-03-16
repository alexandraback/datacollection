package pl.gg.codejam2015.roundQ.taskB;

import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class TaskB {
	
	private final static int MAX_CAKES = 10;
	
	private static int special[][] = new int[MAX_CAKES][MAX_CAKES];
	
	private static void initSpecial() {
		for (int cakes = 0; cakes < MAX_CAKES; cakes++) {
			for (int minutes = 0; minutes < MAX_CAKES; minutes++) {
				special[cakes][minutes] = 0;
			} 
		}
		
		for (int cakes = 0; cakes < MAX_CAKES; cakes++) {
			for (int minutes = 0; minutes < MAX_CAKES; minutes++) {
				if (minutes < cakes) {
					special[cakes][minutes] = Integer.MAX_VALUE;
					
					for (int i = 1; i < cakes; i++) {
						if (special[cakes][minutes] > special[i][minutes] + special[cakes - i][minutes] + 1) {
							special[cakes][minutes] = special[i][minutes] + special[cakes - i][minutes] + 1;
						}
					}
				}				
				//System.out.print(" " + special[cakes][minutes]);
			}
			
			//System.out.println("");
		}
	}
	
	private static int solve(List<Integer> diners) {
		int maxCakes = 0, result = Integer.MAX_VALUE;
		
		for (int i = 0; i < diners.size(); i++) {
			if (diners.get(i) > maxCakes) {
				maxCakes = diners.get(i);
			}
		}
		
		for (int minutes = 1; minutes <= maxCakes; minutes++) {
			int specialSum = 0;
			
			for (int i = 0; i < diners.size(); i++) {
				specialSum += special[diners.get(i)][minutes];
			}
			
			if (specialSum + minutes < result) {
				result = specialSum + minutes;
			}
			
			//System.out.println("  " + minutes + " " + specialSum);
		}

		return result;
	}
	
	public static void main(String[] args) throws FileNotFoundException {
		//System.setIn(TaskB.class.getResourceAsStream("B-small-attempt2.in"));
		//System.setOut(new PrintStream(new FileOutputStream("C:\\Users\\Grzegorz\\workspace_juno\\CodeJam2015\\src\\pl\\gg\\codejam2015\\roundQ\\taskB\\B-small-attempt2.out")));

		initSpecial();
		
		try (Scanner in = new Scanner(System.in)) {
			int nCases = in.nextInt();
			
			for (int i = 1; i <= nCases; i++) {
				int nDiners = in.nextInt();
				List<Integer> diners = new ArrayList<>(nDiners);
				
				for (int j = 0; j < nDiners; j++) {
					int cakes = in.nextInt();
					diners.add(cakes);
				}
				
				int res = solve(diners);
				
				System.out.println("Case #" + i + ": " + res);
			}
		}
	}
}
