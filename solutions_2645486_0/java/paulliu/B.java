
/* @JUDGE_ID: 1848XX XXX Java */

import java.util.*;
import java.io.*;

class Main {
    private Stdin stdin = new Stdin();
    private java.util.logging.Logger logger = null;
    private static String logger_name = "XXX";

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

	com1 = stdin.get1();
	if (com1==null) {
	    return ret;
	}
	T = Integer.parseInt(com1);

	for (int i=0; i<T; i++) {
	    long E,R;
	    com1 = stdin.get1();
	    if (com1==null) {
		return ret;
	    }
	    E = Long.parseLong(com1);
	    com1 = stdin.get1();
	    if (com1==null) {
		return ret;
	    }
	    R = Long.parseLong(com1);
	    int N;
	    com1 = stdin.get1();
	    if (com1==null) {
		return ret;
	    }
	    N = Integer.parseInt(com1);
	    long[] v = new long[N];
	    for (int j=0; j<N; j++) {
		com1 = stdin.get1();
		if (com1==null) {
		    return ret;
		}
		v[j] = Long.parseLong(com1);
	    }
	    solve(E,R,v);
	}
	ret=0;
    	return ret;
    }

    private long f(long E, long R, long haveEnergy, long remain, long[] v, int start, int end) {
	long ret=0;
	if (haveEnergy>E) {
	    haveEnergy=E;
	}
	if (remain>E) {
	    remain=E;
	}
	if (start>end) {
	    return ret;
	}
	if ((haveEnergy+(end-start+1)*R)<remain) {
	    return ret;
	}
	if (start==end) {
	    if (R>=remain) {
		return haveEnergy*v[start];
	    } else {
		if (remain-R >= haveEnergy) {
		    return 0;
		} else {
		    return ((haveEnergy+R)-remain)*v[start];
		}
	    }
	}
	int maxVi=-1;
	long maxV=Long.MIN_VALUE;
	for (int i=start; i<=end; i++) {
	    if (v[i]>maxV) {
		maxV = v[i];
		maxVi = i;
	    }
	}
	long r1=0;
	long r2=0;
	long r3=0;
	long nowE=haveEnergy;
	if (maxVi-1>=start) {
	    if (haveEnergy+R*(maxVi-1-start+1) >= E) {
		nowE=E;
		r1 = f(E, R, haveEnergy, E, v, start, maxVi-1);
	    } else {
		nowE = haveEnergy+R*(maxVi-1-start+1);
		r1 = f(E, R, haveEnergy, nowE, v, start, maxVi-1);
	    }
	}
	long canObtain = 0;
	canObtain = (end-maxVi+1)*R;
	if ( canObtain-remain >=0) {
	    r2 = nowE*v[maxVi];
	    r3 = f(E, R, R, remain, v, maxVi+1, end);
	} else {
	    if ( nowE - (remain-canObtain) > 0) {
		r2 = (nowE-(remain-canObtain)) * v[maxVi];
		r3 = f(E, R, (remain-canObtain), remain, v, maxVi+1, end);
	    } else {
		r2 = 0;
		r3 = f(E, R, nowE, remain, v, maxVi+1, end);
	    }
	}
	return r1+r2+r3;
    }
    /**
     * Solve the problems here.
     * It will call output to output the results.
     */
    private void solve(long E, long R, long[] v) {
	long r;
	r = f(E, R, E, 0, v, 0, v.length-1);
	output(r);
    }

    int output_N=0;
    /**
     * Output the results
     */
    private void output(long r) {
	output_N++;
	System.out.format("Case #%1$d: %2$d%n", output_N, r);
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
	this.logger = java.util.logging.Logger.getLogger(Main.logger_name);
	if (this.logger.getLevel() != java.util.logging.Level.INFO) {
	    this.logger = null;
	}
	init();
	while (input()==1) {
	}
    }

    public void unittest() {
	this.logger = java.util.logging.Logger.getLogger(Main.logger_name);
    }

    public static void main (String args[]) {
	Main myMain = new Main();
	if (args.length >= 1 && args[0].compareTo("unittest")==0) {
	    myMain.unittest();
	    return;
	}
	java.util.logging.Logger.getLogger(Main.logger_name).setLevel(java.util.logging.Level.SEVERE);
	for (int i=0; args!=null && i<args.length; i++) {
	    if (args[i].compareTo("debug")==0) {
		java.util.logging.Logger.getLogger(Main.logger_name).setLevel(java.util.logging.Level.INFO);
	    }
	}
	myMain.begin();
    }
}

class Stdin
{
    private java.io.InputStream cin;
    private java.io.BufferedReader cin_br;
    private java.io.StreamTokenizer cin_st;

    public static java.lang.String endl = System.getProperty("line.separator");

    public Stdin() {
	this(java.lang.System.in);
    }

    public Stdin(java.io.InputStream cin) {
	this.cin = cin;
 	cin_br = new java.io.BufferedReader(new java.io.InputStreamReader(this.cin));
	cin_st = new java.io.StreamTokenizer(cin_br);
	cin_st.resetSyntax();
	cin_st.wordChars('\u0021','\u007E');
	cin_st.wordChars('\u00A0','\u00FF');
	cin_st.whitespaceChars('\u0000', '\u0020');
    }

    public java.io.InputStream getInputStream() {
	return cin;
    }

    public java.io.BufferedReader getBufferedReader() {
	return cin_br;
    }

    public java.io.StreamTokenizer getStreamTokenizer() {
	return cin_st;
    }

    public java.lang.String gets() {
	java.lang.String str=null;
	try {
	    str = this.cin_br.readLine();
	} catch (java.lang.Exception e) {
	    str = null;
	}
	return str;
    }

    public java.lang.String get1() {
	java.lang.String str=null;
	try {
	    if (cin_st.nextToken() != java.io.StreamTokenizer.TT_EOF) {
		str = cin_st.sval;
	    }
	} catch (java.lang.Exception e) {
	    str = null;
	}
	return str;
    }
}
