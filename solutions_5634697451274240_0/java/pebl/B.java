package codejam.f2016;

import java.util.Scanner;

public class B {

	private static void handleCase(int nr, Scanner scanner) {
		String s = scanner.nextLine();
		
		int swaps = 0;
		boolean swapped = false;		
		for(int i=s.length()-1; i>=0; i--) {
			char p = s.charAt(i);
			if (swapped ^ (p == '+'))
				continue;
			swapped = !swapped;
			swaps++;
		}
		
		System.out.println("Case #"+nr+": "+swaps);
	}
	
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int cases = scanner.nextInt();
		scanner.nextLine();
		
		for(int i=0;i<cases; i++)
			handleCase(i+1,scanner);
	}
}
