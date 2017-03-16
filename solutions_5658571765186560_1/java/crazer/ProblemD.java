import java.io.BufferedWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStream;
import java.util.InputMismatchException;


public class ProblemD {
	
	public static void main(String[] args) throws IOException {
		String inputFileName = "D-large.in";
		Reader reader = new Reader(new FileInputStream(inputFileName));
		
		String outputFileName = inputFileName.split("\\.")[0] + ".out";
		File file = new File(outputFileName);
		file.createNewFile();
		BufferedWriter out = new BufferedWriter(new FileWriter(file.getAbsoluteFile()));
		

		int T = (int) reader.nextInt();
		
		for (int t = 1; t <= T; t++) {
			String answer = "";
			String winner = "GABRIEL";
			
			int X = (int) reader.nextInt();
			int R = (int) reader.nextInt();
			int C = (int) reader.nextInt();

			switch (X) {
			case 1:
				winner = "GABRIEL";
				break;
			case 2:
				if ((R * C) % 2 != 0) {
					winner = "RICHARD";
				} else {
					winner = "GABRIEL";
				}
				break;
			case 3:
				if (((R * C) % 3 != 0) || (R * C == 3)) {
					winner = "RICHARD";
				} else  {
					winner = "GABRIEL";
				}
				break;
			case 4:
				if (((R * C) % 4 != 0) || (R * C <= 8)) {
					winner = "RICHARD";
				} else  {
					winner = "GABRIEL";
				}
				break;
			case 5:
				if (((R * C) % 5 != 0) || (R * C <= 10)) {
					winner = "RICHARD";
				} else  {
					winner = "GABRIEL";
				}
				break;
				
			case 6:
				if (((R * C) % 6 != 0) || R <= 3 || C <= 3) {
					winner = "RICHARD";
				} else  {
					winner = "GABRIEL";
				}
				break;

			default:
				winner = "RICHARD";
				break;
			}
			
			
			answer = "Case #" + t + ": " + winner;
			
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