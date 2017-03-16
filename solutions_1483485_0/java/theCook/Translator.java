package codejam.speakingintongues;

import java.util.TreeMap;

public class Translator {

	private TreeMap<Character, Character> translations;

	public Translator(String[] googlerese, String[] english) {
		translations = new TreeMap<>();
		for (int i = 0; i < googlerese.length; i++) {
			char[] in = googlerese[i].toCharArray();
			char[] out = english[i].toCharArray();
			addTranslation(in, out);
		}
	}

	private void addTranslation(char[] in, char[] out) {
		for (int j = 0; j < in.length; j++) {
			translations.put(in[j], out[j]);
		}
	}

	public String translate(String googlerese) {
		StringBuilder result = new StringBuilder();
		char[] in = googlerese.toCharArray();
		for (int i = 0; i < in.length; i++) {
			Character character = translations.get(in[i]);
			if (character == null) {
				character = 'q';
			}
			result.append(character);
		}
		return result.toString();
	}
}
