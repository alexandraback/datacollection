import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Comparator;
import java.util.Iterator;
import java.util.Scanner;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;

public class A implements CodeJamStyleOneCaseSolver {
	
	long r, t;
	
	public void input(Scanner in) {
		r = in.nextLong();
		t = in.nextLong();
	}
	
	public String solve() {
		IndexBinarySearcherResult<Int64> res = IndexBinarySearcherUtil.searchLastTrue(new IndexBinarySearcherData<Int64>() {
			public boolean get(Int64 index) {
				long sum = calc(index);
				boolean rr = sum <= t;
				return rr;
			}
		}, Int64.ONE, new Int64(t));
		return res.getIndex() + "";
	}

	private long calc(Int64 index) {
		long sum = 0;
		for(int i : Range.get(1, (int)index.toPrimitive())) {
			sum += LongSquare.calc(r+2*i-1) - LongSquare.calc(r+2*i-2);
		}
		return sum;
	}

	public static void main(String[] args) throws Exception {
		CodeJamProblemSolverLauncher.launch(8, "A-example.in", new CodeJamStyleOneCaseSolverFactory() {
			public CodeJamStyleOneCaseSolver createSolver() {
				return new A();
			}
		});
	}

}

class LongSquare {

	public static long calc(long a) {
		return a*a;
	}

}

interface IndexBinarySearcherData<T> {
	boolean get(T index);
}

interface IndexBinarySearcherResult<T> {
	
	boolean isExist();
	T getIndex();
	
}

class IndexBinarySearcherUtil {
	
	static public <T extends Int<T>> IndexBinarySearcherResult<T> searchLastTrue(final IndexBinarySearcherData<T> data, T start, T end) {
		IndexBinarySearcherResult<T> subr = IndexBinarySearcher.searchFirstTrue(new IndexBinarySearcherData<T>() {
			public boolean get(T index) {
				return data.get(index.getAddInvert());
			}			
		}, end.getAddInvert(), start.getAddInvert());
		if(subr.isExist())		
			return new IndexBinarySearcher.FoundResult<T>(subr.getIndex().getAddInvert());
		else
			return new IndexBinarySearcher.NotFoundResult<T>();
	}
	
	static public <T> IndexBinarySearcherResult<Int32> searchFirst(final ReadableArray<T> a, int start, int end, final T target, final Comparator<T> comp) {
		IndexBinarySearcherResult<Int32> subr = IndexBinarySearcher.searchFirstTrue(new IndexBinarySearcherData<Int32>() {
			public boolean get(Int32 index) {
				return comp.compare(a.get(index.toPrimitive()), target) >= 0;
			}
		}, new Int32(start), new Int32(end));
		if(subr.isExist() && a.get(subr.getIndex().toPrimitive()).equals(target))
			return subr;
		return new IndexBinarySearcher.NotFoundResult<Int32>();			
	}
	
	static public <T> IndexBinarySearcherResult<Int32> searchLast(final ReadableArray<T> a, int start, int end, final T target, final Comparator<T> comp) {
		IndexBinarySearcherResult<Int32> subr = searchLastTrue(new IndexBinarySearcherData<Int32>() {
			public boolean get(Int32 index) {
				return comp.compare(a.get(index.toPrimitive()), target) <= 0;
			}
		}, new Int32(start), new Int32(end));
		if(subr.isExist() && a.get(subr.getIndex().toPrimitive()).equals(target))
			return subr;
		return new IndexBinarySearcher.NotFoundResult<Int32>();			
	}
	
	static public <T> IndexBinarySearcherResult<Int32> searchFirst(ReadableArray<T> a, int start, int end, T target) {
		return searchFirst(a, start, end, target, new DefaultComparator<T>());			
	}
	
	static public <T> IndexBinarySearcherResult<Int32> searchFirst(ReadableArray<T> a, T target) {
		return searchFirst(a, 0, a.size()-1, target, new DefaultComparator<T>());			
	}
	
	static public <T> IndexBinarySearcherResult<Int32> searchLast(ReadableArray<T> a, T target) {
		return searchLast(a, 0, a.size()-1, target, new DefaultComparator<T>());			
	}
	
	static public <T> IndexBinarySearcherResult<Int32> searchLast(ReadableArray<T> a, int start, int end, T target) {
		return searchLast(a, start, end, target, new DefaultComparator<T>());			
	}
	
}

class DefaultComparator<T> implements Comparator<T> {
	// TODO extends Comparable<T>로 받는게 좋겠다.
	@SuppressWarnings("unchecked")
	public int compare(T arg0, T arg1) {
		return ((Comparable<T>)arg0).compareTo(arg1);
	}

}

interface ReadableArray<T> extends Container<T> {
	T get(int index);
}

interface Container<T> extends Iterable<T> {
	int size();
	boolean isEmpty();
}

interface Int<T extends Int<T>> extends Multiplicative<T> {
	T mod(T v);
	T floorDivide(T v);
	double toDouble();
}

interface Multiplicative<T extends Multiplicative<T>> extends Additive<T> { // 이름바꾸기 Multipliable
	T times(T a);
	T getOne();
	T get(int v);
	boolean isOne();
}

interface Additive<T extends Additive<T>> extends Number<T> { // TODO 이름바꾸기 Addable
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

class Int32 implements Int<Int32>, EqualityChecker<Int32> {
	
	private final int v;
	
	public Int32(int v) {
		this.v = v;
	}

	public Int32 plus(Int32 t) {
		return new Int32(v + t.v);
	}
	
	public Int32 minus(Int32 t) {
		return new Int32(v - t.v);
	}
	
	public int toPrimitive() {
		return v;
	}
	
	public Int32 getAddInvert() {
		return new Int32(-v);
	}
	
	public int compareTo(Int32 o) {
		return compare(v, o.v);
	}

	public static int compare(int v1, int v2) {
		if(v1 > v2)
			return 1;
		else if(v1 < v2)
			return -1;
		return 0;
	}
	
	public String toString() {
		return Integer.toString(v);
	}
	
	public Int32 getZero() {
		return ZERO;
	}
	
	public Int32 getOne() {
		return ONE;
	}
	
	public boolean isOne() {
		return v == 1;
	}
	
	public Int32 times(Int32 a) {
		return new Int32(v * a.v);
	}	
	
	public Int32 floorDivide(Int32 o) {
		return new Int32(v / o.v);
	}
	
	public Int32 mod(Int32 o) {
		return new Int32(v % o.v);
	}		
	
	public double toDouble() {
		return v;
	}
	
	public boolean equals(Object obj) {
		return StrictEqualityChecker.isEquals(this, obj, this);
	}
	
	public boolean isEquals(Int32 o1, Int32 o2) {
		return o1.v == o2.v;
	}
	
	public int hashCode() {
		return Int32Hash.hash(v);
	}	
	
	public int getSign() {
		if(v > 0)
			return 1;
		else if(v < 0)
			return -1;
		return 0;
	}

	public final Int32 get(int v) {
		return new Int32(v);
	}

	public final boolean isPositive() {
		return v > 0;
	}

	public final boolean isNegative() {
		return v < 0;
	}

	public final boolean isZero() {
		return v == 0;
	}

	static final public Int32 ZERO = new Int32(0);
	static final public Int32 ONE = new Int32(1);
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

class IndexBinarySearcher {

	public static class FoundResult<T> implements IndexBinarySearcherResult<T> {
		public T index;
		public FoundResult(T index) {
			this.index = index;
		}
		public T getIndex() {
			return index;
		}
		public boolean isExist() {
			return true;
		}
	}

	public static class NotFoundResult<T> implements IndexBinarySearcherResult<T> {
		public T getIndex() {
			throw new CannotFindProperIndexException();
		}
		public boolean isExist() {
			return false;
		}
	}

	public static <T extends Int<T>> IndexBinarySearcherResult<T> searchFirstTrue(IndexBinarySearcherData<T> data, T left, T right) {
		boolean found = false;
		T index = left;
		T one = left.getOne();
		T two = left.get(2);		
		while(left.compareTo(right) <= 0) {
			T mid = left.plus(right).floorDivide(two);
			if(data.get(mid)) {
				found = true;
				index = mid;
				right = mid.minus(one);
			} else 
				left = mid.plus(one);
		}
		if(found)
			return new IndexBinarySearcher.FoundResult<T>(index);
		else
			return new IndexBinarySearcher.NotFoundResult<T>();
	}

}

class CannotFindProperIndexException extends RuntimeException {
	private static final long serialVersionUID = 1L;
}

class CodeJamProblemSolverLauncher {

	public static void launch(int threadNumber, String inputFileNameOnDesktop, CodeJamStyleOneCaseSolverFactory factory, Integer... caseNumbers) throws Exception {
		String outputFileNameOnDesktop = inputFileNameOnDesktop.substring(0, inputFileNameOnDesktop.length()-3) + ".out";
		String desktopDir = System.getProperty("user.home") + "/Desktop";
		String inputFile = desktopDir + "/" + inputFileNameOnDesktop;
		String outputFile = desktopDir + "/" + outputFileNameOnDesktop;
		CodeJamStyleProblemSolverLauncher.launch(threadNumber, inputFile, outputFile, factory, caseNumbers);
	}

}

interface CodeJamStyleOneCaseSolverFactory {
	CodeJamStyleOneCaseSolver createSolver();
}

interface CodeJamStyleOneCaseSolver {
	void input(Scanner in);
	String solve();
}

class CodeJamStyleProblemSolverLauncher {
	
	public static void launch(final int threadNumber, String inputFilePath, String outputFilePath, final CodeJamStyleOneCaseSolverFactory factory, Integer... caseIndices) throws Exception {
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
				public void run() {
					int casei;
					String result = null;
					{
						CodeJamStyleOneCaseSolver caseSolver = factory.createSolver();
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
					throw new RuntimeException("invalid case index : " + v);
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

class Range {

	public static Iterable<Integer> get(int len) {
		return IntSequenceIterable.create(0, 1, len);
	}

	public static Iterable<Integer> get(int from, int size) {
		return IntSequenceIterable.create(from, 1, size);
	}

}

class IntSequenceIterable {
	public static Iterable<Integer> create(final int from, final int step, final int size) {
		return new Iterable<Integer>() {
			public Iterator<Integer> iterator() {
				return new AbstractIterator<Integer>() {
					int nextIndex = 0;
					public boolean hasNext() {
						return nextIndex < size;
					}
					public Integer next() {
						return from + step * (nextIndex++);
					}
				};
			}
		};
	}
}

abstract class AbstractIterator<T> implements Iterator<T> {
	public final void remove() {
		throw new UnsupportedOperationException();
	}
}

class Int64 implements Int<Int64>, EqualityChecker<Int64> {
	
	// TODO 생성자대신 valueOf 도입하기. 캐시기능추가.
	
	private final long v;
	
	public Int64(long v) {
		this.v = v;
	}

	public Int64 plus(Int64 t) {
		return new Int64(v + t.v);
	}
	
	public Int64 minus(Int64 t) {
		return new Int64(v - t.v);
	}
	
	public long toPrimitive() {
		return v;
	}
	
	public Int64 getAddInvert() {
		return new Int64(-v);
	}
	
	public int compareTo(Int64 o) {
		if(v > o.v)
			return 1;
		else if(v < o.v)
			return -1;
		return 0;
	}
	
	public String toString() {
		return Long.toString(v);
	}
	
	public Int64 getZero() {
		return ZERO;
	}
	
	public Int64 getOne() {
		return ONE;
	}
	
	public boolean isOne() {
		return v == 1;
	}
	
	public Int64 times(Int64 a) {
		return new Int64(v * a.v);
	}	
	
	public Int64 floorDivide(Int64 o) {
		return new Int64(v / o.v);
	}
	
	public Int64 mod(Int64 o) {
		return new Int64(v % o.v);
	}
	
	public double toDouble() {
		return v;
	}
	
	public boolean equals(Object obj) {
		return StrictEqualityChecker.isEquals(this, obj, this);
	}
	
	public boolean isEquals(Int64 o1, Int64 o2) {
		return o1.v == o2.v;
	}
	
	public int hashCode() {
		return Int64Hash.hash6432shift(v);		
	}
	
	public int getSign() {
		if(v > 0)
			return 1;
		else if(v < 0)
			return -1;
		return 0;
	}

	public final Int64 get(int v) {
		return new Int64(v);
	}

	public final boolean isPositive() {
		return v > 0;
	}

	public final boolean isNegative() {
		return v < 0;
	}

	public final boolean isZero() {
		return v == 0;
	}

	static final public Int64 ZERO = new Int64(0);
	static final public Int64 ONE = new Int64(1);
}

class Int64Hash {
	public static int hash6432shift(long key) { 
		// from http://www.concentric.net/~ttwang/tech/inthash.htm
		key = (~key) + (key << 18); // key = (key << 18) - key - 1;
		key = key ^ (key >>> 31);
		key = key * 21; // key = (key + (key << 2)) + (key << 4);
		key = key ^ (key >>> 11);
		key = key + (key << 6);
		key = key ^ (key >>> 22);
		return (int) key;
	}
}
