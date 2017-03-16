import java.util.Scanner;

class aSmall {
    static boolean first;
    static String s, best;
    
    static void go(String p, int pos) {
	if (pos == s.length()) {
	    if (first || p.compareTo(best)>0) {
		best = p;
		first = false;
	    }
	} else {
	    go(s.charAt(pos) + p, pos+1);
	    go(p + s.charAt(pos), pos+1);
	}
    }
    
    public static void main(String args[]) {
	Scanner in = new Scanner(System.in);

	int n = in.nextInt();
	for (int i=1; i<=n; i++) {
	    s = in.next();
	    first = true;
	    go("", 0);
	    System.out.printf("Case #%d: %s%n", i, best);
	}

	
    }
}
