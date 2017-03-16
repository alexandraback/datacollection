package com.eduardcapell.gcj2013.r1c;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.util.HashSet;
import java.util.List;
import java.util.Set;
import java.util.Vector;

public class A {

	public static final String X_WINS = "X won";
	public static final String O_WINS = "O won";
	public static final String DRAW = "Draw";
	public static final String NOT_OVER = "Game has not completed";

	public static void main(String[] args) throws Exception {
		A a = new A();
		a.run();
	}

	public void run() throws Exception {
		String fileName = "/Users/edu/Dropbox/google_code_jam/2013/r1c/A-small-attempt0.in";
		File f = new File(fileName);
		List<String> rows = getLines(f);

		int n = 0;

		for (String row : rows) {
			if (n == 0) {
				n++;
				continue;
			}
			String result = processCase(row);
			print("Case #" + n++ + ": " + result);
		}
	}

	private String processCase(String row) {
		String[] values = row.split(" ");
		int n = Integer.parseInt(values[1]);
		String s = values[0];

		int result = 0;

		Set<String> set = new HashSet<String>();
		for (int i = s.length(); i >= n; i--) {
			for (int j = 0; j < s.length() - i + 1; j++) {
				String sub = s.substring(j, i + j);
				// print(sub);
				if (consonantsOK(sub, n)) {
					result++;
				}
			}
		}

		// for (String str : set) {
		// System.out.println(str);
		// }

		return result + "";
	}

	private boolean consonantsOK(String s, int n) {
		s = s.toLowerCase();

		int k = 0;
		for (int i = 0; i < s.length(); i++) {
			if (s.charAt(i) == 'a' || s.charAt(i) == 'e' || s.charAt(i) == 'i'
					|| s.charAt(i) == 'o' || s.charAt(i) == 'u') {
				k = 0;
			} else {
				k++;
				if (k >= n) {
					return true;
				}
			}
		}
		return false;
	}

	private void print(Object o) {
		System.out.println(o);
	}

	public List<String> getLines(File f) throws Exception {
		List<String> lines = new Vector<String>();

		BufferedReader in = new BufferedReader(new FileReader(f));
		String line = null;
		while ((line = in.readLine()) != null) {
			lines.add(line);
		}

		in.close();
		return lines;
	}
}
