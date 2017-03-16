package com.google;

import java.util.Scanner;

/**
 * @author Debraj
 */
public final class Lawnmower {

	/**
	 * @param args
	 */
	public static void main(final String[] args) {
		final String Y = "YES";
		final String N = "NO";
		//		final Map<String, Node> m = new HashMap<>();
		Node n;

		final Scanner sc = new Scanner(System.in);
		final int t = sc.nextInt();
		int x;
		int y;
		int[][] a;
		boolean b;
		for (int i = 0; i < t;) {
			x = sc.nextInt();
			y = sc.nextInt();
			a = new int[x][y];
			b = false;

			for (int j = 0; j < x; j++) {
				for (int k = 0; k < y; k++) {
					a[j][k] = sc.nextInt();
				}
			}

			if (x == 1 || y == 1) {
				System.out.println("Case #" + ++i + ": " + Y);
				continue;
			}

			loop:
				for (int j = 0; j < x; j++) {
					for (int k = 0; k < y; k++) {
						n = new Node(j, k, a, x, y);
						//					m.put(j + "-" + k, new Node(j, k, a, x, y));
						if (n.isHasOne()) {
							if (!n.isOne()) {
								b = false;
								break loop;
							}
							b = true;
						} else {
							b = true;
						}
					}
				}


			if (b) {
				System.out.println("Case #" + ++i + ": " + Y);
			} else {
				System.out.println("Case #" + ++i + ": " + N);
			}
		}
	}
}

class Node {
	private final int x;
	private final int y;
	private final int arr[][];
	private final int sx;
	private final int sy;
	private boolean hasOne;
	private boolean isOne;

	Node(final int x, final int y, final int arr[][], final int sx, final int sy) {
		this.x = x;
		this.y = y;
		this.arr = arr;
		this.sx = sx;
		this.sy = sy;
		process();
	}

	private void process() {
		if (this.arr[this.x][this.y] == 1) {
			this.hasOne = true;

			if (this.y == 0 && this.sy > 1 && this.arr[this.x][this.y + 1] == 1
					|| this.y > 0 && this.arr[this.x][this.y - 1] == 1 && this.y == this.sy - 1
					|| this.y > 0 && this.arr[this.x][this.y - 1] == 1 && this.y < this.sy - 1 && this.arr[this.x][this.y + 1] == 1
					|| this.x == 0 && this.sx > 1 && this.arr[this.x + 1][this.y] == 1
					|| this.x > 0 && this.arr[this.x - 1][this.y] == 1 && this.x == this.sx - 1
					|| this.x > 0 && this.arr[this.x - 1][this.y] == 1 && this.x < this.sx - 1 && this.arr[this.x + 1][this.y] == 1) {
				this.isOne = true;
			}
			if (this.y > 0 && this.arr[this.x][this.y - 1] == 1 && this.y < this.sy - 1 && this.arr[this.x][this.y + 1] != 1
					|| this.x > 0 && this.arr[this.x - 1][this.y] == 1 && this.x < this.sx - 1 && this.arr[this.x + 1][this.y] != 1) {
				this.isOne = false;
			}
		}
	}

	/**
	 * @return the hasOne
	 */
	boolean isHasOne() {
		return this.hasOne;
	}

	/**
	 * @return the isOne
	 */
	boolean isOne() {
		return this.isOne;
	}
}