package round0;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class FinitePancakes {
	private static FileWriter writer;

	public static void main(String[] args) throws IOException {
		File file = new File("round0/B-large.in");
		BufferedReader reader = new BufferedReader(new FileReader(file));
	
		File outputFile = new File("round0/output-pancakes.txt");
		writer = new FileWriter(outputFile);
		int numberOfBreakfasts = Integer.parseInt(reader.readLine());
		for (int breakfast = 1; breakfast <= numberOfBreakfasts; breakfast++) {
			int numberOfPlates = Integer.parseInt(reader.readLine());
			String[] split = reader.readLine().split(" ");
			List<Integer> pancakes = new ArrayList<>();
			for (int plate = 0; plate < numberOfPlates; plate++) {
				pancakes.add(Integer.parseInt(split[plate]));
			}
			
			generateOutput("Case #" + breakfast + ": " + timeToEat(pancakes));
		}
		
		
		reader.close();
		writer.close();
	}
	
	private static void generateOutput(String line) throws IOException {
		System.out.println(line);
		writer.write(line + "\n");
	}

	private static int timeToEat(List<Integer> pancakes) {
		int currentBest = Integer.MAX_VALUE;
		for (int maxHeight = 1; maxHeight <= 1002; maxHeight++) {
			int guess = maxHeight;
			for (Integer stack : pancakes) {
				guess += (stack-1)/maxHeight;
			}
			if (guess < currentBest) {
				currentBest = guess;
			}
		}
		return currentBest;
	}
	
}
