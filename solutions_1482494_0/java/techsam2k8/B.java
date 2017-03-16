import java.io.*;
import java.util.*;
import java.math.*;
/** @author Samuel Ahn */

public class B {
    public static void main(String args[]) throws Exception {
	Scanner in = new Scanner(System.in);
	int T = in.nextInt();
	test:
	for (int i = 1; i <= T; i++) {
	    int N = in.nextInt();
	    int[] one = new int[N];
	    int[] two = new int[N];
	    for (int j = 0; j < N; j++) {
		one[j] = in.nextInt();
		two[j] = in.nextInt();
	    }
	    int stars = 0;
	    int sum = 0;
	    loop:
	    while (stars != (2 * N)) {
		for (int j = 0; j < N; j++) {
		    if ((one[j] != 2002) && (two[j] <= stars)) {
			stars += 2;
			one[j] = 2002;
			two[j] = 2002;
			sum++;
			continue loop;
		    }
		}

		for (int j = 0; j < N; j++) {
		    if ((one[j] == 2002) && (two[j] <= stars)) {
			stars++;
			two[j] = 2002;
			sum++;
			continue loop;
		    }
		}
		int max = -1;
		int pos = -1;
		for (int j = 0; j < N; j++) {
		    if (one[j] <= stars) {
			if (two[j] > max) {
			    max = two[j];
			    pos = j;
			}
		    }
		}
		if (pos == -1) {
		    System.out.printf("Case #%d: Too Bad\n", i);
		    continue test;
		} else {
		    stars++;
		    one[pos] = 2002;
		    sum++;
		}
	    }
	    System.out.printf("Case #%d: %d\n", i, sum);
	}
    }
}
