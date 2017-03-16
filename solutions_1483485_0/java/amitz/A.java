package com.google.code;

import java.io.IOException;
import java.util.HashMap;

public class A extends GCJ {

	// I'm mapping all the conversion rule manually since rule doesn't change
	// across cases.
	protected A() throws IOException {
		super();
		converter.put("y", "a");
		converter.put("e", "o");
		converter.put("z", "q");
		converter.put(" ", " ");
		converter.put("j", "u");
		converter.put("p", "r");
		converter.put("m", "l");
		converter.put("s", "n");
		converter.put("l", "g");
		converter.put("c", "e");
		converter.put("k", "i");
		converter.put("d", "s");
		converter.put("x", "m");
		converter.put("v", "p");
		converter.put("d", "s");
		converter.put("n", "b");
		converter.put("r", "t");
		converter.put("i", "d");
		converter.put("b", "h");
		converter.put("t", "w");
		converter.put("a", "y");
		converter.put("h", "x");
		converter.put("w", "f");
		converter.put("f", "c");
		converter.put("o", "k");
		converter.put("u", "j");
		converter.put("g", "v");
		converter.put("q", "z");
	}

	HashMap<String, String> converter = new HashMap<String, String>();

	@Override
	protected void code(int count) throws IOException {
		readInputLine(input);
		for (int i = 0; i < inputLine.length(); i++)
			write(converter.get(inputLine.substring(i, i+1)));
		writeln();
	}

	public static void main(String[] args) throws NumberFormatException,
			IOException {
		new A().run();
	}
}
