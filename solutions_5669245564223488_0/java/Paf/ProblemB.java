import java.io.*;
import java.util.*;

import javax.management.*;

import static java.lang.Math.*;
import static java.lang.System.*;

public class ProblemB {


	public class Case {
		String[] cars;

		LinkedHashSet<ArrayList<Integer>> allPerms = new LinkedHashSet<ArrayList<Integer>>();
		
		public void solve(int caseIndex) {

			long validPerms = 0;
			long perms = factorial(cars.length);
			for (long p = 0; p < perms; p++) {
				ArrayList<Integer> left = new ArrayList<>();
				for (int i = 0; i < cars.length; i++) left.add(i);

				ArrayList<Integer> order = new ArrayList<>();
				long perm = p;
				for (int i = 0; i < cars.length; i++) {
					long divisor = (cars.length - i);
					int index = (int) (perm % divisor);
					int carIndex = left.remove(index);
					order.add(carIndex);
					perm /= divisor;
				}
				if (!left.isEmpty()) throw new RuntimeException();
//				System.out.println("Perm: "+order);

				if (isValid(order)) {
//					System.out.println(""+order);
//					StringBuilder b = new StringBuilder();
//					for (Integer i : order) {
//						b.append(" "+cars[i]);
//					}
//					System.out.println(""+b.toString());
					validPerms++;
				}
//				System.out.println(""+order+", "+p);
//				if (!allPerms.add(order)) {
//					throw new RuntimeException(""+order);
//				}
			}

//			if (allPerms.size() != perms) throw new RuntimeException();

			println("Case #" + (caseIndex + 1) + ": " + validPerms);
		}

		boolean isValid(ArrayList<Integer> order) {
			LinkedHashSet<Character> processed = new LinkedHashSet<>();

			Character last = null;
			for (Integer i : order) {
				String s = cars[i];
				for (int k = 0; k < s.length(); k++) {
					char ch = s.charAt(k);
//					System.out.println("Current: "+ch);
					if (last != null && last.charValue() == ch) {
//						System.out.println("Last: "+last+", processed: "+processed);
					}
					else {
						if (processed.contains(ch)) return false;
						processed.add(ch);
					}
					last = ch;
				}
			}
			return true;
		}
		
		long factorial(long p) {
			long result = 1;
			for (long i = 2; i <= p; i++) result *= i;
			return result;
		}

	}

	public void run() throws Exception {
		BufferedReader r = new BufferedReader(new FileReader("input.txt"));
		int numCases = new InputParser(r.readLine()).readInt();

		for (int caseIndex = 0; caseIndex < numCases; caseIndex++) {
			Case c = new Case();

			InputParser p = new InputParser(r.readLine());

			c.cars = new String[p.readInt()];
			p = new InputParser(r.readLine());
			for (int i = 0; i < c.cars.length; i++) {
				c.cars[i] = p.readToken();
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



