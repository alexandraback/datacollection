package round1;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Writer;
import java.util.ArrayList;
import java.util.List;

public class LessMoney {
	private static Writer writer;
	private static BufferedReader reader;

	public static void main(String[] args) throws IOException {
		File file = new File("round1/C-small-attempt0.in");
		reader = new BufferedReader(new FileReader(file));
		
		File outputFile = new File("round1/outputC.txt");
		writer = new FileWriter(outputFile);
		
		int numberOfExercises = Integer.parseInt(reader.readLine());
		for (int exercise = 1; exercise <= numberOfExercises; exercise++) {
			String[] split = reader.readLine().split(" ");
			int C = Integer.parseInt(split[0]);
			int D = Integer.parseInt(split[1]);
			int V = Integer.parseInt(split[2]);
			String[] denominationsArray = reader.readLine().split(" ");
			List<Integer> denominationsList = new ArrayList<>();
			for (int d = 0; d < D; d++) {
				denominationsList.add(Integer.parseInt(denominationsArray[d]));
			}
			generateOutput("Case #" + exercise + ": " + doExercise(C, V, denominationsList));
		}
		reader.close();
		writer.close();
	}
	
	private static void generateOutput(String line) throws IOException {
		System.out.println(line);
		writer.write(line + "\n");
	}
	
	private static int doExercise(int c, int v, List<Integer> denominationsList) {
		int answer = 0;
		int coin = 1;
		int totalValue = 0;
		int d = 0;
		while (coin <= v) {
			if (denominationsList.size() <= d || denominationsList.get(d) > coin) {
				//add coin of value coin
				answer++;
				totalValue += coin;
				coin = totalValue + 1;
			}
			else {
				//add coin from existing denominations;
				totalValue += denominationsList.get(d);
				d++;
				coin = totalValue + 1;
			}
		}
		return answer;
	}

}
