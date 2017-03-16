import java.io.BufferedWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStream;
import java.util.InputMismatchException;


public class ProblemC {
	
	public static void main(String[] args) throws IOException {
		String inputFileName = "C-small-attempt1.in";
		Reader reader = new Reader(new FileInputStream(inputFileName));
		
		String outputFileName = inputFileName.split("\\.")[0] + ".out";
		File file = new File(outputFileName);
		file.createNewFile();
		BufferedWriter out = new BufferedWriter(new FileWriter(file.getAbsoluteFile()));
		

		
		int T = (int) reader.nextInt();
		
		for (int t = 1; t <= T; t++) {
			String answer = "";
			
			long C =  reader.nextInt();
			int D =  (int)reader.nextInt();
			long V =  reader.nextInt();
			
			long[] denominations = new long[D];
			for (int i = 0; i < D; i++) {
				denominations[i] = (int) reader.nextInt();
			}
			
			long numberReachedSoFar = 0;
			long nextNumberRequired = 1;
			long requiredNewDenominations = 0;
			for (int i = 0; i < denominations.length; i++) {
				if (numberReachedSoFar > V) {
					break;
				}
				if (denominations[i] > nextNumberRequired && numberReachedSoFar < nextNumberRequired) {
					requiredNewDenominations++;
					numberReachedSoFar = nextNumberRequired * C + numberReachedSoFar;
					nextNumberRequired = numberReachedSoFar + 1;
					i--;
				} else {
					numberReachedSoFar = numberReachedSoFar + denominations[i];
					nextNumberRequired = numberReachedSoFar + 1;
				}
			}
			
			while (numberReachedSoFar < V) {
				requiredNewDenominations++;
				numberReachedSoFar = nextNumberRequired * C + numberReachedSoFar;
				nextNumberRequired = numberReachedSoFar + 1;
			}
			
			answer = "Case #" + t + ": " + requiredNewDenominations;
			
			if (t != T) {
				answer = answer + "\n";
			}
			
			out.write(answer);
			System.out.print(answer);
		}
		
		
		out.flush();
		out.close();
	}
	
	static class Reader {

		private InputStream stream;
		private byte[] buf = new byte[1024 * 1024];
		private int curChar;
		private int numChars;

		public Reader(InputStream stream) {
			this.stream = stream;
		}

		public int read() {
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
		
		public long nextInt() {
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
				res += c & 15;
				c = read();
			} while (!isSpaceChar(c));
			return res * sgn;
		}

		public String next() {
			int c = read();
			while (isSpaceChar(c))
				c = read();
			StringBuilder res = new StringBuilder();
			do {
				res.appendCodePoint(c);
				c = read();
			} while (!isSpaceChar(c));
			return res.toString();
		}

		public static boolean isSpaceChar(int c) {
			return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
		}

	}
}