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

public class C implements Runnable {
	
	PrintWriter out;
	BufferedReader breader;
	StringTokenizer st;
	
	ArrayList< Long > vals;
	
	boolean isPal(long v) {
		ArrayList< Integer > lst = new ArrayList<Integer>();
		for (; v != 0; v /= 10) {
			lst.add((int)(v % 10));
		}
		boolean result = true;
		for (int i = 0; i < lst.size(); ++i) {
			result &= lst.get(i) == lst.get(lst.size() - 1 - i);			
		}
		return result;		
	}
	void preprocess() {
		vals = new ArrayList<Long>();
		for (long i = 0; i <= 10000000; ++i) {
			if (isPal(i) && isPal(i * i)) {
				vals.add(i * i);
			}
		}
		System.out.println(vals.size());

	}
	
	int request(long a, long b) {
		int res = 0;
		for (Long l: vals) {
			res += a <= l && l <= b ? 1 : 0;
		}
		return res;
	}
		
	void solve() throws NoSuchAlgorithmException, IOException {
		long a = nextLong();
		long b = nextLong();
		out.println(request(a, b));
	
	}
	
	/**
	 * @param args
	 * @throws NoSuchAlgorithmException 
	 * @throws IOException 
	 * @throws LineUnavailableException 
	 */
	
	public static void main(String[] args)  {
		(new Thread(new C())).start();
	}

	@Override
	public void run() {
		try {
			//breader = new BufferedReader(new InputStreamReader(System.in));
			breader = new BufferedReader(new FileReader("inp.file"));
			st = new StringTokenizer("");
			out = new PrintWriter("res.file");
			preprocess();
			int tst = nextInt();
			for (int i = 1; i <= tst; ++i) {
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
