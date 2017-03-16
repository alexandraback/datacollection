/**
 * 
 */


import java.io.*;
import java.util.*;


/**
 * @author Dani
 *
 */
public class Main {

	FastScanner in;
	PrintWriter out;
	class Lane implements Comparable{
		ArrayList<Integer> list= new ArrayList<Integer>(); 
		ArrayList<Integer> original= new ArrayList<Integer>(); 
		
		public Lane() {
			for (int line = 0; line < n ; line++ ){
				list.add(in.nextInt());	
			}
			original = new ArrayList<Integer>(list);
			System.err.println(list.toString());
		}
		@Override
		public int compareTo(Object o) {
			int compare=((Lane) o ).list.get(0);
	        /* For Ascending order*/
	        return this.list.get(0).compareTo(compare);

		}
		
		public void removeFirst(){
			list.remove(0);
		}
		
	}
	int n;
	void solve() {
		int tc = in.nextInt();
		for (int t = 0; t < tc; t++) {
			out.print("Case #" + (t + 1) + ":");
			 n = in.nextInt();
			 Map<Integer, Integer> map = new HashMap<Integer, Integer>();
			ArrayList<Lane> lanes = new ArrayList<Main.Lane> (); 
			for (int line = 0; line < 2*n - 1; line++ ){
				for (int i = 0; i < n ; i++ ){
					int key = in.nextInt();
					if( map.containsKey(key))
						map.put(key, map.get(key) + 1);
					else
						map.put(key, 1);

				}
			}
			Set<Integer> keys = map.keySet();
			ArrayList<Integer> odd = new ArrayList<Integer>();
			for (Integer k : keys) {
				if(map.get(k).intValue() % 2 != 0){
					odd.add(k);
					System.err.println(" " + k);

				}
			}
			Collections.sort(odd);
			for (Integer integer : odd) {
				out.print(" " + integer);

			}
			out.println("");
			System.err.println((t + 1) + "/" + tc + " done");
			}

		}


	void run() {
		try {
			in = new FastScanner(new File("input"));
			out = new PrintWriter(new File("output.out"));

			solve();

			out.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
	}

	void runIO() {
		in = new FastScanner(System.in);
		out = new PrintWriter(System.out);

		solve();

		out.close();
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		public FastScanner(File f) {
			try {
				br = new BufferedReader(new FileReader(f));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}

		public FastScanner(InputStream f) {
			br = new BufferedReader(new InputStreamReader(f));
		}

		String next() {
			while (st == null || !st.hasMoreTokens()) {
				String s = null;
				try {
					s = br.readLine();
				} catch (IOException e) {
					e.printStackTrace();
				}
				if (s == null)
					return null;
				st = new StringTokenizer(s);
			}
			return st.nextToken();
		}

		boolean hasMoreTokens() {
			while (st == null || !st.hasMoreTokens()) {
				String s = null;
				try {
					s = br.readLine();
				} catch (IOException e) {
					e.printStackTrace();
				}
				if (s == null)
					return false;
				st = new StringTokenizer(s);
			}
			return true;
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		long nextLong() {
			return Long.parseLong(next());
		}

		double nextDouble() {
			return Double.parseDouble(next());
		}
	}

	public static void main(String[] args) {
		new Main().run();
	}
}