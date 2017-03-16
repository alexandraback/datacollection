import java.util.*;

public class KingdomRush {
	public static void main( String [] args ) {
		Scanner scan = new Scanner(System.in);
		int tc = scan.nextInt();
		for(int k = 0; k<tc; k++ ) {
			int levels = scan.nextInt();
			int [][] stat = new int [levels][3];
			//first column is a check for if it has been completed
			//second column is the number of stars needed to get 1
			//third column is the number of stars needed to get 2
			for(int j = 0; j<levels; j++) {
				int one = scan.nextInt();
				int two = scan.nextInt();
				stat[j][0] = 0;
				stat[j][1] = one;
				stat[j][2] = two;
			}
			//array is now filled in with the data needed to solve
			int stars = 0;						//counter for how many stars we have
			int plays = 0;
			boolean foundOne = true;
			while(stars < levels*2) {
				//find the two stars
					for(int i = 0; i<levels; i++) {
						if( stat[i][0] <= 1 && stat[i][2] <= stars) {
							stars += 2 - stat[i][0];
							stat[i][0] = 2;
							plays++;
							i = -1;					//redo the first loop
						}
					}
					
					if(levels*2 == stars) {
						//System.out.println("Got here");
						break;
					}
					
					int bestChoice = -1;
					for(int i = 0; i<levels; i++) {
						if( stat[i][0] == 0 && stat[i][1] <= stars  && stars != levels*2) {
							if(bestChoice == -1) {
								bestChoice = i;
							}
							else if( stat[bestChoice][2] < stat[i][2] && stars != levels*2 ) {
								//use the new one instead
								bestChoice = i;
							}
						}
					}
					if(bestChoice != -1 && stars !=2*levels ) {
						stars += 1;
						stat[bestChoice][0] = 1;
						plays++;
						//now redo the whole thing
					}
					else if( stars != 2*levels) {
						System.out.println("Case #" + (k+1) + ": Too Bad");
						break;
					}								
			}
			if ( stars == levels*2 ) {
				System.out.println("Case #" + (k+1) + ": " + plays);
			}
		}
	}
}	
