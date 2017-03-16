import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class Main {
	public static void main(String[] args) throws IOException {
		//InputStream inputStream = System.in;
		//OutputStream outputStream = System.out;

		InputStream inputStream = new FileInputStream("input.txt");
		OutputStream outputStream = new FileOutputStream("output.txt");

		InputReader in = new InputReader(inputStream);
		OutputWriter out = new OutputWriter(outputStream);

		TaskA solver = new TaskA();

		solver.solve(in, out);

		out.close();
	}
}

class TaskA {

	public void solve(InputReader in, OutputWriter out) {
		
		int n = 1000000;
		int[] dp = new int[n+1];
		Arrays.fill(dp, Integer.MAX_VALUE-100);
		boolean[] used = new boolean[n+1];
		dp[1] = 1; used[1] = true;
		TreeSet<Pair> set = new TreeSet<Pair>();
		set.add(new Pair(1,1));
		while(!set.isEmpty()){
			Pair cur = set.first();
			used[cur.ind] = true;
			set.remove(cur);
			if(cur.ind+1<=n && !used[cur.ind+1]){
				if(set.contains(new Pair(cur.ind+1,dp[cur.ind+1]))){
					set.remove(new Pair(cur.ind+1,dp[cur.ind+1]));
				}
				dp[cur.ind+1] = Math.min(dp[cur.ind+1], dp[cur.ind]+1);
				set.add(new Pair(cur.ind+1,dp[cur.ind+1]));
			}
			int temp=0,ind = cur.ind, pow=1;
			while(pow<=ind) pow*=10; pow/=10;
			while(ind>0){
				temp+=(ind%10)*pow;
				pow/=10;
				ind/=10;
			}
			if(temp<=n && !used[temp]){
				if(set.contains(new Pair(temp,dp[temp])))
					set.remove(new Pair(temp,dp[temp]));
				dp[temp] = Math.min(dp[temp], dp[cur.ind]+1);
				set.add(new Pair(temp,dp[temp]));
			}
			
		}
		
		
		int t = in.nextInt();
		for(int i=0; i<t; i++){
			int x = in.nextInt();
			out.writeln("Case #"+(i+1)+": "+dp[x]);
		}
		
	}

}

class Pair implements Comparable<Pair>{
	
	public Pair(int ind, int val){
		this.ind = ind;
		this.val = val;
	}
	
	public int compareTo(Pair p){
		return val==p.val ? ind-p.ind : val-p.val;
	}
	
	int ind,val;
}

class InputReader {

	BufferedReader reader;
	StringTokenizer tokenizer;

	public InputReader(InputStream stream) {
		tokenizer = null;
		reader = new BufferedReader(new InputStreamReader(stream));
	}

	public String next() {
		while (tokenizer == null || !tokenizer.hasMoreTokens()) {
			try {
				tokenizer = new StringTokenizer(reader.readLine());
			} catch (IOException e) {
				throw new RuntimeException();
			}
		}

		return tokenizer.nextToken();
	}

	public String nextLine() {
		tokenizer = null;
		try {
			return reader.readLine();
		} catch (IOException e) {
			throw new RuntimeException();
		}
	}

	public int nextInt() {
		return Integer.parseInt(next());
	}

	public long nextLong() {
		return Long.parseLong(next());
	}

	public double nextDouble() {
		return Double.parseDouble(next());
	}

	public int[] nextIntArray(int n) {
		int[] res = new int[n];
		for (int i = 0; i < n; i++)
			res[i] = nextInt();

		return res;
	}

}

class OutputWriter {

	PrintWriter out;

	public OutputWriter(OutputStream stream) {
		out = new PrintWriter(
				new BufferedWriter(new OutputStreamWriter(stream)));
	}

	public void write(Object... o) {
		for (Object cur : o)
			out.print(cur);
	}

	public void writeln(Object... o) {
		write(o);
		out.println();
	}

	public void flush() {
		out.flush();
	}

	public void close() {
		out.close();
	}

}