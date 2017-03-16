package com.eduardcapell.gcj2013.r1c;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.util.List;
import java.util.Vector;

public class B {

	public static void main(String[] args) throws Exception {
		B b = new B();
		b.run();
	}

	public void run() throws Exception {
		String fileName = "/Users/edu/Dropbox/google_code_jam/2013/r1c/B-small-attempt2.in";
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
		String[] vals = row.split(" ");
		int dx = Integer.parseInt(vals[0]);
		int dy = Integer.parseInt(vals[1]);

		StringBuilder seq = new StringBuilder();

		int x = 0;
		boolean b = false;
		int n = 0;
		while (!b) {
			n++;
			x += n;
			seq.append(dx > 0 ? "E" : "W");
			if (Math.abs(x) > Math.abs(dx)) {
				int diff = Math.abs(x) - Math.abs(dx);
				for (int i = 0; i < diff; i++) {
					seq.append(dx > 0 ? "EW" : "WE");
					n += 2;
				}
				x = dx;
			}
			b = Math.abs(x) == Math.abs(dx);
		}

		int y = 0;
		b = false;
		while (!b) {
			n++;
			y += n;
			seq.append(dy > 0 ? "N" : "S");
			if (Math.abs(y) > Math.abs(dy)) {
				int diff = Math.abs(y) - Math.abs(dy);
				for (int i = 0; i < diff; i++) {
					seq.append(dy > 0 ? "NS" : "SN");
					n += 2;
				}
				y = dy;
			}
			b = Math.abs(y) == Math.abs(dy);
		}

		return seq.toString();
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
