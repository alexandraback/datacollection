import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;


public class Round1AProblemB {
	public static void main(String args[]) throws FileNotFoundException {
		Scanner scan = new Scanner(new File("input"));
		int cases = scan.nextInt();
		scan.nextLine();
		
		for (int i = 1; i <= cases; i++) {
			int levels = scan.nextInt();
			int stars[][] = new int[levels][2];
			for (int j = 0; j < levels; j++) {
				for (int k = 0; k < 2; k++) {
					stars[j][k] = scan.nextInt();
				}
			}
			
			int beaten = 0;
			int totalStars = 0;
			
			int oneStar = -1;
			int oneStarVal = -1;
			int oneStarSecondVal = -1;
			int oneSecondStar = -1;
			
			int startOver = levels-1;
			boolean done = false;
			
			while (!done) {
				for (int j = 0; j < levels; j++) {
					if (stars[j][1] <= totalStars) {
						if (stars[j][0] == Integer.MAX_VALUE) {
							oneSecondStar = j;
						
							if (startOver == j) {
								totalStars++;
								beaten++;
								stars[oneSecondStar][1] = Integer.MAX_VALUE;
								//System.out.println("a(" + oneSecondStar + ",1) " + totalStars + " " + beaten);
								oneStar = -1;
								oneStarVal = -1;
								oneStarSecondVal = -1;
								startOver = j;
								oneSecondStar = -1;
							}
							/*
							totalStars++;
							stars[j][1] = Integer.MAX_VALUE;
							oneStar = -1;
							oneStarVal = -1;
							oneStarSecondVal = -1;
							startOver = j;
							beaten++;
							//System.out.println("(" + j + ",1) " + totalStars + " " + beaten);
							 */
						} else {
							totalStars += 2;
							stars[j][0] = stars[j][1] = Integer.MAX_VALUE;
							oneStar = -1;
							oneStarVal = -1;
							oneStarSecondVal = -1;
							oneSecondStar = -1;
							startOver = j;
							beaten++;
							//System.out.println("b(" + j + ",0&1) " + totalStars + " " + beaten);
						}
					} else if (stars[j][0] <= totalStars) {
						if (stars[j][1] > oneStarSecondVal) {
							oneStar = j;
							oneStarVal = stars[j][0];
							oneStarSecondVal = stars[j][1];
						}
						
						if (startOver == j) {
							totalStars++;
							beaten++;
							stars[oneStar][0] = Integer.MAX_VALUE;
							//System.out.println("c(" + oneStar + ",0) " + totalStars + " " + beaten);
							oneStar = -1;
							oneStarVal = -1;
							oneStarSecondVal = -1;
							oneSecondStar = -1;
							startOver = j;
						}
					} else if (startOver == j) {
						if (oneSecondStar != -1) {
							totalStars++;
							beaten++;
							stars[oneSecondStar][1] = Integer.MAX_VALUE;
							//System.out.println("d(" + oneSecondStar + ",1) " + totalStars + " " + beaten);
							oneStar = -1;
							oneStarVal = -1;
							oneStarSecondVal = -1;
							startOver = j;
							oneSecondStar = -1;
						} else if (oneStar == -1) {
							done = true;
							break;
						} else {
							totalStars++;
							beaten++;
							stars[oneStar][0] = Integer.MAX_VALUE;
							//System.out.println("e(" + oneStar + ",0) " + totalStars + " " + beaten);
							oneStar = -1;
							oneStarVal = -1;
							oneStarSecondVal = -1;
							oneSecondStar = -1;
							startOver = j;
						}
					}
				}
			}
			
			if (totalStars < levels*2) {
				System.out.println("Case #" + i + ": Too Bad");
			} else {
				System.out.println("Case #" + i + ": " + beaten);
			}
		}
	}
}
