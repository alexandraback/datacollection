package qualification;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.InputStream;
import java.io.PrintStream;


public class C {

	static byte[][] MAP = new byte[1000][1000];
	
	private static final char[] CASE = "Case #".toCharArray();
	
	public static void main(String[] args) throws Throwable {
//		in = System.in;
//		out = System.out;
		in = new FileInputStream("in/C-small-attempt0.in");
//		in = new FileInputStream("in/C-large.in");
		out = new PrintStream(new FileOutputStream("out/C.out"));

		
		int T = readInt();
		
		for (int test = 1; test <= T; test++) {
			int A = readInt();
			int B = readInt();
			
			int result = 0;
			
			for (int n = A; n < B; n++) {
				int nLen = length(n);
				
				// find all possible recycled numbers for this one
				for (int i = 1; i < nLen; i++) {
					int tenpow = pow(10,i);
					int tenpowfront = pow(10, nLen-i);
					int m = (n/tenpow) + ((n%tenpow) * tenpowfront);
					if (m == n) break;// if we found n back, it is a circular number (ex: 123123), and if we keep going, we'll duplicate the results found
					// the recycled numbers have to be: n < m; m <= B
					if (n < m && m <= B) {
						result++;
					}
				}
			}
			
			writeOut(CASE);
			writeOutNumber(test);
			writeOut(':');
			writeOut(' ');
			writeOutNumber(result);
			writeOutLn();
			flush();
		}
		
		flush();

	}
	
	static int length(int num) {
		int len = 1;
		int powerTen = 10;
		while (num >= powerTen) {
			powerTen *= 10;
			len++;
		}
		return len;
	}

	static InputStream in;
	static PrintStream out;
	
	static byte[] buffer = new byte[8192];
	static int pos;
	static int max;

	static final int maxOut = 8192;
	static byte[] output = new byte[maxOut];
	static int posOut = 0;
	
	static char[] tmpcharr = new char[128];

	static int pow2(int v) {
		return v * v;
	}
	
	static int pow(int v, int mag) {
		return (int) Math.pow(v, mag);
	}

	static boolean reachedEndOfLine() throws Throwable {
		while (true) {
			int data = read();
			if (data == -1)
				return true;
			if (data == '\r' || data == '\n') {
				return true;
			}
			if (data == ' ') {
				continue;
			}
			pos--;
			return false;
		}
	}

	// COMPARISION FUNCTIONS

	static boolean isValidChar(int v) {
		// nao verifica o 'DELETE' (127)
		return (v & 0xE0) != 0;
	}

	static boolean isNum(int v) {
		return v >= '0' && v <= '9';
	}

	static boolean isLowercase(int cur) {
		return cur >= 'a' && cur <= 'z';
	}

	static boolean isUppercase(int cur) {
		return cur >= 'A' && cur <= 'Z';
	}

	// is a letter (alphabetic)
	static boolean isAlpha(int cur) {
		return isLowercase(cur) || isUppercase(cur);
	}

	// is alphanumeric (letters and numbers)
	static boolean isAlphaNum(int cur) {
		return isAlpha(cur) || isNum(cur);
	}

	static boolean isMinus(int cur) {
		return cur == '-';
	}

	static boolean isPlus(int cur) {
		return cur == '+';
	}

	// INPUT FUNCTIONS

	static void goToBeginOfNextWord() throws Throwable {
		int cur;
		// se for -1 já sai do método
		while ((cur = read()) != -1) {
			// se for um char válido então deixa o ponteiro nele
			if (cur > 32) {
				pos--;
				return;
			}
		}
	}

	// return the length of the string read
	static String readWord() throws Throwable {
		int len = 0;
		int cur;
		// descarta os espacos em branco primeiro
		while ((cur = read()) < 33) {
			if (cur == -1) return "";
		}

		tmpcharr[len++] = (char) cur;
		while ((cur = (char) read()) > 32) {
			tmpcharr[len++] = (char) cur;
		}

		return new String(tmpcharr, 0, len);
	}

	static void discardWord() throws Throwable {
		int cur;
		// descarta os espacos em branco primeiro
		while ((cur = read()) < 33) {
			if (cur == -1)
				return;
		}
		// descarta os valores 'validos'
		while ((cur = read()) > 32)
			;
	}

	static int readInt() throws Throwable {
		int cur;
		while (!isNum(cur = read()) && !isMinus(cur))
			if (cur == -1)
				return -1;
		int v = 0;
		boolean minus = false;
		if (isMinus(cur)) {
			minus = true;
			cur = read();
		}
		while (isNum(cur)) {
			v *= 10;
			v += (cur - '0');
			cur = read();
		}
		return minus ? -v : v;
	}

	static char readChar() throws Throwable {
		int cur;
		for (;;) {
			cur = read();
			if (cur == -1)
				return 0;
			if (cur == '\r' || cur == '\n' || cur == ' ')
				continue;

			return (char) cur;
		}
	}

	static long readLong() throws Throwable {
		int cur;
		while (!isNum(cur = read()) && !isMinus(cur))
			if (cur == -1)
				return -1;
		long v = 0;
		boolean minus = false;
		if (isMinus(cur)) {
			minus = true;
			cur = read();
		}
		while (isNum(cur)) {
			v *= 10;
			v += (cur - '0');
			cur = read();
		}
		return minus ? -v : v;
	}

	static boolean hasInput() throws Throwable {
		while (true) {
			int data = read();
			if (data == -1)
				return false;
			if ((data & 0xE0) != 0) {
				pos--;
				return true;
			}
		}
	}

	static int read() throws Throwable {
		if (pos >= max) {
			max = in.read(buffer);
			if (max < 0)
				return -1;
			pos = 0;
		}
		return buffer[pos++] & 0xff;
	}

	// OUTPUT FUNCTIONS

	// escreve um char

	static void writeOut(char c) {
		if (posOut >= maxOut) {
			writeOutToStream();
		}
		output[posOut++] = (byte) c;
	}

	// escreve a quebra de linha
	static void writeOutLn() {
		writeOut('\n');
	}

	// escreve um char[]
	static void writeOut(char[] cs) {
		writeOut(cs, 0, cs.length);
	}

	// escreve uma cadeia de caracteres
	static void writeOut(char[] chars, int offset, int length) {
		final int end = offset + length;
		for (int i = offset; i < end; i++) {
			writeOut(chars[i]);
		}
	}

	static void writeOutNumber(int value) {
		int len = 0;
		int pos = tmpcharr.length;
		if (value == 0) {
			writeOut('0');
			return;
		}
		boolean negative = value < 0;
		if (negative)
			value = -value;
		while (value > 0) {
			tmpcharr[--pos] = (char) ((value % 10) + '0');
			len++;
			value /= 10;
		}
		if (negative)
			writeOut('-');
		writeOut(tmpcharr, pos, len);
	}

	static void writeOutNumberAsBin(int num) {
		int len = 0;
		int pos = tmpcharr.length;
		if (num == 0) {
			writeOut('0');
			return;
		}
		while (num > 0) {
			tmpcharr[--pos] = ((num & 1) == 1) ? '1' : '0';
			len++;
			num >>>= 1;
		}
		writeOut(tmpcharr, pos, len);
	}

	static void flush() {
		writeOutToStream();
		out.flush();
	}

	// PRIVATE methods must be used only by the utility methods

	private static void writeOutToStream() {
		out.write(output, 0, posOut);
		posOut = 0;
	}

}