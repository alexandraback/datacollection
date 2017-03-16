package com.google.code;

import java.io.IOException;

public class B extends GCJ {

	protected B() throws IOException {
		super();
	}

	@Override
	protected void code(int count) throws IOException {
		readLine();
		int N = getIntInput(0);
		int S = getIntInput(1);
		int p = getIntInput(2);
		
		int limitForOrdinary = p + (p - 1 < 0 ? p : p - 1) * 2;
		int result = 0;
		for (int i = 0; i < N; i++) {
			int googler = getIntInput(3 + i);
			if (googler>= limitForOrdinary) {
				result ++;
				continue;
			}
			if (S>0)
				if (googler>1 && googler+2 >=limitForOrdinary) {
					S--;
					result++;
					continue;
				}			
		}
		writeln(result);
	}
	public static void main(String[] args) throws NumberFormatException,
	IOException {
		new B().run();
}
}
