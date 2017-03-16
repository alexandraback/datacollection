package org.ivansopin.jam;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class KingdomRush {
	final static String fileName = "B-small-attempt4";

	final static String inExtension = ".in";
	final static String outExtension = ".out";
	final static String source = fileName + inExtension;
	final static String destination = fileName + outExtension;

	static BufferedReader bufferedReader;
	static BufferedWriter bufferedWriter;

	/* this is problem-specific */
	static int numOfCases;
	static int numOfLevels;
	static ArrayList<Case> levels;
	static PriorityQueue<Case> numOnes, numTwos;
	static int numOfOneStars, numOfTwoStars;

	public static void main(String[] args) throws NumberFormatException, IOException, InterruptedException {
		bufferedReader = new BufferedReader(new FileReader(new File(source)));
		bufferedWriter = new BufferedWriter(new FileWriter(new File(destination)));

		numOfCases = Integer.parseInt(bufferedReader.readLine());
		
		Comparator<Case> comp1 = new Comp1();
		Comparator<Case> comp2 = new Comp2();
		
		for (int c = 0; c < numOfCases; c++) {
			numOfLevels = Integer.parseInt(bufferedReader.readLine());
			numOnes = new PriorityQueue<KingdomRush.Case>(numOfLevels, comp1);
			numTwos = new PriorityQueue<KingdomRush.Case>(numOfLevels, comp2);
			levels = new ArrayList<KingdomRush.Case>(numOfLevels);
			
			for (int i = 0; i < numOfLevels; i++) {
				StringTokenizer tokenizer = new StringTokenizer(bufferedReader.readLine());
				int cost1 = Integer.parseInt(tokenizer.nextToken());
				int cost2 = Integer.parseInt(tokenizer.nextToken());
				
				Case cs = new Case(i, cost1, cost2);
				System.out.println("Case " + c + ": adding level " + i + ": " + cs.cost1 + ", " + cs.cost2);
				
				levels.add(cs);
				numOnes.add(cs);
				numTwos.add(cs);
			}
			System.out.println("Cheapest 1: " + numOnes.peek().cost1 + "; cheapest 2: " + numTwos.peek().cost2);
			int result = solve();
			bufferedWriter.write("Case #" + (c + 1) + ": " + (result < 0 ? "Too Bad" : result) + "\n");
		}

		bufferedWriter.close();
		bufferedReader.close();
	}

	static int solve() {
		Case curNum1, curNum2;
		int score = 0;
		int completes = 0;
		
		while (numTwos.size() > 0) {
			curNum1 = numOnes.peek();
			curNum2 = numTwos.peek();
			
			if (score >= curNum2.cost2) {
				System.out.println("Min score 2 is " + curNum2.level);
				
				if (curNum2.comp1)
					score++;
				else {
					score += 2;
					numOnes.remove(curNum2);
				}

				numTwos.poll();
				System.out.println("Removing " + curNum2.level);
				completes++;
			} /*else if (score > curNum2.cost2) {
				ArrayList<Case> cases = new ArrayList<KingdomRush.Case>();
				Case pulledCase;
				
				while ((pulledCase = numTwos.poll()).cost2 < score) {
					
				}
			} */else if (curNum1 != null && score >= curNum1.cost1) {
				score++;
				curNum1.comp1 = true;
				
				numOnes.poll();
				completes++;
				System.out.println("Marking " + curNum1.level + " : " + numTwos.contains(curNum1));
			} else {
				return -1;
			}
			
			System.out.println("Score: " + score + ", size: " + numTwos.size());
		}
		
		return completes;
	}
	
	static class Case {
		int level;
		int cost1, cost2;
		boolean comp1, comp2;
		
		Case(int level, int cost1, int cost2) {
			this.level = level;
			this.cost1 = cost1;
			this.cost2 = cost2;
		}
	}

	static class Comp1 implements Comparator<Case> {
	    public int compare(Case o1, Case o2) {
	    	if (o1.cost1 == o2.cost1) {
	    		return new Integer(o2.cost2).compareTo(o1.cost2);
	    	} else {
	    		return new Integer(o1.cost1).compareTo(o2.cost1);
	    	}
	    }
	}
	static class Comp2 implements Comparator<Case> {
	    public int compare(Case o1, Case o2) {
	    	if (o1.cost2 == o2.cost2) {
	    		return new Integer(o2.cost1).compareTo(o1.cost1);
	    	} else {
	    		return new Integer(o1.cost2).compareTo(o2.cost2);
	    	}
	    }
	}
}
