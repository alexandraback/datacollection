import java.io.*;
import java.util.HashSet;
import java.util.InputMismatchException;
import java.util.Locale;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Alex
 */
public class Main {
	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		InputStream inputStream;
		try {
			final String regex = "C-(small|large).*[.]in";
			File directory = new File(".");
			File[] candidates = directory.listFiles(new FilenameFilter() {
				public boolean accept(File dir, String name) {
					return name.matches(regex);
				}
			});
			File toRun = null;
			for (File candidate : candidates) {
				if (toRun == null || candidate.lastModified() > toRun.lastModified())
					toRun = candidate;
			}
			inputStream = new FileInputStream(toRun);
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		OutputStream outputStream;
		try {
			outputStream = new FileOutputStream("c.out");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		InputReader in = new InputReader(inputStream);
		OutputWriter out = new OutputWriter(outputStream);
		TaskC solver = new TaskC();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskC {
    public void solve(int testNumber, InputReader in, OutputWriter out){
	    int length = in.ri(), multiplier = in.ri();
	    String input = in.next();
	    StringBuilder multiplecopies = new StringBuilder();
	    for(int i = 0; i < multiplier; i++) multiplecopies.append(input);
	    String str = multiplecopies.toString();
	    HashSet<Integer> goodlast = new HashSet<>();
	    for(int i = 1; i < str.length(); i++) if (reduce(str.substring(i)) == 'k') goodlast.add(i);
	    char f = str.charAt(0);
	    int count = 0;
	    for(int first = 1; first < str.length() - 1; first++) {
		    if (f == 'i' && (count % 2 == 0)){
			    char s = str.charAt(first);
			    char count2 = 0;
			    for(int second = first + 1; second < str.length(); second++) {
				    if (s == 'j' && count2 % 2 == 0){
//					    String t = str.substring(second);
//					    if(reduce(t) == 'k'){
					    if (goodlast.contains(second)){
						    out.printLine("Case #" + testNumber + ": " + ("YES"));
						    System.err.println("Done with testcase: " + testNumber);
						    return;
					    }
				    }
				    Pair<Character, Integer> res = multiply(s, str.charAt(second));
				    s = res.first;
				    count2 += res.second;
			    }
		    }
		    Pair<Character, Integer> res = multiply(f, str.charAt(first));
		    f = res.first;
		    count += res.second;
	    }
	    out.printLine("Case #" + testNumber+": "+("NO"));
	    System.err.println("Done with testcase: " + testNumber);
    }
	char reduce(String s){
		char first = s.charAt(0);
		int count = 0;
		for(int i = 1; i< s.length(); i++) {
			Pair<Character, Integer> res = multiply(first, s.charAt(i));
			first = res.first;
			count += res.second;
		}
		if (count % 2 != 0) return '?';
		return first;
	}

	Pair<Character, Integer> multiply(char f, char s){
		if (f == '1' && s == '1') return Pair.makePair('1', 0);
		if (f == s) return Pair.makePair('1', 1);
		if (f == '1') return Pair.makePair(s, 0);
		if (s == '1') return Pair.makePair(f, 0);
		if (f == 'j' && s == 'i') return Pair.makePair('k', 1);
		if (f == 'k' && s == 'i') return Pair.makePair('j', 0);
		if (f == 'k' && s == 'j') return Pair.makePair('i', 1);
		if (f == 'i' && s == 'j') return Pair.makePair('k', 0);
		if (f == 'i' && s == 'k') return Pair.makePair('j', 1);
		if (f == 'j' && s == 'k') return Pair.makePair('i', 0);
		throw new RuntimeException();
	}
}

class InputReader {
	private InputStream stream;
	private byte[] buf = new byte[1024];
	private int curChar;
	private int numChars;
	private SpaceCharFilter filter;

	public InputReader(InputStream stream) {
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
	public int ri(){
		return readInt();
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
	public String readString() {
		int c = read();
		while (isSpaceChar(c))
			c = read();
		StringBuilder res = new StringBuilder();
		do {
			if (Character.isValidCodePoint(c))
				res.appendCodePoint(c);
			c = read();
		} while (!isSpaceChar(c));
		return res.toString();
	}

	public boolean isSpaceChar(int c) {
		if (filter != null)
			return filter.isSpaceChar(c);
		return isWhitespace(c);
	}

	public static boolean isWhitespace(int c) {
		return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
	}
	public String next() {
		return readString();
	}
	public interface SpaceCharFilter {
		public boolean isSpaceChar(int ch);
	}
}

class OutputWriter {
	private final PrintWriter writer;

	public OutputWriter(OutputStream outputStream) {
		writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
	}
	public void print(Object...objects) {
		for (int i = 0; i < objects.length; i++) {
			if (i != 0)
				writer.print(' ');
			writer.print(objects[i]);
		}
	}
	public void printLine(Object...objects) {
		print(objects);
		writer.println();
	}
	public void close() {
		writer.close();
	}
}

class Pair<U, V> implements Comparable<Pair<U, V>> {
	public final U first;
	public final V second;

	public static<U, V> Pair<U, V> makePair(U first, V second) {
		return new Pair<U, V>(first, second);
	}

	private Pair(U first, V second) {
		this.first = first;
		this.second = second;
	}

	public boolean equals(Object o) {
		if (this == o) return true;
		if (o == null || getClass() != o.getClass()) return false;

		Pair pair = (Pair) o;

		return !(first != null ? !first.equals(pair.first) : pair.first != null) && !(second != null ? !second.equals(pair.second) : pair.second != null);

	}

	public int hashCode() {
		int result = first != null ? first.hashCode() : 0;
		result = 31 * result + (second != null ? second.hashCode() : 0);
		return result;
	}
	public String toString() {
		return "(" + first + "," + second + ")";
	}

	public int compareTo(Pair<U, V> o) {
		int value = ((Comparable<U>)first).compareTo(o.first);
		if (value != 0)
			return value;
		return ((Comparable<V>)second).compareTo(o.second);
	}
}

