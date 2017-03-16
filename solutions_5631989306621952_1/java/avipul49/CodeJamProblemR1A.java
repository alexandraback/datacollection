
import java.io.DataInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.*;
public class CodeJamProblemR1A {

	static class State {
		String input;
		int level;
		public State(String in,int l){
			input = in;
			level = l;
		}
	}
	public static void main(String[] args) {
		File file = new File("input2.txt");
		try {
			Parser in = new Parser(new FileInputStream(file));
			PrintWriter out = new PrintWriter("output2.txt");
			int T = in.nextInt();

			for (int i = 0; i < T; i++) {
				String input = in.next();
				String output = ""+input.charAt(0);
				for(int j=1;j<input.length();j++){
					int k = 0;
					while(k<output.length() && output.charAt(k) == input.charAt(j)){
						k++;
					}
					if(k == output.length())
						k--;
					if(output.charAt(k) > input.charAt(j)){
						output = output+input.charAt(j);
					}else{
						output = input.charAt(j)+output;
					}
				}
				out.println("Case #"+(i+1)+": "+output);
			}
			out.close();
		} catch (Exception e) {
			e.printStackTrace();
		}

	}

	static class Parser {
		final private int BUFFER_SIZE = 1 << 16;

		private DataInputStream din;
		private byte[] buffer;
		private int bufferPointer, bytesRead;

		public Parser(InputStream in) {
			din = new DataInputStream(in);
			buffer = new byte[BUFFER_SIZE];
			bufferPointer = bytesRead = 0;
		}

		public long nextLong() throws Exception {
			long ret = 0;
			byte c = read();
			while (c <= ' ')
				c = read();
			boolean neg = c == '-';
			if (neg)
				c = read();
			do {
				ret = ret * 10 + c - '0';
				c = read();
			} while (c > ' ');
			if (neg)
				return -ret;
			return ret;
		}

		// reads in the next string
		public String next() throws Exception {
			StringBuilder ret = new StringBuilder();
			byte c = read();
			while (c <= ' ')
				c = read();
			do {
				ret = ret.append((char) c);
				c = read();
			} while (c > ' ');
			return ret.toString();
		}

		public int nextInt() throws Exception {
			int ret = 0;
			byte c = read();
			while (c <= ' ')
				c = read();
			boolean neg = c == '-';
			if (neg)
				c = read();
			do {
				ret = ret * 10 + c - '0';
				c = read();
			} while (c > ' ');
			if (neg)
				return -ret;
			return ret;
		}

		private void fillBuffer() throws Exception {
			bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE);
			if (bytesRead == -1)
				buffer[0] = -1;
		}

		private byte read() throws Exception {
			if (bufferPointer == bytesRead)
				fillBuffer();
			return buffer[bufferPointer++];
		}
	}
}
