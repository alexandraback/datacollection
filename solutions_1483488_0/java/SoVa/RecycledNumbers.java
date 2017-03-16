package org.ivansopin.jam;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashSet;
import java.util.StringTokenizer;

public class RecycledNumbers {
	final static String fileName = "RecycledNumbers1";

	final static String inExtension = ".in";
	final static String outExtension = ".out";
	final static String source = fileName + inExtension;
	final static String destination = fileName + outExtension;

	static BufferedReader bufferedReader;
	static BufferedWriter bufferedWriter;
	static int counter;

	/* this is problem-specific */
	static int numOfCases;
	static int a, tmpA;
	static int b, tmpB;

	public static void main(String[] args) throws NumberFormatException, IOException, InterruptedException {
		bufferedReader = new BufferedReader(new FileReader(new File(source)));
		bufferedWriter = new BufferedWriter(new FileWriter(new File(destination)));

		numOfCases = Integer.parseInt(bufferedReader.readLine());

		Reader reader = new Reader();
		reader.start();
		reader.join();

		for (int i = 0; i < numOfCases; i++) {
			copyData();

			reader = new Reader();
			reader.start();

			/********* this is where the real logic starts **********/

			// at some point, the results should be printed:
			bufferedWriter.write("Case #" + (i + 1) + ": " + getNumOfRecNums(a, b) + "\n");
			

			/********** this is where the real logic ends ***********/

			if (reader.isAlive()) {
				reader.join();
			}
		}

		bufferedWriter.close();
		bufferedReader.close();
	}

	static int getNumOfRecNums(int a, int b) {
		boolean[] seen = new boolean[2000001];
		HashSet<Integer> set;
		int curNum;
		int size;
		int total = 0;
		
		for (int num = a; num <= b; num++) {
			if (!seen[num]) {
				set = new HashSet<Integer>();
				String numStr = num + "";
				int length = numStr.length() - 1;
			
				seen[num] = true;
				if (num >= a && num <= b)
					set.add(num);
				
				for (int i = 0; i < length; i++) {
					numStr = numStr.charAt(length) + numStr.substring(0, length);
					curNum = Integer.parseInt(numStr);
					seen[curNum] = true;
					if (curNum >= a && curNum <= b)
						set.add(curNum);
				}
				
				if ((size = set.size()) > 1) {
					total += (size * (size - 1) / 2);
				}
			}
		}
		
		return total;
	}
	
	static void copyData() {
		/* this is problem-specific */
		a = tmpA;
		b = tmpB;
	}

	static class Reader extends Thread {
		public Reader() {
		}

		@Override
		public void run() {
			String line;
			StringTokenizer tokenizer;

			try {
				if (counter < numOfCases) {
					/* this is problem-specific */
					line = bufferedReader.readLine();
					tokenizer = new StringTokenizer(line);
					
					tmpA = Integer.parseInt(tokenizer.nextToken());
					tmpB = Integer.parseInt(tokenizer.nextToken());

					counter++;
				}
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
	}
}
