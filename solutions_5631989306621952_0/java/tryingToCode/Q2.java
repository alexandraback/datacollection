
import java.util.*;
import java.io.*;

public class OR1_1 {

	public static void main(String[] args) {
		InputReader s = new InputReader(System.in);
		OutputStream outputStream = System.out;
		PrintWriter out = new PrintWriter(outputStream);
		//Main code starts from here
		int t = s.nextInt(),n=t;
		while(t-->0){
			String inp = s.next(),op=""+inp.charAt(0);
			int len = inp.length();
			for(int i=1;i<len;i++){
				if(inp.charAt(i)>=op.charAt(0))
					op=(""+inp.charAt(i))+op;
				else
					op+=(""+inp.charAt(i));
			}
			out.println("Case #"+(n-t)+": "+op);
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
