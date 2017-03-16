import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class D implements Runnable {
	
	PrintWriter out;
	BufferedReader breader;
	StringTokenizer st;
	private int k;
	private int n;
	private int[] keys;
	private int[] type;
	private int[][] mkeys;
	
	int compare(ArrayList< Integer > lhs, ArrayList< Integer > rhs) {
		if (rhs == null) {
			return -1;
		}
		for (int i = 0; i < lhs.size(); ++i) {
			if (lhs.get(i) != rhs.get(i)) {
				return lhs.get(i) - rhs.get(i);					
			}
		}
		return 0;
	}
	
	boolean possible(int msk, int j) {
		int nkey = type[j];
		
		int balance = 0;
		for (int i = 0; i < n; ++i) {
			if ((msk >> i) % 2 == 1) {
				balance += mkeys[i][nkey];
				balance -= type[i] == nkey ? 1 : 0;
			}
		}
		balance += keys[nkey];
		return balance > 0;		
	}
	
	void solve() throws NoSuchAlgorithmException, IOException {
		k = nextInt();
		n = nextInt();
		keys = new int[201];
		mkeys = new int[n][201];
		for (int i = 0; i < k; ++i) {
			++keys[nextInt()];
		}
		type = new int[n];
		for (int i = 0; i < n; ++i) {
			type[i] = nextInt();
			int l = nextInt();
			for (int j = 0; j < l; ++j) {
				++mkeys[i][nextInt()];
			}
		}
		
		
		ArrayList< Integer >[] d = new ArrayList[1 << n];		
		d[0] = new ArrayList<Integer>();
		int tmp = 0;		
		int lpos = 0;
		for (int msk = 1; msk < d.length; ++msk) {
			ArrayList< Integer > best = null;			
			for (int j = 0; j < n; ++j) {			
				tmp = msk ^ (1 << j);
				if ((msk >> j) % 2 == 1 && possible(msk ^ (1 << j), j) && 
						d[tmp] != null && compare(d[tmp], best) < 0) {
					best = d[tmp];
					lpos = j;
				}
			}
			if (best != null) {
				d[msk] = new ArrayList<Integer>();
				for (Integer i : best) {
					d[msk].add(i);
				}
				d[msk].add(lpos + 1);
			}
		}
		if (d[d.length - 1] != null) {
			for (Integer i : d[d.length - 1]) {
				out.print(i + " ");
			}
			out.println();
		} else {
			out.println("IMPOSSIBLE");
		}
		
	
	}
	
	/**
	 * @param args
	 * @throws NoSuchAlgorithmException 
	 * @throws IOException 
	 * @throws LineUnavailableException 
	 */
	
	public static void main(String[] args)  {
		(new Thread(new D())).start();
	}

	@Override
	public void run() {
		try {
			//breader = new BufferedReader(new InputStreamReader(System.in));
			breader = new BufferedReader(new FileReader("inp.file"));
			st = new StringTokenizer("");
			out = new PrintWriter("res.file");
			int tst = nextInt();
			for (int i = 1; i <= tst; ++i) {
				System.out.println(i);
				out.print("Case #" + i + ": ");
				solve();
			}
			out.close();
		} catch (NoSuchAlgorithmException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

	String next() throws IOException {
		while (!st.hasMoreTokens()) {
			String temp = breader.readLine();
			if (temp == null) {
				return null;
			}
			st = new StringTokenizer(temp);
		}
		return st.nextToken();
	}
	int nextInt() throws IOException {
		return Integer.parseInt(next());
	}
	double nextDouble() throws IOException {
		return Double.parseDouble(next());
	}
	long nextLong() throws IOException {
		return Long.parseLong(next());
	}
	
}
