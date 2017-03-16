
/* @JUDGE_ID: 1848XX 2015CodeJamQualificationB Java */

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

    class MyComparator implements Comparator<Integer> {
	public int compare(Integer aI,Integer bI) {
	    int a=aI.intValue();
	    int b=bI.intValue();
	    if (a<b) {
		return 1;
	    } else if(a>b) {
		return -1;
	    }
	    return 0;
	}
	public boolean equals(Object obj) {
	    return true;
	}
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

	if (stdin.hasNextInt()) {
	    T = stdin.nextInt();
	} else {
	    return ret;
	}

	for (int t1=0; t1<T; t1++) {
	    int D;
	    if (stdin.hasNextInt()) {
		D = stdin.nextInt();
	    } else {
		return ret;
	    }
	    PriorityQueue <Integer> p = new PriorityQueue<Integer>(D,new MyComparator());
	    for (int d1=0; d1<D; d1++) {
		int pi;
		if (stdin.hasNextInt()) {
		    pi = stdin.nextInt();
		} else {
		    return ret;
		}
		p.add(new Integer(pi));
	    }
	    solve(D,p);
	}
	ret=0;
    	return ret;
    }

    private int solve_BruteForce(ArrayList<Integer> a, int time, int uMinTime) {
	Collections.sort(a, new MyComparator());
	if (a.get(0).intValue()<=3) {
	    return a.get(0).intValue()+time;
	}
	if (time >= uMinTime) {
	    return a.get(0).intValue()+time;
	}
	int minTime = a.get(0).intValue()+time;
	for (int i=a.get(0).intValue()/2; i>=1; i--) {
	    ArrayList<Integer> b = new ArrayList<Integer>(a);
	    int m1 = a.get(0).intValue()-i;
	    int m2 = i;
	    
	    b.set(0,new Integer(m1));
	    b.add(new Integer(m2));
	    int nowTime = solve_BruteForce(b, time+1, Math.min(minTime, uMinTime));
	    if (nowTime < minTime) {
		minTime = nowTime;
	    }
	}
	return minTime;
    }
    private void solve_BruteForce(int D,PriorityQueue<Integer> p) {
	ArrayList<Integer> a = new ArrayList<Integer>();
	while (!p.isEmpty()) {
	    a.add(p.poll());
	}
	Collections.sort(a, new MyComparator());
	int minTime = solve_BruteForce(a,0,a.get(0).intValue());
	output(minTime);
    }

    private HashMap<ArrayList<Integer>, Integer> bForce1Table = null;
    private int solve_BruteForce1(ArrayList<Integer> a, int time, int uMinTime) {
	Collections.sort(a, new MyComparator());
	if (bForce1Table.containsKey(a)) {
	    return bForce1Table.get(a).intValue()+time;
	}
	if (a.get(0).intValue()<=3) {
	    return a.get(0).intValue()+time;
	}
	if (time >= uMinTime) {
	    return a.get(0).intValue()+time;
	}
	int minTime = a.get(0).intValue()+time;
	for (int i=a.get(0).intValue()/2; i>=1; i--) {
	    ArrayList<Integer> b = new ArrayList<Integer>(a);
	    int m1 = a.get(0).intValue()-i;
	    int m2 = i;
	    
	    b.set(0,new Integer(m1));
	    b.add(new Integer(m2));
	    int nowTime = solve_BruteForce1(b, time+1, Math.min(minTime, uMinTime));
	    if (nowTime < minTime) {
		minTime = nowTime;
	    }
	}
	bForce1Table.put(a, new Integer(minTime));	
	return minTime;
    }
    private void solve_BruteForce1(int D,PriorityQueue<Integer> p) {
	ArrayList<Integer> a = new ArrayList<Integer>();
	while (!p.isEmpty()) {
	    a.add(p.poll());
	}
	bForce1Table = new HashMap<ArrayList<Integer>, Integer>();
	Collections.sort(a, new MyComparator());
	int minTime = solve_BruteForce1(a,0,a.get(0).intValue());
	output(minTime);
    }

    
    /**
     * Solve the problems here.
     * It will call output to output the results.
     */
    private void solve(int D,PriorityQueue<Integer> p) {
	ArrayList<Integer> p1 = new ArrayList<Integer>(p);
	TreeSet<Integer> div = new TreeSet<Integer>();
	int sum=0;
	for (Integer a : p1) {
	    sum += a.intValue();
	}
	for (int i=p1.size(); ; i++) {
	    if (sum%i==0) {
		int a1 = sum/i;
		if (a1 <= 0) {
		    break;
		}
		div.add(new Integer(a1));
	    } else {
		int a1 = sum/i;
		int a2 = sum/i+1;
		if (a1>0) {
		    div.add(new Integer(a1));
		}
		if (a2 > 0) {
		    div.add(new Integer(a2));
		}
		if (a2 <= 0 || a1 <= 0) {
		    break;
		}
	    }
	}
	int minTime = Integer.MAX_VALUE;
	for (Integer d1 : div) {
	    int d = d1.intValue();
	    PriorityQueue<Integer> p2 = new PriorityQueue<Integer>(p1.size(), new MyComparator());
	    p2.addAll(p1);
	    
	    for (int i=0; !p2.isEmpty(); i++) {
		int pi = p2.poll().intValue();
		if (pi+i < minTime) {
		    minTime = pi+i;
		}
		if (pi<=d || pi <= 3) {
		    break;
		}

		p2.add(new Integer(d));
		p2.add(new Integer(pi-d));
	    }
	}
	output(minTime);
    }
    
    private void solve_Wrong1(int D,PriorityQueue<Integer> p) {
	
	int minTime = Integer.MAX_VALUE;
	for (int i=0; !p.isEmpty(); ) {
	    int pi = p.poll().intValue();
	    if (pi+i < minTime) {
		minTime = pi+i;
	    }
	    if (pi<=3) {
		break;
	    }
	    int k1 = (int)MyMath.sqrt((long)pi);
	    if (k1<0) {
		k1 = -(k1+1);
		k1++;
	    }
	    
	    while (pi > 0) {
		if (pi >= k1) {
		    p.add(new Integer(k1));
		    Integer remaining = new Integer(pi-k1);
		    p.add(remaining);
		    i++;
		    if (p.peek().intValue()+i<minTime) {
			minTime = p.peek().intValue()+i;
		    }
		    p.remove(remaining);
		    pi-=k1;
		} else {
		    p.add(new Integer(pi));
		    pi=0;
		}
	    }
	}
	output(minTime);
    }


    
    private int output_N=0;
    /**
     * Output the results
     */
    private void output(int minTime) {
	output_N++;
	System.out.format("Case #%1$d: %2$d%n",output_N,minTime);
	
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
}
