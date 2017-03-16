package twentytwelve.roundonec.a;

import java.util.ArrayList;
import java.util.Scanner;

public final class A {

    static ArrayList<ArrayList<Integer>> pars;
    static boolean[] reached;

    static boolean visit(int n) {
	if (reached[n]) {
	    return true;
	} else {
	    reached[n] = true;
	    for (Integer p : pars.get(n)) {
		if (visit(p)) {
		    return true;
		}
	    }
	}
	return false;
    }

    /**
     * @param args
     */
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	int cases = sc.nextInt();
	for (int no = 1; no <= cases; no++) {
	    int N = sc.nextInt();
	    pars = new ArrayList<ArrayList<Integer>>();
	    pars.add(null);
	    reached = new boolean[N + 1];
	    for (int n = 1; n <= N; n++) {
		reached[n] = false;
		int M = sc.nextInt();
		pars.add(n, new ArrayList<Integer>());
		for (int m = 1; m <= M; m++) {
		    pars.get(n).add(sc.nextInt());
		}
	    }

	    boolean diamond = false;
	    for (int n = 1; n <= N; n++) {
		for (int i = 1; i <= N; i++) {
		    reached[i] = false;
		}
		diamond = visit(n);
		if (diamond) {
		    break;
		}
	    }

	    // boolean diamond = false;
	    // for (int n = 1; n <= N; n++) {
	    // ArrayList<Integer> a = new ArrayList<Integer>();
	    // for (Integer p1 : pars.get(n)) {
	    // for (Integer p2 : pars.get(p1)) {
	    // if (pars.get(n).contains(p2)) {
	    // diamond = true;
	    // break;
	    // } else {
	    // a.add(p2);
	    // }
	    // }
	    // if (diamond) {
	    // break;
	    // }
	    // }
	    // if (diamond) {
	    // break;
	    // }
	    // pars.get(n).addAll(a);
	    // }

	    System.out.print("Case #" + no + ": " + (diamond ? "Yes" : "No"));

	    System.out.println();
	}
    }
}
