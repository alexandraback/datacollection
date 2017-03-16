import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.List;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;
import java.util.Stack;


public class DiamondInheritance {
	
	static String INPUT = "A-large";

	static class Node {
		
		@Override
		public int hashCode() {
			final int prime = 31;
			int result = 1;
			result = prime * result + num;
			return result;
		}

		@Override
		public boolean equals(Object obj) {
			if (this == obj)
				return true;
			if (obj == null)
				return false;
			if (getClass() != obj.getClass())
				return false;
			Node other = (Node) obj;
			if (num != other.num)
				return false;
			return true;
		}

		public Node(int num) {
			super();
			this.num = num;
		}
		
		public void addParent(Node j) {
			parents.add(j);
		}
		
		public void addChildren(Node j) {
			children.add(j);
		}

		Set<Node> parents = new HashSet<Node>();
		Set<Node> children  = new HashSet<Node>();
		
		Iterator<Node> it;
		int num;
	}
	static Map<Integer, Node> map;
	static Set<Node> roots;
	static boolean diamond;
	
	static void init() {
		diamond = false;
		map = new HashMap();
		roots = new HashSet();
	}
	
	static void run(Scanner s) {
		int N = s.nextInt();
		for(int i=1;i<=N;i++) {
			int M = s.nextInt();
			Node nodei = map.get(i);
			if(nodei == null) {
				nodei = new Node(i);
				map.put(i, nodei);
			}
			for(int j=1;j<=M;j++) {
				int mj = s.nextInt();
				Node nodej = map.get(mj);
				if(nodej == null) {
					nodej = new Node(mj);
					map.put(mj, nodej);
				}
				nodei.addParent(nodej);
				nodej.addChildren(nodei);
			}
			if(M ==0)
				roots.add(nodei);
		}
		if(roots.isEmpty()) {
			throw new RuntimeException("Impossible");
		}
		OUTER:
		for(Node root : roots) {
			boolean[] visited = new boolean[N];
			for(int i=1;i<=N;i++) {
				map.get(i).it = null;
			}
			Node visiting = root;
			Stack<Node> origins = new Stack();
			boolean justReturned = false;
			while(visiting!=null) {
				if(!visited[visiting.num-1]) {
					visited[visiting.num-1] = true;
				} else if(!justReturned){
					diamond = true;
					break OUTER;
				}
				justReturned = false;
				
				if(visiting.it==null) {
					visiting.it = visiting.children.iterator();
				}
				if(visiting.it.hasNext()) {
					origins.push(visiting);
					visiting = visiting.it.next();
				} else {
					if(!origins.isEmpty()) {
						visiting = origins.pop();
						justReturned = true;
					} else {
						visiting = null;
					}
				}
			}
		}
	}
	
	static void print(PrintWriter p) {
		p.println(diamond ? "Yes" : "No");
	}

	
	
	// Utility 

	public static void main(String[] argv) throws Exception {
		start(INPUT);
	}

	public static void start(String inputFile) throws Exception {
		Scanner s ;
		if(inputFile == null) {
			s = new Scanner(System.in);
		} else {
			s = new Scanner(new FileInputStream(inputFile + ".in"));
		}
		PrintWriter p;
		if(inputFile == null) {
			p = new PrintWriter(System.out);
		} else {
			p = new PrintWriter(new FileOutputStream(inputFile + ".out")) {
				
				@Override
				public void println() {
					super.println();
					try {
						w.write(java.security.AccessController.doPrivileged(
						        new sun.security.action.GetPropertyAction("line.separator")));
						w.flush();
					} catch (IOException e) {
						throw new RuntimeException(e);
					}
				}

				private OutputStreamWriter w = new OutputStreamWriter(System.out);
				
				@Override
				public void write(String s, int off, int len) {
					super.write(s, off, len);
					try {
						w.write(s, off, len);
						w.flush();
					} catch (IOException e) {
						throw new RuntimeException(e);
					}
				}
				
			};
		}
		try {
			int T = s.nextInt();
			
			for(int i =0;i<T;i++) {
				init();
				run(s);
				doPrint(p, i);
				p.flush();				
			}
		} finally {
			s.close();
			p.close();
		}
	}
	
	static void doPrint(PrintWriter p, int i) {
		p.print("Case #" + (i+1) + ": ");
		print(p);
	}
	
	private static class KEY {
		private List set = new ArrayList();
		private static KEY newKey(Object...objects) {
			KEY k = new KEY();
			for(Object o:objects) {
				k.set.add(o);
			}
			return k;
		}
		@Override
		public int hashCode() {
			final int prime = 31;
			int result = 1;
			result = prime * result + ((set == null) ? 0 : set.hashCode());
			return result;
		}
		@Override
		public boolean equals(Object obj) {
			if (this == obj)
				return true;
			if (obj == null)
				return false;
			if (getClass() != obj.getClass())
				return false;
			KEY other = (KEY) obj;
			if (set == null) {
				if (other.set != null)
					return false;
			} else if (!set.equals(other.set))
				return false;
			return true;
		}
	}
	
	long pow(long x, long y) {
		if(y < 0) throw new RuntimeException("y<0");
		if(y == 0) return 1;
		if(y == 1) return x;
		if(y == 2) return x*x;
		if(y%2 == 0) {
			long p = pow(x, y/2);
			return p*p;
		} else {
			long p = pow(x, y-1);
			return p*x;
		}
	}
	
	private static DP<Long,Long> fracDP = new DP<Long,Long>() {
		@Override
		Long calc(Long k) {
			if(k<0) throw new RuntimeException("k<0");
			if(k==0) return 1L;
			return k*doCalc(k-1);
		}
		
	};
	long frac(long n) {
		return fracDP.doCalc(n);
	}
	
	abstract static class DP<K,V> {
		Map<K,V> map = new HashMap<K,V>();
		
		void reset() {
			map.clear();
		}
		V doCalc(K k) {
			if(map.get(k) == null) {
				V v = calc(k);
				if(v!=null) {
					map.put(k, v);
					return v;
				}
				return null;
			} else {
				return map.get(k);
			}
		}
		
		abstract V calc(K k);
	}
	
	static void out(String... txts) {
		for(String txt:txts) {
			System.out.print(txt +" ");
		}
		System.out.println();
	}
	
	static void addToMapList(Map map, Object key, Object value) {
		Object o = map.get(key);
		if(o == null) {
			List list = new ArrayList();
			list.add(value);
			map.put(key, list);
		}
		else {
			((List)o).add(value);
		}
	}
}
