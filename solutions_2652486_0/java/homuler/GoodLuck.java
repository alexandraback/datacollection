package gcj_2014_r1A;
import java.util.*;
import java.io.*;

public class GoodLuck {
	public void nextArray(int[] x, int m){
		for(int i = x.length-1; i >= 0; i--){
			x[i]++;
			if( x[i] <= m ){
				break;
			}
			x[i] = 2;
		}
	}
	public void solve() throws IOException {
		Random rand = new Random();
		int t = nextInt();
		writer.println("Case #1:");
		int r = nextInt();
		int n = nextInt();
		int m = nextInt();
		int k = nextInt();
		for(int i = 0; i < r; i++){
			boolean flag = true;
			int[] v = new int[k];
			for(int j = 0; j < k; j++){
				v[j] = nextInt();
				if( v[j] != 1 ){
					flag = false;
				}
			}
			if( flag ){
				for(int j = 0; j < n; j++){
					writer.print(rand.nextInt(n-1)+2);
				}
				writer.println();
				continue;
			}
			
			int[] x = new int[n];
			for(int j = 0; j < n; j++){
				x[j] = 2;
			}
			int rep = (int)Math.pow(m-2+1, n);
		out:
			while( rep-- > 0 ){
				Set<Integer> set = new HashSet<Integer>();
				int rep2 = 1 << n;
				while( rep2-- > 0 ){
					int p = 1;
					for(int j = 0; j < n; j++){
						if( ((rep2 >> j)&1) == 1 ){
							p *= x[j];
						}
					}
					set.add(p);
				}
				for(int j = 0; j < k; j++){
					if( !set.contains(v[j]) ){
						nextArray(x, m);
						continue out;
					}
				}
				for(int y : x){
					writer.print(y);
				}
				writer.println();
				break;
			}
		}
		writer.flush();
	}

	public static void main(String[] args) throws IOException {
		new GoodLuck().run();
	}

	BufferedReader reader;
	StringTokenizer tokenizer;
	PrintWriter writer;

	public void run() throws IOException {
		try {
			reader = new BufferedReader(new InputStreamReader(System.in));
			tokenizer = null;
			writer = new PrintWriter(System.out);
			solve();
			reader.close();
			writer.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	public String nextToken() throws IOException {
		while (tokenizer == null || !tokenizer.hasMoreTokens()) {
			tokenizer = new StringTokenizer(reader.readLine());
		}
		return tokenizer.nextToken();
	}

	public int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}
}
