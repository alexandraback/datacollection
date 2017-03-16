package com.google.code.qualification_round_2015;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashMap;
import java.util.Map;
import java.util.TreeMap;

public class ProblemCBright {
	
	private static String inputFilePath = "/home/chiwang/Downloads/CodeJam/C-small-attempt4.in";
	private static String outputFilePath = "/home/chiwang/Downloads/CodeJam/Solution/";
	private static BufferedReader br;
	private static BufferedWriter bw;
		
	public static Quaternion multiply(Quaternion i, Quaternion j) {
		boolean sign = i.sign ^ j.sign;
		char value = '1';
		
		switch (i.value) {
		case '1':
			value = j.value;
			break;
		case 'i':
			if (j.value == '1') { value = 'i'; }
			else if (j.value == 'i') { sign = !sign; value = '1'; }
			else if (j.value == 'j') { value = 'k'; }
			else if (j.value == 'k') { sign = !sign; value = 'j'; }
			break;
		case 'j':
			if (j.value == '1') { value = 'j'; }
			else if (j.value == 'i') { sign = !sign; value = 'k'; }
			else if (j.value == 'j') { sign = !sign; value = '1'; }
			else if (j.value == 'k') { value = 'i'; }
			break;
		case 'k':
			if (j.value == '1') { value = 'k'; }
			else if (j.value == 'i') { value = 'j'; }
			else if (j.value == 'j') { sign = !sign; value = 'i'; }
			else if (j.value == 'k') { sign = !sign; value = '1'; }
			break;
		}
		
		return new Quaternion(sign, value);
	}
	
	private static int L;
	private static long X;
	private static String block;
	private static Quaternion blockQuaternion;
	private static Quaternion[] blockQuaternionPrefix;
	private static Quaternion[] blockQuaternionSuffix;
	
	private static void compute() throws IOException {
	/*
	 * Fill in the implementation details
	 */
		final int T = Integer.parseInt(br.readLine());
		
		for (int caseNum = 1; caseNum <= T; caseNum++) {
			String[] parts = br.readLine().split(" ");
			L = Integer.parseInt(parts[0]);
			X = Long.parseLong(parts[1]);

			block = br.readLine();
	
			Quaternion blockQuaternion = Quaternion.get('1');
			for (int i = 0; i < L; i++) {
				blockQuaternion = multiply(blockQuaternion, Quaternion.get(block.charAt(i)));
			}

			int xX = (int) (X % 4);
			boolean isPossible = false;
			
			Quaternion tmp = Quaternion.get('1');			
			for (int i = 0; i < xX; i++) {
				tmp = multiply(tmp, blockQuaternion);
			}
			
			Quaternion negOne = new Quaternion(true, '1');
			if (tmp.equals(negOne)) {
				// Further check
				isPossible = isPossible();
			}
			
			String pos = (isPossible ? "YES" : "NO");

			String result = String.format("Case #%d: %s%n", caseNum, pos);
			System.out.println(result);
			bw.write(result);
		}				
	}
	
	private static boolean isPossible() {
		
		Quaternion left = Quaternion.get('1');
		Quaternion right = Quaternion.get('1');
		
		for (int i = 0; i < Math.min(4 * L, L * X); i++) {
			left = multiply(left, Quaternion.get((block.charAt(i % L))));
			if (isValidFirst(left)) {
				for (long j = L * X - 1; j >= Math.max(L * X - 4 * L, i); j--) {
					right = multiply(Quaternion.get(block.charAt((int)(j % L))), right);
					if (isValidLast(right)) {
						return true;
					}
				}
				return false;
			}
		}
		return false;
	}
	
	private static boolean isValidFirst(Quaternion first) {
		return first.equals(Quaternion.get('i'));
	}
	
	private static boolean isValidMid(Quaternion mid) {
		return mid.equals(Quaternion.get('j'));
	}
	
	private static boolean isValidLast(Quaternion last) {
		return last.equals(Quaternion.get('k'));
	}
	
	
	public static void main(String[] args) {
		
		long startTime = System.currentTimeMillis();
		
		// Initialisation
		try {
			outputFilePath += inputFilePath.substring(inputFilePath.lastIndexOf("/") + 1, inputFilePath.length() - 3) + ".out";
			
			br = new BufferedReader(new FileReader(inputFilePath));
			bw = new BufferedWriter(new FileWriter(outputFilePath));
			
			compute();		
			
		} catch (IOException ioe) {
			ioe.printStackTrace();
		} finally {
			try {
				if (br != null)
					br.close();
				if (bw != null)
					bw.close();
			} catch (IOException ioe) {
				ioe.printStackTrace();
			}
		}
		
		System.out.println("========================================");
		System.out.println("Done! :)");
		
		long endTime = System.currentTimeMillis();;
		System.out.printf("Finished in %d seconds.%n", (endTime - startTime) / 1000);
	}

}

