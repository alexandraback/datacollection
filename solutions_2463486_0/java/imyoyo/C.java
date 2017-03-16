import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Iterator;
import java.util.Scanner;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;
public class C1 implements OneCaseSolver {

	static DynamicArray<Long> v = DynamicArray.create();

	static {
		for(long i=1;i*i<=1000000000000000L;i++) {
			long cand = i*i;
			if(ispal(i) && ispal(cand)) {
				v.addToLast(cand);
			}
		}
	}

	private static boolean ispal(long cand) {
		String s = Long.toString(cand);
		boolean ok = true;
		for(int j : Indices.create(s.length()/2)) 
			if(s.charAt(j) != s.charAt(s.length()-1-j))
				ok = false;
		return ok;
	}

	long a, b;
	
	@Override
	public void input(Scanner in) {
		a = in.nextLong();
		b = in.nextLong();
	}
	
	@Override
	public String solve() {
		IndexBinarySearcherResult<Int32> r1 = IndexBinarySearcher.searchFirstTrue(new IndexBinarySearcherData<Int32>() {
			@Override
			public boolean get(Int32 index) {
				return a <= v.get(index.toPrimitive());
			}
		}, new Int32(0), new Int32(v.size()-1));
		
		IndexBinarySearcherResult<Int32> r2 = IndexBinarySearcher.searchFirstTrue(new IndexBinarySearcherData<Int32>() {
			@Override
			public boolean get(Int32 index) {
				return b < v.get(index.toPrimitive());
			}
		}, new Int32(0), new Int32(v.size()-1));
		return (r2.getIndex().toPrimitive() - r1.getIndex().toPrimitive()) + "";
	}

	public static void main(String[] args) throws Exception {
		String ex = "C.in";
		CodeJamProblemSolver.launch(1, "C-small-attempt0.in", new OneCaseSolverFactory() {
			@Override
			public OneCaseSolver createSolver() {
				return new C1();
			}
		});
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
interface Int<T extends Int<T>> extends Multiplicative<T> {
	T mod(T v);
	T floorDivide(T v);
	double toDouble();
}
interface Multiplicative<T extends Multiplicative<T>> extends Additive<T> {
	T times(T a);
	T getOne();
	T get(int v);
	boolean isOne();
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
class CannotFindProperIndexException extends RuntimeException {
	private static final long serialVersionUID = 1L;
}
interface IndexBinarySearcherData<T> {
	boolean get(T index);
}
interface IndexBinarySearcherResult<T> {
	
	boolean isExist();
	T getIndex();
	
}
class CodeJamProblemSolver {

	public static void launch(int threadNumber, String inputFileNameOnDesktop, OneCaseSolverFactory factory, Integer... caseNumbers) throws Exception {
		String outputFileNameOnDesktop = inputFileNameOnDesktop.substring(0, inputFileNameOnDesktop.length()-3) + ".out";
		String desktopDir = System.getProperty("user.home") + "/Desktop";
		String inputFile = desktopDir + "/" + inputFileNameOnDesktop;
		String outputFile = desktopDir + "/" + outputFileNameOnDesktop;
		CodeJamStyleProblemSolver.launch(threadNumber, inputFile, outputFile, factory, caseNumbers);
	}

}
class CodeJamStyleProblemSolver {
	
	public static void launch(final int threadNumber, String inputFilePath, String outputFilePath, final OneCaseSolverFactory factory, Integer... caseIndices) throws Exception {
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
						OneCaseSolver caseSolver = factory.createSolver();
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
interface OneCaseSolver {
	void input(Scanner in);
	String solve();
}
interface OneCaseSolverFactory {
	OneCaseSolver createSolver();
}
class Indices {

	public static IntSequenceIterable create(int len) {
		return new IntSequenceIterable(0, len);
	}

}
class IntSequenceIterable implements Iterable<Integer> {
	
	private final int from;
	private final int size;

	public IntSequenceIterable(int from, int size) {
		this.from = from;
		this.size = size;
	}

	@Override
	public Iterator<Integer> iterator() {
		return new AbstractIterator<Integer>() {
			int next = from;
			@Override
			public boolean hasNext() {
				return next < from + size;
			}
			@Override
			public Integer next() {
				return next++;
			}
		};
	}
}
abstract class AbstractIterator<T> implements Iterator<T> {

	@Override
	public final void remove() {
		throw new UnsupportedOperationException();
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
interface ReadableArray<T> extends Container<T> {
	T get(int index);
	T last();
	T first();
}
interface StaticArray<T> extends ReadableArray<T>{
	void set(int index, T value);	
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
	
	@Override
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
	
	@Override
	public boolean equals(Object obj) {
		return StrictEqualityChecker.isEquals(this, obj, this);
	}
	
	@Override
	public boolean isEquals(Int32 o1, Int32 o2) {
		return o1.v == o2.v;
	}
	
	@Override
	public int hashCode() {
		return Int32Hash.hash(v);
	}	
	
	@Override
	public int getSign() {
		if(v > 0)
			return 1;
		else if(v < 0)
			return -1;
		return 0;
	}

	@Override
	public final Int32 get(int v) {
		return new Int32(v);
	}

	@Override
	public final boolean isPositive() {
		return v > 0;
	}

	@Override
	public final boolean isNegative() {
		return v < 0;
	}

	@Override
	public final boolean isZero() {
		return v == 0;
	}

	static final public Int32 ZERO = new Int32(0);
	static final public Int32 ONE = new Int32(1);
}
