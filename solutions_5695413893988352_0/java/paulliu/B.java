
/* @JUDGE_ID: 1848XX 2016CodeJamRound1B_B Java */

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
	    String S1, S2;
	    if (stdin.hasNext()) {
		S1 = stdin.next();
	    } else {
		return ret;
	    }
	    if (stdin.hasNext()) {
		S2 = stdin.next();
	    } else {
		return ret;
	    }
	    solve(S1, S2);
	    
	}

	ret=0;
    	return ret;
    }

    private long minDifference(String S1, String S2) {
	StringBuffer NS1 = new StringBuffer();
	for (int i=0; i<S1.length(); i++) {
	    if (S1.charAt(i) == '?') {
		NS1.append("0");
	    } else {
		NS1.append(S1.charAt(i));
	    }
	}
	long minS1 = Long.parseLong(NS1.toString());
	NS1 = new StringBuffer();
	for (int i=0; i<S1.length(); i++) {
	    if (S1.charAt(i) == '?') {
		NS1.append("9");
	    } else {
		NS1.append(S1.charAt(i));
	    }
	}
	long maxS1 = Long.parseLong(NS1.toString());

	for (int i=0; i<S2.length(); i++) {
	    if (S2.charAt(i) == '?') {
		NS1.append("0");
	    } else {
		NS1.append(S2.charAt(i));
	    }
	}
	long minS2 = Long.parseLong(NS1.toString());
	NS1 = new StringBuffer();
	for (int i=0; i<S2.length(); i++) {
	    if (S2.charAt(i) == '?') {
		NS1.append("9");
	    } else {
		NS1.append(S2.charAt(i));
	    }
	}
	long maxS2 = Long.parseLong(NS1.toString());

	long ret = Math.abs(maxS2-minS1);
	if (Math.abs(maxS1-minS2) < ret) {
	    ret = Math.abs(maxS1 - minS2);
	}
	if (Math.abs(minS1-minS2) < ret) {
	    ret = Math.abs(minS1 - minS2);
	}
	if (Math.abs(maxS1-maxS2) < ret) {
	    ret = Math.abs(maxS1 - maxS2);
	}
	return ret;
    }

    private long solveR_ans;
    private String solveR_S1;
    private String solveR_S2;
    
    private long solveR(char[] S1, char[] S2) {
	int index=-1;
	for (int i=0; i<S1.length ; i++) {
	    if (S1[i]=='?' || S2[i]=='?') {
		index = i;
		break;
	    }
	}
	if (index == -1) {
	    long ans = Math.abs(Long.parseLong(new String(S1))-Long.parseLong(new String(S2)));
	    if (ans < solveR_ans) {
		solveR_ans = ans;
		solveR_S1 = new String(S1);
		solveR_S2 = new String(S2);
	    }
	    return ans;
	}
	if (S1[index] == '?') {
	    long absMin = Long.MAX_VALUE;
	    int absAns = -1;
	    for (int i=0; i<=9; i++) {
		S1[index] = (char)('0'+i);
		long abs1 = solveR(S1, S2);
		if (abs1 < absMin) {
		    absMin = abs1;
		    absAns = i;
		}
	    }
	    S1[index] = '?';
	    return absMin;
	} else if (S2[index] == '?') {
	    long absMin = Long.MAX_VALUE;
	    int absAns = -1;
	    for (int i=0; i<=9; i++) {
		S2[index] = (char)('0'+i);
		long abs1 = solveR(S1, S2);
		if (abs1 < absMin) {
		    absMin = abs1;
		    absAns = i;
		}
	    }
	    S2[index] = '?';
	    return absMin;
	}
	return Math.abs(Long.parseLong(new String(S1))-Long.parseLong(new String(S2)));
    }
    
    /**
     * Solve the problems here.
     * It will call output to output the results.
     */
    private void solve(String S1, String S2) {

	char[] S1A = S1.toCharArray();
	char[] S2A = S2.toCharArray();

	solveR_ans = Long.MAX_VALUE;
	long Ans = solveR(S1A, S2A);
	
	output(solveR_S1, solveR_S2);
    }

    private int output_N=0;
    /**
     * Output the results
     */
    private void output(String X, String Y) {
	output_N++;
	if (X != null) {
	    System.out.format("Case #%1$d: %2$s %3$s%n",output_N,X, Y);
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
