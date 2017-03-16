import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.PrintStream;
import java.util.HashSet;
import java.util.Scanner;

// Qualification Round 2012
// Problem C

public class RecycledNumbers {

	public static void main(String[] args) {
		Scanner sc = null;
		try {
			sc = new Scanner(new File("C-small.in"));
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}

		PrintStream output = null;

		try {
			output = new PrintStream(new File("C-small.out"));
		} catch (IOException e) {
			e.printStackTrace();
		}

		int cases = sc.nextInt();
		sc.nextLine();

		for(int c = 0; c < cases; c++){
			int A = sc.nextInt();
			int B = sc.nextInt();
			HashSet<String> pairs = new HashSet<String>(); 

			for(int n = A; n <= B; n++){
				String testn = n + "";
				String testm = testn;
				int l = testn.length();

				for(int i = 0; i < l - 1; i++){
					testm = testm.charAt(l - 1) + testm.substring(0, l - 1);
					int m = Integer.parseInt(testm);
					if(n < m && m <= B && m > A){
						pairs.add(n + " " + m);
					}
				}

			}
			
			System.out.printf("Case #%d: %s\n", c + 1, pairs.size());
			output.printf("Case #%d: %s\n", c + 1, pairs.size());
		}
	}
}
