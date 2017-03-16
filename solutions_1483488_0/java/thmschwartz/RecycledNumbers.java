package twentytwelve.qualification.c;

import java.util.Scanner;

public final class RecycledNumbers {

    /**
     * @param args
     */
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	int cases = sc.nextInt();
	for (int no = 1; no <= cases; no++) {
	    System.out.print("Case #" + no + ": ");
	    int A = sc.nextInt();
	    int B = sc.nextInt();

	    int pairs = 0;

	    int Adigits = 1;
	    int setSize = 0;
	    while (A >= 10 * Adigits) {
		Adigits *= 10;
		setSize++;
	    }
	    int[] currentSet = new int[setSize];

	    for (int current = A; current <= B; current++) {
		int bdigits = 10;
		int udigits = Adigits;
		for (int i = 0; udigits > 1; bdigits *= 10, udigits /= 10) {
		    int recycled = current / bdigits + (current % bdigits) * udigits;
		    if (recycled > current && recycled <= B) {
			boolean found = false;
			for (int j = 0; j < i; j++) {
			    if (currentSet[j] == recycled) {
				found = true;
			    }
			}
			if (!found) {
			    // System.out.println(current + " -> " + recycled);
			    currentSet[i++] = recycled;
			    pairs++;
			}
		    }
		}
	    }
	    System.out.println(pairs);
	}
    }
}
