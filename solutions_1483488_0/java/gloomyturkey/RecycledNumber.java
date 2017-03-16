package com.google.cj12;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.HashSet;

public class RecycledNumber {

	public static void main(String[] args) throws IOException {
		String name = "C-small-attempt0";
		
		BufferedReader f = new BufferedReader(new FileReader("resources/" + name + ".in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(
				"resources/" + name + ".out")));
		new RecycledNumber().solve(f, out);
		out.close();
	}

	private void solve(BufferedReader f, PrintWriter out) throws IOException {
		int T = read(f);
		HashSet<String> set = new HashSet<String>();
		
		for (int i=0; i<T; i++) {
			int count = 0;
			int[] a = read(f, 2);
			int A = a[0];
			int B = a[1];
			
			for (int n=A; n<B; n++) {
				String s = "" + n;
				for (int j=0; j<s.length()-1; j++) {
					s = s.substring(1) + s.charAt(0);
					if (s.charAt(0) == '0' || set.contains(s)) continue;
					
					set.add(s);
					int m = Integer.parseInt(s);
					if (m > n && m <= B) {
						count++;
					}
				}
				
				set.clear();
			}
			
			out.println("Case #" + (i+1) + ": " + count);
		}
	}
	
	public int read(BufferedReader f) throws IOException {
		return Integer.parseInt(f.readLine());
	}
	
	public int[] read(BufferedReader f, int N) throws IOException {
		String[] t = f.readLine().split(" ");
		int[] a = new int[N];
		for (int i=0; i<N; i++) {
			a[i] = Integer.parseInt(t[i]);
		}
		return a;
	}
}
