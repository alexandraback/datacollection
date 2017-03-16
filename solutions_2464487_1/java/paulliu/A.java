
/* @JUDGE_ID: 1848XX XXX Java */

import java.util.*;
import java.io.*;
import java.math.*;

class Main {
    private Stdin stdin = new Stdin();
    private java.util.logging.Logger logger = null;
    private static String logger_name = "XXX";
    private MathContext mc = MathContext.DECIMAL128;

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
	    BigDecimal r;
	    BigDecimal t;
	    com1 = stdin.get1();
	    if (com1==null) {
		return ret;
	    }
	    r = new BigDecimal(com1, mc);
	    com1 = stdin.get1();
	    if (com1==null) {
		return ret;
	    }
	    t = new BigDecimal(com1, mc);
	    solve(r,t);
	}
	ret=0;
    	return ret;
    }

    /**
     * Solve the problems here.
     * It will call output to output the results.
     */
    private void solve(BigDecimal r, BigDecimal t) {
	BigDecimal k;
	BigDecimal one = new BigDecimal(1.0,mc);
	BigDecimal two = new BigDecimal(2.0,mc);
	BigDecimal four = new BigDecimal(4.0,mc);

	k = t.divide(two);
	BigDecimal r1,r2;
	r1 = two.multiply(r).subtract(one).divide(four);
	r2 = r1.multiply(r1);
	k = k.add(r2);

	double kf = k.doubleValue();
	double n;
	n = Math.sqrt(kf)-(2.0*r.doubleValue()-1.0)/4.0;
	logInfo("n=%1$f",n);
	double nf;
	nf = Math.floor(n);
	logInfo("nf=%1$f",nf);
	long ni = (long)nf;
	output(ni);
    }

    int output_N=0;
    /**
     * Output the results
     */
    private void output(long r) {
	output_N++;
	if (r<0) {
	    r=0;
	}
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
