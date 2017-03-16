import java.io.*;
import java.math.BigInteger;
import java.util.*;


public class C {

	void solve() throws IOException {
		nextInt();
		int r=nextInt();
		int n=nextInt();
		int m=nextInt();
		int k=nextInt();
		out.println("Case #1:");
		for(int R=0;R<r;R++){
			int[] a=new int[k];
			for(int i=0;i<k;i++)
				a[i]=nextInt();
			boolean found=false;
			for(int i=2;i<=m&&!found;i++)
			for(int j=2;j<=m&&!found;j++)
			for(int h=2;h<=m&&!found;h++){
				boolean good=true;
				for(int q=0;q<k;q++){
					int x=a[q];
					if(x%i==0)x/=i;
					if(x%j==0)x/=j;
					if(x%h==0)x/=h;
					if(x!=1){
						good=false;
						break;
					}
				}
				if(good){
					out.printf("%d%d%d\n",i,j,h);
					found=true;
				}
			}
		}
	}

	public static void main(String[] args) throws IOException {
		new C().run();
	}

	void run() throws IOException {
		//		reader = new BufferedReader(new InputStreamReader(System.in));
		reader = new BufferedReader(new FileReader("input.txt"));
//		out = new PrintWriter(new OutputStreamWriter(System.out));
		out = new PrintWriter(new FileWriter("output.txt"));
		tokenizer = null;
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
