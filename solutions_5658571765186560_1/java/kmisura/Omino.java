package com.ominous;

public class Omino {
	private int x;
	private int r;
	private int c;
	
	public Omino(String line){
		String tokens[] = line.split(" ");
		x = Integer.parseInt(tokens[0]);
		r = Integer.parseInt(tokens[1]);
		c = Integer.parseInt(tokens[2]);
	}
	
	public boolean richardWins() {
		if (!((r * c) % x == 0))
			return true;

		int cols = Math.min(r, c);

		if (x <= 2) {
			return false;
		} else if (x == 3) {
			return cols < 2;
		} else if (x == 4) {
			return cols <= 2;
		} else if (x == 5) {
			return cols <= 3;
		} else if (x == 6) {
			return cols <= 3;
		} else if (x >= 7) {
			return true;
		} else {
			throw new IllegalArgumentException();
		}
	}
}
