
/* @JUDGE_ID: 1848XX 2015CodeJamQualificationA Java */

import java.util.*;
import java.io.*;

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
	    int Smax;
	    String shyness;
	    if (stdin.hasNextInt()) {
		Smax = stdin.nextInt();
	    } else {
		return ret;
	    }
	    if (stdin.hasNext()) {
		shyness = stdin.next();
	    } else {
		return ret;
	    }
	    solve(Smax, shyness);
	    
	}

	ret=0;
    	return ret;
    }

    /**
     * Solve the problems here.
     * It will call output to output the results.
     */
    private void solve(int Smax, String shyness) {
	int standUpPeople=0;
	int friends=0;
	for (int i=0; i<shyness.length(); i++) {
	    int currentPeople;
	    currentPeople = (int)(shyness.charAt(i)-'0');
	    if (standUpPeople+friends>=i) {
		standUpPeople += currentPeople;
	    } else {
		friends += i-(standUpPeople+friends);
		standUpPeople += currentPeople;
	    }
	}
	output(friends);
    }

    private int output_N=0;
    /**
     * Output the results
     */
    private void output(int friends) {
	output_N++;
	System.out.format("Case #%1$d: %2$d%n",output_N,friends);
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
