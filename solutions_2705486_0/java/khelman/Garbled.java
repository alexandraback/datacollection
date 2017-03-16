package pl.helman;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class Garbled {

	private static List<String> words;

	public static void main(String[] args) throws IOException {

		words = new ArrayList<String>(530000);

		FileReader dictReader = new FileReader(
				"d:\\cj\\garbled_email_dictionary.txt");
		BufferedReader dictBr = new BufferedReader(dictReader);

		String word = dictBr.readLine().trim();

		while (word != null) {
			words.add(word.trim());
			word = dictBr.readLine();
		}

		dictReader.close();

		FileReader fr = new FileReader("d:\\cj\\garb.in");
		BufferedReader br = new BufferedReader(fr);
		String line = br.readLine();

		FileWriter f0 = new FileWriter("d:\\cj\\garb.out");

		// number of cases
		int t = Integer.parseInt(line.trim());

		for (int c = 1; c <= t; c++) {

			line = br.readLine().trim();
			char[] chars = new char[line.length()];
			line.getChars(0, line.length(), chars, 0);

			int lastModifiedIndex = -5;
			int startIndex = 0;
			int modifiedLetters = 0;
			int wordIndex = 0;

			List<Elem> stack = new ArrayList<Garbled.Elem>(4000);

			int[][] endings = new int[5][line.length() + 1];
			for (int i = 0; i < line.length() + 1; i++) {
				for (int j = 0; j < 5; j++) {
					endings[j][i] = 4000;
				}
			}

			int min = line.length();

			stack.add(new Elem(-1, -5, -5, 0, 0, 0));

			while (!stack.isEmpty()) {
				while (wordIndex < words.size()) {
					Elem elem = doesWordFits(chars, wordIndex,
							lastModifiedIndex, startIndex, modifiedLetters);
					if (elem != null && min > elem.modifiedLettersAfter) {
						int nextWordStart = elem.wordStart
								+ words.get(wordIndex).length();

						if (nextWordStart == line.length()) {
							min = elem.modifiedLettersAfter;

							for (int i = stack.size() - 1; i > 0; i--) {
								Elem e = stack.get(i);
								
								e.hit = true;
								
								int ending = e.wordStart
										+ words.get(e.wordIndex).length();
								int firstFreeIndex = ending
										- e.modifiedIndexAfter;
								if (firstFreeIndex > 4) {
									firstFreeIndex = 4;
								}
								endings[firstFreeIndex][ending] = min
										- e.modifiedLettersAfter;
							}

//							System.out.println("got to end : " + min);
						} else {

//							System.out.println("  Matched: "
//									+ words.get(wordIndex));
							if (stack.size() == 1) {
								System.out.println("Matched: "
										+ words.get(wordIndex));

							}

							int firstFreeIndex = nextWordStart
									- elem.modifiedIndexAfter;
							if (firstFreeIndex > 4) {
								firstFreeIndex = 4;
							}

							if (endings[firstFreeIndex][nextWordStart] < 4000) {
								if (elem.modifiedLettersAfter
										+ endings[firstFreeIndex][nextWordStart] < min) {
									min = elem.modifiedLettersAfter
											+ endings[firstFreeIndex][nextWordStart];
								}
							} else {

								// going deeper

								stack.add(elem);

								lastModifiedIndex = elem.modifiedIndexAfter;
								startIndex = nextWordStart;
								modifiedLetters = elem.modifiedLettersAfter;

								// new search
								wordIndex = 0;
								continue;
							}
						}
					}

					wordIndex++;
				}

//				 System.out.println("  Step back");
				// step back
				for (int i = stack.size() - 1; i > 0; i--) {
					Elem e = stack.get(i);

					if (!e.hit) {
						int ending = e.wordStart
								+ words.get(e.wordIndex).length();
						int firstFreeIndex = ending - e.modifiedIndexAfter;
						if (firstFreeIndex > 4) {
							firstFreeIndex = 4;
						}
						endings[firstFreeIndex][ending] = 3999;
					}
				}
				
				Elem elem = stack.remove(stack.size() - 1);

				if (elem.wordIndex == -1) {
					break;
				}
				

				lastModifiedIndex = elem.modifiedIndexBefore;
				startIndex = elem.wordStart;
				modifiedLetters = elem.modifiedLettersBefore;
				wordIndex = elem.wordIndex + 1;
			}

			f0.write("Case #" + c + ": " + min + "\r\n");
			System.out.println("Case #" + c + ": " + min);
		}

		fr.close();
		f0.close();
	}

	public static Elem doesWordFits(char[] chars, int wordIndex,
			int lastModifiedIndex, int startIndex, int modifiedLetters) {

		int modifiedIndex = lastModifiedIndex;
		int modifiedLettersAfter = modifiedLetters;

		String word = words.get(wordIndex);

		if (chars.length < startIndex + word.length()) {
			return null;
		}

		for (int i = 0; i < word.length(); i++) {
			if (chars[startIndex + i] != word.charAt(i)) {

				if (startIndex + i - modifiedIndex >= 5) {
					// it's ok
					modifiedIndex = startIndex + i;
					modifiedLettersAfter++;
				} else {
					return null;
				}
			}
		}

		return new Elem(wordIndex, modifiedIndex, lastModifiedIndex,
				startIndex, modifiedLettersAfter, modifiedLetters);

	}

	public static class Elem {
		int wordIndex;
		int modifiedIndexAfter;
		int modifiedIndexBefore;
		int wordStart;
		int modifiedLettersAfter;
		int modifiedLettersBefore;
		boolean hit = false;

		public Elem(int wordIndex, int modifiedIndexAfter,
				int modifiedIndexBefore, int wordStart,
				int modifiedLettersAfter, int modifiedLettersBefore) {
			this.wordIndex = wordIndex;
			this.modifiedIndexAfter = modifiedIndexAfter;
			this.modifiedIndexBefore = modifiedIndexBefore;
			this.wordStart = wordStart;
			this.modifiedLettersAfter = modifiedLettersAfter;
			this.modifiedLettersBefore = modifiedLettersBefore;
		}

	}
}
