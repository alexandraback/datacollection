/*
	read data

	guest1 map1
	guest2 map2

	compare 2 maps

	output
*/

import java.io.*;
import java.util.*;
import java.text.*;

public class Main {

	public static void main(String[] args) throws Exception {

		Scanner scan = new Scanner(System.in);
		int i0 = scan.nextInt();
		PrintStream out = new PrintStream("03out.txt");

		Q q = new Q();
		for (int i = 0; i < i0; i++) {
			q.r = scan.nextInt();
			q.c = scan.nextInt();
			q.m = scan.nextInt();
			q.init();
			out.println("Case #" + (i+1) + ":");
			out.println(q.ans());
		}
		out.close();

	}

	static class Q {
		int r, c, m;
		int w;
		char[][] d;

		void init() {
			w = r * c - m;
			d = new char[r][c];

			for (int i = 0; i < r; i++) {
				for (int j = 0; j < c; j++) {
					d[i][j] = '*';
				}
			}
		}

		String ans() {
			if (w == 1) {
				d[0][0] = 'c';
			} else if (w < 1) {
				return "Impossible";
			} else if (r == 1 || c == 1) {
				int count = 0;
				LOOP:
				for (int i = 0; i < r; i++) {
					for (int j = 0; j < c; j++) {
						if (count < w) {
							d[i][j]	= '.';
							count++;
						} else {
							//System.out.println(i + "," + j);
							break LOOP;
						}
					}
				}
				d[0][0] = 'c';
			} else if (r == 2 || c == 2) {
				/*
				if (r == 2) {
					int tmp = r;
					r = c;
					c = tmp;
					init();
				}
				*/
				if (w % 2 == 1 || w == 2) {
					return "Impossible";
				}
				if (r==2) {
					int count = 0;
					LOOP:
					for (int i = 0; i < c; i++) {
						for (int j = 0; j < r; j++) {
							if (count < w) {
								d[j][i]	= '.';
								count++;
							} else {
								break LOOP;
							}
						}
					}
				} else if (c==2) {
					int count = 0;
					LOOP:
					for (int i = 0; i < r; i++) {
						for (int j = 0; j < c; j++) {
							if (count < w) {
								d[i][j]	= '.';
								count++;
							} else {
								break LOOP;
							}
						}
					}
				}
				d[0][0] = 'c';
				/*
				if (r == 2) {
					char[][] dd = d;
					this.d = new char[r][c];
					for (int i = 0; i < r; i++) {
						for (int j = 0; j < c; j++) {
							d[j][i] = dd[i][j];
						}

					}
				}*/
			} else {

				if (w == 2 || w == 3 || w == 5 || w == 7) {
					return "Impossible";
				} else if (w == 4){
					d[0][0] = 'c';
					d[1][0] = '.';
					d[0][1] = '.';
					d[1][1] = '.';
				} else if (w == 6){
					d[0][0] = 'c';
					d[1][0] = '.';
					d[2][0] = '.';
					d[0][1] = '.';
					d[1][1] = '.';
					d[2][1] = '.';
				} else if (w == 8){
					d[0][0] = 'c';
					d[1][0] = '.';
					d[2][0] = '.';
					d[0][1] = '.';
					d[1][1] = '.';
					d[2][1] = '.';
					d[0][2] = '.';
					d[1][2] = '.';
				} else if (w == 9){
					d[0][0] = '.';
					d[1][0] = '.';
					d[2][0] = '.';
					d[0][1] = '.';
					d[1][1] = 'c';
					d[2][1] = '.';
					d[0][2] = '.';
					d[1][2] = '.';
					d[2][2] = '.';
				} else {
					int count = 0;
					int j;


					for (j = 0; j < c; j++) {
						if (count < w) {
							d[0][j] = '.';
							d[1][j] = '.';
							count += 2;
						} else {
							break;
						}
					}

					LOOP:
					for (int i = 2; i < r; i++) {
						for (j = 0; j < c; j++) {
							if (count < w) {
								d[i][j] = '.';
								count++;
								if (count == w && j == 0) {
									d[i-1][c-1] = '*';
									d[i][j+1] = '.';
									if (i == 2) {
										d[i-2][c-1] = '*';
										d[i][j+2] = '.';
									}
									break LOOP;
								}
							}
						}
					}
					d[0][0] = 'c';
				}

			}
			return print();
		}

		String print() {
			//System.out.println(r + "," + c + "," + m);

			StringBuilder str = new StringBuilder();

			for (int i = 0; i < r; i++) {
				for (int j = 0; j < c; j++) {
					str.append(d[i][j]);
				}
				if (i != r-1) {
					str.append("\r\n");
				}
			}

			return str.toString();
		}

	}


}
