import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;


public class Pancake {
	
	public static void main(String[] args) throws FileNotFoundException {
		
		Scanner scanner = new Scanner(new File("B-large.in"));
		PrintWriter pw = new PrintWriter("B-large-Out.txt");
		int numCase = scanner.nextInt();
		for (int c = 1; c <= numCase; c++) {

			int d = scanner.nextInt();
			ArrayList<Integer> arrVal = new ArrayList<Integer>();
			for (int i = 0; i < d; i++) {
				int p = scanner.nextInt();
				arrVal.add(p);
			}
			int ans = calcRst(arrVal, d);
			pw.println("Case #" + c + ": " + ans);
		}
		pw.flush();
		pw.close();
	}
	
	public static int calcRst(ArrayList<Integer> arrVal, int d) {
		
		int ans = Integer.MAX_VALUE;
		int maxVal = Collections.max(arrVal);
		for (int val = 1; val <= maxVal; val++) {
			
			int cost = 0;
			for (int i = 0; i < arrVal.size(); i++) {
				
				int p = arrVal.get(i);
				if (p % val == 0) {
					
					cost += p / val - 1;
				}
				else {
					
					cost += p / val;
				}
			}
			cost += val;
			ans = Math.min(ans, cost);
		}
		
		return ans;
	}
	
	public static int getUpper(int x, int y) {
		
		if (x % y == 0) {
			
			return x / y;
		}
		else {
			
			return x / y + 1;
		}
	}
}