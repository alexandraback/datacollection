import java.io.*;
import java.math.BigInteger;
import java.util.*;


public class Chard {

	void solve() throws IOException {
		nextInt();
		int r=nextInt();
		int n=nextInt();
		int m=nextInt();
		int k=nextInt();
		out.println("Case #1:");
		for(int R=0;R<r;R++){
			long[] a=new long[k];
			for(int i=0;i<k;i++)
				a[i]=nextLong();
			int[] x=new int[10];
			for(int i=0;i<k;i++){
				int[] y=new int[10];
				long q=a[i];
				for(int j=2;j<=8;j++){
					while(q%j==0){
						q/=j;
						y[j]++;
					}
				}
				for(int j=0;j<9;j++)x[j]=Math.max(x[j],y[j]);
			}
			int count=0;
			for(int i=0;i<9;i++)
				count+=x[i];
			if(count>n){
				boolean good=true;
				while(count>n&&x[2]>=3&&good){
					if(x[2]==3)
					for(int i=0;i<k;i++)
						if(a[i]%2==0&&a[i]%8!=0){
							good=false;
						}
					if(x[2]==2)
						for(int i=0;i<k;i++)
							if(a[i]%4==0&&a[i]%8!=0){
								good=false;
							}
					if(good){
						count-=2;
						x[2]-=3;
						x[8]++;
					}
				}
				good=true;
				while(count>n&&x[2]>=2&&good){
					if(x[2]==2)
					for(int i=0;i<k;i++)
						if(a[i]%2==0&&a[i]%4!=0){
							good=false;
						}
					if(good){
						count--;
						x[2]-=2;
						x[4]++;
					}
				}
				good=true;
				while(count>n&&x[2]>0&&a[3]>0&&good){

					if(good){
						count-=1;
						x[2]--;
						x[3]--;
						x[6]++;
					}
				}

			}
			int q=0;
			for(int i=0;i<9;i++)
				for(int j=0;j<x[i]&&q<n;j++,q++){
					out.print(i);
				}
			for(int i=count;i<n;i++)
				out.print(2);
			out.println();
		}

	}

	public static void main(String[] args) throws IOException {
		new Chard().run();
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
