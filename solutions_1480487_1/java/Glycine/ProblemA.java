package glycine.gcj2012.rb;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class ProblemA {

	private static List<Double> solve(List<Integer> scoreList, int playerNum) {
		int sum = 0;
		int max = Collections.max(scoreList);
		for (int i = 0; i < scoreList.size(); ++i) {
			sum += scoreList.get(i);
		}
		List<Integer> diffList = new ArrayList<Integer>(scoreList.size());
		for (Integer score : scoreList) {
			diffList.add(max - score);
		}
		for( Integer diff: diffList){
			//System.out.print( diff + " ");
		}
		//System.out.println("");
		double ave = sum;
		for (Integer diff : diffList) {
			ave -= diff;
		}
		ave /= (double) (diffList.size());
		//System.out.println("ave = " + ave);

		List<Double> result = new ArrayList<Double>(scoreList.size());
		double doubleSum = (double) sum;

		for (Integer diff : diffList) {
			result.add((100.0 * (double) (diff + ave) / doubleSum));
		}

		double mSum = 0.0;
		double mCount = 0;
		for( Double r: result){
			if( r < 0.0){
				mSum += r;
				mCount++;
			}
		}
		double pCount = playerNum - mCount;
		List<Double> trueResult = new ArrayList<Double>(result.size());
		for( Double r: result){
			if( r < 0.0)
				trueResult.add(0.0);
			else{
				trueResult.add(r + (mSum / (double)pCount));
			}
		}

		return trueResult;
	}

	public static void main(String[] args) throws IOException {
		if (args.length != 1) {
			System.err.println("Usage: <program> inputFilename");
			return;
		}
		BufferedReader reader = new BufferedReader(new FileReader(args[0]));
		String line = reader.readLine();
		int times = Integer.parseInt(line);
		for (int i = 0; i < times; ++i) {
			line = reader.readLine();
			String[] tokens = line.split(" ");
			int playerNum = Integer.parseInt(tokens[0]);
			List<Integer> scoreList = new ArrayList<Integer>(playerNum);
			for (int j = 0; j < playerNum; ++j) {
				scoreList.add(new Integer(tokens[j + 1]));
			}
			List<Double> result = solve(scoreList, playerNum);
			System.out.print("Case #" + (i + 1) + ": ");
			for (int j = 0; j < result.size() - 1; ++j) {
				System.out.print(String.format("%1$3f ", result.get(j)));
			}
			System.out.println(String.format("%1$3f",
					result.get(result.size() - 1)));
		}

	}

}
