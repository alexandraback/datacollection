import java.io.*;
import java.util.*;

public class SafteyInNumbers {
	public static void main(String[] args) {
		try {
			FileWriter output = new FileWriter(new File("output.txt"));
			Scanner s = new Scanner(new File("input.txt"));
			int trials = s.nextInt();
			s.nextLine();
			ArrayList<Integer> contestants = new ArrayList<Integer>(200);
			for (int i = 0; i < trials; i++) {
				int numContestants = s.nextInt();
				int sum = 0;
				for (int b = 0; b < numContestants; b++) {
					int newNum = s.nextInt();
					contestants.add(newNum);
					sum += newNum;
				}
				double doubleMean = (2.0 * sum) / numContestants;
				int sumUnderDoubleMean = 0;
				int countUnderDoubleMean = 0;
				for (int b = 0; b < numContestants; b++) {
					if (contestants.get(b) < doubleMean) {
						sumUnderDoubleMean += contestants.get(b);
						countUnderDoubleMean++;
					}
				}
				double valueNeeded = Math.min(
						((double) sumUnderDoubleMean + sum)
								/ ((double) countUnderDoubleMean), doubleMean);
				output.write("Case #" + (i + 1) + ": ");
				for (int b = 0; b < numContestants; b++) {
					double value;
					if (contestants.get(b) > doubleMean)
						value = 0;
					else
						value = (valueNeeded - contestants.get(b)) / sum;
					output.write("" + (value * 100) + " ");
				}
				contestants.clear();
				output.write('\n');
			}
			s.close();
			output.close();
			System.out.println("Done");
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}
