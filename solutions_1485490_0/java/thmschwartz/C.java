package twentytwelve.roundonec.c;

import java.util.Scanner;

public final class C {
    long a[][], b[][];
    int N, M;
    long table[][];

    long calc(int n, long ns, int m, long ms) {
	int _m = m, _n = n;
	if (_n >= (long) N || _m >= (long) M) {
	    return 0;
	} else if (table[n][m] >= 0) {
	    return table[n][m];
	}

	if (ns < 0) {
	    ns = a[_n][0];
	}

	if (ms < 0) {
	    ms = b[_m][0];
	}

	long sent = 0;
	long max = 0;
	if (a[_n][1] == b[_m][1]) {
	    if (ns == ms) {
		sent = ns;
		ns = -1;
		ms = -1;
		_n++;
		_m++;
	    } else if (ns > ms) {
		sent = ms;
		ns -= ms;
		ms = -1;
		_m++;
	    } else {
		// ms > ns
		sent = ns;
		ms -= ns;
		ns = -1;
		_n++;
	    }
	    max = Math.max(max, calc(_n, ns, _m, ms));
	} else {
	    max = Math.max(max, calc(_n + 1, -1, _m, ms));
	    _m++;
	    for (; _m < M; _m++) {
		max = Math.max(max, calc(_n, ns, _m, -1));
	    }
	}

	table[n][m] = max + sent;

	return max + sent;
    }

    /**
     * @param args
     */
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	int cases = sc.nextInt();
	C c = new C();
	for (int no = 1; no <= cases; no++) {
	    c.N = sc.nextInt();
	    c.M = sc.nextInt();

	    c.a = new long[c.N][2];
	    c.b = new long[c.M][2];
	    c.table = new long[c.N][c.M];

	    for (int n = 0; n < c.N; n++) {
		c.a[n][0] = sc.nextLong();
		c.a[n][1] = sc.nextLong();
	    }

	    for (int m = 0; m < c.M; m++) {
		c.b[m][0] = sc.nextLong();
		c.b[m][1] = sc.nextLong();
	    }

	    for (int n = 0; n < c.N; n++) {
		for (int m = 0; m < c.M; m++) {
		    c.table[n][m] = -1;
		}
	    }

	    long max = c.calc(0, -1, 0, -1);

	    System.out.print("Case #" + no + ": " + max);

	    System.out.println();
	}
    }
}
