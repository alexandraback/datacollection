import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Scanner;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;
public class D1 implements OneCaseSolver {
	
	private static final JavaHashMapFactory MAPF = new JavaHashMapFactory();
	private static final MemoizationFactory MEMOF = new MemoizationFactory(MAPF);
	int startkeyn;
	int[] startkey;
	
	int n;
	int[] toopen;
	int[] insiden;
	int[][] inside;
	
	@Override
	public void input(Scanner in) {
		startkeyn = in.nextInt();
		n = in.nextInt();
		startkey = new int[startkeyn];
		for(int i=0;i<startkeyn;i++)
			startkey[i] = in.nextInt();
		toopen = new int[n];
		insiden = new int[n];
		inside = new int[n][];
		for(int i=0;i<n;i++) {
			toopen[i] = in.nextInt();
			insiden[i] = in.nextInt();
			inside[i] = new int[insiden[i]];
			for(int j=0;j<insiden[i];j++)
				inside[i][j] = in.nextInt();
		}
	}


	@Override
	public String solve() {
		Memoization<BitSet32, Integer> memo = MEMOF.create(new ItemCalculator<BitSet32, Integer>() {
			@Override
			public Integer calc(BitSet32 visited, SubItem<BitSet32, Integer> sub) {
				if(isfull(visited)) {
					return -1;
				} else {
					int[] kn = new int[201];
					for(int key : startkey)
						kn[key]++;
					for(int i=0;i<n;i++)
						if(visited.is(i)) {
							for(int key : inside[i])
								kn[key]++;
							kn[toopen[i]]--;
						}
					for(int i=0;i<n;i++) {
						int key = toopen[i];
						if(!visited.is(i) && kn[key] > 0) {
							BitSet32 nv = visited.set(i);
							if(sub.get(nv) != -2)
								return i;
						}
					}				
					return -2;
				}
			}

		});
		
		BitSet32 init = new BitSet32(0);
		Integer r = memo.get(init);
		if(r != -2) {
			BitSet32 now = init;
			String s = "";
			while(!isfull(now)) {
				Integer v = memo.get(now);
				s += (v+1 + " ");
				now = now.set(v);
			}
			return s;
		} else {
			return "IMPOSSIBLE";
		}
	}

	private boolean isfull(BitSet32 visited) {
		boolean full = true;
		for(int i=0;i<n;i++)
			if(!visited.is(i))
				full = false;
		return full;
	}

	public static void main(String[] args) throws Exception {
		String small = "D-small-attempt0.in";
		CodeJamProblemSolver.launch(1, small, new OneCaseSolverFactory() {
			@Override
			public OneCaseSolver createSolver() {
				return new D1();
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
class BitSet32 {
	
	public static BitSet32 EMPTY = new BitSet32(0);
	
	final int bits;
	
	public BitSet32(int bits) {
		this.bits = bits;
	}
	
	public BitSet32 set(int pos) {
		return new BitSet32(bits | (1 << pos)); 
	}
	
	public BitSet32 unset(int pos) {
		return new BitSet32(bits & (~0 - (1<<pos)));
	}
	
	public BitSet32 toggle(int pos) {
		return new BitSet32(bits ^ (1 << pos));
	}
	
	public boolean is(int pos) {
		return (bits & (1<<pos)) != 0;
	}
	
	@Override
	public boolean equals(Object arg0) {
		return bits == ((BitSet32)arg0).bits;
	}
	
	@Override
	public int hashCode() {
		return Int32Hash.hash(bits);
	}
	
	@Override
	public String toString() {
		return Integer.toBinaryString(bits);
	}
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
class JavaHashMapFactory implements MapFactory {

	@Override
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
		return ConvertedDataIterator.createx(map.entrySet().iterator(), new DataConverter<java.util.Map.Entry<K,V>, Entry<K,V>>() {
			@Override
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
	
	@Override
	public String toString() {
		return map.toString();
	}
	
	private static class EntryWrapper<K, V> implements Entry<K, V>, EqualityChecker<EntryWrapper<K,V>> {
		private java.util.Map.Entry<K, V> e;
		private EntryWrapper(java.util.Map.Entry<K, V> e) {
			this.e = e;
		}
		@Override
		public K getKey() {
			return e.getKey();
		}
		@Override
		public V getValue() { 
			return e.getValue();
		}
		@Override
		public void setValue(V v) {
			e.setValue(v);						
		}
		@Override
		public boolean equals(Object obj) {
			return StrictEqualityChecker.isEquals(this, obj, this);
		}
		@Override
		public boolean isEquals(EntryWrapper<K, V> o1, EntryWrapper<K, V> o2) {
			return o1.getKey().equals(o2.getKey()) && o1.getValue().equals(o2.getValue());
		}
		@Override
		public int hashCode() {
			return PairHash.hash(getKey().hashCode(), getValue().hashCode());
		}
	}

}
class ConvertedDataIterator {

	public static <T1, T2> Iterator<T2> createx(final Iterator<T1> outerIterator, final DataConverter<T1, T2> extractor) {
		return new AbstractIterator<T2>() {
			@Override
			public boolean hasNext() {
				return outerIterator.hasNext();
			}
			@Override
			public T2 next() {
				return extractor.convert(outerIterator.next());
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
interface DataConverter<T1, T2> {
	T2 convert(T1 v);
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
