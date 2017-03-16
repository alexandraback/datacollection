import java.io.*;
import java.math.BigInteger;
import java.util.*;


public class c {

	boolean isPalindrom(long x){
		long y=0;
		long z=x;
		while(x!=0){
			y=y*10+x%10;
			x/=10;
		}
		return z==y;
	}

	void solve() throws IOException {
		ArrayList<Long> pal=new ArrayList<Long>();
		for(long i=1;i<=10000000;i++){
			if(isPalindrom(i)&&isPalindrom(i*i)){
				pal.add(i*i);
			}
		}
		int t=nextInt();
		for(int testCase=0;testCase<t;testCase++){
			long a,b;
			a=nextLong();
			b=nextLong();
			int res=0;
			for(int i=0;i<pal.size();i++)
				if(pal.get(i)>=a&&pal.get(i)<=b)
					res++;
			out.printf("Case #%d: %d\n",testCase+1,res);
		}

	}

	public static void main(String[] args) throws IOException {
		new c().run();
	}

	void run() throws IOException {
		reader = new BufferedReader(new FileReader("input.txt"));
		tokenizer = null;
		out = new PrintWriter(new FileWriter("output.txt"));
		solve();
		reader.close();
		out.flush();

	}

	BufferedReader reader;
	StringTokenizer tokenizer;
	PrintWriter out;

	int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

	String nextToken() throws IOException {
		while (tokenizer == null || !tokenizer.hasMoreTokens()) {
			tokenizer = new StringTokenizer(reader.readLine());
		}
		return tokenizer.nextToken();
	}
}
