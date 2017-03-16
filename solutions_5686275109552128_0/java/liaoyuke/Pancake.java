import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;


public class Pancake {
	
	private static int ans = Integer.MAX_VALUE;
	
	public static void main(String[] args) throws FileNotFoundException {
		
		Scanner scanner = new Scanner(new File("B-small-attempt3.in"));
		PrintWriter pw = new PrintWriter("B-small-attempt3-Out.txt");
		int numCase = scanner.nextInt();
		int[] arrVal = new int[10];
		int[] arrSplit = new int[10];
		for (int c = 1; c <= numCase; c++) {
			ans = Integer.MAX_VALUE;
			int d = scanner.nextInt();
			for (int i = 0; i < d; i++) {
				
				int p = scanner.nextInt();
				arrVal[i] = p;
			}
			calcRst(arrVal, d, 0, arrSplit);
			pw.println("Case #" + c + ": " + ans);
		}
		pw.flush();
		pw.close();
	}
	
	public static void calcRst(int[] arrVal, int d, int step, int[] arrSplit) {
		
		if (step == d) {
			
			int tmpAns = 0;
			int upper = -1;
			for (int i = 0; i < d; i++) {
				
				tmpAns += arrSplit[i] - 1;
				upper = Math.max(upper, getUpper(arrVal[i], arrSplit[i]));
			}
			tmpAns += upper;
			ans = Math.min(ans, tmpAns);
		}
		else {
			
			for (int i = 1; i <= arrVal[step]; i++) {
				
				arrSplit[step] = i;
				calcRst(arrVal, d, step + 1, arrSplit);
			}
		}
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