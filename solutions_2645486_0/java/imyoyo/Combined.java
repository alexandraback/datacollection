import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Scanner;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;

public class B implements CodeJamStyleOneCaseSolver{
	
	int e, r, n;
	int[] v = new int[10000000];
	
	public void input(Scanner in) {
		e = in.nextInt();
		r = in.nextInt();
		n = in.nextInt();
		for(int i: Range.get(n))
			v[i] = in.nextInt();
	}
	
	public String solve() {
		Memoization<Index2D, Long> memo = new MemoizationFactory(new JavaHashMapFactory()).create(new ItemCalculator<Index2D, Long>() {
			public Long calc(Index2D index, SubItem<Index2D, Long> sub) {
				int i = index.i1;
				int j = index.i2;
				if(i == n) {
					return 0L;
				} else {
					long max = 0;
					for(int k : Range.get(0, j+1)) {
						max = Math.max(max, v[i] * k + sub.get(new Index2D(i+1, Math.min(j-k+r, e))));
					}
					return max;
				}
			}
		});
		
		return memo.get(new Index2D(0, e)) + "";
	}

	public static void main(String[] args) throws Exception {
		String ex = "B-example.in";
		CodeJamProblemSolverLauncher.launch(8, ex, new CodeJamStyleOneCaseSolverFactory() {
			public CodeJamStyleOneCaseSolver createSolver() {
				return new B();
			}
		});
	}

}

interface ItemCalculator<I, V> {
	V calc(I index, SubItem<I, V> sub);
}

interface SubItem<I, V> {
	V get(I index);
}

class Memoization<I, V> {
	
	private ItemCalculator<I, V> calc;  
	private Map<I, V> table;
	
	// TODO factory에 익명클래스로 넣자.
	Memoization(MapFactory mapFactory, ItemCalculator<I, V> calc) {
		this.calc = calc; 
		this.table = mapFactory.create();
	}

	public V get(I index) {
		V v = table.get(index);
		if(v == null) {
			v = calc.calc(index, subItem);
			table.put(index, v);
		}
		return v;
	}
	
	private SubItem<I, V> subItem = new SubItem<I, V>() {
		public V get(I index) {
			return Memoization.this.get(index);
		}			
	};

}

interface Map<K, V> extends Container<Entry<K, V>> {
	void clear(); 
	void put(K key, V value);
	void remove(K key);
	boolean containsKey(K key);
	V get(K key);
	Iterable<V> values();
	Iterable<K> keys();
}

interface Container<T> extends Iterable<T> {
	int size();
	boolean isEmpty();
}

interface Entry<K, V> {
	K getKey();
	V getValue();
	void setValue(V v);
}

interface MapFactory {
	<K,V> Map<K,V> create();
}

class MemoizationFactory {
	
	private MapFactory mapFactory;

	public MemoizationFactory(MapFactory mapFactory) {
		this.mapFactory = mapFactory;
	}
	
	public <I, V> Memoization<I, V> create(ItemCalculator<I, V> calc) {
		return new Memoization<I, V>(mapFactory, calc);
	}

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

class Index2D implements EqualityChecker<Index2D>{
	
	public final int i1;
	public final int i2;
	
	public Index2D(int i, int j) {
		this.i1 = i;
		this.i2 = j;
	}
	
	public boolean equals(Object obj) {
		return StrictEqualityChecker.isEquals(this, obj, this);
	}
	
	public boolean isEquals(Index2D o1, Index2D o2) {
		return o1.i1 == o2.i1 && o1.i2 == o2.i2;
	}

	public int hashCode() {
		return PairHash.hash(i1, i2);
	}
	
	public String toString() {
		return "("+i1+","+i2 +")";
	}
}

interface EqualityChecker<T> {
	boolean isEquals(T o1, T o2);
}

class PairHash {
	public static int hash(int h1, int h2) {
		return Int64Hash.hash6432shift((((long) h1) << 32) | h2);
	}
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

class JavaHashMapFactory implements MapFactory {

	public <K, V> Map<K, V> create() {
		return new MapWrapperForJavaMap<K, V>(new HashMap<K, V>());
	}
	
}

class MapWrapperForJavaMap<K, V> implements Map<K, V> {
	
	private final java.util.Map<K,V> map;
	
	public MapWrapperForJavaMap(java.util.Map<K,V> map) {
		this.map = map;				
	}

	public boolean containsKey(K key) {
		return map.containsKey(key);
	}

	public V get(K key) {
		return map.get(key);
	}

	public Iterable<K> keys() {
		return map.keySet();
	}

	public void put(K key, V value) {
		map.put(key, value);
	}

	public Iterable<V> values() {
		return map.values();
	}

	public void clear() {
		map.clear();
	}

	public boolean isEmpty() {
		return map.isEmpty();
	}

	public Iterator<Entry<K, V>> iterator() {
		return ConvertedDataIterator.create(map.entrySet().iterator(), new DataConverter<java.util.Map.Entry<K,V>, Entry<K,V>>() {
			public Entry<K, V> convert(java.util.Map.Entry<K, V> e) {
				return new EntryWrapper<K, V>(e);
			}
		});
	}

	public int size() {
		return map.size();
	}
	
	public void remove(K key) {
		map.remove(key);
	}
	
	public String toString() {
		return map.toString();
	}
	
	private static class EntryWrapper<K, V> implements Entry<K, V>, EqualityChecker<EntryWrapper<K,V>> {
		private java.util.Map.Entry<K, V> e;
		private EntryWrapper(java.util.Map.Entry<K, V> e) {
			this.e = e;
		}
		public K getKey() {
			return e.getKey();
		}
		public V getValue() { 
			return e.getValue();
		}
		public void setValue(V v) {
			e.setValue(v);						
		}
		public boolean equals(Object obj) {
			return StrictEqualityChecker.isEquals(this, obj, this);
		}
		public boolean isEquals(EntryWrapper<K, V> o1, EntryWrapper<K, V> o2) {
			return o1.getKey().equals(o2.getKey()) && o1.getValue().equals(o2.getValue());
		}
		public int hashCode() {
			return PairHash.hash(getKey().hashCode(), getValue().hashCode());
		}
	}

}

class ConvertedDataIterator {
	public static <T1, T2> Iterator<T2> create(final Iterator<T1> outerIterator, final DataConverter<T1, T2> extractor) {
		return new AbstractIterator<T2>() {
			public boolean hasNext() {
				return outerIterator.hasNext();
			}
			public T2 next() {
				return extractor.convert(outerIterator.next());
			}
		};
	}
}

interface DataConverter<T1, T2> {
	T2 convert(T1 v);
}
