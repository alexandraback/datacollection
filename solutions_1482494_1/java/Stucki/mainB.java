import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;


public class mainB {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		try(Scanner sc = new Scanner(new File("./B-large.in"))) {
			System.setOut(new PrintStream(new File("B-large.out")));
			
			int T = sc.nextInt();
			
			for (int t = 1; t <= T; t++) {
				int N = sc.nextInt();
				int[] a = new int[N], b = new int[N];
				
				for (int i= 0; i < N; i++) {
					a[i] = sc.nextInt();
					b[i] = sc.nextInt();
				}			
				
				boolean[] a_passed = new boolean[N];
				boolean[] b_passed = new boolean[N];
				
				int stars = 0;
				int turn = 0;
				
				LOOP:
				while(true) {					
					LOOP_2_STARS:
					while(true) {
						for (int i = 0; i < N; i++) {
							if(!b_passed[i] && b[i]<=stars) {
								b_passed[i] = true;
								if(a_passed[i]) {
									stars++;
								} else {
									stars += 2;
									a_passed[i] = true;
								}
								turn++;
								continue LOOP;
							}		
						}
						break LOOP_2_STARS;
					}
				
					int max2stars = -1;
					for (int i = 0; i < N; i++) {
						if(!a_passed[i] && a[i]<=stars) {
							if(max2stars==-1 || b[i]>b[max2stars])
								max2stars = i;								
						}
					}					
					
					if(max2stars!=-1) {
						a_passed[max2stars] = true;
						stars++;
						turn++;
						continue LOOP;
					}
					
					break LOOP;
				}
				
				boolean tooBad = false;
				for (boolean u : b_passed) if(!u) { tooBad = true; break; }
				
				System.out.format("Case #%d: %s%n", t, tooBad ? "Too Bad" : turn);
			}			
			
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
	}

}
