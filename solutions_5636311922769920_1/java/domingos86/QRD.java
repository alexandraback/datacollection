package codejam.CJ2016.QR;

import java.util.Scanner;

public class QRD {

	
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		int t = in.nextInt();
		for(int i=1; i<=t; i++){
			
			int k = in.nextInt();
			int c = in.nextInt();
			int s = in.nextInt();
			
			System.out.print("Case #" + i + ":");
			
			if (s<(k+c-1)/c) {
				System.out.println(" IMPOSSIBLE");
			} else {
				int order = 1;
				long base = 1;
				long pos = 1;
				int tilesCovered = 0;
				
				while (tilesCovered < k) {
					pos += tilesCovered*base;
					tilesCovered++;
					if (order == c) {
						System.out.print(" " + pos);
						base = 1;
						pos = 1;
						order = 1;
					} else {
						base *= k;
						order++;
					}
				}
				if (order > 1) {
					System.out.print(" " + pos);
				}
				System.out.println();
			}
		}
		
		in.close();
	}
}
