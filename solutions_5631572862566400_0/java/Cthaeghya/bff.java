import java.util.*;
import java.io.*;

public class bff {

    public static void main (String[] args) {

	Scanner in = new Scanner(System.in);

	int count = in.nextInt();
	for (int l = 0; l < count; l++) {

	    int size = in.nextInt();

	    int[] bffs = new int[size];
	    int[] doubles = new int[size];
	    int[] paths = new int[size];
	    for (int i = 0; i < size; i++) {
		bffs[i] = in.nextInt() - 1;
		doubles[i] = -1;
		paths[i] = 0;
	    }

	    int best = -1;

	    for (int i = 0; i < size; i++) {
		if (bffs[bffs[i]] != i) {
		    int current = bffs[i];
		    int circle = 1;
		    while (current != i && circle <= size+1) {
			current = bffs[current];
			circle += 1;
		    }
		    if (current == i)
			doubles[i] = -2;
		    if (current == i && circle > best)
			best = circle;
		} else {
		    doubles[i] = bffs[i];
		    doubles[bffs[i]] = i;
		}
	    }

	    for (int i = 0; i < size; i++) {
		if (doubles[i] == -1) {
		    int current = bffs[i];
		    int path = 1;
		    while (current != i && path <= size+1 && doubles[current] == -1) {
			current = bffs[current];
			path += 1;
		    }
		    if (doubles[current] > -1) {
			if (paths[current] < path)
			    paths[current] = path;
		    }
		}
	    }

	    int doubleScore = 0;

	    for (int i = 0; i < size; i++) {
		if (doubles[i] > -1) {
		    int score = 1 + paths[i];
		    doubleScore += score;
		}
	    }
	    if (doubleScore > best)
		best = doubleScore;

	    //	    for (int i = 0; i < size; i++)
	    //	System.out.print(bffs[i]+1 + " ");
	    //  System.out.println();
	    System.out.println("Case #" + (l+1) + ": " + best);

	}

    }

}
