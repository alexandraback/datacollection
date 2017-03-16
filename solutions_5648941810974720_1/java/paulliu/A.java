
/* @JUDGE_ID: 1848XX 2016CodeJamRound1B_A Java */

import java.util.*;
import java.io.*;
import java.math.*;

class Main {
    private Scanner stdin = new Scanner(System.in);
    private java.util.logging.Logger logger = null;
    public static String loggerName = "MainLogger";

    /**
     * Init class data here
     */
    private void init() {
	
    }

    /**
     * Handle the input here.
     * This method will call solve() method inside to solve the problem.
     * The return value indicates if there are more input data need to 
     * be handled. If it doesn't return 0, means this function have to be
     * called again to solve next data.
     * @return 0: end. 1: need to call input() again for next data.
     */
    private int input() {
	int ret=0;
	String com1;
	int T;

	if (stdin.hasNextInt()) {
	    T = stdin.nextInt();
	} else {
	    return ret;
	}

	for (int t1=0; t1<T; t1++) {
	    String S;
	    if (stdin.hasNext()) {
		S = stdin.next();
	    } else {
		return ret;
	    }
	    solve(S);
	    
	}

	ret=0;
    	return ret;
    }

    /**
     * Solve the problems here.
     * It will call output to output the results.
     */
    private void solve(String S) {
	String[] digits = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE" };

	int[][] digits1 = new int[10][26];

	for (int i=0; i<10; i++) {
	    for (int j=0; j<digits[i].length(); j++) {
		digits1[i][digits[i].charAt(j)-'A']++;
	    }
	}
	
	int[] tab1 = new int[26];

	for (int i=0; i<S.length(); i++) {
	    tab1[S.charAt(i)-'A']++;
	}

	ArrayList<String> a1 = new ArrayList<String>();

	/* 0 */
        while (tab1['Z'-'A'] > 0) {
	    a1.add("0");
	    for (int i=0; i<26; i++) {
		tab1[i] -= digits1[0][i];
	    }
	}

	/* 2 */
        while (tab1['W'-'A'] > 0) {
	    a1.add("2");
	    for (int i=0; i<26; i++) {
		tab1[i] -= digits1[2][i];
	    }
	}

	/* 6 */
        while (tab1['X'-'A'] > 0) {
	    a1.add("6");
	    for (int i=0; i<26; i++) {
		tab1[i] -= digits1[6][i];
	    }
	}

	/* 8 */
        while (tab1['G'-'A'] > 0) {
	    a1.add("8");
	    for (int i=0; i<26; i++) {
		tab1[i] -= digits1[8][i];
	    }
	}

	/* 4 */
        while (tab1['U'-'A'] > 0) {
	    a1.add("4");
	    for (int i=0; i<26; i++) {
		tab1[i] -= digits1[4][i];
	    }
	}

	/* 1 */
        while (tab1['O'-'A'] > 0) {
	    a1.add("1");
	    for (int i=0; i<26; i++) {
		tab1[i] -= digits1[1][i];
	    }
	}

	/* 5 */
        while (tab1['F'-'A'] > 0) {
	    a1.add("5");
	    for (int i=0; i<26; i++) {
		tab1[i] -= digits1[5][i];
	    }
	}

	/* 7 */
        while (tab1['V'-'A'] > 0) {
	    a1.add("7");
	    for (int i=0; i<26; i++) {
		tab1[i] -= digits1[7][i];
	    }
	}

	/* 9 */
        while (tab1['I'-'A'] > 0) {
	    a1.add("9");
	    for (int i=0; i<26; i++) {
		tab1[i] -= digits1[9][i];
	    }
	}

	
	
	/* 3*/
        while (tab1['H'-'A'] > 0) {
	    a1.add("3");
	    for (int i=0; i<26; i++) {
		tab1[i] -= digits1[3][i];
	    }
	}

	Collections.sort(a1);
	StringBuffer sb1 = new StringBuffer();
	for (String i : a1) {
	    sb1.append(i);
	}
	
	output(sb1.toString());
    }

    private int output_N=0;
    /**
     * Output the results
     */
    private void output(String X) {
	output_N++;
	if (X != null) {
	    System.out.format("Case #%1$d: %2$s%n",output_N,X);
	} else {
	    System.out.format("Case #%1$d: %2$s%n",output_N,X);
	}	    
    }


    /**
     * log information for debugging.
     */
    public void logInfo(String a, Object... args) {
	if (logger != null) {
	    logger.info(String.format(a,args));
	}
    }

    public void begin() {
	this.logger = java.util.logging.Logger.getLogger(Main.loggerName);
	if (this.logger.getLevel() != java.util.logging.Level.INFO) {
	    this.logger = null;
	}
	init();
	while (input()==1) {
	}
    }

    public void unittest() {
	this.logger = java.util.logging.Logger.getLogger(Main.loggerName);
    }

    public static void main (String args[]) {
	Main myMain = new Main();
	if (args.length >= 1 && args[0].equals("unittest")) {
	    myMain.unittest();
	    return;
	}
	java.util.logging.Logger.getLogger(Main.loggerName).setLevel(java.util.logging.Level.SEVERE);
	for (int i=0; args!=null && i<args.length; i++) {
	    if (args[i].equals("debug")) {
		java.util.logging.Logger.getLogger(Main.loggerName).setLevel(java.util.logging.Level.INFO);
	    }
	}
	myMain.begin();
    }
}
