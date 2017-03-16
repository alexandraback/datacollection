import java.io.BufferedWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.InputMismatchException;


public class ProblemC {

	public static void main(String[] args) throws IOException {
		Reader reader = new Reader(System.in);
		reader = new Reader(new FileInputStream("C-large.in"));

		File file = new File("C-large.out");
		file.createNewFile();
		BufferedWriter out = new BufferedWriter(new FileWriter(
				file.getAbsoluteFile()));

		int T = (int) reader.nextInt();

		for (int t = 1; t <= T; t++) {
			String answer = "";
			String result = "NO";

			int L = (int) reader.nextInt();
			long tempX = reader.nextInt();

			if (tempX >= 8) {
				tempX = 8 + tempX % 4;
			}
			int X = (int) tempX;

			String str = reader.next();

			ArrayList<Quaternion> list = new ArrayList<>();
			for (int i = 0; i < str.length(); i++) {
				list.add(new Quaternion(str.charAt(i)));
			}
			
			Quaternion current = new Quaternion(1, 0, 0, 0);
			int index = 0;
			boolean isIObtained = false;
			boolean isJObtained = false;
			boolean isKObtained = false;
			for (index = 0; index < L * X; index++) {
				int listIndex = index % L;
				current = current.times(list.get(listIndex));
				if ("i".equalsIgnoreCase(current.toString())) {
					isIObtained = true;
					break;
				}
			}

			current = new Quaternion(1, 0, 0, 0);
			for (index = index + 1; index < L * X; index++) {
				int listIndex = index % L;
				current = current.times(list.get(listIndex));
				if ("j".equalsIgnoreCase(current.toString())) {
					isJObtained = true;
					break;
				}
			}
			
			current = new Quaternion(1, 0, 0, 0);
			for (index = index + 1; index < L * X; index++) {
				int listIndex = index % L;
				current = current.times(list.get(listIndex));
			}
			if ("k".equalsIgnoreCase(current.toString())) {
				isKObtained = true;
			}
			
			result = isIObtained && isJObtained && isKObtained ? "YES" : "NO";

			answer = "Case #" + t + ": " + result;

			if (t != T) {
				answer = answer + "\n";
			}

			out.write(answer);
			System.out.print(answer);
		}

		out.flush();
		out.close();
	}

	public static class Quaternion {
		private final int x0, x1, x2, x3;
		
		public Quaternion(char axis) {
			this.x0 = 0;
			switch (axis) {
			case 'i':
				this.x1 = 1;
				this.x2 = 0;
				this.x3 = 0;
				break;
				
			case 'j':
				this.x1 = 0;
				this.x2 = 1;
				this.x3 = 0;
				break;
				
			case 'k':
				this.x1 = 0;
				this.x2 = 0;
				this.x3 = 1;
				break;

			default:
				this.x1 = 0;
				this.x2 = 0;
				this.x3 = 0;
				break;
			}
		}

		// create a new object with the given components
		public Quaternion(int x0, int x1, int x2, int x3) {
			this.x0 = x0;
			this.x1 = x1;
			this.x2 = x2;
			this.x3 = x3;
		}

		// return a string representation of the invoking object
		public String toString() {
			String result = "";
			
			if (x0 != 0) {
				result += x0;
			}
			
			if (x1 != 0) {
				if (!result.isEmpty()) {
					result = result + " + ";
				}
				
				if (x1 == 1) {
					result += ("i");
				} else if (x1 == -1) {
					result += ("-i");
				}else {
					result += (x1 + "i");
				}
				
			}
			
			if (x2 != 0) {
				if (!result.isEmpty()) {
					result = result + " + ";
				}

				if (x2 == 1) {
					result += ("j");
				} else if (x2 == -1) {
					result += ("-j");
				}else {
					result += (x2 + "j");
				}
			}
			
			if (x3 != 0) {
				if (!result.isEmpty()) {
					result = result + " + ";
				}

				if (x3 == 1) {
					result += ("k");
				} else if (x3 == -1) {
					result += ("-k");
				}else {
					result += (x3 + "k");
				}
			}
			
			
			return result;
		}

		// return a new Quaternion whose value is (this * b)
		public Quaternion times(Quaternion b) {
			Quaternion a = this;
			int y0 = a.x0 * b.x0 - a.x1 * b.x1 - a.x2 * b.x2 - a.x3 * b.x3;
			int y1 = a.x0 * b.x1 + a.x1 * b.x0 + a.x2 * b.x3 - a.x3 * b.x2;
			int y2 = a.x0 * b.x2 - a.x1 * b.x3 + a.x2 * b.x0 + a.x3 * b.x1;
			int y3 = a.x0 * b.x3 + a.x1 * b.x2 - a.x2 * b.x1 + a.x3 * b.x0;
			return new Quaternion(y0, y1, y2, y3);
		}
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