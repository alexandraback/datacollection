package codejam.CJ2016.QR;

import java.util.Scanner;

public class QRB {

	private static void flip(boolean[] stack, int depth) {
		System.err.println("flipping " + depth);
		if (depth <= 0) return;
		boolean temp;
		for (int j = 0; j <= (depth-1)/2; j++) {
			temp = !stack[j];
			stack[j] = !stack[depth-1-j];
			stack[depth-1-j] = temp;
		}
	}
	
	
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		int t = in.nextInt();
		in.nextLine();
		for(int i=1; i<=t; i++){
			
			String seq = in.nextLine().trim();
			System.err.println(seq);
			boolean[] pancakes = new boolean[seq.length()];
			for (int j = 0; j<seq.length(); j++) {
				pancakes[j] = seq.charAt(j)=='+';
			}
			int depth = seq.length();
			int flips = 0;
			while (depth > 0) {
				if (pancakes[depth-1]) {
					depth--;
					System.err.println("depth became " + depth);
				} else {
					int preFlip = 0;
					while (pancakes[preFlip]) {
						preFlip++;
					}
					if (preFlip > 0) {
						flip(pancakes, preFlip);
						flips++;
					}
					flip(pancakes, depth);
					flips++;
				}
			}
			
			
			System.out.print("Case #" + i + ": ");
			
			System.out.print(flips);
			
			System.out.println();
		}
		
		in.close();
	}
}
