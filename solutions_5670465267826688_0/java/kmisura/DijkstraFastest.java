package com.dijkstra;

public class DijkstraFastest {
	private final static byte p1 = 0;
	private final static byte pi = 1;
	private final static byte pj = 2;
	private final static byte pk = 3;
	private final static byte m1 = 4;
	private final static byte mi = 5;
	private final static byte mj = 6;
	private final static byte mk = 7;

	private final static byte EMPTY = 8;

	private int l;
	private long x;
	private String word;
	private byte[][] tab;
	private byte[][] cache;
	private byte fullLenResult;

	public DijkstraFastest(int l, long x, String word) {
		this.l = l;
		this.x = x;
		this.word = word;

		tab = new byte[][] { { p1, pi, pj, pk }, { pi, m1, pk, mj }, { pj, mk, m1, pi }, { pk, pj, mi, m1 } };
		cache = new byte[3][4 * l];
		initCache();
	}

	private void initCache() {
		for (int k = 0; k < 3; k++) {
			for (int i = 0; i < 4 * l; i++) {
				cache[k][i] = EMPTY;
			}
		}

		byte r = p1;
		for (int i = 0; i < l; i++) {
			r = mult(r, charToNum(word.charAt(i)));
		}
		fullLenResult = r;
	}

	private byte getFromCache(byte goal, long idx) {
		return cache[(goal-1)&0x3][getCacheIndex(goal, idx)];
	}

	private void saveToCache(byte goal, long idx, boolean value) {
		cache[(goal-1)&0x3][getCacheIndex(goal, idx)] = (byte) (value ? 1 : 0);
	}
	
	private int getCacheIndex(byte goal, long idx){
		return (int) (idx % (4 * l));
	}

	public boolean isValid() {
		return isValid(pi, 0);
	}

	public boolean isValid(byte goal, long idx) {
		byte cached = getFromCache(goal, idx);
		if (cached != EMPTY) {
			return cached == 1;
		}

		boolean result = false;

		if (goal == pi) {
			byte current = p1;
			for (long i = idx; i < Math.min(l * x, 4 * l); i++) {
				current = mult(current, numAt(i));
				if (current == pi && isValid(pj, i + 1)) {
					result = true;
					break;
				}
			}
		} else if (goal == pj) {
			byte current = p1;
			for (long i = idx; i < Math.min(l * x, idx + 4 * l); i++) {
				current = mult(current, numAt(i));
				if (current == pj && isValid(pk, i + 1)) {
					result = true;
					break;
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
			if (current == pk) {
				result = true;
			}
		} else {
			throw new IllegalArgumentException();
		}

		saveToCache(goal, idx, result);
		return result;
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
