import java.io.*;
import java.math.BigInteger;
import java.util.*;


public class b {

	void solve() throws IOException {
		int t=nextInt();
		for(int testCase=0;testCase<t;testCase++){
			int n=nextInt();
			int m=nextInt();
			int[][] a=new int[n][m];
			for(int i=0;i<n;i++)
				for(int j=0;j<m;j++)
					a[i][j]=nextInt();
			boolean doWork=true;
			boolean[][] cut=new boolean[n][m];
			while(doWork){
				doWork=false;
				for(int i=0;i<n;i++){
					boolean good=true;
					int h=100;
					for(int j=0;j<m;j++)
						if(!cut[i][j]&&a[i][j]!=100){
							h=a[i][j];
							break;
						}
					if(h!=100){
						for(int j=0;j<m;j++)
							if(!(a[i][j]==h||(a[i][j]<=h&&cut[i][j]))){
								good=false;
								break;
							}
						if(good){
							doWork=true;
							for(int j=0;j<m;j++){
								a[i][j]=h;
								cut[i][j]=true;
							}
						}
					}
				}
				for(int j=0;j<m;j++){
					boolean good=true;
					int h=100;
					for(int i=0;i<n;i++)
						if(!cut[i][j]&&a[i][j]!=100){
							h=a[i][j];
							break;
						}
					if(h!=100){
						for(int i=0;i<n;i++)
							if(!(a[i][j]==h||(a[i][j]<=h&&cut[i][j]))){
								good=false;
								break;
							}
						if(good){
							doWork=true;
							for(int i=0;i<n;i++){
								a[i][j]=h;
								cut[i][j]=true;
							}
						}
					}
				}
			}
			boolean good=true;
			for(int i=0;i<n;i++)
				for(int j=0;j<m;j++)
					if(!(a[i][j]==100||cut[i][j]))
						good=false;
			if(good)
				out.printf("Case #%d: YES\n",testCase+1);
			else
				out.printf("Case #%d: NO\n",testCase+1);
		}
	}

	public static void main(String[] args) throws IOException {
		new b().run();
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
