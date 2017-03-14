import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Comparator;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Scanner;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;
public class D implements CodeJamCaseSolver {
	
	private static final Fraction TWO = new Fraction(2);
	private static final Fraction HALF = new Fraction(1,2);
	int n, m, d;
	String[] a;
	
	@Override
	public void input(Scanner in) {
		n = in.nextInt();
		m = in.nextInt();
		d = in.nextInt();
		a = new String[n];
		for(int i=0;i<n;i++)
			a[i] = in.next();
	}
	
	DynamicArray<Segment<Fraction>> hseg = DynamicArray.create();
	DynamicArray<Segment<Fraction>> vseg = DynamicArray.create();
	DynamicArray<Point<Fraction>> dpoint = DynamicArray.create();
	DynamicArray<Point<Fraction>> rpoint = DynamicArray.create();
	Point<Fraction> spoint;
	
	@Override
	public String solve() {
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				if(a[i].charAt(j) == 'X')
					spoint = Point.create(new Fraction(i).plus(HALF), new Fraction(j).plus(HALF));
		
		for(int i=0;i<n-1;i++)
			for(int j=0;j<m;j++)
				if(isBetweenWallAndSpace(i, j, i+1, j)) 
					vseg.addToLast(Segment.create(Point.create(new Fraction(i+1), new Fraction(j)), Point.create(new Fraction(i+1), new Fraction(j+1))));
		
		for(int i=0;i<n-1;i++) 
			for(int j=0;j<m-1;j++) 
				if(isWall(i,j) == isWall(i,j+1) && isWall(i+1, j)== isWall(i+1,j+1) && isWall(i,j) != isWall(i+1,j))
					vseg.addToLast(Segment.create(Point.create(new Fraction(i+1), new Fraction(j)), Point.create(new Fraction(i+1), new Fraction(j+2))));					
		
		for(int i=0;i<n;i++)
			for(int j=0;j<m-1;j++) 
				if(isBetweenWallAndSpace(i, j, i, j+1))
					hseg.addToLast(Segment.create(Point.create(new Fraction(i), new Fraction(j+1)), Point.create(new Fraction(i+1), new Fraction(j+1))));
		
		for(int i=0;i<n-1;i++) 
			for(int j=0;j<m-1;j++) 
				if(isWall(i,j) == isWall(i+1,j) && isWall(i, j+1)== isWall(i+1,j+1) && isWall(i,j) != isWall(i,j+1))
					hseg.addToLast(Segment.create(Point.create(new Fraction(i), new Fraction(j+1)), Point.create(new Fraction(i+2), new Fraction(j+1))));					
			
		for(int i=0;i<n-1;i++) {
			for(int j=0;j<m-1;j++) {
				int wallcount = 0;
				for(int k=i;k<=i+1;k++)
					for(int q=j;q<=j+1;q++)
						if(isWall(k, q))
							wallcount++;
				if(wallcount == 3)
					rpoint.addToLast(Point.create(new Fraction(i+1), new Fraction(j+1)));
				if(wallcount == 1)
					dpoint.addToLast(Point.create(new Fraction(i+1), new Fraction(j+1)));
			}
		}
		int count = 0;
		int process = 0;
		for(int dx = -50; dx<=50; dx++) {
			for(int dy = -50; dy <= 50; dy++) {
				if(!(dx==0 && dy==0) && SRMGCD.gcd(Math.abs(dx), Math.abs(dy)) == 1 && (dx*dx+dy*dy) <= (d*d)) {
					process ++;
					Point<Fraction> dest = Point.create(spoint.x.plus(new Fraction(dx)), spoint.y.plus(new Fraction(dy)));
//					System.out.println(process + " " + dest);
					HalfLineV2<Fraction> hline = HalfLineV2.create(spoint, dest);
					if(canSee(hline)) 
						count++;
				}
			}			
		}
		
//		HalfLineV2<Fraction> hline = HalfLineV2.create(spoint, Point.create(spoint.x.plus(HALF), spoint.y));
//		HalfLineV2<Fraction> hline = HalfLineV2.create(spoint, Point.create(spoint.x.plus(HALF), spoint.y.plus(HALF)));
//		HalfLineV2<Fraction> hline = HalfLineV2.create(spoint, Point.create(spoint.x, spoint.y.plus(Fraction.ONE)));
//		if(canSee(hline)) 
//			count++;

		return count + "";
	}

	private boolean canSee(HalfLineV2<Fraction> hline) {
		
		Fraction xdiffsum = Fraction.ZERO;
		Fraction ydiffsum = Fraction.ZERO;
				
		while(true) {
//			System.out.println("START " + hline);
			Point<Fraction> cur = hline.startp;
			Point<Fraction> closestInter = null;
			HalfLineV2<Fraction> nextLine = null;
			boolean see = false;
			boolean impossible = false;
			
			for(Segment<Fraction> seg : hseg) {
//				System.out.println(hline + " " + cur + " " + seg + " " + isIntersect(hline, seg) + " " + PointOnSegment.is(cur, seg));
				if(isIntersectExceptStartPoint(hline, seg)) {
					Point<Fraction> inter = getIntersection(hline, seg);
					if(isInSegment(inter, seg)) {
						if(isCloserFrom(inter, closestInter, cur)) {
//							System.out.println(inter);
							closestInter = inter;
							nextLine = HalfLineV2.create(inter, Point.create(cur.x.plus(TWO.times(inter.x.minus(cur.x))), cur.y));
							see = false;
							impossible = false;
						}
					}
				}
			}

			for(Segment<Fraction> seg : vseg) {
//				System.out.println(hline + " " + cur + " " + seg + " " + isIntersect(hline, seg) + " " + PointOnSegment.is(cur, seg));
				if(isIntersectExceptStartPoint(hline, seg)) {
					Point<Fraction> inter = getIntersection(hline, seg);
					if(isInSegment(inter, seg)) {
						if(isCloserFrom(inter, closestInter, cur)) {
//							System.out.println(inter);
							closestInter = inter;
							nextLine = HalfLineV2.create(inter, Point.create(cur.x, cur.y.plus(TWO.times(inter.y.minus(cur.y)))));
							see = false;
							impossible = false;
						}
					}
				}
			}
			
			for(Point<Fraction> p : rpoint) {
				if(!cur.equals(p) && PointOnHalfLine.is(p, hline)) {
					if(isCloserFrom(p, closestInter, cur)) {
//						System.out.println("C " + p);
						closestInter = p;
						nextLine = HalfLineV2.create(p, cur);
						see = false;
						impossible = false;
					}
				}
			}
			
			for(Point<Fraction> p : dpoint) {
				if(PointOnHalfLine.is(p, hline)) {
					if(isCloserFrom(p, closestInter, cur)) {
//						System.out.println("D " + p);
						closestInter = p;
						nextLine = hline;
						see = false;
						impossible = true;
					}
				}
			}
			
			if(PointOnHalfLine.is(spoint, hline)) {
				if(!cur.equals(spoint) && isCloserFrom(spoint, closestInter, cur)) {
					closestInter = spoint;
					nextLine = hline;
					see = true;
					impossible = false;
				}
			}
				
			if(closestInter == null) {
				throw new RuntimeException();
			}
			
//			System.out.println(closestInter);
			
			Fraction xdiff = ABS.abs(closestInter.x.minus(cur.x));
			Fraction ydiff = ABS.abs(closestInter.y.minus(cur.y));
			xdiffsum = xdiffsum.plus(xdiff);
			ydiffsum = ydiffsum.plus(ydiff);
//			System.out.println(xdiff + " " + ydiff);
//			System.out.println(xdiffsum + " " + ydiffsum);
			
			if(sumSquare(xdiffsum, ydiffsum).compareTo(Square.sq(new Fraction(d))) > 0)
				return false;
			if(see)
				return true;
			if(impossible)
				return false;
			
			hline = nextLine;			
		}		
	}

	private boolean isCloserFrom(Point<Fraction> newOne, Point<Fraction> nullableOldOne, Point<Fraction> from) {
		return nullableOldOne == null || DistanceBetweenPoints.calcSquare(from, newOne).compareTo(DistanceBetweenPoints.calcSquare(from, nullableOldOne)) < 0;
	}

	private boolean isIntersectExceptStartPoint(HalfLineV2<Fraction> hline, Segment<Fraction> seg) {
		return isIntersect(hline, seg) && !PointOnSegment.is(hline.startp, seg);
	}

	private Fraction sumSquare(Fraction v1, Fraction v2) {
		return Square.sq(v1).plus(Square.sq(v2));
	}

	private Point<Fraction> getIntersection(HalfLineV2<Fraction> hline, Segment<Fraction> seg) {
		return IntersectionBetweenHalfLineAndSegment.get(hline, seg);
	}

	private boolean isIntersect(HalfLineV2<Fraction> hline, Segment<Fraction> seg) {
		return IntersectionBetweenHalfLineAndSegment.isIntersect(hline, seg);
	}

	private boolean isInSegment(Point<Fraction> pointOnSegment, Segment<Fraction> seg) {
		return !pointOnSegment.equals(seg.p1) && !pointOnSegment.equals(seg.p2);
	}

	private boolean isBetweenWallAndSpace(int x1, int y1, int x2, int y2) {
		return (isWall(x1, y1) && !isWall(x2, y2)) || (!isWall(x1, y1) && isWall(x2, y2));
	}

	private boolean isWall(int x, int y) {
		return isWall(a[x].charAt(y));
	}

	private boolean isWall(char c1) {
		return c1 == '#';
	}

	public static void main(String[] args) throws Exception {
		CodeJamSolver.launch(8, "D-small-attempt0.in", new CodeJamCaseSolverFactory() {
			@Override
			public CodeJamCaseSolver createSolver() {
				return new D();
			}
		});
	}

}
class ABS {
	static public int abs(int v) {
		if(v < 0) {
			return -v;
		} else {
			return v;
		}
	}
	static public <T extends Additive<T>> T abs(T v) {
		if(v.isNegative())
			return v.getAddInvert();
		return v;
	}
}
interface Additive<T extends Additive<T>> extends Number<T> {
	T plus(T v);
	T minus(T v);
	T getAddInvert();
	T getZero();
	boolean isPositive();
	boolean isZero();
	boolean isNegative();
	int getSign();
}
interface Number<T> extends Comparable<T> {
}
class Square {
	static public double sq(double a) {
		return a*a;
	}
	static public long sq(long a) {
		return a*a;
	}
	static public <T extends Multiplicative<T>>T sq(T v) {
		return v.times(v);
	}
}
interface Multiplicative<T extends Multiplicative<T>> extends Additive<T> {
	T times(T a);
	T getOne();
	T get(int v);
	boolean isOne();
}
class SRMGCD {
	
	public static long gcd(long a, long b) {
		if(a<0)
			return gcd(-a,b);
		if(b<0)
			return gcd(a,-b);
		if(a > b) 
			return gcd(b, a);
		while(true) {
			if(a == 0) 
				return b;
			long temp = a;
			a = b % a;
			b = temp;
		}
	}
}
interface CodeJamCaseSolver {
	void input(Scanner in);
	String solve();
}
interface CodeJamCaseSolverFactory {
	CodeJamCaseSolver createSolver();
}
class CodeJamSolver {

	public static void launch(int threadNumber, String inputFileNameOnDesktop, CodeJamCaseSolverFactory factory, Integer... caseNumbers) throws Exception {
		if(!inputFileNameOnDesktop.endsWith(".in"))
			throw new RuntimeException("input filename should ends with '.in'");
		String outputFileNameOnDesktop = inputFileNameOnDesktop.substring(0, inputFileNameOnDesktop.length()-3) + ".out";
		String desktopDir = System.getProperty("user.home") + "/Desktop";
		String inputFile = desktopDir + "/" + inputFileNameOnDesktop;
		String outputFile = desktopDir + "/" + outputFileNameOnDesktop;
		launch(inputFile, outputFile, threadNumber, factory, caseNumbers);
	}

	private static void launch(String inputFilePath, String outputFilePath, final int threadNumber, final CodeJamCaseSolverFactory factory, Integer... caseIndices) throws Exception {
		final Object lock = new Object();
		final long startTime = System.currentTimeMillis();
		final Scanner in = new Scanner(new File(inputFilePath));
		final int casen = in.nextInt();
		final int[] nextIndex = {0}; 
		final String[] results = new String[casen];
		final java.util.Set<Integer> caseIndexToSolve = createCaseIndicesToSolve(casen, caseIndices);
		ExecutorService executor = Executors.newFixedThreadPool(threadNumber);
		for(int i=0;i<casen;i++) {
			executor.execute(new Runnable() {
				@Override
				public void run() {
					int casei;
					String result = null;
					{
						CodeJamCaseSolver caseSolver = factory.createSolver();
						synchronized(lock) {
							caseSolver.input(in);
							casei = nextIndex[0]++;
						}
						if(caseIndexToSolve.contains(casei+1))
							result = caseSolver.solve();
					}
					if(result != null) {
						synchronized(lock) {
							results[casei] = result;
							int solved = countNotNull(results);
							outputProgess(startTime, solved, caseIndexToSolve.size());
						}
					}
				}
			});
		}
		executor.shutdown();
		executor.awaitTermination(Long.MAX_VALUE, TimeUnit.SECONDS);
		printLine();
		outputResult(results, outputFilePath);
		printLine();
		System.out.println("Output is written to " + outputFilePath);
	}

	private static java.util.Set<Integer> createCaseIndicesToSolve(int casen, Integer... caseIndices) {
		final java.util.Set<Integer> set = new java.util.TreeSet<Integer>();
		if(caseIndices.length == 0) {
			for(int i=1;i<=casen;i++)
				set.add(i);
		} else {
			for(int v : caseIndices) {
				if(v < 1 || v > casen)
					throw new RuntimeException("invalid index : " + v);
				set.add(v);
			}
		}
		return set;
	}

	private static void printLine() {
		for(int i=0;i<100;i++)
			System.out.print("-");
		System.out.println();
	}

	private static int countNotNull(final String[] results) {
		int solved = 0;
		for(String s : results)
			if(s != null)
				solved++;
		return solved;
	}

	private static void outputProgess(long startTime, int solved, int caseNumberToSolve) {
		long duration = System.currentTimeMillis() - startTime;
		long estimation = (long)Math.round((double)duration * caseNumberToSolve / solved / 1000);
		System.out.printf("%.03fs : %d/%d solved (estimated : %dm %ds)\n", (double)duration / 1000, solved,  caseNumberToSolve, estimation / 60, estimation % 60);
	}

	private static void outputResult(final String[] results, String outputFilePath) throws FileNotFoundException {
		PrintStream ps = new PrintStream(outputFilePath);
		for(int i=0;i<results.length;i++) {
			if(results[i] != null) {
				String line = String.format("Case #%d: %s", i+1, results[i]);
				System.out.println(line);
				ps.println(line);
			}
		}
		ps.close();
	}

}
class DynamicArray<T> extends AbstractReadableArray<T>  implements StaticArray<T> {
	
	public static <T> DynamicArray<T> create() {
		return new DynamicArray<T>();
	}
	
	private T[] a;
	private int asize;
	
	
	@SuppressWarnings("unchecked")
	private void init(int cap) {
		asize = 0;
		a = (T[])new Object[Math.max(1, cap)];		
	}
	
	public DynamicArray() {
		init(1);
	}
	
	public DynamicArray(int initialCapacity) {
		init(initialCapacity);
	}
	
	public T get(int index) {
		return a[index];
	}	
	
	public void set(int index, T value) {
		a[index] = value;		
	}
	
	public int size() {
		return asize;
	}
	
	public void clear() {
		asize = 0;
	}
	
	@SuppressWarnings("unchecked")
	public void reserve(int size) {
		if(a.length < size) {
			T[] ta = (T[])new Object[size];
			for(int i=0;i<a.length;i++)
				ta[i] = a[i];
			a = ta;
		}
	}
	
	@SuppressWarnings("unchecked")
	public void addToLast(T value) {
		if(a.length == asize) {
			T[] ta = (T[])new Object[asize*2];
			for(int i=0;i<asize;i++)
				ta[i] = a[i];
			a =ta;
		}
		a[asize++] = value;						
	}
	
	public void addToLastAll(Iterable<? extends T> values) {
		for(T v : values)
			addToLast(v);
	}
	
	public T removeLast() {
		T r = last();
		a[--asize] = null;
		return r;
	}
	
	@Override
	public boolean equals(Object obj) {
		return StrictEqualityChecker.isEquals(this, obj, new EqualityChecker<DynamicArray<T>>() {
			@Override
			public boolean isEquals(DynamicArray<T> o1, DynamicArray<T> o2) {
				if(o1.size() != o2.size())
					return false;
				for(int i=0;i<o1.size();i++)
					if(!o1.get(i).equals(o2.get(i)))
						return false;		
				return true;
			}
		});
	}

	@Override
	public int hashCode() {
		int r = 0;
		for(int i=0;i<size();i++)
			r ^= Int32Hash.hash(get(i).hashCode());
		return r;
	}
	
}
interface EqualityChecker<T> {
	boolean isEquals(T o1, T o2);
}
class Int32Hash {

	public static int hash(int key) {
	  key = ~key + (key << 15); // key = (key << 15) - key - 1;
	  key = key ^ (key >>> 12);
	  key = key + (key << 2);
	  key = key ^ (key >>> 4);
	  key = key * 2057; // key = (key + (key << 3)) + (key << 11);
	  key = key ^ (key >>> 16);
	  return key;
	}
}
class StrictEqualityChecker {

	@SuppressWarnings("unchecked")
	public static <T> boolean isEquals(T me, Object you, EqualityChecker<T> ec) {
		if(me == you)
			return true;
		if(you == null)
			return false;
		if(you.getClass() != me.getClass())
			return false;
		return ec.isEquals(me, (T)you);
	}

}
abstract class AbstractReadableArray<T> extends AbstractContainer<T> implements ReadableArray<T> {
	
	@Override
	public final boolean isEmpty() {
		return size() == 0;
	}
	
	@Override
	public final T last() {
		return get(size()-1);
	}
	
	@Override
	public final T first() {
		return get(0);
	}	
	
	@Override
	public final Iterator<T> iterator() {
		return new AbstractIterator<T>() {
			int p = 0;
			public boolean hasNext() {
				return p < size();
			}
			public T next() {
				return get(p++);
			}
		};
	}

}
abstract class AbstractContainer<T> implements Container<T> {

	@Override
	public final String toString() {
		StringBuilder sb = new StringBuilder();
		sb.append('(');
		boolean first = true;
		for(T v : this) {
			if(first)
				first = false;
			else
				sb.append(',');
			sb.append(v);
		}
		sb.append(')');
		return sb.toString();
	}
	
}
interface Container<T> extends Iterable<T> {
	int size();
	boolean isEmpty();
}
abstract class AbstractIterator<T> implements Iterator<T> {

	@Override
	public final void remove() {
		throw new UnsupportedOperationException();
	}

}
interface ReadableArray<T> extends Container<T> {
	T get(int index);
	T last();
	T first();
}
interface StaticArray<T> extends ReadableArray<T>{
	void set(int index, T value);	
}
class DistanceBetweenPoints {
	
	public static double calc(Point<Dbl> p1, Point<Dbl> p2) {
		return Math.sqrt(DistanceBetweenPoints.calcSquare(p1, p2).toPrimitive());		
	}

	public static <T extends Multiplicative<T>> T calcSquare(Point<T> p1, Point<T> p2) {
		T sq1 = Square.sq(p1.x.minus(p2.x));
		T sq2 = Square.sq(p1.y.minus(p2.y));
		return sq1.plus(sq2);
	}
}
class Dbl extends AbstractMultiplicative<Dbl> implements RealNumber<Dbl>, EqualityChecker<Dbl> {

	// TODO factory? ????, ???? ????? ??? ? ??? ??	
	
	private final double v;
	
	public Dbl(double v) {
		this.v = v;
	}

	@Override
	public Dbl plus(Dbl t) {
		return new Dbl(v + t.v);
	}

	@Override
	public Dbl minus(Dbl t) {
		return new Dbl(v - t.v);
	}
	
	@Override
	public Dbl getAddInvert() {
		return new Dbl(-v);
	}
	
	@Override
	public String toString() {
		if(v == Math.round(v))
			return Integer.toString((int)v);
		return Double.toString(v);
	}
	
	public double toPrimitive() {
		return v;
	}
	
	@Override
	public int compareTo(Dbl o) {
		return DoubleCompare.compare(v, o.v);
	}
	
	@Override
	public Dbl getZero() {
		return ZERO;
	}
	
	@Override
	public Dbl divide(Dbl o) {
		return new Dbl(v / o.v);
	}
	
	@Override
	public Dbl getOne() {
		return ONE;
	}
	
	@Override
	public Dbl getMultiplicativeInvert() {
		return new Dbl(1/v);
	}
	
	@Override
	public Dbl times(Dbl a) {
		return new Dbl(v * a.v);
	}	
	
	@Override
	public boolean equals(Object obj) {
		return StrictEqualityChecker.isEquals(this, obj, this);
	}
	
	@Override
	public boolean isEquals(Dbl o1, Dbl o2) {
		return o1.compareTo(o2) == 0; // TODO ?.. equality? eps? ?? ???? ???..
	}
	
	@Override
	public int hashCode() { 
		return 1; //TODO GG!!
	}
	
	static public final Dbl ZERO = new Dbl(0);
	static public final Dbl ONE = new Dbl(1);

}
class DoubleCompare {
	
	static public double eps = 1e-12;  
	
	static public int compare(double v1, double v2) {
		if(Math.abs(v1-v2) < eps)
			return 0;
		else if(v1 < v2)
			return -1;			
		else
			return 1;
	}
	
	static public int getSign(double v) {
		if(Math.abs(v) < eps)
			return 0;
		else if(v < 0)
			return -1;			
		else
			return 1;
	}
	
	static public boolean isZero(double v) {
		return compare(v, 0)==0;
	}
	
	static public boolean isPositive(double v) {
		return compare(v, 0) > 0;
	}

	static public boolean isNegative(double v) {
		return compare(v, 0) < 0;
	}
	
	static public final Comparator<Double> comparator = new Comparator<Double>() {
		public int compare(Double o1, Double o2) {
			return DoubleCompare.compare(o1, o2);			
		}
	};

}
abstract class AbstractMultiplicative<T extends Multiplicative<T>> extends AbstractAdditive<T> implements Multiplicative<T> {

	@Override
	public final boolean isOne() {
		return equals(getOne());
	}
	
	@Override
	public final T get(int v) { // O(log) ? ?? ????? ??? ??? ?.
		T r = getOne();
		for(int i=0;i<v-1;i++)
			r = r.plus(getOne());
		return r;
	}
}
abstract class AbstractAdditive<T extends Additive<T>> implements Additive<T> {
	
	@Override
	public final boolean isPositive() {
		return getSign() > 0;
	}
	
	@Override
	public final boolean isNegative() {
		return getSign() < 0;
	}
	
	@Override
	public final boolean isZero() {
		return getSign() == 0;
	}
	
	@Override
	public final int getSign() {
		return compareTo(getZero());
	}
}
interface RealNumber<T extends RealNumber<T>> extends Divisable<T> {
}
interface Divisable<T extends Divisable<T>> extends Multiplicative<T> {
	T divide(T o);
	T getMultiplicativeInvert();
}
class Point<T> implements Vector2D<T>, EqualityChecker<Point<T>> {

	public static <T> Point<T> create(T x, T y) {
		return new Point<T>(x, y); 
	}
	
	public final T x;
	public final T y;
	
	public Point(T x, T y) {
		this.x = x;
		this.y = y;
	}

	public T x() {
		return x;
	}
	
	public T y() {
		return y;
	}

	@Override
	public final boolean equals(Object o) {
		return StrictEqualityChecker.isEquals(this, o, this);
	}

	@Override
	public boolean isEquals(Point<T> o1, Point<T> o2) {
		return o1.x.equals(o2.x) && o1.y.equals(o2.y);
	}

	public final int hashCode() {
		return x.hashCode() ^ y.hashCode();
	}
	
	@Override
	public String toString() {
		return "(" + x + "," + y + ")";
	}
	
}
interface Vector2D<T> {
	T x();
	T y();
}
class IntersectionBetweenHalfLineAndSegment {
	
	// TODO ???? halfline? ????? segment? ???? ??? ????? ???? ???? ????-_-; 
	
	public static <T extends Divisable<T>> boolean isIntersect(HalfLineV2<T> hline, Segment<T> seg) {
		Line<T> line1 = LineFromPoint.toLine(hline.startp, hline.directionp);
		Line<T> line2 = LineFromPoint.toLine(seg.p1, seg.p2);
		if(ParallelBetweenLines.isParallel(line1, line2))
			return false;
		Point<T> inter = IntersectionOfLines.calc(line1, line2);
		return PointOnHalfLine.is(inter, hline) && PointOnSegment.is(inter, seg);
	}
	
	public static <T extends Divisable<T>> Point<T> get(HalfLineV2<T> hline, Segment<T> seg) {
		Line<T> line1 = LineFromPoint.toLine(hline.startp, hline.directionp);
		Line<T> line2 = LineFromPoint.toLine(seg.p1, seg.p2);
		Point<T> inter = IntersectionOfLines.calc(line1, line2);
		if(PointOnHalfLine.is(inter, hline) && PointOnSegment.is(inter, seg))
			return inter;
		else
			throw new IllegalArgumentException("No Intersection between " + hline + " and " + seg);
	}
}
class HalfLineV2<T> {
	
	public static <T> HalfLineV2<T> create (Point<T> startp, Point<T> directionp) {
		return new HalfLineV2<T>(startp, directionp);
	}
	
	public final Point<T> startp,  directionp;
	
	public HalfLineV2(Point<T> startp, Point<T> directionp) {
		this.startp = startp;
		this.directionp = directionp;
	}
	
	@Override
	public String toString() {
		return "HalfLine(" + startp + "-" + directionp + ")";
	}
}
class HalfLine {
	public final Point<Dbl> p;
	public final Direction d;
	
	public HalfLine(Point<Dbl> p, Direction d) {
		this.p = p;
		this.d = d;
	}
	
	public HalfLine(Point<Dbl> start, Point<Dbl> end) {
		p = start;
		d = DirectionFromPoint.calc(end, start);
	}
}
class DirectionFromPoint {

	public static Direction calc(Point<Dbl> p, Point<Dbl> ref) {
		return new Direction(Math.atan2(p.y.toPrimitive() - ref.y.toPrimitive(), p.x.toPrimitive() - ref.x.toPrimitive()));
	}

}
class Direction {
	
	public final double a; // 0 =< a < 2pi
	
	public Direction(double radian) {
		if(Double.isNaN(radian))
			throw new IllegalArgumentException("Direction cannot be NaN");
		while(radian < 0)
			radian += Math.PI + Math.PI;
		while(DoubleCompare.compare(radian,Math.PI + Math.PI) >= 0)
			radian -= Math.max(0, Math.PI + Math.PI);
		a = radian;
	}
	
	@Override
	public final boolean equals(Object v) { // TODO A? ??? ????? ??? ???. 
		if(v==null)
			return false;
		if(v == this)
			return true;
		if(!(v instanceof Direction))
			return false;
		Direction d = (Direction)v;
		return OldDoubleEquals.equals(a, d.a);
	}
	
	@Override
	public final int hashCode() { // TODO equals? ??? ????
		return 1;
	}
	
	public double cos() {
		return Math.cos(a);
	}
	
	public double sin() {
		return Math.sin(a);
	}
	
	public double tan() {
		return Math.tan(a);
	}
	
	public String toString() {
		return "Dir(" + String.format("%.2f", a) +"pi)";
	}
	
}
class OldDoubleEquals {

	static public boolean equals(double v1, double v2) {
		return DoubleCompare.compare(v1,v2)==0;
	}

}
class Line<T extends Additive<T>> implements EqualityChecker<Line<T>> {

	public final T a,b,c; // ax+by+c = 0 

	public Line(T a,T b,T c) {
		this.a = a;
		this.b = b;
		this.c = c;
	}
	
	@Override
	public final boolean equals(Object obj) {
		return StrictEqualityChecker.isEquals(this, obj, this);
	}

	@Override
	public boolean isEquals(Line<T> o1, Line<T> o2) {
		return o1.a.equals(o2.a) && o1.b.equals(o2.b) && o1.c.equals(o2.c);
	}
	
	@Override
	public int hashCode() {
		return a.hashCode() ^ b.hashCode() ^ c.hashCode();
	}
	
	@Override
	public String toString() {
		String r = a + "x";
		if(!b.isNegative())
			r += "+";
		r += b + "y";
		if(!c.isNegative())
			r += "+";
		r += c + "=0";
		return r;
	}
}
class Segment<T> {
	
	public static <T> Segment<T> create(Point<T> p1, Point<T> p2) {
		return new Segment<T>(p1, p2);
	}
	
	public final Point<T> p1;
	public final Point<T> p2;

	public Segment(Point<T> p1, Point<T> p2) {
		if(p1.equals(p2))
			throw new RuntimeException("Segment : two points are same");
		this.p1 = p1;
		this.p2 = p2;
	}

	public String toString() {
		return "Segment(" + p1 + " - " + p2 + ")";
	}
	
	@SuppressWarnings("unchecked")
	public final boolean equals(Object obj) { // TODO use util class
		if(obj == null)
			return false;
		if(obj == this)
			return true;
		if(!(obj instanceof Segment))
			return false;
		Segment<T> s = (Segment<T>)obj;
		return (p1.equals(s.p1) && p2.equals(s.p2)) || (p1.equals(s.p2) && p2.equals(s.p1));
	}
	
	public final int hashCode() { // TODO improve.
		return p1.hashCode() + p2.hashCode();
	}
	
}
class IntersectionOfLines {
	
	public static <T extends Divisable<T>> Point<T> calc(Line<T> line1, Line<T> line2) {
		if(ParallelBetweenLines.isParallel(line1, line2))
			throw new IllegalArgumentException("Two lines (" + line1 + " and " + line2 + ") are parellel");
		T divisor = line2.a.times(line1.b).minus(line1.a.times(line2.b));
		T x = (line2.b.times(line1.c).minus(line1.b.times(line2.c))).divide(divisor);
		T y = (line2.a.times(line1.c).minus(line1.a.times(line2.c))).divide(divisor.getAddInvert());
		return Point.create(x, y);
	}

}
class ParallelBetweenLines {
	public static <T extends Multiplicative<T>> boolean isParallel(Line<T> line1, Line<T> line2) {
		return line2.a.times(line1.b).equals(line1.a.times(line2.b));
	}
}
class LineFromPoint {

	public static <T extends Divisable<T>> Line<T> toLine(Point<T> p1, Point<T> p2) {
		T a, b, c;
		if(p1.x.equals(p2.x)) {
			if(p1.y.equals(p2.y))
				throw new IllegalArgumentException("Cannot create a line from same points");
			a = p1.x.getOne();
			b = p1.x.getZero();
			c  = p1.x.getAddInvert();
		} else {
			b = p1.x.getOne();
			a = (p1.y.minus(p2.y)).divide(p1.x.minus(p2.x)).getAddInvert();
			c = a.times(p1.x).getAddInvert().minus(b.times(p1.y));
		}
		return new Line<T>(a, b, c);
	}
}
class PointOnHalfLine {
	
	public static <T extends Multiplicative<T>> boolean is(Point<T> p, HalfLineV2<T> h) {
		return StraightLine.is(h.startp, h.directionp, p) || StraightLine.is(h.startp, p, h.directionp);
	}

}
class StraightLine { // TODO rename StraightOrder

	static public <T extends Multiplicative<T>>boolean is(Point<T> p1,Point<T> p2,Point<T> p3) {
		if(!CCW.ccw(p1, p2, p3).isZero())
			return false;
		
		T maxx = Max.max(p1.x, p3.x);
		T minx = Min.min(p1.x, p3.x);
		T maxy = Max.max(p1.y, p3.y);
		T miny = Min.min(p1.y, p3.y);
		return InRange.is(p2.x, minx, maxx) && InRange.is(p2.y, miny, maxy);
		
//		T dis13 = DistanceBetweenPoints.calcSquare(p1, p3);
//		
//		if(DistanceBetweenPoints.calcSquare(p1, p2).compareTo(dis13) > 0)
//			return false;
//		
//		if(DistanceBetweenPoints.calcSquare(p2, p3).compareTo(dis13) > 0)
//			return false;
//		return true;		
	}

}
class InRange {
	
	static public <T extends Comparable<T>> boolean is(T v, T lower, T upper) {
		return lower.compareTo(v) <= 0 && v.compareTo(upper) <= 0;
	}

}
class Max {
	
	public static <T extends Comparable<T>> T max(T v1, T v2) {
		if(v1.compareTo(v2) > 0)
			return v1;
		else
			return v2;
	}
	
}
class Min {
	// TODO MAX? ???? ??
	// TODO ? ??? ????
	
	static public <T extends Comparable<T>> T min(T v1, T v2) {
		if(v1.compareTo(v2) < 0)
			return v1;
		else
			return v2;
	}

	static public <T> T min(Iterable<T> c, Comparator<T> comp) {
		T min = null;
		for(T a : c) 
			if(min == null || comp.compare(min, a) > 0)
				min = a;
		return min;
	}
	
	static public <T> int minIndex(ReadableArray<T> c, Comparator<T> comp) {
		int r = -1;
		for(int i=0;i<c.size();i++)
			if(r==-1 || comp.compare(c.get(r), c.get(i)) > 0)
				r = i;
		return r;
	}
	
	static public <T extends Comparable<T>> T min(Iterable<T> c) {
		return min(c, new DefaultComparator<T>()); 
	}
}
class DefaultComparator<T> implements Comparator<T> {

	@SuppressWarnings("unchecked")
	public int compare(T arg0, T arg1) {
		return ((Comparable<T>)arg0).compareTo(arg1);
	}

}
class CCW {
	static public <T extends Multiplicative<T>> T ccw(Point<T> p1, Point<T> p2, Point<T> p3) {
		return p1.x.times(p2.y).plus(p2.x.times(p3.y)).plus(p3.x.times(p1.y)).minus(p1.x.times(p3.y)).minus(p2.x.times(p1.y)).minus(p3.x.times(p2.y)).getAddInvert();
	}
}
class PointOnSegment {
	static public <T extends Multiplicative<T>>boolean is(Point<T> p, Segment<T> s) {
		return StraightLine.is(s.p1, p, s.p2);
	}
}
class Fraction extends AbstractMultiplicative<Fraction> implements Divisable<Fraction>, EqualityChecker<Fraction> {
	
	public final long up;
	public final long down;
	
	public Fraction(long v) {
		up = v;
		down = 1;
	}
	
	public Fraction(long iup, long idown) {
		if(idown < 0) {
			iup *= -1;
			idown *= -1;
		}
		long gcd = SRMGCD.gcd(iup, idown);
		this.up = iup / gcd;
		this.down = idown / gcd;
		if(!LongInRange.is(up*down, -100000000000000000L, 100000000000000000L))
			throw new RuntimeException(iup + " " + idown);
	}
	
	public Fraction(String s) {
		int p = s.indexOf('/');
		String ups, downs;
		if(p == -1) {
			ups = s;
			downs = "1";
		} else {
			ups = s.substring(0,p);
			downs = s.substring(p+1);
		}
		up = Long.parseLong(ups);
		down = Long.parseLong(downs);
	}
	
	@Override
	public Fraction times(Fraction f) {
		return new Fraction(up * f.up, down * f.down);
	}
	
	@Override
	public Fraction divide(Fraction f) {
		return new Fraction(up * f.down, down * f.up);
	}
	
	@Override
	public Fraction plus(Fraction f) {
		return new Fraction(up * f.down + f.up * down, down * f.down);
	}
	
	@Override
	public Fraction minus(Fraction f) {
		return new Fraction(up * f.down - f.up * down, down * f.down);
	}
	
	@Override
	public int compareTo(Fraction o) {
		long v1 = up *  o.down;
		long v2 = o.up * down;
		if(v1 < v2)
			return -1;
		else if(v1 > v2)
			return 1;
		else
			return 0;
	}
	
	@Override
	public Fraction getZero() {
		return ZERO;
	}
	
	@Override
	public Fraction getAddInvert() {
		return new Fraction(-up, down);
	}
	
	@Override
	public Fraction getOne() {
		return ONE;
	}
	
	@Override
	public Fraction getMultiplicativeInvert() {
		return new Fraction(down, up);
	}
	
	@Override
	public String toString() {
		if(down == 1)
			return up + "";
		else
			return up + "/" + down;
	}
	
	public double toDouble() {
		return (double)up / down;
	}
	
	@Override
	public boolean equals(Object obj) {
		return StrictEqualityChecker.isEquals(this, obj, this);
	}
	
	@Override
	public boolean isEquals(Fraction o1, Fraction o2) {
		return o1.compareTo(o2) == 0;
	}	
	
	@Override
	public int hashCode() {
		return (int)(up ^ down);
	}
	
	static final public Fraction ZERO = new Fraction(0);
	static final public Fraction ONE = new Fraction(1);
}
class LongInRange {
	public static boolean is(long v, long min, long max) {
		return min <= v && v <= max;
	}
}
class C implements CodeJamCaseSolver {
	
	int a, b;
	
	@Override
	public void input(Scanner in) {
		a = in.nextInt();
		b = in.nextInt();
	}
	
	@Override
	public String solve() {
		int count = 0;
		for(int i=a;i<=b;i++) {
			int n = i;
			String s = Integer.toString(i);
			Set<Integer> mset = new HashSetFactory().create();
			for(int j=0;j<s.length();j++) {
				String ms = s.substring(j, s.length()) + s.substring(0, j);
				int m = Integer.parseInt(ms);
				if(n != m && IntInRange.is(m, a, b))
				mset.insert(m);
			}
			count += mset.size();
		}
		return count/2 + "";
	}

	public static void main(String[] args) throws Exception {
		CodeJamSolver.launch(8, "C-large.in", new CodeJamCaseSolverFactory() {
			@Override
			public CodeJamCaseSolver createSolver() {
				return new C();
			}
		});
	}

}
class IntInRange {
	public static boolean is(int v, int min, int max) {
		return min <= v && v <= max;
	}
}
class HashSetFactory implements SetFactory {

	public <T> Set<T> create() {
		return new SetWrapper<T>(new HashSet<T>());
	}
	
}
interface Set<T> extends Container<T> {
	
	void clear();
	void insert(T v);
	void insertAll(Iterable<T> a);
	boolean contains(T v);
	void remove(T v);
}
interface SetFactory {
	<T> Set<T> create();
}
class SetWrapper<T> extends AbstractSet<T> {
	
	private final java.util.Set<T> set;
	
	public SetWrapper(java.util.Set<T> set) {
		this.set = set;
	}
	public void clear() {
		set.clear();		
	}
	
	public boolean contains(T v) {
		return set.contains(v);		
	}
	
	public void insert(T v) {
		set.add(v);
	}

	public Iterator<T> iterator() {
		return set.iterator();
	}
	
	public int size() {
		return set.size();
	}
	
	public void remove(T v) {
		set.remove(v);
	}
}
abstract class AbstractSet<T> implements Set<T> {

	final public void insertAll(Iterable<T> a) {
		for(T v : a)
			insert(v);
	}
	
	@Override
	final public boolean isEmpty() {
		return size() == 0;
	}
	
	final public String toString() {
		String r = "";
		for(T v : this) {
			if(!r.isEmpty())
				r += ",";
			r += v;			
		}
		return "{" + r + "}";
	}

}
