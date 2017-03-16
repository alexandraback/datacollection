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
		File file = new File("round1/C-large.in");
		reader = new BufferedReader(new FileReader(file));
		
		File outputFile = new File("round1/outputC-large.txt");
		writer = new FileWriter(outputFile);
		
		int numberOfExercises = Integer.parseInt(reader.readLine());
		for (int exercise = 1; exercise <= numberOfExercises; exercise++) {
			String[] split = reader.readLine().split(" ");
			long C = Long.parseLong(split[0]);
			long D = Long.parseLong(split[1]);
			long V = Long.parseLong(split[2]);
			String[] denominationsArray = reader.readLine().split(" ");
			List<Long> denominationsList = new ArrayList<>();
			for (int d = 0; d < D; d++) {
				denominationsList.add(Long.parseLong(denominationsArray[d]));
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
	
	private static long doExercise(long c, long v, List<Long> denominationsList) {
		long answer = 0;
		long coin = 1;
		long totalValue = 0;
		int d = 0;
		while (coin <= v) {
			if (denominationsList.size() <= d || denominationsList.get(d) > coin) {
				//add coin of value coin
				answer++;
				totalValue += coin * c;
				coin = totalValue + 1;
			}
			else {
				//add coin from existing denominations;
				totalValue += denominationsList.get(d) * c;
				d++;
				coin = totalValue + 1;
			}
		}
		return answer;
	}

}
