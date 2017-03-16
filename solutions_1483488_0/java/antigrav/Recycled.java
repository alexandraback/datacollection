package codejam2.recycled;

import java.util.HashSet;
import java.util.Scanner;

import codejam2.CodejamCase;
import codejam2.CodejamRunner;

public class Recycled extends CodejamRunner implements CodejamCase {
	private int min;
	private int max;
	private String result;
	@Override
	public void compute() {
		int r = 0;
		for(int i = min; i <= max; i++) {
			HashSet<String> ss = new HashSet<String>();
			String s = String.valueOf(i);
			for(int j = 1; j < s.length(); j++) {
				String n = s.substring(j) + s.substring(0, j);
				int in = Integer.valueOf(n);
				if (in > i && in <= max) {
					ss.add(n);
				}
			}
			r += ss.size();
		}
		result = String.valueOf(r);
	}

	@Override
	public String getOutput() {
		return result;
	}

	@Override
	public CodejamCase parseCase(Scanner s) {
		Recycled r = new Recycled();
		r.min = s.nextInt();
		r.max = s.nextInt();
		return r;
	}

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		new Recycled().run(args);
	}

}
