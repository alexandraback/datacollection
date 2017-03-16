package codejam.CJ2015;

import java.util.Scanner;

public class QRD {

/*	private static int gcd(int a, int b){
		if(a<0) a = -a;
		if(b<0) b = -b;
		int r = b;
		if(a<b){
			b = a;
			a = r;
			r = b;
		}
		while (r>0){
			r = a % b;
			a = b;
			b = r;
		}
		return a;
	}*/
	
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		int t = in.nextInt();
		for(int i=1; i<=t; i++){
			int x = in.nextInt();
			int r = in.nextInt();
			int c = in.nextInt();
			if(r>c){
				int temp = r;
				r = c;
				c = temp;
			}
			
			boolean result = true;
			
			if(x==1) result = true;
			else if(x>c) result = false; // can make a line piece that never fits
			else if((r*c)%x!=0) result = false; // grid dimensions not compatible with piece sizes
			else if(x>=7) result = false; // can make a hole in the piece
			else if(x>2*r) result = false; // can make a piece wider than r in both dimensions
			//else if((r==c)&&(x==2*r)) result = false; // can make a piece wider than both r and c in one of the dimensions - line piece is a stronger condition
			else if(x>=2*r-1){ //can make a piece r-wide in both directions, that will disconnect the grid
				//only way is to take advantage of divisibility issues, i.e., disrupting both sides no matter how much we slide the piece either way
				if(x==4) result = false; //in this case, r must be 2 and we already know we can make odd on both sides
				else if(x==5){ //only way is r=3, best pieces only separate 1-3 or 2-2 (RICH controls that). 2-2 not good
					if(c==5) result = false; // RICH chooses 1-3 piece
				} else if(x==6) result = false; //only way is r=3. RICH can force piece's direction. c is at least 6. Can always do 2-4 and 2+r*k is never multiple of x
			}
			
			System.out.print("Case #" + i + ": ");
			if(result) System.out.print("GABRIEL");
			else System.out.print("RICHARD");
			System.out.println();
		}
		
		in.close();
	}
}
