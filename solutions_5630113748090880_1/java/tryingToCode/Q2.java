
import java.util.*;
import java.io.*;

public class OR1_2 {

	public static void main(String[] args) {
		InputReader s = new InputReader(System.in);
		OutputStream outputStream = System.out;
		PrintWriter out = new PrintWriter(outputStream);
		//Main code starts from here
		int t =s.nextInt(),p=t;
		while(t-->0){
			int n = s.nextInt();
			int inp[][]=new int[n][n];
			int cnt[]=new int[2501];
			int row=0;
			int odd[]=new int[n];
			for(int i=0;i<2*n-1;i++){
				for(int j=0;j<n;j++){
					cnt[s.nextInt()]++;
				}
			}
			for(int i=1;i<2501;i++){
				if((cnt[i] & 1)==1)
					odd[row++]=i;
			}
			Arrays.sort(odd);
			out.print("Case #"+(p-t)+": ");
			for(int i=0;i<n;i++){
				if(i!=(n-1))
					out.print(odd[i]+" ");
				else
					out.println(odd[i]);
			}
		}
		//Ends here
		out.close();
	}

	static class InputReader {
		public BufferedReader reader;
		public StringTokenizer tokenizer;

		public InputReader(InputStream inputstream) {
			reader = new BufferedReader(new InputStreamReader(inputstream));
			tokenizer = null;
		}

		public String nextLine() {
			String fullLine = null;
			while (tokenizer == null || !tokenizer.hasMoreTokens()) {
				try {
					fullLine = reader.readLine();
				} catch (IOException e) {
					throw new RuntimeException(e);
				}
				return fullLine;
			}
			return fullLine;
		}

		public String next() {
			while (tokenizer == null || !tokenizer.hasMoreTokens()) {
				try {
					tokenizer = new StringTokenizer(reader.readLine());
				} catch (IOException e) {
					throw new RuntimeException(e);
				}
			}
			return tokenizer.nextToken();
		}

		public long nextLong() {
			return Long.parseLong(next());
		}

		public int nextInt() {
			return Integer.parseInt(next());
		}

		public double nextDouble() {
			return Double.parseDouble(next());
		}
	}
}
