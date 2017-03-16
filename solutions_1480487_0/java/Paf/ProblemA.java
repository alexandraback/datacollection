import java.io.*;
import java.util.*;

public class ProblemA {


	public class Case {
		int[] judgePoints;
		double[] score;
		double voteTotal = 0;
		int n;
		double votesLeft = 0;
		ArrayList<Integer> high = new ArrayList<Integer>();
		ArrayList<Integer> low = new ArrayList<Integer>();
		double level;

		public void solve(int caseIndex) {
			n = judgePoints.length;
			score = new double[n];

			for (int i = 0; i < n; i++) {
				score[i] = judgePoints[i];
				voteTotal += judgePoints[i];
				high.add(i);
			}
			votesLeft = voteTotal;

			Collections.sort(high, new Comparator<Integer>() {
				public int compare(Integer o1, Integer o2) {
					return new Double(score[o1]).compareTo(new Double(score[o2]));
				}
			});

			while (true) {
				if (!raise()) break;
			}

			print("Case #" + (caseIndex + 1) + ":");

			for (int i = 0; i < n; i++) {
				double votes = (score[i] - judgePoints[i]) / voteTotal;
				if (votes < 0) votes = 0;
				if (votes > 1) votes = 1;
				print(" "+(votes * 100));
			}
			println("");
		}

		boolean raise() {
			if (low.isEmpty()) {
				low.add(high.remove(0));
				level = score[low.get(0)];
				return true;
			}

			if (!high.isEmpty()) {
				if (level >= score[high.get(0)]) {
					low.add(high.remove(0));
					return true;
				}
			}

			if (votesLeft <= 0) return false;

			if (high.isEmpty()) {
				double d = votesLeft / low.size();
				for (Integer i : low) {
					score[i] += d;
				}
				return false;
			}

			double nextLevel = score[high.get(0)];
			double votesNeeded = (nextLevel - level) * low.size();
			double nextVotesLeft = votesLeft - votesNeeded;
			if (nextVotesLeft < 0) {
				nextLevel = level + votesLeft / low.size();
				nextVotesLeft = 0;
			}

			for (Integer i : low) {
				score[i] += (nextLevel - level);
			}

			level = nextLevel;
			votesLeft = nextVotesLeft;
			return true;
		}
	}

	public void run() throws Exception {

		BufferedReader r = new BufferedReader(new FileReader("input.txt"));
		int numCases = new InputParser(r.readLine()).readInt();

		for (int caseIndex = 0; caseIndex < numCases; caseIndex++) {
			Case c = new Case();

			InputParser p = new InputParser(r.readLine());

			c.judgePoints = new int[p.readInt()];
			for (int i = 0; i < c.judgePoints.length; i++) {
				c.judgePoints[i] = p.readInt();
			}

			c.solve(caseIndex);
		}

		r.close();
	}

	public static void main(String[] args) throws Exception {
		fileWriter = new PrintWriter(new OutputStreamWriter(new BufferedOutputStream(new FileOutputStream("output.txt"))));
		new ProblemA().run();
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
