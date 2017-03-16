import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.StringTokenizer;

public class Problem1CB {

	public static void main(String[] args) throws NumberFormatException,
			IOException {
		FileWriter writer = new FileWriter(
				"C:\\Users\\mchang\\workspace\\Google Code Jam\\src\\output.txt");
		String filename = "C:\\Users\\mchang\\workspace\\Google Code Jam\\src\\input.txt";
		long startTime = System.currentTimeMillis();
		try {
			BufferedReader br = new BufferedReader(new FileReader(filename));
			int numCases = Integer.parseInt(br.readLine());
			for (int caseNum = 1; caseNum <= numCases; caseNum++) {
				System.out.println(caseNum);
				int n = Integer.parseInt(br.readLine());
				StringTokenizer st = new StringTokenizer(br.readLine());
				ArrayList<String> trains = new ArrayList<String>();
				while (st.hasMoreTokens()) {
					trains.add(st.nextToken());
				}
				if (!checkForFailure(trains)) {
					printAnswer("" + 0, caseNum, writer);
					System.out.println("failure");
				} else {
					HashMap<Character, String> t = new HashMap<Character, String>();
					for (int i = 0; i < trains.size(); i++) {
						String word = trains.get(i);
						char firstChar = word.charAt(0);
						char lastChar = word.charAt(word.length() - 1);
						if (t.containsKey(firstChar)) {
							t.put(firstChar, t.get(firstChar) + lastChar);
						} else {
							t.put(firstChar, "" + lastChar);
						}
					}
					boolean done = false;
					Iterator<Character> it = t.keySet().iterator();
					while (it.hasNext()) {
						char key = it.next().charValue();
						String target = t.get(key);
						char otherLetter = '+';
						int copies = 0;
						for (int i = 0; i < target.length(); i++) {
							if (target.charAt(i) == key) {
								copies++;
							} else {
								if (otherLetter != '+') {
									done = true;
								} else {
									otherLetter = target.charAt(i);
								}
							}
							if (done) {
								break;
							}
						}
						if (done)
							break;
						String newTarget = "";
						if (otherLetter != '+') {
							newTarget += otherLetter;
						}
						for (int i = 0; i < copies; i++) {
							newTarget += key;
						}
						t.put(key, newTarget);
					}
					if (done) {
						printAnswer("" + 0, caseNum, writer);
						//System.out.println("internal failure");
					} else {
						int sum = 0;
						it = t.keySet().iterator();
						String keySet = "";
						while (it.hasNext()) {
							keySet += it.next().charValue();
						}
						System.out.println(keySet);
						for (int i = 0; i < keySet.length(); i++) {
							//System.out.println(keySet.charAt(i) + " " + t.get(keySet.charAt(i)) + " " + sum);
							sum += countPossibilities(
									t,
									"" + keySet.charAt(i),
									keySet.substring(0, i)
											+ keySet.substring(i + 1),
									keySet.charAt(i));
						}
						printAnswer("" + sum, caseNum, writer);
					}
				}
			}
			br.close();
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		writer.close();
		System.out.println(System.currentTimeMillis() - startTime);
	}

	public static int stupidWay(ArrayList<String> trains, String thusFar) {
		if (trains.size() == 0) {
			if (satisfies(thusFar)) {
				return 1;
			} else {
				return 0;
			}
		}
		int total = 0;
		for (int i = trains.size() - 1; i >= 0; i--) {
			String nextWord = trains.get(i);
			trains.remove(i);
			total += stupidWay(trains, thusFar + nextWord);
			trains.add(i, nextWord);
		}
		return total;
	}

	public static boolean satisfies(String s) {
		boolean[] let = new boolean[26];
		let[s.charAt(0) - 'a'] = true;
		for (int i = 1; i < s.length(); i++) {
			if (s.charAt(i) != s.charAt(i - 1)) {
				if (let[s.charAt(i) - 'a'])
					return false;
				let[s.charAt(i) - 'a'] = true;
			}
		}
		return true;
	}

	public static long countPossibilities(HashMap<Character, String> t,
			String visited, String remainingKeys, char c) {
		if (remainingKeys.length() == 0) {
			char lastChar = t.get(c).charAt(0);
			if(lastChar == c) return factorial(t.get(c).length());
			if (t.containsKey(lastChar))
				return 0;
			return 1;
		}

		String next = t.get(c);
		if (next.charAt(0) == c) {
			long sum = 0;
			for (int i = 0; i < remainingKeys.length(); i++) {
				sum += countPossibilities(
						t,
						visited + remainingKeys.charAt(i),
						remainingKeys.substring(0, i)
								+ remainingKeys.substring(i + 1),
						remainingKeys.charAt(i));
			}
			return sum * factorial(next.length());
		}
		int index = remainingKeys.indexOf(next.charAt(0));
		if (index == -1 && !t.containsKey(next.charAt(0))) {
			long sum = 0;
			for (int i = 0; i < remainingKeys.length(); i++) {
				sum += countPossibilities(
						t,
						visited + remainingKeys.charAt(i),
						remainingKeys.substring(0, i)
								+ remainingKeys.substring(i + 1),
						remainingKeys.charAt(i));
			}
			return sum * factorial(next.length() - 1);
		} else if(index == -1){
			return 0;
		}
		return countPossibilities(
				t,
				visited + next.charAt(0),
				remainingKeys.substring(0, index)
						+ remainingKeys.substring(index + 1), next.charAt(0))
				* factorial(next.length() - 1);

	}

	public static long factorial(long n) {
		if (n <= 1)
			return 1;
		return n * factorial(n - 1);
	}

	public static boolean checkForFailure(ArrayList<String> list) {
		boolean[] lettersSeenInMiddle = new boolean[26];
		for (int i = 0; i < list.size(); i++) {
			String word = list.get(i);
			char lastChar = word.charAt(word.length() - 1);
			int backIndex = word.length() - 1;
			while (backIndex >= 0 && word.charAt(backIndex) == lastChar) {
				backIndex--;
			}
			char firstChar = word.charAt(0);
			int frontIndex = 0;
			while (frontIndex < word.length()
					&& word.charAt(frontIndex) == firstChar) {
				frontIndex++;
			}
			HashSet<Character> middleChars = new HashSet<Character>();
			for (int index = frontIndex; index <= backIndex; index++) {
				middleChars.add(word.charAt(index));
			}
			Iterator<Character> it = middleChars.iterator();
			while (it.hasNext()) {
				char let = it.next().charValue();
				if (lettersSeenInMiddle[let - 'a']) {
					return false;
				} else {
					lettersSeenInMiddle[let - 'a'] = true;
				}
			}
		}
		for (int i = 0; i < list.size(); i++) {
			String word = list.get(i);
			if (lettersSeenInMiddle[word.charAt(0) - 'a']) {
				return false;
			}
			if (lettersSeenInMiddle[word.charAt(word.length() - 1) - 'a']) {
				return false;
			}
		}
		return true;

	}

	public static void printAnswer(String answer, int caseNumber,
			FileWriter writer) throws IOException {
		writer.write("Case #" + caseNumber + ": " + answer + "\n");
	}

}
