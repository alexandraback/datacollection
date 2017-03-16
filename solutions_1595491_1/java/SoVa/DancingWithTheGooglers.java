package org.ivansopin.jam;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.StringTokenizer;

public class DancingWithTheGooglers {
	final static String fileName = "DancingWithTheGooglers2";

	final static String inExtension = ".in";
	final static String outExtension = ".out";
	final static String source = fileName + inExtension;
	final static String destination = fileName + outExtension;

	static BufferedReader bufferedReader;
	static BufferedWriter bufferedWriter;
	static int counter;

	/* this is problem-specific */
	static int numOfCases;
	static int numOfPeople, tmpNumOfPeople;
	static int numOfSurp, tmpNumOfSurp;
	static int max, tmpMax;
	static int[] points, tmpPoints;

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
			
			Comparator<Score> comparator = new ScoreComparator();
			ArrayList<Score> scores = new ArrayList<Score>();
			int curNumOfSurp = 0;
			int curNumOfGood = 0;
			
			for (int j = 0; j < numOfPeople; j++) {
				 Score score = new Score(points[j], max);
				 scores.add(score);
				 //score.display();
				 if (score.surprising)
					 curNumOfSurp++;
				 if (score.elMax >= max)
					 curNumOfGood++;
			}
			
			System.out.println(curNumOfSurp + " surprises initially; " + numOfSurp + " expected");
			
			if (curNumOfSurp < numOfSurp) {
				Collections.sort(scores, comparator);
				
				int j = 0;
				
				while (curNumOfSurp < numOfSurp) {
					Score score = scores.get(j++);
					
					if (!score.surprising) {
						score.switchSurp();
						curNumOfSurp++;
					}
				}
				
			} else if (curNumOfSurp > numOfSurp) {
				Collections.sort(scores, comparator);
				
				int j = scores.size() - 1;
				
				while (curNumOfSurp > numOfSurp) {
					Score score = scores.get(j--);
					
					if (score.surprising) {
						boolean wasGoodScore = score.elMax >= max;
						if (score.switchSurp())
							curNumOfSurp--;
						boolean isGoodScore = score.elMax >= max;
						if (wasGoodScore && !isGoodScore)
							curNumOfGood--;
					}
				}
			}

			//for (int j = 0; j < numOfPeople; j++) {
			//	 scores.get(j).display();
			//}
			
			// at some point, the results should be printed:
			bufferedWriter.write("Case #" + (i + 1) + ": " + curNumOfGood + "\n");
			

			/********** this is where the real logic ends ***********/

			if (reader.isAlive()) {
				reader.join();
			}
		}

		bufferedWriter.close();
		bufferedReader.close();
	}

	static class ScoreComparator implements Comparator<Score>
	{
	    @Override
	    public int compare(Score x, Score y)
	    {
	        // Assume neither string is null. Real code should
	        // probably be more robust
	        if (x.total < y.total)
	        {
	            return -1;
	        }
	        if (x.total > y.total)
	        {
	            return 1;
	        }
	        return 0;
	    }
	}
	
	static class Score {
		int type;
		boolean surprising = false;
		int elMax;
		int total;
		
		Score (int total, int maxWanted) {
			this.total = total;
			int rem = total % 3;
			int maxElement;
			
			if (rem == 0) {
				if (total == 0) {
					maxElement = 0;
					type = 1;
				} else {
					maxElement = total / 3;
					
					if ((maxElement >= maxWanted) || (maxElement + 1 < maxWanted)) {
						elMax = maxElement;
						type = 1;
					} else {
						elMax = maxElement + 1;
						surprising = true;
						type = 5;
					}
				}
			} else if (rem == 1) {
				maxElement = total / 3 + 1;
				
				elMax = maxElement;
				type = 2;
			} else {
				maxElement = total / 3 + 1;
				
				if ((maxElement >= maxWanted) || (maxElement + 1 < maxWanted)) {
					elMax = maxElement;
					type = 3;
				} else {
					elMax = maxElement + 1;
					surprising = true;
					type = 4;
				}
			}
		}
	
		boolean switchSurp() {
			if (surprising) {
				if (type == 5) {
					type = 1;
					elMax -= 2;
				} else if (type == 6) {
					type = 2;
				} else {
					type = 3;
					elMax -= 1;
				}
				
				return true;
			} else {
				if (type == 1) {
					if (total != 0) {
						type = 5;
						elMax += 2;
						return true;
					}
					return false;
				} else if (type == 2) {
					type = 6;
					return true;
				} else {
					type = 4;
					elMax += 1;
					return true;
				}
			}
		}
	
		void display() {
			String triple = "\t[";
			
			if (type == 1) {
				triple += elMax + "," + elMax + "," + elMax; 
			} else if (type == 2) {
				triple += (elMax - 1) + "," + (elMax - 1) + "," + (elMax);
			} else if (type == 3) {
				triple += (elMax - 1) + "," + (elMax) + "," + (elMax);
			} else if (type == 4) {
				triple += (elMax - 2) + "," + (elMax - 2) + "," + (elMax);
			} else if (type == 5) {
				triple += (elMax - 2) + "," + (elMax - 1) + "," + (elMax);
			} else {
				triple += (elMax - 2) + "," + (elMax) + "," + (elMax);
			}
			
			System.out.println(triple + "] = " + total + " (" + surprising + ") (type " + type + ")");
		}
	}
	
	static void copyData() {
		/* this is problem-specific */
		numOfPeople = tmpNumOfPeople;
		numOfSurp = tmpNumOfSurp;
		max = tmpMax;
		points = tmpPoints;
	}

	static class Reader extends Thread {
		public Reader() {
		}

		@Override
		public void run() {
			int item;
			String line;
			StringTokenizer tokenizer;

			try {
				if (counter < numOfCases) {
					/* this is problem-specific */
					line = bufferedReader.readLine();
					tokenizer = new StringTokenizer(line);
					
					tmpNumOfPeople = Integer.parseInt(tokenizer.nextToken());
					tmpNumOfSurp = Integer.parseInt(tokenizer.nextToken());
					tmpMax = Integer.parseInt(tokenizer.nextToken());
					tmpPoints = new int[tmpNumOfPeople];

					for (int i = 0; i < tmpNumOfPeople; i++) {
						item = Integer.parseInt(tokenizer.nextToken());

						tmpPoints[i] = item;
					}

					counter++;
				}
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
	}
}
