
/* @JUDGE_ID: 1848XX 2015CodeJamRound1C_A Java */

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
	    int R;
	    int C;
	    int W;
	    if (stdin.hasNextInt()) {
		R = stdin.nextInt();
	    } else {
		return ret;
	    }
	    if (stdin.hasNextInt()) {
		C = stdin.nextInt();
	    } else {
		return ret;
	    }
	    if (stdin.hasNextInt()) {
		W = stdin.nextInt();
	    } else {
		return ret;
	    }
	    solve(R,C,W);
	}
	ret=0;
    	return ret;
    }

    private int solve1(int C,int W) {
	int ans=0;
	while (C-W>=W) {
	    C-=W;
	    ans++;
	}
	if (C==0) {
	} else if (C==W) {
	    ans += W;
	} else {
	    ans += (W+1);
	}
	return ans;
    }
    /**
     * Solve the problems here.
     * It will call output to output the results.
     */
    private void solve(int R,int C,int W) {
	if (R==1) {
	    output(solve1(C,W));
	} else {
	    int ans;
	    ans = solve1(C,W);
	    ans += (R-1)*(C/W);
	    output(ans);
	}
    }

    private int output_N=0;
    /**
     * Output the results
     */
    private void output(long ans) {
	output_N++;
	System.out.format("Case #%1$d: %2$d%n",output_N, ans);
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
