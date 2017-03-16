package com.dijkstra;

public class Dijkstra {
	private final static byte p1 = 0;
	private final static byte pi = 1;
	private final static byte pj = 2;
	private final static byte pk = 3;
	private final static byte m1 = 4;
	private final static byte mi = 5;
	private final static byte mj = 6;
	private final static byte mk = 7;

	private int l;
	private long x;
	private String word;
	private byte[][] tab;
	private byte fullLenResult;

	public Dijkstra(int l, long x, String word) {
		this.l = l;
		this.x = x;
		this.word = word;

		tab = new byte[][] { { p1, pi, pj, pk }, { pi, m1, pk, mj }, { pj, mk, m1, pi }, { pk, pj, mi, m1 } };
		initCache();
	}

	private void initCache() {
		byte r = p1;
		for (int i = 0; i < l; i++) {
			r = mult(r, charToNum(word.charAt(i)));
		}
		fullLenResult = r;
	}

	public boolean isValid() {
		return isValid(pi, 0);
	}

	public boolean isValid(byte goal, long idx) {
		if (goal == pi) {
			byte current = p1;
			for (long i = idx; i < Math.min(l * x, 4 * l); i++) {
				current = mult(current, numAt(i));
				if (current == pi) {
					return isValid(pj, i + 1);
				}
			}
		} else if (goal == pj) {
			byte current = p1;
			for (long i = idx; i < Math.min(l * x, idx + 4 * l); i++) {
				current = mult(current, numAt(i));
				if (current == pj) {
					return isValid(pk, i+1);
				}
			}
		} else if (goal == pk) {
			byte current = p1;
			long remaining = l * x - idx;
			remaining = remaining % (4 * l);
			long remainingFull = remaining / l;
			long remainingModulo = remaining % l;
			for (long i = idx; i < idx + remainingModulo; i++) {
				current = mult(current, numAt(i));
			}
			for(int i=0;i<remainingFull;i++){
				current = mult(current, fullLenResult);
			}
			return current == pk;
		} else {
			throw new IllegalArgumentException();
		}
		
		return false;
	}

	private byte numAt(long idx) {
		return charToNum(word.charAt((int) (idx % l)));
	}

	private byte charToNum(char c) {
		if (c == 'i') {
			return pi;
		} else if (c == 'j') {
			return pj;
		} else if (c == 'k') {
			return pk;
		} else {
			throw new IllegalArgumentException();
		}
	}

	private byte mult(int a, int b) {
		byte sa = (byte) (a & (1 << 2));
		byte sb = (byte) (b & (1 << 2));
		byte aa = (byte) (a & (0x3));
		byte ab = (byte) (b & (0x3));

		byte ar = tab[(int) aa][(int) ab];
		if (sa > 0 && sb > 0 || sa == 0 && sb == 0) {
			return ar;
		} else {
			return (byte) (ar ^ ((byte) (1 << 2)));
		}
	}
}
