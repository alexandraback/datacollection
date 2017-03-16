import java.io.*;
import java.math.BigInteger;
import java.util.*;


public class Bhard {

	long[] v;
	int n;
	long e,R;
	long ans;

	void doit(int l,int r1,long st,long fin){
		if(l>r1)return;
		long le=st+(r1-l+1)*1l*R;
		if(le<=fin)return;
		int nmax=l;
		for(int i=l+1;i<=r1;i++)
			if(v[i]>v[nmax])
				nmax=i;
		long me=Math.min(st+(nmax-l)*1l*R,e);
		long x=(r1-nmax+1)*1l*R;
		long st1;
		if(x<fin){
			st1=fin-x;
			me=me-st1;
		}
		else
			st1=0;
		st1+=R;
		ans+=v[nmax]*me;
		doit(l,nmax-1,st,me);
		doit(nmax+1,r1,st1,fin);
	}

	void solve() throws IOException {
		int t=nextInt();
		for(int testCase=0;testCase<t;testCase++){
			e=nextInt();
			R=nextInt();
			n=nextInt();
			v=new long[n];
			for(int i=0;i<n;i++)
				v[i]=nextInt();
			ans=0;
			doit(0,n-1,e,0);
			out.printf("Case #%d: %d\n",testCase+1,ans);
		}

	}

	public static void main(String[] args) throws IOException {
		new Bhard().run();
	}

	void run() throws IOException {
		tokenizer = null;
//		reader = new BufferedReader(new InputStreamReader(System.in));
		reader = new BufferedReader(new FileReader("input.txt"));
//		out = new PrintWriter(new OutputStreamWriter(System.out));
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
