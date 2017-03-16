import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintStream;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.HashMap;
import java.util.InputMismatchException;
import java.util.Locale;
import java.util.Map;

/**
 * @author Mikeldi Latorre (mikeldi10@gmail.com)
 */
public class B implements Runnable {
	private InputReader in;
	private PrintWriter out;

	public static void main(String[] args) {
		new B().run();
	}

	public B() {
		try {
			System.setIn(new FileInputStream("input.in"));
			System.setOut(new PrintStream(new FileOutputStream("output.out")));
		} catch (FileNotFoundException e) {
			throw new RuntimeException();
		}
		in = new InputReader(System.in);
		out = new PrintWriter(System.out);
	}

	public void run() {
	 int numTests = in.readInt();
        for (int testNumber = 0; testNumber < numTests; testNumber++) {
        	out.println("Case #" + (testNumber + 1) + ": "+algorithm());
		}
		out.close();
	}
	
	private String algorithm(){
		int k = in.readInt();
		int l = in.readInt();
		int s = in.readInt();
		
		Map<Character,Integer> chars = new HashMap<Character,Integer>();
		for (int i = 0; i < k; i++) {
			char c = in.readCharacter();
			if(chars.containsKey(c)){
				chars.put(c, chars.get(c)+1);
			}else{
				chars.put(c,1);
			}
		}
//		double probability = 1.0;
		
		StringBuilder str = new StringBuilder();
		for (int i = 0; i < l; i++) {
			char c = in.readCharacter();
			if(!chars.containsKey(c)){
				if(i+1!=l) in.readLine();
				return format(0.0);
			}
			str.append(c);
//			probability *= ((double)chars.get(c))/((double)k);
		}
		
		int pos = 0;
		double probability = 1.0;
		for (int i = 1; i < l; i++) {
			char c = str.charAt(i);
			if(c!=str.charAt(pos)){
				pos = 0;
				probability = 1.0;
			}else{
				pos++;
				probability *= ((double)chars.get(c))/((double)k);
			}
		}
		
		double probability2 = 1.0;
		for (int i = pos; i < l; i++) {
			char c = str.charAt(i);
			probability2 *= ((double)chars.get(c))/((double)k);
		}
		
		int min = (s/(l-pos));
		return format(((double)min)-(probability*probability2)*min);
	}
	
	private String format(double x){
		return String.format(Locale.ENGLISH, "%.7f", x);
	}

	private static class InputReader {
		private InputStream stream;
		private byte[] buf = new byte[1000];
		private int curChar, numChars;

		public InputReader(InputStream stream) {
			this.stream = stream;
		}

		private int read() {
			if (numChars == -1)
				throw new InputMismatchException();
			if (curChar >= numChars) {
				curChar = 0;
				try {
					numChars = stream.read(buf);
				} catch (IOException e) {
					throw new InputMismatchException();
				}
				if (numChars <= 0)
					return -1;
			}
			return buf[curChar++];
		}

		public int readInt() {
			int c = read();
			while (isSpaceChar(c))
				c = read();
			int sgn = 1;
			if (c == '-') {
				sgn = -1;
				c = read();
			}
			int res = 0;
			do {
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res *= 10;
				res += c - '0';
				c = read();
			} while (!isSpaceChar(c));
			return res * sgn;
		}

		public long readLong() {
			int c = read();
			while (isSpaceChar(c))
				c = read();
			int sgn = 1;
			if (c == '-') {
				sgn = -1;
				c = read();
			}
			long res = 0;
			do {
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res *= 10;
				res += c - '0';
				c = read();
			} while (!isSpaceChar(c));
			return res * sgn;
		}

		public String readString() {
			int c = read();
			while (isSpaceChar(c))
				c = read();
			StringBuffer res = new StringBuffer();
			do {
				res.appendCodePoint(c);
				c = read();
			} while (!isSpaceChar(c));
			return res.toString();
		}

		private boolean isSpaceChar(int c) {
			return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
		}

		private String readLine0() {
			StringBuffer buf = new StringBuffer();
			int c = read();
			while (c != '\n' && c != -1) {
				buf.appendCodePoint(c);
				c = read();
			}
			return buf.toString();
		}

		public String readLine() {
			String s = readLine0();
			while (s.trim().length() == 0)
				s = readLine0();
			return s;
		}

		public String readLine(boolean ignoreEmptyLines) {
			if (ignoreEmptyLines)
				return readLine();
			else
				return readLine0();
		}

		public BigInteger readBigInteger() {
			try {
				return new BigInteger(readString());
			} catch (NumberFormatException e) {
				throw new InputMismatchException();
			}
		}

		public char readCharacter() {
			int c = read();
			while (isSpaceChar(c))
				c = read();
			return (char) c;
		}

		public double readDouble() {
			int c = read();
			while (isSpaceChar(c))
				c = read();
			int sgn = 1;
			if (c == '-') {
				sgn = -1;
				c = read();
			}
			double res = 0;
			while (!isSpaceChar(c) && c != '.') {
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res *= 10;
				res += c - '0';
				c = read();
			}
			if (c == '.') {
				c = read();
				double m = 1;
				while (!isSpaceChar(c)) {
					if (c < '0' || c > '9')
						throw new InputMismatchException();
					m /= 10;
					res += (c - '0') * m;
					c = read();
				}
			}
			return res * sgn;
		}
	}
}
