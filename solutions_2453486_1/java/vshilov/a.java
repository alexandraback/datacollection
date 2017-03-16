import java.io.*;
import java.math.BigInteger;
import java.util.*;


public class a {

	void solve() throws IOException {
		int t=nextInt();
		for(int testCase=0;testCase<t;testCase++){
			String[] s=new String[4];
			for(int i=0;i<4;i++)
				s[i]=nextToken();
			int res=3;
			String[] ans={"X won","O won","Game has not completed","Draw"};
			for(int i=0;i<4;i++){
				int x=0;
				int o=0;
				for(int j=0;j<4;j++){
					if(s[i].charAt(j)=='X')
						x++;
					if(s[i].charAt(j)=='O')
						o++;
					if(s[i].charAt(j)=='T'){
						x++;
						o++;
					}
				}
				if(x==4)
					res=0;
				if(o==4)
					res=1;
			}

			for(int i=0;i<4;i++){
				int x=0;
				int o=0;
				for(int j=0;j<4;j++){
					if(s[j].charAt(i)=='X')
						x++;
					if(s[j].charAt(i)=='O')
						o++;
					if(s[j].charAt(i)=='T'){
						x++;
						o++;
					}
				}
				if(x==4)
					res=0;
				if(o==4)
					res=1;
			}

			int x=0;
			int o=0;
			for(int j=0;j<4;j++){
				if(s[j].charAt(j)=='X')
					x++;
				if(s[j].charAt(j)=='O')
					o++;
				if(s[j].charAt(j)=='T'){
					x++;
					o++;
				}
			}
			if(x==4)
				res=0;
			if(o==4)
				res=1;
			x=0;
			o=0;
			for(int j=0;j<4;j++){
				if(s[j].charAt(3-j)=='X')
					x++;
				if(s[j].charAt(3-j)=='O')
					o++;
				if(s[j].charAt(3-j)=='T'){
					x++;
					o++;
				}
			}
			if(x==4)
				res=0;
			if(o==4)
				res=1;
			if(res==3){
				for(int i=0;i<4;i++)
					for(int j=0;j<4;j++)
						if(s[i].charAt(j)=='.')
							res=2;
			}

			out.printf("Case #%d: %s\n",testCase+1,ans[res]);

		}

	}

	public static void main(String[] args) throws IOException {
		new a().run();
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
