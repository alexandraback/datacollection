import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Scanner;
import java.util.Set;
import java.util.TreeSet;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;
public class A implements CodeJamCaseSolver {

	static Map<Character, Character> m = new JavaHashMapFactory().create(); 
	
	static {
		String[] s1 = {"ejp mysljylc kd kxveddknmc re jsicpdrysi", "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd", "de kr kd eoya kw aej tysr re ujdr lkgc jv"};
		String[] s2 = {"our language is impossible to understand", "there are twenty six factorial possibilities", "so it is okay if you want to just give up"};
		for(int i=0;i<s1.length;i++) 
			for(int j=0;j<s1[i].length();j++) 
				m.put(s1[i].charAt(j), s2[i].charAt(j));
		m.put('z', 'q');
		m.put('q', 'z');
	}
	
	String src;
	
	@Override
	public void input(Scanner in) {
		src = "";
		while(src.length() == 0)
			src = in.nextLine();
	}
	
	@Override
	public String solve() {
		String r = "";
		for(int i=0;i<src.length();i++)
			r += m.get(src.charAt(i));
		return r;
	}

	public static void main(String[] args) throws Exception {
		CodeJamSolver.launch(8, "A-small-attempt0.in", new CodeJamCaseSolverFactory() {
			@Override
			public CodeJamCaseSolver createSolver() {
				return new A();
			}
		});
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
		final Set<Integer> caseIndexToSolve = createCaseIndicesToSolve(casen, caseIndices);
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

	private static Set<Integer> createCaseIndicesToSolve(int casen, Integer... caseIndices) {
		final Set<Integer> set = new TreeSet<Integer>();
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
class JavaHashMapFactory implements MapFactory {

	@Override
	public <K, V> Map<K, V> create() {
		return new MapWrapperForJavaMap<K, V>(new HashMap<K, V>());
	}
	
	@Override
	public <K, V> Map<K, V> create(int reserve) {
		return new MapWrapperForJavaMap<K, V>(new HashMap<K, V>(reserve));
	}
	
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
interface Entry<K, V> extends Comparable<Entry<K,V>>{
	K getKey();
	V getValue();
	void setValue(V v);
}
interface MapFactory {
	<K,V> Map<K,V> create();
	<K,V> Map<K,V> create(int reserve);
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
		return new Iterable<K>() {
			public Iterator<K> iterator() {
				return map.keySet().iterator();
			}
		};
	}

	public void put(K key, V value) {
		map.put(key, value);
	}

	public Iterable<V> values() {
		return new Iterable<V>() {
			public Iterator<V> iterator() {
				return map.values().iterator();
			}
		};
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
			public Entry<K, V> convert(final java.util.Map.Entry<K, V> e) {
				return new AbstractEntry<K, V>() {
					public K getKey() {
						return e.getKey();
					}
					public V getValue() {
						return e.getValue();
					}
					public void setValue(V v) {
						e.setValue(v);						
					}
				};
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
abstract class AbstractEntry<K, V> implements Entry<K, V> {
	@SuppressWarnings("unchecked")
	final public int compareTo(Entry<K, V> o) {
		return ((Comparable<K>)getKey()).compareTo(o.getKey());
	}
	@SuppressWarnings("unchecked")
	@Override
	final public boolean equals(Object obj) {
		return getKey().equals(((Entry<K, V>)obj).getKey());
	}
	@Override
	final public int hashCode() {
		return getKey().hashCode();
	}

}
