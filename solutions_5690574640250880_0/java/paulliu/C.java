
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
	int T=0;

	com1 = stdin.get1();
	if (com1==null) {
	    return ret;
	}
	try {
	    T = Integer.parseInt(com1);
	} catch (Exception e) {
	    return ret;
	}

	for (int t=0; t<T; t++) {
	    int R;
	    int C;
	    int M;

	    com1 = stdin.get1();
	    if (com1==null) {
		return ret;
	    }
	    try {
		R = Integer.parseInt(com1);
	    } catch (Exception e) {
		return ret;
	    }
	    
	    com1 = stdin.get1();
	    if (com1==null) {
		return ret;
	    }
	    try {
		C = Integer.parseInt(com1);
	    } catch (Exception e) {
		return ret;
	    }
	    
	    com1 = stdin.get1();
	    if (com1==null) {
		return ret;
	    }
	    try {
		M = Integer.parseInt(com1);
	    } catch (Exception e) {
		return ret;
	    }
	    if (R*C-M==1) {
		output1(R,C);
	    } else {
		solve(R, C, M);
	    }
	}
	ret=0;
    	return ret;
    }

    int countSpace(int[][] table) {
	boolean[][] counted = new boolean[table.length][table[0].length];
	for (int i=0; i<counted.length; i++) {
	    for (int j=0; j<counted[i].length; j++) {
		counted[i][j]=false;
	    }
	}
	int count=0;
	for (int i=1; i<table.length-1; i++) {
	    for (int j=1; j<table[i].length-1; j++) {
		if (table[i][j]==0) {
		    for (int ii=-1; ii<=1; ii++) {
			if (i+ii<=0 || i+ii>=table.length-1) {
			    continue;
			}
			for (int jj=-1; jj<=1; jj++) {
			    if (j+jj<=0 || j+jj>=table[i+ii].length-1) {
				continue;
			    }
			    if (!counted[i+ii][j+jj]) {
				count++;
				counted[i+ii][j+jj]=true;
			    }
			}
		    }
		}
	    }
	}
	return count;
    }

    int makeSpaceForOutput(int[][] table) {
	boolean[][] counted = new boolean[table.length][table[0].length];
	for (int i=0; i<counted.length; i++) {
	    for (int j=0; j<counted[i].length; j++) {
		counted[i][j]=false;
	    }
	}
	int count=0;
	for (int i=1; i<table.length-1; i++) {
	    for (int j=1; j<table[i].length-1; j++) {
		if (table[i][j]==0) {
		    for (int ii=-1; ii<=1; ii++) {
			if (i+ii<=0 || i+ii>=table.length-1) {
			    continue;
			}
			for (int jj=-1; jj<=1; jj++) {
			    if (j+jj<=0 || j+jj>=table[i+ii].length-1) {
				continue;
			    }
			    if (!counted[i+ii][j+jj]) {
				count++;
				counted[i+ii][j+jj]=true;
			    }
			}
		    }
		}
	    }
	}
	for (int i=1; i<counted.length-1; i++) {
	    for (int j=1; j<counted[i].length-1; j++) {
		if (!counted[i][j]) {
		    table[i][j]=-100;
		}
	    }
	}
	return count;
    }

    class RData {
	public int [][] table;
	public int whiteNeeded;
	public int searchPos;
    }

    class RAnswer {
	public int [][] table;
	public int startPos;
    }

    private RAnswer sf(RData rData) {
	int N,M;
	N = rData.table.length-2;
	M = rData.table[0].length-2;
	logInfo("rData.startPos = %1$d", rData.searchPos);
	for (int i=rData.searchPos+1; i<N*M; i++) {
	    int rowW, colW;
	    rowW = i/M+1;
	    colW = i%M+1;
	    boolean whiteFlag=false;
	    if (rData.searchPos==-1) {
		whiteFlag=true;
	    }
	    loopC_1413242: for (int ii=-1; ii<=1; ii++) {
		for (int jj=-1; jj<=1; jj++) {
		    if (rData.table[rowW+ii][colW+jj]==0) {
			whiteFlag=true;
			break loopC_1413242;
		    }
		}
	    }
	    if (whiteFlag) {
		int whiteSpace=0;
		rData.table[rowW][colW]=0;
		whiteSpace = countSpace(rData.table);
		logInfo("whiteSpace = %1$d, rData.whiteNeeded = %2$d", whiteSpace, rData.whiteNeeded);
		if (whiteSpace == rData.whiteNeeded) {
		    RAnswer ans = new RAnswer();
		    ans.table = rData.table;
		    ans.startPos = i;
		    return ans;
		}
		if (whiteSpace < rData.whiteNeeded) {
		    int keepSearchPos = rData.searchPos;
		    rData.searchPos = i;
		    RAnswer result = sf(rData);
		    if (result != null) {
			result.startPos = i;
			return result;
		    }
		    rData.searchPos = keepSearchPos;
		}
		rData.table[rowW][colW]=-1;
	    }
	}
	return null;
    }
    /**
     * Solve the problems here.
     * It will call output to output the results.
     */
    private void solve(int R, int C, int M) {
	int[][] table = new int[R+2][C+2];
	for (int i=1; i<R+1; i++) {
	    for (int j=1; j<C+1; j++) {
		table[i][j]=-1;
	    }
	}
	for (int i=0; i<R+2; i++) {
	    table[i][0]=-2;
	    table[i][C+1]=-2;
	}
	for (int i=0; i<C+2; i++) {
	    table[0][i]=-2;
	    table[R+1][i]=-2;
	}
	RData rData = new RData();
	rData.table = table;
	rData.whiteNeeded = R*C-M;
	rData.searchPos=-1;
	RAnswer result1=null;
	result1 = sf(rData);
	output(result1);
    }

    int output_N=0;
    /**
     * Output the results
     */
    private void output(RAnswer ans) {
	output_N++;
	System.out.format("Case #%1$d:%n",output_N);
	if (ans==null) {
	    System.out.println("Impossible");
	} else {
	    int N=ans.table.length-2;
	    int M=ans.table[0].length-2;
	    makeSpaceForOutput(ans.table);
	    for (int i=1; i<=N; i++) {
		for (int j=1; j<=M; j++) {
		    if ((i-1)*M+(j-1) == ans.startPos) {
			System.out.print("c");
		    } else if (ans.table[i][j]==0) {
			System.out.print(".");
		    } else if (ans.table[i][j]==-1) {
			System.out.print(".");
		    } else if (ans.table[i][j]==-100) {
			System.out.print("*");
		    } else {
			System.out.print("?");
		    }
		}
		System.out.println();
	    }
	}
    }

    private void output1(int R, int C) {
	output_N++;
	System.out.format("Case #%1$d:%n",output_N);
	for (int i=0; i<R; i++) {
	    for (int j=0; j<C; j++) {
		if (i==0 && j==0) {
		    System.out.print("c");
		} else {
		    System.out.print("*");
		}
	    }
	    System.out.println();
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
