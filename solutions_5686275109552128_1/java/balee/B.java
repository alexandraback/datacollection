import java.io.FileInputStream;
import java.util.Arrays;
import java.util.Scanner;

public class B {

	private static int getFullTime(int d, int[] p, int eatingTime) {
		int extraTimeNeeded = 0;
		for(int i = d - 1; i >= 0 && p[i] > eatingTime; i--) {
			int splitMins = p[i] / eatingTime;
			if ( p[i] % eatingTime == 0 )
				splitMins--;
			extraTimeNeeded += splitMins;
		}
		//System.out.println((eatingTime + extraTimeNeeded) + " " + eatingTime + " " + extraTimeNeeded);
		return eatingTime + extraTimeNeeded;
	}

	private static String process(Scanner in) {
		int d = in.nextInt();
		int p[] = new int[d];
		for(int i = 0; i < d; i++)
			p[i] = in.nextInt();
		Arrays.sort(p);
		int minTime = Integer.MAX_VALUE;
		for(int i = 1; i < minTime; i++) {
			int time = getFullTime(d, p, i);
			if ( time < minTime )
				minTime = time;
		}
		return Integer.toString(minTime);
	}

	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(System.in.available() > 0 ? System.in : 
			new FileInputStream(Thread.currentThread().getStackTrace()[1].getClassName() + ".practice.in"));
		int T = in.nextInt();
		for(int i = 1; i <= T; i++) 
			System.out.format("Case #%d: %s\n", i, process(in));
	}
}
