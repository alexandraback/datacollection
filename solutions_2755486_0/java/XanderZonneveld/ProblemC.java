import java.io.File;
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.Scanner;


public class ProblemC {
	public static void main(String[] args) throws FileNotFoundException {
		Scanner sc = new Scanner(new File("C-small-attempt1.in"));
//		Scanner sc = new Scanner(new File("C-large.in"));
//		Scanner sc = new Scanner(new File("C.in"));
		int n = sc.nextInt();
		int count = 1;
		
		while(n --> 0) {
			int succesfullAttacks = 0;
			int day = 0;
			int numTribes = sc.nextInt();
			int[] startDay = new int[numTribes];
			int[] numAttacks = new int[numTribes];
			int[] westPoint = new int[numTribes];
			int[] eastPoint = new int[numTribes];
			int[] strength = new int[numTribes];
			int[] delay = new int[numTribes];
			int[] distance = new int[numTribes];
			int[] change = new int[numTribes];
			int[] wall = new int[500];
			int[] tempWall = new int[500];
			Arrays.fill(tempWall, 0);
			int numberOfAttacks = 0;
			
			for(int i = 0; i < numTribes; i++) {
				startDay[i] = sc.nextInt();
				numAttacks[i] = sc.nextInt();
				westPoint[i] = sc.nextInt();
				eastPoint[i] = sc.nextInt();
				strength[i] = sc.nextInt();
				delay[i] = sc.nextInt();
				distance[i] = sc.nextInt();
				change[i] = sc.nextInt();
				numberOfAttacks += numAttacks[i];
			}
			
			while(numberOfAttacks > 0) {
//				System.out.println(day);
				for(int i = 0 ; i < wall.length; i++)
					wall[i] = tempWall[i];
				for(int i = 0; i < numTribes; i++) {
					if(numAttacks[i] > 0) {
						if(startDay[i] == day) {
							boolean success = false;
							for(int j = westPoint[i] + 250; j <= eastPoint[i] + 251; j++) {
//								System.out.println(i + "," + day);
//								System.out.println(wall[j] + "," + strength[i]);
								if(wall[j] < strength[i]) {
									success = true;
									if(tempWall[j] < strength[i])
										tempWall[j] = strength[i];
								}
							}
							if(success)
								succesfullAttacks++;
							startDay[i] += delay[i];
							numAttacks[i]--;
							numberOfAttacks--;
							westPoint[i] += distance[i];
							eastPoint[i] += distance[i];
							strength[i] += change[i]; 
						}
					}
				}
				day++;
			}
			
			System.out.println("Case #" + count + ": " + succesfullAttacks);
			count++;
		}
	}
}
;