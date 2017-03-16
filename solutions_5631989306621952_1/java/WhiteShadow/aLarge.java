import java.util.Scanner;

class aLarge {    
    public static void main(String args[]) {
	Scanner in = new Scanner(System.in);

	int n = in.nextInt();
	for (int i=1; i<=n; i++) {
	    String s = in.next();
	    String sol = "" + s.charAt(0);
	    for (int j=1; j<s.length(); j++)
		if (s.charAt(j) >= sol.charAt(0)) sol = s.charAt(j) + sol;
		else sol = sol + s.charAt(j);
	    System.out.printf("Case #%d: %s%n", i, sol);
	}

	
    }
}
