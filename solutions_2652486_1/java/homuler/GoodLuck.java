package gcj_2014_r1A;
import java.util.*;
import java.io.*;

public class GoodLuck {
	Random rand = new Random();
	public void nextArray(int[] x, int m){
		for(int i = x.length-1; i >= 0; i--){
			x[i] = rand.nextInt(m-1)+2;
		}
	}
	public void solve() throws IOException {	
		int t = nextInt();
		writer.println("Case #1:");
		int r = nextInt();
		int n = nextInt();
		int m = nextInt();
		int k = nextInt();
		for(int i = 0; i < r; i++){
		//	writer.println(i);
		//	writer.flush();			
			int[] v = new int[k];
			for(int j = 0; j < k; j++){
				v[j] = nextInt();				
			}
			
			int[] x = new int[n];
			for(int j = 0; j < n; j++){
				x[j] = 2;
			}
			int rep = 10;
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
				break;
			}
			for(int y : x){
				writer.print(y);
			}
			writer.println();
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
