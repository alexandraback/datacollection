package com.noxoin.codejam2014;

import java.util.Scanner;

class MinesweeperMaster {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		
		int t = Integer.parseInt(s.nextLine());
		
		for (int i = 1; i <= t; ++i){
			// solve
			String message = "";
			String[] input = s.nextLine().split(" ");

			int r = Integer.parseInt(input[0]);
			int c = Integer.parseInt(input[1]);
			int m = Integer.parseInt(input[2]);
			
			int n = r*c;
			int ns = (r-2)*(c-2);
			if ( m >= n ) {
				message = "Impossible";
			} else if (r == 1 || c == 1) {
				String[][] b = new String[r][c];
				int count = 0;
				for (int j = c; j > 0; --j){
					for(int k = r; k > 0; --k){
						String in = (count < m) ? "*" : ".";
						b[k-1][j-1] = in;
						count++;
					}
				}
				b[0][0] = "c";
				message = bs(b,r,c);
			}else if (r == 2 || c == 2) {
				if ((m%2 == 1 && m != n-1) || ( m == n-2)){
					message = "Impossible";
				} else if (m == n-1) {
					String[][] b = new String[r][c];
					for(int j = 0; j < r; ++j) {
						for (int k = 0; k < c; ++k) {
							b[j][k] = "*";
						}
					}
					b[0][0] = "c";
					message = bs(b,r,c);
				} else {
					String[][] b = new String[r][c];
					int count = 0;
					for (int j = n/2; j > 2; --j){
						String in = (count < m) ? "*" : ".";
						if(r == 2) {
							b[0][j-1] = in;
							b[1][j-1] = in;
						} else {
							b[j-1][0] = in;
							b[j-1][1] = in;
						}
						count += 2;
					}
					b[0][0] = "c";
					b[0][1] = ".";
					b[1][0] = ".";
					b[1][1] = ".";
					message = bs(b,r,c);
					
				}
			} else {
				if (( m == n-2) || m == n-3 || m == n-5 || m == n-7){
					message = "Impossible";
				} else {
					String[][] b = new String[r][c];
					int count = 0;

					for (int j = c; j > 2; --j){
						for (int k = r; k > 2; --k){
							String in = (count < m) ? "*" : ".";
							b[k-1][j-1] = in;
							count++;
						}
					}

					for (int j = c; j > 3; --j){
						String in = (count < m) ? "*" : ".";
						b[1][j-1] = in;
						count++;
						in = (count < m) ? "*" : ".";
						b[0][j-1] = in;
						if(count == m) {
							b[2][2] = in;
							b[0][j-1] = "*";
						}
						count ++;
					}
					for (int j = r; j > 3; --j){
						String in = (count < m) ? "*" : ".";
						b[j-1][1] = in;
						count++;
						in = (count < m) ? "*" : ".";
						b[j-1][0] = in;
						if(count == m) {
							b[2][2] = in;
							b[j-1][0] = "*";
						}
						count++;
					}
					
					String in = (count < m) ? "*" : ".";
					b[0][2] = in;
					b[1][2] = in;
					count += 2;
					
					in = (count < m) ? "*" : ".";
					b[2][0] = in;
					b[2][1] = in;
					count += 2;
					
					in = (count < m) ? "*" : ".";
					b[0][0] = "c";
					b[0][1] = in;
					b[1][0] = in;
					b[1][1] = in;
					
					message = bs(b,r,c);
				}
			}


			System.out.println("Case #" + i + ": \n" + message);
		}
		
		s.close();
	}

	private static String bs(String[][] b, int r, int c) {
		String s = "";
		for(int i = 0; i < r; ++i) {
			for(int j = 0; j < c; ++j){
				s += b[i][j];
			}
			if (i != r-1){
				s += "\n";
			}
		}
		return s;
	}
}