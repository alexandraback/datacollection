package codejam.e2014;

import java.util.Arrays;
import java.util.Locale;
import java.util.Scanner;

public class D {

	private static double[] readHand(int N, Scanner scanner) {
		double[] handD = new double[N]; 
		for(int i=0; i<N; i++) {
			handD[i] = scanner.nextDouble();
		}
		Arrays.sort(handD);
		return handD;
	}

	private static void handleCase(int nr, Scanner scanner) {
		int N = scanner.nextInt();
		
		double[] naomi = readHand(N,scanner);
		double[] ken   = readHand(N,scanner);
		
		// 0.186 0.300 0.389 0.557 0.832 0.899 0.907 0.959 0.992
		// 0.215 0.271 0.341 0.458 0.520 0.521 0.700 0.728 0.916 
		
		int deceiveWar = 0;
		int lowKen = 0;
		int highKen = N-1;
		for(int i=0; i<N; i++) {
			if (naomi[i] < ken[lowKen]) {
				highKen--;
				continue;
			}
			deceiveWar++;
			lowKen++;
		}
		
		int war = 0;
		lowKen = 0;
		highKen = N-1;
		for(int i=N-1; i>=0; i--) {
			if (ken[highKen] < naomi[i]) {
				lowKen++;
				war++;
				continue;
			}
			highKen--;
		}
		
		System.out.println("Case #"+nr+": "+deceiveWar+" "+war);
	}

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in).useLocale(Locale.US);
		int cases = scanner.nextInt();
		
		for(int i=0;i<cases; i++)
			handleCase(i+1,scanner);
	}
}
