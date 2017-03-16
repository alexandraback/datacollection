package jam2015.round1c.a;

import java.util.Scanner;

public class A {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int T = scanner.nextInt();
		
		for(int i = 0; i<T; i++) {
			int R = scanner.nextInt();
			int C = scanner.nextInt();
			int W = scanner.nextInt();
			
			int offset = (C/W);
			int score = offset * R + W;
			
			if(W == 1 || C%W == 0) {
				score--;
			}
			
			System.out.println(String.format("Case #%d: %d", i+1, score));
		}
		
	}
	
}
