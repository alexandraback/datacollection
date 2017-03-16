package gcj_2014_r1A;
import java.util.*;
import java.io.*;

public class Energy {
	public void nextArray(int e, int[] x){
		for(int i = x.length-1; i >= 0; i--){
			x[i]++;
			if( x[i] <= e ){
				break;
			}
			x[i] = 0;
		}
	}
	public int maximum(int e, int r, int[] v, int n){
		int[] x = new int[n];
		int rep = (int)Math.pow(e+1, n);
		int max = 0;
	//	writer.println(rep);
	//	writer.flush();
		while( rep-- > 0 ){
		//	writer.println(rep);
			/*for(int y : x){
				writer.print(y + " ");
			}
			writer.println();*/
			int en = e;
			int val = 0;
			for(int i = 0; i < n; i++){
				if( en < x[i] ){
					val = 0;
					break;
				}
				en -= x[i];
				en += r;
				if( en > e ){
					en = e;
				}
				val += v[i]*x[i];
			}
			max = Math.max(max, val);
			nextArray(e, x);
		}
		return max;
	}
/*	public int maximum(int e, int r, int[] v, int n){
		if( n == v.length ){
			return 0;
		}
		int max = 0;
		for(int i = 0; i <= e; i++){
			max = Math.max(max, i*v[n] + maximum(Math.min(e-i+r, e), r, v, n+1));
		//	writer.println(max + " (" + i + ", " + e + ", " + r + ", " + n + ")");
		}
		return max;
	}*/
	public void solve() throws IOException {
		int T = nextInt();
		for(int i = 0; i < T; i++){
			int e = nextInt();
			int r = nextInt();
			int n = nextInt();
			int[] v = new int[n];
			for(int j = 0; j < n; j++){
				v[j] = nextInt();
			}
			writer.println("Case #" + (i+1) + ": " + maximum(e, r, v, n));
		}
		writer.flush();
	}

	public static void main(String[] args) throws IOException {
		new Energy().run();
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
