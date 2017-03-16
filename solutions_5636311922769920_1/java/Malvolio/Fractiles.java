package round0;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Writer;

public class Fractiles {
	private static Writer writer;
	private static BufferedReader reader;

	public static void main(String[] args) throws IOException {
		File file = new File("round0/D-large.in");
		reader = new BufferedReader(new FileReader(file));
		
		File outputFile = new File("round0/fractile-output.txt");
		writer = new FileWriter(outputFile);
		
		int numberOfExercises = Integer.parseInt(reader.readLine());
		for (int exercise = 1; exercise <= numberOfExercises; exercise++) {
			generateOutput("Case #" + exercise + ": " + doExercise());
		}
		reader.close();
		writer.close();
	}
	
	private static void generateOutput(String line) throws IOException {
		System.out.println(line);
		writer.write(line + "\n");
	}
	
	private static String doExercise() throws IOException {
		String[] parameters = reader.readLine().split(" ");
		int K = Integer.parseInt(parameters[0]);
		int C = Integer.parseInt(parameters[1]);
		int S = Integer.parseInt(parameters[2]);
		if (S*C < K) {
			return "IMPOSSIBLE";
		}
		S = (int) Math.ceil((1.*K)/C);//This line is not necessary, but it is there to make sure the small attempt is representative of the large attempt.
		
		String answer = "";
		int blockSize = (int) Math.ceil((1.*K)/S);
		long prod = 1;
		int counter = 0;
		for (int k = 1; k <= K; k++) {
			prod=K*(prod-1) + k;
			counter++;
			if (counter == blockSize || k == K) {
				answer += prod + " ";
				prod = 1;
				counter = 0;
			}
		}
		return answer;
	}
}
