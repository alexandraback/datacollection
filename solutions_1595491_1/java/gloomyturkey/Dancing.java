package com.google.cj12;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

class Dancing {

	public static void main(String[] args) throws IOException {
		BufferedReader f = new BufferedReader(new FileReader("resources/B-large.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(
				"resources/B-large.out")));
		new Dancing().solve(f, out);
		out.close();
	}
	
	private void solve(BufferedReader f, PrintWriter out) throws IOException {
		int T = read(f);
		for (int i=0; i<T; i++) {
			int count = 0;
			String[] s = f.readLine().split(" ");
			
			int N = Integer.parseInt(s[0]);
			int S = Integer.parseInt(s[1]);
			int p = Integer.parseInt(s[2]);
			
			for (int j=0; j<N; j++) {
				int t = Integer.parseInt(s[j+3]);
				int base = t/3;
				
				int max = t%3==0? base : base+1;
				if (max >= p) {
					count++;
					continue;
				}
				
				if (S == 0 || t<2 || t%3==1) continue;
				
				max = t%3==0? base+1 : base+2;
				if (max >= p) {
					count++;
					S--;
				}
			}
			
			out.println("Case #" + (i+1) + ": " + count);
		}
	}
	
	public int read(BufferedReader f) throws IOException {
		return Integer.parseInt(f.readLine());
	}
}
