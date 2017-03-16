package com.google.jam2013.Round1B;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;

public class Osmos {

	/**
	 * @param args
	 * @throws IOException 
	 * @throws NumberFormatException 
	 */
	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new FileReader(args[0]));
		PrintWriter pw = new PrintWriter(new File(args[1]));
		int T = Integer.valueOf(br.readLine());
		for (int i = 0; i < T; i++) {
			String[] an = br.readLine().split(" ");
			Long a = Long.valueOf(an[0]);
			int n = Integer.valueOf(an[1]);
			
			String[] s_values = br.readLine().split(" ");
			long[] values = new long[n];
			for (int j = 0; j < n; j++) {
				values[j] = Long.valueOf(s_values[j]);
			}
			Arrays.sort(values);
			if (a == 1) {
				pw.println("Case #" + (i+1) + ": " + n);
				continue;
			}
			int min = n;
			int curr = 0;
			for (int j = 0; j < n; j++) {
				if (a > values[j]) {
					a += values[j];
				} else {
					long addtionals = 0;
					int delta = 0;
					while (a + addtionals <= values[j]) {
						addtionals += (a + addtionals - 1);
						delta++;
					}
					int oper_simple = curr + (n-j);
					if (oper_simple < min) {
						min = oper_simple;
					}
					
					a += (addtionals + values[j]);
					curr += delta;
					
					if (delta >= (n-j)) {
						break;
					}
				}
			}
			if (curr < min) {
				min = curr;
			}
			
			pw.println("Case #" + (i+1) + ": " + min);
		}
		pw.close();
		br.close();
	}

}
