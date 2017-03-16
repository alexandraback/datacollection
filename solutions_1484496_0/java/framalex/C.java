import java.io.*;
import java.util.*;
import java.math.*;

public class C implements Runnable {
	
	
	public void run() {
		int tst = nextInt();
		for (int ts = 0; ts < tst; ++ts) {
			int n = nextInt();
			HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
			
			int[] arr = new int[n];
			for (int i = 0; i < n; ++i) {
				arr[i] = nextInt();
			}
			
			boolean found = false;
			for (int mask = 1; mask < (1<<n)-1; ++mask) {
				int sum = 0;
				for (int bit = 0; bit < n; ++bit) {
					if ((mask & (1 << bit)) != 0) {
						sum += arr[bit];
					}
				}
				
				if (!map.containsKey(sum)) {
					map.put(sum, mask);
				}
				else {
					int mask2 = map.get(sum);
					found = true;
					
					int xor = mask ^ mask2;
					mask &= xor;
					mask2 &= xor;
					
					out.println("Case #"+(ts+1)+":");
					for (int i = 0; i < n; ++i) {
						if ((mask & (1<<i)) != 0) {
							out.print((arr[i]) + " ");
						}
					}
					out.println();
					for (int i = 0; i < n; ++i) {
						if ((mask2 & (1<<i)) != 0) {
							out.print((arr[i]) + " ");
						}
					}
					out.println();
					break;
				}
			}
			
			
			if (!found) {
				out.println("Case #"+(ts+1)+":");
				out.println("Impossible");
			}
			
		}
		out.flush();
	}
	
	private static BufferedReader br = null;
	private static StringTokenizer stk = null;
	private static PrintWriter out = null;
	
	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new FileReader(new File("D:\\C.txt")));
		out = new PrintWriter("D:\\CC.txt");
		(new Thread(new C())).start();
	}
	
	public void loadLine() {
		try {
			stk = new StringTokenizer(br.readLine());
		}
		catch (IOException e) {
			e.printStackTrace();
		}
	}
	
	public String nextLine() {
		try {
			return (br.readLine());
		}
		catch (IOException e) {
			e.printStackTrace();
		}
		return null;
	}
	
	public int nextInt() {
		while (stk==null || !stk.hasMoreTokens()) loadLine();
		return Integer.parseInt(stk.nextToken());
	}
	
	public long nextLong() {
		while (stk==null || !stk.hasMoreTokens()) loadLine();
		return Long.parseLong(stk.nextToken());
	}
	
	public double nextDouble() {
		while (stk==null || !stk.hasMoreTokens()) loadLine();
		return Double.parseDouble(stk.nextToken());
	}
	
	public String nextWord() {
		while (stk==null || !stk.hasMoreTokens()) loadLine();
		return (stk.nextToken());
	}
}
