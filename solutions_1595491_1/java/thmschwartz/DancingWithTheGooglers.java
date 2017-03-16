package twentytwelve.qualification.b;

import java.util.Scanner;

public final class DancingWithTheGooglers {

    /**
     * @param args
     */
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	int cases = sc.nextInt();
	for (int no = 1; no <= cases; no++) {
	    System.out.print("Case #" + no + ": ");
	    // googlers
	    int N = sc.nextInt();
	    // surprises
	    int S = sc.nextInt();
	    // best result
	    int p = sc.nextInt();

	    // unnecessary calculations
	    int p2 = 3 * p - 2;
	    int p4 = p2 - 2;

	    int max = 0;
	    for (int triplet = 0; triplet < N; triplet++) {
		int score = sc.nextInt();
		if (score >= p) {
		    if (score >= p2) {
			max++;
		    } else if (score < p2 && score >= p4 && S > 0) {
			max++;
			S--;
		    }
		}
	    }
	    System.out.println(max);
	}
    }
}
