import java.io.*;
import java.util.*;

import static java.lang.System.*;

public class ProblemB {


	public class Case {
		int initialWaterHeight;
		int m, n;
		int f[];
		int c[];
		long time = 0;

		TreeMap<Long, LinkedHashSet<Square>> squaresByEntryTime = new TreeMap<Long, LinkedHashSet<Square>>();
		Square[] squares;

		public void solve(int caseIndex) {
			squares = new Square[n * m];

			for (int y = 0; y < n; y++) {
				for (int x = 0; x < m; x++) {
					squares[y * m + x] = new Square(x, y, f[y * m + x], c[y * m + x]);
				}
			}

			squares[0].entryTime = 0L;
			addSquare(squares[0]);

			while (true) {
				Square s = squaresByEntryTime.firstEntry().getValue().iterator().next();
				removeSquare(s);
				time = s.entryTime;
//				println("Entry "+s.x+", "+s.y+": "+s.entryTime);

				if (s.x == m - 1 && s.y == n - 1) break;

				handleMove(s, +1, 0);
				handleMove(s, -1, 0);
				handleMove(s, 0, +1);
				handleMove(s, 0, -1);
			}

			println("Case #" + (caseIndex + 1) + ": " + (((double) time) / 10));
		}

		void handleMove(Square s, int dx, int dy) {
			int x2 = s.x + dx;
			int y2 = s.y + dy;
			if (x2 < 0 || x2 >= m) return;
			if (y2 < 0 || y2 >= n) return;

			Square s2 = squares[y2 * m + x2];

			if (s2.entryTime != null && s2.entryTime <= time) return;

			if (s.floor + 50 > s2.ceiling) return;
			if (s2.floor + 50 > s2.ceiling) return;
			if (s2.floor + 50 > s.ceiling) return;

			long entryTime = 0;
			long waterLevel = s2.ceiling - 50;
			long waterLevelTime = initialWaterHeight - waterLevel;
			if (waterLevelTime < 0) waterLevelTime = 0;
			entryTime = Math.max(time, waterLevelTime);

			if (entryTime > 0) {
				if (initialWaterHeight - entryTime - s.floor >= 20) {
					entryTime += 10;
				}
				else {
					entryTime += 100;
				}
			}

			if (s2.entryTime == null || entryTime < s2.entryTime) {
				removeSquare(s2);
				s2.entryTime = entryTime;
				addSquare(s2);
			}
		}

		void addSquare(Square s) {
			addToMultiMapLinkedHashSet(s.entryTime, s, squaresByEntryTime);
		}

		void removeSquare(Square s) {
			if (s.entryTime != null) {
				LinkedHashSet<Square> set = squaresByEntryTime.get(s.entryTime);
				if (!set.remove(s)) throw new RuntimeException();
				if (set.isEmpty()) {
					squaresByEntryTime.remove(s.entryTime);
				}
				else {
					squaresByEntryTime.put(s.entryTime, set);
				}
			}
		}

		class Square {
			int x, y;
			int floor, ceiling;
			Long entryTime;

			public Square(int x, int y, int floor, int ceiling) {
				this.x = x;
				this.y = y;
				this.floor = floor;
				this.ceiling = ceiling;
			}
		}
	}

	public void run() throws Exception {

		BufferedReader r = new BufferedReader(new FileReader("/home/useruser/datacollection/input/1485488_0.in"));
		int numCases = new InputParser(r.readLine()).readInt();

		for (int caseIndex = 0; caseIndex < numCases; caseIndex++) {
			Case c = new Case();

			{
				InputParser p = new InputParser(r.readLine());
				c.initialWaterHeight = p.readInt();
				c.n = p.readInt();
				c.m = p.readInt();
				c.f = new int[c.n * c.m];
				c.c = new int[c.n * c.m];
			}

			for (int i = 0; i < c.n; i++) {
				InputParser p = new InputParser(r.readLine());
				for (int k = 0; k < c.m; k++) {
					c.c[i * c.m + k] = p.readInt();
				}
			}

			for (int i = 0; i < c.n; i++) {
				InputParser p = new InputParser(r.readLine());
				for (int k = 0; k < c.m; k++) {
					c.f[i * c.m + k] = p.readInt();
				}
			}

			c.solve(caseIndex);
		}

		r.close();
	}

	public static void main(String[] args) throws Exception {
		fileWriter = new PrintWriter(new OutputStreamWriter(new BufferedOutputStream(new FileOutputStream("output.txt"))));
		new ProblemB().run();
		fileWriter.close();
	}

	public static class InputParser {
		String text;
		int pos;

		public InputParser(String text) {
			this.text = text;
		}

		public void skipSpaces() {
			while (pos < text.length()) {
				if (text.charAt(pos) != ' ') break;
				pos++;
			}
		}

		public String readUntil(char expectedChar) {
			StringBuilder b = new StringBuilder();
			while (pos < text.length()) {
				char ch = text.charAt(pos);
				if (ch == expectedChar) break;
				b.append(ch);
				pos++;
			}
			return b.toString();
		}

		public String readToken() {
			skipSpaces();
			return readUntil(' ');
		}

		public int readInt() {
			return Integer.parseInt(readToken());
		}

		public long readLong() {
			return Long.parseLong(readToken());
		}

		public char readChar() {
			char ch = text.charAt(pos);
			pos++;
			return ch;
		}

		public void readExpectedString(String s) {
			for (int i = 0; i < s.length(); i++) {
				char ch = s.charAt(i);
				if (readChar() != ch) throw new RuntimeException("Expected: "+ch);
			}
		}
	}

	public static PrintWriter fileWriter;

	public static void print(String text) {
		fileWriter.print(text);
		System.out.print(text);
	}

	public static void println(String text) {
		fileWriter.println(text);
		System.out.println(text);
	}

	public static <Key, Value> void addToMultiMapArrayList(Key key, Value value, Map<Key, ArrayList<Value>> map) {
		ArrayList<Value> list = map.get(key);
		if (list == null) {
			list = new ArrayList<Value>();
			map.put(key, list);
		}
		list.add(value);
	}

	public static <Key, Value> void addToMultiMapLinkedHashSet(Key key, Value value, Map<Key, LinkedHashSet<Value>> map) {
		LinkedHashSet<Value> list = map.get(key);
		if (list == null) {
			list = new LinkedHashSet<Value>();
			map.put(key, list);
		}
		list.add(value);
	}

	public static <Key, Value> ArrayList<Value> getMultiMapValues(Map<Key, Collection<Value>> map) {
		ArrayList<Value> result = new ArrayList<Value>();
		for (Collection<Value> list : map.values()) {
			result.addAll(list);
		}
		return result;
	}


}
