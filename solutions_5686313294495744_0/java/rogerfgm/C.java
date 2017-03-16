

import java.io.*;
import java.util.*;

import static java.lang.Math.*;
import static java.lang.Integer.*;

public class C {
	static Scanner sc = null;
	static BufferedReader br = null;
	static PrintWriter out = null;
	static PrintStream sysout = System.out;
	static Random rnd = new Random();
	
	int INF = Integer.MAX_VALUE / 10;
	double DF = 0.0000000001;
	
	long b = 1;
	int N = 0;
	int M = 0;
	
	public class Combination implements Iterable<int[]> {
		private final int max;
		private final int select;
		
		public Combination(int max, int select) {
			if (max < 1 || 62 < max) {
				throw new IllegalArgumentException();
			}
			this.max = max;
			this.select = select;
		}
	
		public Iterator<int[]> iterator() {
			return new CombinationIterator(max, select);
		}
		
		private class CombinationIterator implements Iterator<int[]> {
			private long value;
			private final long max;
			private final int size;
			private int[] ret = null;
			public CombinationIterator(int max, int select) {
				this.value = (1L << select) - 1L;
				this.size = max;
				this.max = 1L << max;
				this.ret = new int[size];
			}

	
			public boolean hasNext() {
				return value < max;
			}


			public int[] next() {
				long stock = value;
				value = next(value);
				
				for(int i = 0; i < size; i++){
					long tmp = stock >> i;
					tmp = tmp & 1;
					ret[i] = (int)tmp;
				}
				
				return ret;
			}

	
			public void remove() {
				throw new UnsupportedOperationException();
			}

			private long next(long source) {
				long param1 = smallestBitOf(source);
				long param2 = param1 + source;
				long param3 = smallestBitOf(param2);
				long param5 = (param3 / param1) >>> 1;
				return param5 - 1 + param2;
			}

			private long smallestBitOf(long source) {
				long result = 1L;
				while (source % 2 == 0) {
					source >>>= 1;
					result <<= 1;
				}
				return result;
			}
		}
	}
	
	public void solve() throws Exception{
		String s = br.readLine();
		N = Integer.parseInt(s);
		List<String> list1 = new ArrayList<>();
		List<String> list2 = new ArrayList<>();
		for(int i = 0; i < N; i++){
			s = br.readLine();
			String[] sp = s.split(" ");
			list1.add(sp[0]);
			list2.add(sp[1]);
		}
		int ans = 0;
		
		
		for(int cm = 1; cm <= N-2; cm++){
			Combination c = new Combination(N, cm);
			Iterator<int[]> ite = c.iterator();
			while(ite.hasNext()){
				int[] d = ite.next();
				int cnt = 0;
				for(int i = 0; i < d.length; i++){
					if(d[i] == 0){
						continue;
					}
					String s1 = list1.get(i);
					String s2 = list2.get(i);
					boolean f1 = false;
					boolean f2 = false;
					for(int j = 0; j < N; j++){
						if(j == i){
							continue;
						}
						if(d[j] == 1){
							continue;
						}
						if(s1.equals(list1.get(j))){
							f1 = true;
						}
						if(s2.equals(list2.get(j))){
							f2 = true;
						}
					}
					if(f1 && f2){
						cnt++;
					}
				}
				ans = Math.max(ans, cnt);
			}	
		}
		
		
		
		
		println(ans);

	}
	
	/**
	 * @param args
	 */
	public static void main(String[] args) throws Exception{
		File file = new File("C-small-attempt4.in");
		if(file.exists()){
			System.setIn(new BufferedInputStream(new FileInputStream(file)));
		}
		else{
			throw new Exception("can't find a input file : " + file.getAbsolutePath());
		}
		//sc =  new Scanner(System.in);
		br = new BufferedReader(new InputStreamReader(System.in));
		FileWriter fw = new FileWriter(new File("output.txt"));
		out = new PrintWriter(fw);
		
		C b = new C();
		int T = 0;
		if(sc != null){
			T = sc.nextInt();
		}
		else{
			T = parseInt(br.readLine());
		}
		int t = 1;
		while(t <= T){
			out.print("Case #" + t + ": ");
			System.out.print("Case #" + t + ": ");
			b.solve();
			t++;
		}
		out.close();
		fw.close();
	}
	
	void print(int i){
		out.print(i + "");
		System.out.print(i);
	}
	void println(int i){
		out.println(i + "");
		System.out.println(i);
	}
	void print(String s){
		out.print(s);
		System.out.print(s);
	}
	void println(String s){
		out.println(s);
		System.out.println(s);
	}
	void print(long i){
		out.print(i + "");
		System.out.print(i);
	}
	void println(long i){
		out.println(i + "");
		System.out.println(i);
	}
}
