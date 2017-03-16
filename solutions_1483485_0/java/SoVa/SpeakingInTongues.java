package org.ivansopin.jam;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashMap;

public class SpeakingInTongues {
	final static String fileName = "SpeakingInTongues3";

	final static String inExtension = ".in";
	final static String outExtension = ".out";
	final static String source = fileName + inExtension;
	final static String destination = fileName + outExtension;

	static BufferedReader bufferedReader;
	static BufferedWriter bufferedWriter;
	
	static int counter;
	static String line, tmpLine;

	/* this is problem-specific */
	static int numOfCases;
	static HashMap<Character, Character> mapping = new HashMap<Character, Character>();

	public static void main(String[] args) throws NumberFormatException, IOException, InterruptedException {
		BufferedReader br1 = new BufferedReader(new FileReader(new File("SpeakingInTonguesSample.in")));
		BufferedReader br2 = new BufferedReader(new FileReader(new File("SpeakingInTonguesSample.out")));
		
		String line1, line2;
		
		while ((line1 = br1.readLine()) != null) {
			line2 = br2.readLine();
			
			int l = line1.length();
			
			for (int i = 0; i < l; i++) {
				mapping.put(line1.charAt(i), line2.charAt(i));
				System.out.println(mapping.size());
			}
			mapping.put('q', 'z');
			mapping.put('z', 'q');
		}
		
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

			StringBuilder builder = new StringBuilder();
			
			int l = line.length();
			
			for (int j = 0; j < l; j++) {
				builder.append(mapping.get(line.charAt(j)));
			}
			
			// at some point, the results should be printed:
			bufferedWriter.write("Case #" + (i + 1) + ": " + builder.toString() + "\n");
			

			/********** this is where the real logic ends ***********/

			if (reader.isAlive()) {
				reader.join();
			}
		}

		bufferedWriter.close();
		bufferedReader.close();
	}

	static void copyData() {
		/* this is problem-specific */
		line = tmpLine;
	}

	static class Reader extends Thread {
		public Reader() {
		}

		@Override
		public void run() {
			try {
				if (counter < numOfCases) {
					/* this is problem-specific */
					tmpLine = bufferedReader.readLine();
					counter++;
				}
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
	}
}
