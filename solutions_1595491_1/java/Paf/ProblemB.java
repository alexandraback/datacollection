import java.io.*;
import java.util.*;
import static java.lang.System.*;

public class ProblemB {


	public class Case {
		int numSurprising;
		int bestResultThreshold;
		ArrayList<Integer> points = new ArrayList<Integer>();

		ArrayList<ArrayList<Integer>> findTriples(int sum, int maxDiff) {
			int floor = sum / 3;
			int ceil = (sum + 2) / 3;

			int min = Math.max(ceil - maxDiff, 0);
			int max = Math.min(floor + maxDiff, 10);

			ArrayList<ArrayList<Integer>> ts = new ArrayList<ArrayList<Integer>>();
			for (int i1 = min; i1 <= max; i1++) {
				for (int i2 = min; i2 <= max; i2++) {
					loop:
					for (int i3 = min; i3 <= max; i3++) {
						ArrayList<Integer> t = new ArrayList<Integer>();
						t.add(i1);
						t.add(i2);
						t.add(i3);

						int s = 0;
						for (int i : t) s += i;
						if (s != sum) continue;

						for (int i : t) {
							for (int k : t) {
								if (Math.abs(i - k) > maxDiff) continue loop;
							}
						}

						ts.add(t);
					}
				}
			}

			return ts;
		}

		int getMax(ArrayList<Integer> t) {
			Integer max = null;
			for (Integer i : t) {
				if (max == null || i > max) max = i;
			}
			return max;
		}

		public void solve(int caseIndex) {

			int numBest = 0;

			loop:
			for (int p : points) {
				{
					ArrayList<ArrayList<Integer>> ts = findTriples(p, 1);
					for (ArrayList<Integer> t : ts) {
						if (getMax(t) >= bestResultThreshold) {
							numBest++;
							continue loop;
						}
					}
				}

				if (numSurprising > 0) {
					ArrayList<ArrayList<Integer>> ts = findTriples(p, 2);
					for (ArrayList<Integer> t : ts) {
						if (getMax(t) >= bestResultThreshold) {
							numBest++;
							numSurprising--;
							continue loop;
						}
					}
				}

//				int baseBest = (p + 2) / 3;
//				if (baseBest >= bestResultThreshold) {
//					numBest++;
//				}
//				else {
//					if (numSurprising > 0) {
//						
//					}
//				}
			}

			println("Case #" + (caseIndex + 1) + ": "+numBest);
		}

	}

	public void run() throws Exception {

		BufferedReader r = new BufferedReader(new FileReader("input.txt"));
		int numCases = new InputParser(r.readLine()).readInt();

		for (int caseIndex = 0; caseIndex < numCases; caseIndex++) {
			Case c = new Case();

			InputParser p = new InputParser(r.readLine());

			int googlers = p.readInt();
			c.numSurprising  = p.readInt();
			c.bestResultThreshold = p.readInt();
			for (int i = 0; i < googlers; i++) {
				c.points.add(p.readInt());
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
