package round1c;

import java.util.Scanner;

public class BrattleShip {
	
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		
		for(int zz = 1; zz <= T;zz++){

			int R = in.nextInt();
			int C = in.nextInt();
			int W = in.nextInt();
			
			int count = getMinCount(R,C,W);
			
						
			System.out.format("Case #%d: %d\n", zz, count);
		}		
	}
	
	static int getMinCount(int r, int c, int w) {
		int count = 0;
		
		if (w == 1) {
			return r*c;
		}
		
		if (r == 1) {
			//miss and one hit
			count = c/w;
			
			if (c%w == 0) {
				count += w-1;
			} else {
				count += w;
			}		
			return count;
		} else {
			//miss and one hit
			count = r * (c/w);
			
			if (c%w == 0) {
				count += w-1;
			} else {
				count += w;
			}		
			return count;
		}		
	}
	
}
