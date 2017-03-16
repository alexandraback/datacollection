import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Scanner;


public class test7 {
	public int BFFs(int[] friends) {
		if (friends == null || friends.length < 1) {
			return 0;
		}
		boolean[] travels = new boolean[friends.length];
		int max= 0;
		for (int i = 0; i < friends.length; i++) {
			int current = 0;
			int currentIndex = i;
			travels = new boolean[friends.length];
			while (!travels[currentIndex]) {
				current++;
				travels[currentIndex] = true;
				currentIndex = friends[currentIndex] - 1;
			}
			if (friends[friends[currentIndex] - 1] == currentIndex + 1) {
				int otherMax = 0;
				for (int j = 0; j < friends.length; j++) {
					int otherCurrent = 0;
					int otherCurrentIndex = j;
					boolean[] otherTravel = Arrays.copyOf(travels, travels.length);
					while (!otherTravel[otherCurrentIndex]) {
						otherCurrent++;
						otherTravel[otherCurrentIndex] = true;
						otherCurrentIndex = friends[otherCurrentIndex] - 1;
					}
					if (otherCurrentIndex == friends[currentIndex] - 1) {
						otherMax = Math.max(otherMax, otherCurrent);
					}
				}
				max = Math.max(max, current + otherMax);
			} else if (currentIndex == i) {
				max = Math.max(max, current);
			}
		}
		return max;
	}
	
	public static void main(String[] args) {
		test7 test = new test7();
	    Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
	    Long t = in.nextLong();  // Scanner has functions to read ints, longs, strings, chars, etc.
	    for (int i = 1; i <= t; ++i) {
	      int number = in.nextInt();
	      int[] friendsList = new int[number];
	      for (int j = 0; j < number; ++j) {
	    	  friendsList[j] = in.nextInt();
	      }
	      System.out.println("Case #" + i + ": " + test.BFFs(friendsList));
	    }
		//System.out.println("Case #" + 1 + ": " + test.BFFs(new int[]{7,8,10,10,9,2,9,6,3,3,4}));
	}
}
