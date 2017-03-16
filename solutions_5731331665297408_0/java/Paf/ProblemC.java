import static java.lang.Math.*;

import java.io.*;
import java.util.*;

public class ProblemC {


	public class Case {
		int[] zips;
		LinkedHashMap<Integer, LinkedHashSet<Integer>> edges = new LinkedHashMap<>();

		LinkedHashSet<Integer> order;
//		LinkedHashMap<Integer, Integer> usedOutbounds;
//		LinkedHashMap<Integer, Integer> usedReturns;
		ArrayList<Integer> stack;
		String bestResult;

		public void solve(int caseIndex) {

			for (int start = 0; start < zips.length; start++) {
//				println("-----------------------------");
//				println("Start: "+start);
				order = new LinkedHashSet<>();
				stack = new ArrayList<>();
//				usedOutbounds = new LinkedHashMap<>();
//				usedReturns = new LinkedHashMap<>();
				stack.add(start);
				search(start);
			}

			println("Case #" + (caseIndex + 1) + ": " + bestResult);
		}

		void search(int city) {
//			println("Search: "+city+": "+order);
			boolean added = false;
			if (!order.contains(city)) {
				order.add(city);
				added = true;
			}
//			println("Order: "+order);
			try {
				if (order.size() == zips.length) {
//					println("Order: "+order);
					StringBuilder b = new StringBuilder();
					for (Integer c : order) {
						b.append(Integer.toString(zips[c]));
					}
					String r = b.toString();
//					println("Result: "+r);
					if (bestResult == null || r.compareTo(bestResult) < 0) {
						bestResult = r;
					}
//					println("Return");
					return;
				}

				LinkedHashSet<Integer> nexts = edges.get(city);
				if (nexts != null) {
//					println("Nexts: "+nexts);
					for (Integer next : nexts) {
						if (!order.contains(next)) {
//							println("Forward: "+next+": "+order);
//							if (usedOutbounds.containsKey(city)) throw new RuntimeException();
//							usedOutbounds.put(city, next);
							stack.add(next);
							search(next);
							stack.remove(stack.size() - 1);
//							usedOutbounds.remove(city);
						}
					}
				}

				if (stack.size() >= 2) {
					int prev = stack.get(stack.size() - 2);
					if (stack.get(stack.size() - 1) != city) throw new RuntimeException();
					stack.remove(stack.size() - 1);
//					println("Back: "+city+" -> "+prev+": "+order);
					search(prev);
					stack.add(city);
				}
			}
			finally {
				if (added) order.remove(city);
			}
		}

	}

	public void run() throws Exception {
		BufferedReader r = new BufferedReader(new FileReader("input.txt"));
		int numCases = new InputParser(r.readLine()).readInt();

		for (int caseIndex = 0; caseIndex < numCases; caseIndex++) {
			Case c = new Case();

			InputParser p = new InputParser(r.readLine());
			c.zips = new int[p.readInt()];
			int numFlights = p.readInt();
			for (int i = 0; i < c.zips.length; i++) {
				p = new InputParser(r.readLine());
				c.zips[i] = p.readInt();
			}
			for (int i = 0; i < numFlights; i++) {
				p = new InputParser(r.readLine());
				int p1 = p.readInt() - 1;
				int p2 = p.readInt() - 1;
				addToMultiMapLinkedHashSet(p1, p2, c.edges);
				addToMultiMapLinkedHashSet(p2, p1, c.edges);
			}

			c.solve(caseIndex);
		}

		r.close();
	}

	public static void main(String[] args) throws Exception {
		fileWriter = new PrintWriter(new OutputStreamWriter(new BufferedOutputStream(new FileOutputStream("output.txt"))));
		new ProblemC().run();
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

		public double readDouble() {
			return Double.parseDouble(readToken());
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

//	binarySearch(, , 0.000000001, new Function<Double, Integer>() {
//		public Integer evaluate(Double key) {
//			return ;
//		}
//	});
	public static double binarySearch(double low, double high, double precision, Function<Double, Integer> f) {
		if (high < low) throw new RuntimeException("High ("+high+") cannot be smaller than low ("+low+")");
		{
			int lowValue = f.evaluate(low);
			if (lowValue == 0) return low;
			if (lowValue > 0) throw new RuntimeException("Unsuitable low: "+low);
		}
		{
			int highValue = f.evaluate(high);
			if (highValue == 0) return high;
			if (highValue < 0) throw new RuntimeException("Unsuitable high: "+high);
		}

		while (true) {
			double mid = (low + high) * 0.5;
			if (abs(high - low) < precision) {
				return mid;
			}

			int c = f.evaluate(mid);
			if (c < 0) low = mid;
			else if (c > 0) high = mid;
			else return mid;
		}
	}

	public static <T> LinkedHashSet<T> intersection(Set<T> s1, Set<T> s2) {
		if (s2.size() < s1.size()) {
			Set<T> temp = s1;
			s1 = s2;
			s2 = temp;
		}
		LinkedHashSet<T> result = new LinkedHashSet<T>();
		for (T o : s1) {
			if (s2.contains(o)) result.add(o);
		}
		return result;
	}

	public static interface Function<Key, Value> {
		public Value evaluate(Key key);
	}

	public static class Int2 {
		int x, y;

		public Int2(int x, int y) {
			this.x = x;
			this.y = y;
		}

		@Override
		public int hashCode() {
			final int prime = 31;
			int result = 1;
			result = prime * result + x;
			result = prime * result + y;
			return result;
		}

		@Override
		public boolean equals(Object obj) {
			if (this == obj)
				return true;
			if (obj == null)
				return false;
			if (getClass() != obj.getClass())
				return false;
			Int2 other = (Int2) obj;
			if (x != other.x)
				return false;
			if (y != other.y)
				return false;
			return true;
		}

		@Override
		public String toString() {
			return "("+x+","+y+")";
		}
	}
}



