/**
 * Source code for Google Code Jam 2016 - Online Round 1: Sub-Round B - Problem B
 * Author: Zac ZHANG (zac771989@gmail.com)
 * Date: 04/30/2016
 */

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class B {
	
	public static final String FILE_NAME = "B-small-attempt2";
	
	private BufferedReader in;
	
	public static void main(String[] args) throws IOException {
		B main = new B();
		main.start();
	}
	
	private void start() throws IOException {
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(FILE_NAME + ".out")));
		in = new BufferedReader(new FileReader(FILE_NAME + ".in"));
		
		int numCases = Integer.parseInt(in.readLine());
		for (int iCase = 1; iCase <= numCases; iCase++)
			out.println("Case #" + iCase + ": " + solve());
		
		in.close();
		out.close();
	}
	
	private String solve() throws IOException {
		String[] line = in.readLine().split(" ");
		String CString = line[0];
		String JString = line[1];
		char[] C = CString.toCharArray();
		char[] J = JString.toCharArray();
		
		for (int i = 0; i < C.length; i++) {
			if (C[i] != '?' && J[i] != '?')
				continue;
			if (C[i] != '?') {
				J[i] = C[i];
				continue;
			}
			if (J[i] != '?') {
				C[i] = J[i];
				continue;
			}
		}
		
		for (int i = 0; i < C.length; i++) {
			if (C[i] != '?')
				continue;
			
			// both C[i] and J[i] are '?'
			BigInteger prefixC, prefixJ;
			if (i == 0) {
				prefixC = BigInteger.valueOf(0L);
				prefixJ = BigInteger.valueOf(0L);
			} else {
				prefixC = new BigInteger(new String(C, 0, i));
				prefixJ = new BigInteger(new String(J, 0, i));
			}
			if (prefixC.compareTo(prefixJ) < 0) {
				C[i] = '9';
				J[i] = '0';
			} else if (prefixC.compareTo(prefixJ) > 0) {
				C[i] = '0';
				J[i] = '9';
			} else {
				int j = i + 1;
				while (j < C.length && C[j] != '?' && C[j] == J[j])
					j++;
				if (j == C.length || C[j] == '?') {
					C[i] = '0';
					J[i] = '0';
				} else {
					int minDiff = Math.abs(Integer.parseInt("0" + C[j]) - Integer.parseInt("0" + J[j]));
					char minC = '0';
					char minJ = '0';
					int diff = Math.abs(Integer.parseInt("1" + C[j]) - Integer.parseInt("0" + J[j]));
					if (diff < minDiff) {
						minC = '1';
						minJ = '0';
					}
					diff = Math.abs(Integer.parseInt("0" + C[j]) - Integer.parseInt("1" + J[j]));
					if (diff < minDiff) {
						minC = '0';
						minJ = '1';
					}
					C[i] = minC;
					J[i] = minJ;
				}
			}
		}
			
			/*
			if (C[i] != '?' && J[i] != '?')
				continue;
			if (C[i] == '?' && J[i] != '?') {
				C[i] = J[i];
				continue;
			}
			if (C[i] != '?' && J[i] == '?') {
				J[i] = C[i];
				continue;
			}
			
			// both C[i] and J[i] are '?'
			BigInteger prefixC, prefixJ;
			if (i == 0) {
				prefixC = BigInteger.valueOf(0L);
				prefixJ = BigInteger.valueOf(0L);
			} else {
				prefixC = new BigInteger(new String(C, 0, i));
				prefixJ = new BigInteger(new String(J, 0, i));
			}
			if (prefixC.compareTo(prefixJ) < 0) {
				C[i] = '9';
				J[i] = '0';
			} else if (prefixC.compareTo(prefixJ) > 0) {
				C[i] = '0';
				J[i] = '9';
			} else {
				int j = i + 1;
				while (j < C.length && (C[j] == '?' || J[j] == '?') && !(C[j] == '?' && J[j] == '?'))
					j++;
				if (j == C.length || (C[j] == '?' && J[j] == '?') || Math.abs(C[j] - J[j]) == 5) {
					C[i] = '0';
					J[i] = '0';
				} else {
					if (C[j] > J[j]) {
						C[i] = '0';
						J[i] = '1';
					} else {
						C[i] = '1';
						J[i] = '0';
					}
				}
			}
		}*/
		
		return new String(C) + " " + new String(J);
	}
	
}
