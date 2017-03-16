import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;


public class Dancing {
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(new FileReader("dancing.in"));
		PrintWriter out = new PrintWriter(new FileWriter("DancingAsmall.out"));
		
		int numCases = sc.nextInt();
		int count = 0;

		for (int i = 0; i < numCases; i++) {
			int numGooglers = sc.nextInt();
			int numSurprising = sc.nextInt();
			int p = sc.nextInt();
			count = 0;
			
			for (int j = 0; j < numGooglers; j++) {
				int thisGoogler = sc.nextInt();
				if (thisGoogler == 0 && p != 0) {
					continue;
				}
				else if (thisGoogler >= 3 * p - 2) {
						count++;
				}
				else if (numSurprising > 0 && thisGoogler >= (3 * p - 4))  {
							count++;
							numSurprising--;
				}				
			}
			out.println("Case #" + (i + 1) + ": " + count);
		}
		out.close();
	}
}
