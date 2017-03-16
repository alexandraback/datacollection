import java.io.IOException;
import java.util.Scanner;

/**
 * javac counting_sheep.java
 * cd bin; cat ../test.txt | java CountingSheep
 */

class CountingSheep {
	private static int solve(int n) {
		boolean[] seen = new boolean[48 + 10];
		int left = 10;
		int sum = 0;
		while (left != 0) {
			sum += n;
			for(char c : Integer.toString(sum).toCharArray()) {
				if (!seen[c]) {
					seen[c] = true;
					left -= 1;
				}
			}
		}
		return sum;
	}
	
	public static void main(String[] args) throws IOException {
	    Scanner in = new Scanner(System.in);
	    try {
		    int t = in.nextInt();
		    for (int i=1; i<=t; i++) {
		    	int n = in.nextInt();
		    	if (n == 0) {
			    	System.out.println("Case #" + i + ": INSOMNIA");
		    	} else {
			    	System.out.println("Case #" + i + ": " + solve(n));		    		
		    	}
		    }
	    } finally {
		    in.close();
	    }
	}
}
