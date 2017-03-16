
/* @JUDGE_ID: 1848XX 2016CodeJamQualificationD Java */

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
	    long K;
	    long C;
	    long S;
	    if (stdin.hasNextLong()) {
		K = stdin.nextLong();
	    } else {
		return ret;
	    }
	    if (stdin.hasNextLong()) {
		C = stdin.nextLong();
	    } else {
		return ret;
	    }
	    if (stdin.hasNextLong()) {
		S = stdin.nextLong();
	    } else {
		return ret;
	    }
	    solve(K,C,S);
	    
	}

	ret=0;
    	return ret;
    }

    private void solveSmall(long K,long C,long S) {
	ArrayList<Long> answers = new ArrayList<Long>();
	for (long G=0; G<K; G++) {
	    long m=G;
	    for (long c1=0; c1+1<C; c1++) {
		m=m*K;
	    }
	    answers.add(new Long(m));
	}
	output(answers);
    }
    /**
     * Solve the problems here.
     * It will call output to output the results.
     */
    private void solve(long K,long C,long S) {
	ArrayList<Long> ans = new ArrayList<Long>();
	for (long l=0; l<K; l+=C) {
	    long ans1=0;
	    for (long c=0; c<C; c++) {
		if (l+c<K) {
		    ans1 *= K;
		    ans1 += (l+c);
		}
	    }
	    ans.add(new Long(ans1));
	}
	Collections.sort(ans);
	for (int i=0; i+1<ans.size(); i++) {
	    if (ans.get(i).compareTo(ans.get(i+1))==0) {
		logInfo("Error: duplicated element");
	    }
	}
	if (ans.size()<=S) {
	    output(ans);
	} else {
	    output(null);
	}
    }

    private int output_N=0;
    /**
     * Output the results
     */
    private void output(ArrayList<Long> ans) {
	output_N++;
	System.out.format("Case #%1$d:",output_N);
	if (ans == null) {
	    System.out.print(" IMPOSSIBLE");
	} else {
	    for (int i=0; i<ans.size(); i++) {
		System.out.format(" %1$d",ans.get(i).longValue()+1);
	    }
	}
	System.out.println();
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


class MyMath {

    /**
     * return a^r
     */
    public static long pow(long a,long r) {
	long result=1;
	long v=a;
	for (long r1 = r; r1 > 0; ) {
	    if (r1%2==0) {
		v = (v*v);
		r1/=2;
	    } else {
		result = (result*v);
		r1--;
	    }
	}
	return result;
    }

    /**
     * return a^r mod n
     */
    public static long powMod(long a, long r, long n) {
	long result=1;
	long v=(a%n);
	for (long r1 = r; r1 > 0; ) {
	    if (r1%2==0) {
		v = (v*v)%n;
		r1/=2;
	    } else {
		result = (result*v)%n;
		r1--;
	    }
	}
	return result;
    }

    public static long sqrt(long n) {
	long right=3037000499L;
	long left=1;
	if (n>right*right) {
	    return -(right+1)-1;
	}
	if (n==0) {
	    return 0;
	}
	if (n==1) {
	    return 1;
	}
	if (n<0) {
	    return -1;
	}
	if (n/2 < right) {
	    right = n/2;
	}
	while (left<=right) {
	    long m = (left+right)/2;
	    long m2 = m*m;
	    if (m2 == n) {
		return m;
	    }
	    if (m2 < n) {
		left=m+1;
	    } else {
		right=m-1;
	    }
	}
	return -(left)-1;
    }

    private static long[] FACTORIAL_DP = null;
    private static int FACTORIAL_DP_MAX = 20;
    private static void factorial_init() {
	if (FACTORIAL_DP == null) {
	    FACTORIAL_DP = new long[FACTORIAL_DP_MAX];
	    java.util.Arrays.fill(FACTORIAL_DP, 0);
	    if (FACTORIAL_DP_MAX>0) {
		FACTORIAL_DP[0]=1;
	    }
	}
    }

    /**
     * return n!
     */
    public static long factorial(int n) {
	long ret=1;
	if (n<0) {
	    return 0;
	}
	if (n >= FACTORIAL_DP_MAX) {
	    for (int i=1; i<=n; i++) {
		ret *= ((long) i);
	    }
	    return ret;
	}
	factorial_init();
	if (FACTORIAL_DP[n] != 0) {
	    return FACTORIAL_DP[n];
	}
	int i=n;
	for ( ; i>=0; i--) {
	    if (FACTORIAL_DP[i] != 0) {
		break;
	    }
	}
	if (i<0) {
	    FACTORIAL_DP[0]=1;
	    i=0;
	}
	for (int j=i+1; j<=n; j++) {
	    FACTORIAL_DP[j]=FACTORIAL_DP[j-1]*((long)j);
	}
	return FACTORIAL_DP[n];
    }

    private static long[][] C_DP = null;
    private static int C_DP_MAX = 51;
    private static void C_init() {
	if (C_DP==null) {
	    C_DP = new long[C_DP_MAX][];
	    for (int i=0; i<C_DP_MAX; i++) {
		C_DP[i] = new long[i/2+1];
		java.util.Arrays.fill(C_DP[i], 0);
	    }
	}
    }

    /**
     * Combination C(n,k).
     *
     * This function will use Dynamic Programming for all n < C_DP_MAX.
     *
     * @param n the total number of objects.
     * @param k the number of choosed objects.
     */
    public static long C(int n, int k) {
	long ret=0;
	if (n<0 || k<0 || k>n) {
	    return 0;
	}
	if (n==0) {
	    return 1;
	}
	if (k > n/2) {
	    k = n-k;
	}
	if (n >= C_DP_MAX) {
	    ret = 1;
	    for (int i=1; i<=k; i++) {
		ret *= ((long)(n-i-1));
		ret /= ((long)(i));
	    }
	    return ret;
	}
	C_init();
	if (C_DP[n][k] != 0) {
	    return C_DP[n][k];
	}
	ret = C(n-1,k) + C(n-1, k-1);
	C_DP[n][k] = ret;
	return ret;
    }

    /**
     * Extended GCD
     *
     * @param a a number
     * @param b another number
     * @return an array contains 3 long values. ret[0] is GCD.
     *         And ret[1]*a+ret[2]*b=ret[0].
     */
    public static long[] extendedGCD(long a, long b) {
	long s=0;
        long old_s=1;
        long t=1;
        long old_t=0;
        long r=b;
        long old_r=a;
        long[] ret = new long[3];
        while (r!=0) {
            long quotient = old_r / r;
            long tmp;
            tmp = r;
            r = old_r - quotient*r;
            old_r = tmp;
            tmp = s;
            s = old_s - quotient*s;
            old_s = tmp;
            tmp = t;
            t = old_t - quotient*t;
            old_t = tmp;
        }
        ret[0] = old_r;
        ret[1] = old_s;
        ret[2] = old_t;
        return ret;
    }

    /**
     * return a%n.
     * For negative a, the result will be in 0~(n-1)
     *
     * @param a a number
     * @param n modulo
     */
    public static long pythonMOD(long a, long n) {
	if (a>=0) {
	    return a%n;
	}
	return (a%n+n)%n;
    }

    /**
     * Chinese Remainder Theorem.
     * It solves the Chinese Remainder Theorem. All m should be co-prime.
     * If m is not co-prime, then it throws ArithmeticException.
     *
     * @param r the residual
     * @param m the modulo
     * @return an array contains 2 long values. The first value is the answer.
     *         The second value is the modulo.
     */
    public static long[] chineseRemainderTheorem(long[] r, long[] m) {
	long M=1;
        long ret=0;
        for (int i=0; i<m.length; i++) {
            M *= m[i];
        }
        for (int i=0; i<m.length; i++) {
            long Mi = M/m[i];
            long[] gcd = extendedGCD(Mi, m[i]);
            if (gcd[0] != 1) {
                throw new ArithmeticException("GCD is not 1");
            }
            long inverse = pythonMOD(gcd[1], m[i]);
            
            ret += (r[i] * Mi * inverse);
            ret = pythonMOD(ret, M);
        }
	long[] retA = new long[2];
	retA[0] = ret;
	retA[1] = M;
        return retA;
    }

    /**
     * Chinese Remainder Theorem.
     * It solves the Chinese Remainder Theorem. All m can be non-coprime.
     * If it finds it cannot solve the answer due to non-coprime do not
     * congruent, it throws an ArithmeticException.
     *
     * @param r the residual
     * @param m the modulo
     * @return an array contains 2 long values. The first value is the answer.
     *         The second value is the modulo.
     */
    public static long[] chineseRemainderTheoremExtended(long[] r, long[] m) {
	long r1 = r[0];
        long m1 = m[0];
	long r2;
	long m2;
        for (int i=1; i<m.length; i++) {
	    r2 = r[i];
	    m2 = m[i];
	    long[] gcd = extendedGCD(m1,m2);
	    if (r1 % gcd[0] != r2 % gcd[0]) {
                throw new ArithmeticException("GCD is not 1 and modulo GCD doesn't match.");
            }
	    long n = pythonMOD(r2-r1, m2);
	    n /= gcd[0];
	    m1 /= gcd[0];
	    m2 /= gcd[0];
	    long[] gcd2 = extendedGCD(m1,m2);
	    long inv2 = pythonMOD(gcd2[1], m2);
	    n = pythonMOD(n*inv2, m2);
	    n *= m1*gcd[0];
	    n += r1;
	    m1 = m1*m2*gcd[0];
	    r1 = pythonMOD(n, m1);
        }
	long[] retA = new long[2];
	retA[0] = pythonMOD(r1, m1);
	retA[1] = m1;
        return retA;
    }
}

