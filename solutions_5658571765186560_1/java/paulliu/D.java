
/* @JUDGE_ID: 1848XX 2015CodeJamQualificationD Java */

import java.util.*;
import java.io.*;

class Main {
    private Scanner stdin = new Scanner(System.in);
    private java.util.logging.Logger logger = null;
    public static String loggerName = "MainLogger";
    private int[][] dir = { {1,0}, {-1,0}, {0,-1}, {0,1} };

    ArrayList< ArrayList < Ominoes > > ominoes;
    HashMap<Ominoes, ArrayList<Ominoes> > rotateAndFlips;
    /**
     * Init class data here
     */
    private void init() {
	ominoes = new ArrayList<ArrayList<Ominoes> > ();
	ArrayList<Ominoes> o1 = new ArrayList<Ominoes>();
	Ominoes o1_1 = new Ominoes();
	o1_1.points.add(new Point(0,0));
	o1_1.shift();
	o1.add(o1_1);
	ominoes.add(o1);

	for (int i=1; i<7; i++) {
	    ArrayList<Ominoes> currentOminoesList = new ArrayList<Ominoes>();
	    
	    for (int j=0; j<ominoes.get(i-1).size(); j++) {
		Ominoes previousOminoes = ominoes.get(i-1).get(j);
		for (int k=0; k<previousOminoes.getN(); k++) {
		    Point previousOminoesPoint = previousOminoes.points.get(k);
		    for (int l=0; l<4; l++) {
			Point newPoint = new Point(previousOminoesPoint.x+dir[l][0], previousOminoesPoint.y+dir[l][1]);
			if (previousOminoes.points.contains(newPoint)) {
			    continue;
			}
			
			Ominoes newOminoes = new Ominoes(previousOminoes);
			newOminoes.points.add(newPoint);
			newOminoes.shift();
			boolean isUniqFlag = true;
			for (Ominoes ooo : currentOminoesList) {
			    if (ooo.equalsIgnoreDirection(newOminoes)) {
				isUniqFlag=false;
				break;
			    }
			}
			if (isUniqFlag) {
			    currentOminoesList.add(newOminoes);
			}
			
		    }
		}
	    }
	    ominoes.add(currentOminoesList);
	}
	if (logger != null) {
	    for (int i=0; i<ominoes.size(); i++) {
		logInfo("ominoes[%1$d].size() = %2$d",i,ominoes.get(i).size());
	    }
	    for (int i=0; i<ominoes.size() && i<6; i++) {
		for (int j=0; j<ominoes.get(i).size(); j++) {
		    String s;
		    s = ominoes.get(i).get(j).print1();
		    System.err.println(s);
		}
	    }
	}
	rotateAndFlips = new HashMap<Ominoes, ArrayList<Ominoes> >();
	for (int i=0; i<ominoes.size(); i++) {
	    for (Ominoes oo1 : ominoes.get(i)) {
		Ominoes o2 = new Ominoes(oo1);
		ArrayList<Ominoes> f1 = new ArrayList<Ominoes>();
		for (int m1=0; m1<2; m1++) {
		    for (int m2=0; m2<4; m2++) {
			if (!f1.contains(o2)) {
			    f1.add(new Ominoes(o2));
			}
			o2.turn();
		    }
		    o2.flip();
		}
		rotateAndFlips.put(oo1,f1);
	    }
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
	    int X=0;
	    int R=0;
	    int C=0;
	    if (stdin.hasNextInt()) {
		X = stdin.nextInt();
	    } else {
		return ret;
	    }
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
	    solve(X,R,C);
	}

	ret=0;
    	return ret;
    }

    private void printBoard(int[][] board) {
	for (int i=0; i<board.length; i++) {
	    for (int j=0; j<board[i].length; j++) {
		System.err.print(Integer.toString(board[i][j],10+26));
	    }
	    System.err.println();
	}
    }
    

    private boolean solve_R(int[][] board, int leftPieces, ArrayList<Ominoes> oms, int startUsingPiece) {
	if (leftPieces == 0) {
	    /* found a solution */
	    if (logger != null) {
		logInfo("leftPieces = %1$d",leftPieces);
		printBoard(board);
	    }
	    return true;
	}
	for (int i=startUsingPiece; i<oms.size(); i++) {
	    Ominoes o = oms.get(i);
	    for (Ominoes o1 : rotateAndFlips.get(o)) {
		int width = o1.getWidth();
		int height = o1.getHeight();
		for (int y=0; y+height-1<board.length; y++) {
		    for (int x=0; x+width-1<board[y].length; x++) {
			boolean canPutFlag=true;
			for (Point p : o1.points) {
			    if (board[p.y+y][p.x+x] != 0) {
				canPutFlag=false;
				break;
			    }
			}
			if (!canPutFlag) {
			    continue;
			}
			boolean hasNeighbor=false;
			/*
			neighborCheckLoop11: for (Point p : o1.points) {
			    for (int diri=0; diri<dir.length; diri++) {
				if ( 0 <= p.y+y+dir[diri][1] && p.y+y+dir[diri][1] < board.length ) {
				    if (0 <= p.x+x+dir[diri][0] && p.x+x+dir[diri][0] < board[p.y+y+dir[diri][1]].length) {
					if (board[p.y+y+dir[diri][1]][p.x+x+dir[diri][0]] != 0) {
					    hasNeighbor = true;
					    break neighborCheckLoop11;
					}
				    }
				}
			    }
			}
			if (!hasNeighbor) {
			    continue;
			}
			*/
			if (canPutFlag) {
			    for (Point p : o1.points) {
				board[p.y+y][p.x+x] = leftPieces;
			    }
			    boolean result1;
			    result1 = solve_R(board, leftPieces-1, oms, i);
			    if (result1) {
				return true;
			    }
			    for (Point p : o1.points) {
				board[p.y+y][p.x+x] = 0;
			    }
			}
		    }
		}
	    }
	}
	return false;
    }

    private boolean solve_R(int[][] board, ArrayList<Ominoes> oms, int index) {
	Ominoes must = oms.get(index);
	int R = board.length;
	int C = board[0].length;
	int leftPieces = R*C/must.getN();

	Ominoes o = new Ominoes(must);
	for (int m1=0; m1<1; m1++) {
	    for (int m2=0; m2<4; m2++) {
		int width = o.getWidth();
		int height = o.getHeight();
		for (int y=0; y+height-1<board.length; y++) {
		    for (int x=0; x+width-1<board[y].length; x++) {
			boolean canPutFlag=true;
			for (Point p : o.points) {
			    if (board[p.y+y][p.x+x] != 0) {
				canPutFlag=false;
				break;
			    }
			}
			if (canPutFlag) {
			    for (Point p : o.points) {
				board[p.y+y][p.x+x] = leftPieces;
			    }
			    boolean result1;
			    result1 = solve_R(board, leftPieces-1, oms, 0);
			    if (result1) {
				return true;
			    }
			    for (Point p : o.points) {
				board[p.y+y][p.x+x] = 0;
			    }
			}
		    }
		}
		o.turn();
	    }
	}
	return false;
    }


    private int preCal(int X,int R,int C) {
	if (X==1) {
	    return 0;
	} else if (X==2) {
	    if (R*C%X!=0) {
		return 1;
	    } else {
		return 0;
	    }
	} else if (X==3) {
	    if (R*C%X != 0) {
		return 1;
	    }
	    if (R>=2 && C>=3) {
		return 0;
	    }
	    if (R>=3 && C>=2) {
		return 0;
	    }
	    if (R>=3 && C>=3) {
		return 0;
	    }
	} else if (X==4) {
	    if (R*C%X != 0) {
		return 1;
	    }
	    if (R==2 || C==2) {
		/*
                   #
                  ###
                  divides the space to 2n+1 and 2n+1. Can't divide by 4
		*/
		return 1;
	    }
	    if (R>=4 && C>=3) {
		return 0;
	    }
	    if (R>=3 && C>=4) {
		return 0;
	    }
	    if (R>=4 && C >= 4) {
		return 0;
	    }
	} else if (X==5) {
	    if (R*C%X != 0) {
		return 1;
	    }
	    if (R==2 || C==2) {
		/*
		  # #
                  ###
                  divides the space to 1. Can't divide by 4
		*/
		return 1;
	    }
	    if (R>=3 && C>=10) {
		return 0;
	    } else if (R>=10 && C>=3) {
		return 0;
	    } else if (R>=4 && C>=5) {
		return 0;
	    } else if (R>=5 && C>=4) {
		return 0;
	    }		
	} else if (X==6) {
	    if (R*C%X!=0) {
		return 1;
	    }
	    if (R==2 || C==2) {
		/*
                 # #
                 ####
		*/
		return 1;
	    }
	    if (R==3 || C==3) {
		/*
		  ##
                   #
                  ###
                  divides the space to 3n+1 and 3n+2. Can't divide by 6
		*/
		return 1;
	    }
	    
	    if (R>=6 && C>=4) {
		return 0;
	    }
	    if (C>=6 && R>=4) {
		return 0;
	    }
	    
	} else if (X>=7) {
	    return 1;
	}
	return -1;
    }
    
    /**
     * Solve the problems here.
     * It will call output to output the results.
     */
    private void solve(int X,int R,int C) {
	if (X>=7) {
	    /* there is an ominoes
	       ###
               # #
               ##
	       
	       if Richard wants this. He wins for sure.
	    */
	    output(true);
	    return;
	}
	if (R*C % X != 0) {
	    output(true);
	    return;
	}
	if (R < X && C < X) {
	    output(true);
	    return;
	}
	int preResult = preCal(X,R,C);
	if (preResult != -1) {
	    if (preResult==1) {
		output(true);
	    } else {
		output(false);
	    }
	    return;
	}

	int[][] board = new int[R][C];

	ArrayList<Ominoes> oms = ominoes.get(X-1);
	for (int i=0; i<oms.size(); i++) {
	    for (int r=0; r<R; r++) {
		for (int c=0; c<C; c++) {
		    board[r][c]=0;
		}
	    }
	    if (solve_R(board,oms,i)) {
	    } else {
		if (logger != null) {
		    logInfo("Cannot put %1$d-th Ominoes",i);
		    System.err.println(oms.get(i).print1());
		}
		output(true);
		return;
	    }
	}
	output(false);
    }

    private int output_N=0;
    /**
     * Output the results
     */
    private void output(boolean isRichard) {
	output_N++;
	System.out.format("Case #%1$d: %2$s%n",output_N,isRichard?"RICHARD":"GABRIEL");
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

class Point implements Comparable<Point> {
    public int x;
    public int y;

    public Point(int X,int Y) {
	this.x = X;
	this.y = Y;
    }

    public Point() {
	this.x=0;
	this.y=0;
    }

    // sort first on x then on y
    public int compareTo(Point other)     
    {
	if( x == other.x) {
	    if (y > other.y) {
		return 1;
	    } else if (y<other.y) {
		return -1;
	    }
	    return 0;
	} else {
	    if (x > other.x) {
		return 1;
	    } else if (x<other.x) {
		return -1;
	    }
	    return 0;
	}
    }

    public boolean equals(Object po) {
	if (!(po instanceof Point)) {
	    return false;
	}
	Point p = (Point)(po);
	return (p.x==x) && (p.y==y);
    }
 
    // exterior product of two vectors
    public double exterior( Point p)
    {
	return x * p.y - y * p.x;
    }

    public Point add( Point p)
    {
	return new Point( x + p.x, y + p.y );
    }

    // subtraction of two points
    public Point subtract( Point p)
    {
	return new Point( x - p.x, y - p.y );
    }

    public double distance(Point b) {
	return Math.hypot(x-b.x, y-b.y);
    }
 
    public String toString()
    {
	StringBuffer sb = new StringBuffer();
	sb.append("Point[x=");
	sb.append(x);
	sb.append(",y=");
	sb.append(y);
	sb.append("]");
	return sb.toString();
    }

    public int hashCode (){
	return y*100+x;
    }
}

class Ominoes {
    public ArrayList<Point> points;

    public Ominoes() {
	points = new ArrayList<Point>();
    }

    public Ominoes(Ominoes o) {
	points = new ArrayList<Point>(o.points.size());
	for (int i=0; i<o.points.size(); i++) {
	    Point p1 = o.points.get(i);
	    points.add(new Point(p1.x, p1.y));
	}
    }

    public int getN() {
	return points.size();
    }

    public void shift() {
	int minX=Integer.MAX_VALUE;
	int minY=Integer.MAX_VALUE;
	for (Point p : points) {
	    if (p.x < minX) {
		minX = p.x;
	    }
	    if (p.y < minY) {
		minY = p.y;
	    }
	}
	for (int i=0; i<points.size(); i++) {
	    Point p = points.get(i);
	    Point np = new Point(p.x-minX, p.y-minY);
	    points.set(i,np);
	}
	Collections.sort(points);
    }
    
    public void flip() {
	shift();
	for (int i=0; i<points.size(); i++) {
	    Point p = points.get(i);
	    Point np = new Point(-p.x, p.y);
	    points.set(i,np);
	}
	shift();
    }

    public void turn() {
	shift();
	for (int i=0; i<points.size(); i++) {
	    Point p = points.get(i);
	    Point np = new Point(-p.y, p.x);
	    points.set(i,np);
	}
	shift();
    }

    public boolean equals(Object oO) {
	if (!(oO instanceof Ominoes)) {
	    return false;
	}
	Ominoes o = (Ominoes)(oO);
	if (o.getN() != getN()) {
	    return false;
	}
	for (int i=0; i<points.size(); i++) {
	    Point p1 = points.get(i);
	    Point p2 = o.points.get(i);
	    if (p1.compareTo(p2) != 0) {
		return false;
	    }
	}
	return true;
    }

    public boolean equalsIgnoreDirection(Ominoes o) {
	shift();
	boolean ret=false;
	Ominoes a = new Ominoes(this);
	for (int i=0; i<2; i++) {
	    for (int j=0; j<4; j++) {
		if (!ret && a.equals(o)) {
		    ret = true;
		    return ret;
		}
		a.turn();
	    }
	    a.flip();
	}
	return ret;
    }

    public String toString() {
	StringBuffer sb = new StringBuffer();
	sb.append("Ominoes[points=[");
	for (int i=0; i<points.size(); i++) {
	    if (i>0) {
		sb.append(",");
	    }
	    sb.append(points.get(i).toString());
	}
	sb.append("]]");
	return sb.toString();
    }

    public int getWidth() {
	int maxX=0;
	int maxY=0;
	for (Point p : points) {
	    if (p.x > maxX) {
		maxX = p.x;
	    }
	    if (p.y > maxY) {
		maxY = p.y;
	    }
	}
	return maxX+1;
    }
    public int getHeight() {
	int maxX=0;
	int maxY=0;
	for (Point p : points) {
	    if (p.x > maxX) {
		maxX = p.x;
	    }
	    if (p.y > maxY) {
		maxY = p.y;
	    }
	}
	return maxY+1;
    }

    public String print1() {
	shift();
	int maxX=0;
	int maxY=0;
	for (Point p : points) {
	    if (p.x > maxX) {
		maxX = p.x;
	    }
	    if (p.y > maxY) {
		maxY = p.y;
	    }
	}
	StringBuffer sb = new StringBuffer();
	for (int i=0; i<=maxY; i++) {
	    for (int j=0; j<=maxX; j++) {
		Point p1 = new Point(j,i);
		if (points.contains(p1)) {
		    sb.append("#");
		} else {
		    sb.append(" ");
		}
	    }
	    sb.append(String.format("%n"));
	}
	return sb.toString();
    }

    public int hashCode () {
	int ret=0;
	for (Point p : points) {
	    ret ^= p.hashCode();
	}
	return ret;
    }
}
