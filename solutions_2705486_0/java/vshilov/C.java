import java.io.*;
import java.math.BigInteger;
import java.util.*;


public class C {

	void solve() throws IOException {
		int wc=521196;
		String[] words=new String[wc];
		for(int i=0;i<wc;i++)
			words[i]=dict.readLine();
		int t=nextInt();
		for(int testCase=0;testCase<t;testCase++){
			String s=nextToken();
			int n=s.length();
			int[][] dp=new int[n+1][5];
			for(int i=0;i<=n;i++)
				for(int j=0;j<5;j++)
					dp[i][j]=1000000000;
			dp[0][4]=0;
			for(int i=0;i<=n;i++){
				for(int j=0;j<5;j++){
					for(int k=0;k<wc;k++){
						if(i+words[k].length()>n)continue;
						int lp=j;
						int count=0;
						boolean bad=false;
						for(int h=0;h<words[k].length();h++){
							if(words[k].charAt(h)!=s.charAt(i+h)){
								if(lp<4){
									bad=true;
									break;
								}
								count++;
								lp=0;
							}
							else
								lp++;
						}
						if(!bad){
							lp=Math.min(4,lp);
							dp[i+words[k].length()][lp]=Math.min(dp[i+words[k].length()][lp],dp[i][j]+count);
						}
					}
				}
			}
			int ans=dp[n][0];
			for(int i=1;i<5;i++)
				ans=Math.min(ans,dp[n][i]);
			out.printf("Case #%d: %d\n",testCase+1,ans);
		}

	}

	public static void main(String[] args) throws IOException {
		new C().run();
	}

	void run() throws IOException {
		dict=new BufferedReader(new FileReader("garbled_email_dictionary.txt"));
//		reader = new BufferedReader(new InputStreamReader(System.in));
		reader = new BufferedReader(new FileReader("input.txt"));
		tokenizer = null;
//		out = new PrintWriter(new OutputStreamWriter(System.out));
		out = new PrintWriter(new FileWriter("output.txt"));

		solve();
		reader.close();
		out.flush();

	}

	BufferedReader reader;
	StringTokenizer tokenizer;
	PrintWriter out;
	BufferedReader dict;

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
