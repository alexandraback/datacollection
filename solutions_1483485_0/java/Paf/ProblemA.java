import java.io.*;
import java.util.*;

import static java.lang.System.*;


public class ProblemA {

	LinkedHashMap<Character, Character> mapping = new LinkedHashMap<Character, Character>();

	public class Case {
		String line;

		public void solve(int caseIndex) {

			StringBuilder b = new StringBuilder();
			for (int i = 0; i < line.length(); i++) {
				char ch = mapping.get(line.charAt(i));
				b.append(ch);
			}

			println("Case #" + (caseIndex + 1) + ": "+b.toString());
		}

	}

	void buildMapping() {
		String sampleInput = "ejp mysljylc kd kxveddknmc re jsicpdrysi"+
				"rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd"+
				"de kr kd eoya kw aej tysr re ujdr lkgc jv";
		String sampleOutput = "our language is impossible to understand"+
				"there are twenty six factorial possibilities"+
				"so it is okay if you want to just give up";

		LinkedHashSet<Character> leftOverInput = new LinkedHashSet<Character>();
		LinkedHashSet<Character> leftOverOutput = new LinkedHashSet<Character>();
		for (int ch = 'a'; ch <= 'z'; ch++) {
			leftOverInput.add((char) ch);
			leftOverOutput.add((char) ch);
		}

		for (int i = 0; i < Math.max(sampleInput.length(), sampleOutput.length()); i++) {
			char in = sampleInput.charAt(i);
			char out = sampleOutput.charAt(i);

			Character existing = mapping.get(in);
			if (existing != null) {
				if (!existing.equals(out)) throw new RuntimeException();
			}
			else {
				mapping.put(in, out);
				leftOverInput.remove(in);
				leftOverOutput.remove(out);
			}
		}

		mapping.put('q', 'z');
		leftOverInput.remove('q');
		leftOverOutput.remove('z');

//		out.println(""+leftOverInput);
//		out.println(""+leftOverOutput);
		if (leftOverInput.size() > 1) throw new RuntimeException(""+leftOverInput); 
		if (leftOverOutput.size() > 1) throw new RuntimeException(); 
		if (leftOverOutput.size() != leftOverInput.size()) throw new RuntimeException(); 
		if (leftOverInput.size() == 1) {
			char in = leftOverInput.iterator().next();
			char out = leftOverOutput.iterator().next();
//			System.out.println("leftover: "+in+"="+out);
			mapping.put(in, out);
		}

//		out.println(""+mapping.size());
//		out.println(""+mapping);
	}

	public void run() throws Exception {
		buildMapping();

		BufferedReader r = new BufferedReader(new FileReader("input.txt"));
		int numCases = new InputParser(r.readLine()).readInt();

		for (int caseIndex = 0; caseIndex < numCases; caseIndex++) {
			Case c = new Case();

			c.line = r.readLine();


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
