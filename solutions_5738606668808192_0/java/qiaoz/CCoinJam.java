import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;

public class CCoinJam {
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
		int T = sc.nextInt();
		for (int i = 1; i <= T; i++) {
			int N = sc.nextInt();
			int J = sc.nextInt();
			System.out.println("Case #" + i + ":");
			for (int j = 0; j < J; j++) {
				String s = Integer.toBinaryString(j);
				int dec = Integer.parseInt(s);
				s = String.format("%0" + (N/2 - 2) + "d", dec);
				s = "1" + s + "1";
				String t = s + s;
				System.out.print(t);
				for (int k = 2; k <= 10; k++) {
					System.out.print(" " + Integer.parseInt(s, k));
				}
				System.out.println();
			}
			
		}
		sc.close();
	}
}
