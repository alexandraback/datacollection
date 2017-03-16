import java.io.BufferedWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStream;
import java.util.InputMismatchException;


public class ProblemA {
	
	public static void main(String[] args) throws IOException {
		Reader reader = new Reader(System.in);
		reader = new Reader(new FileInputStream("A-large.in"));
		
		File file = new File("A-large.out");
		file.createNewFile();
		BufferedWriter out = new BufferedWriter(new FileWriter(file.getAbsoluteFile()));
		

		int T = (int) reader.nextInt();
		
		for (int t = 1; t <= T; t++) {
			String answer = "";
			
			int maxS = (int) reader.nextInt();
			
			String str = reader.next();
			
			long extraFriends = 0;
			int alreadyAvailable = 0;
			for (int i = 0; i <= maxS; i++) {
				int currShyLevelMembers = (str.charAt(i) - '0');
				if (alreadyAvailable < i) {
					extraFriends += (i - alreadyAvailable);
					alreadyAvailable += (i - alreadyAvailable);
				}
				alreadyAvailable += currShyLevelMembers;
			}
			answer = "Case #" + t + ": " + extraFriends;
			
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