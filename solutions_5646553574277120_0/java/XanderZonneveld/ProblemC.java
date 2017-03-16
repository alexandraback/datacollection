import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;


public class ProblemC {
	public static void main(String[] args) throws FileNotFoundException {
		Scanner sc = new Scanner(new File("C-small-attempt1.in"));
//		Scanner sc = new Scanner(new File("C-large.in"));
//		Scanner sc = new Scanner(new File("C.in"));
		int cases = sc.nextInt();
		int count = 1;
		
		
//		System.out.println(Integer.toBinaryString(16));

		while(cases --> 0) {
			int C = sc.nextInt();
			int D = sc.nextInt();
			int V = sc.nextInt();
			int[] preexisting = new int[D];

			int newCoins = 0;
			
			if(V <= 1) {
				newCoins = 1;
			} else if(V <= 3) {
				newCoins = 2;
			} else if(V <= 7) {
				newCoins = 3;
			} else if(V <= 15) {
				newCoins = 4;
			} else  {
				newCoins = 5;
			}
			
			for (int i = 0; i < D; i++) {
				preexisting[i] = sc.nextInt();
				
				if(preexisting[i] == 1) {
					newCoins--;
				} else if(preexisting[i] == 2) {
					newCoins--;
				} else if(preexisting[i] == 4) {
					newCoins--;
				} else if(preexisting[i] == 8) {
					newCoins--;
				} else if(preexisting[i] == 16) {
					newCoins--;
				}
			}
			
			System.out.println("Case #" + count + ": " + newCoins);
			
			count++;
		}
		
		sc.close();
	}
}