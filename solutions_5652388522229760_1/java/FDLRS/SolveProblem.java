package be.filip.gcj2016;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.nio.charset.Charset;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.LinkedList;
import java.util.List;

public class SolveProblem {

	public static void main(String[] args) throws NumberFormatException, IOException
	{
		int maxTries = 100000;
		solve("/Users/filip/Desktop/GCM_2016/Sheep/A-large.in", "/Users/filip/Desktop/GCM_2016/Sheep/A-large.out");
	}
	
	public static void solve(String inputFileName, String outputFileName) throws NumberFormatException, IOException
	{
		int maxTries = 100000;
		File inputFile = new File(inputFileName);
		List<String> outputLines = new LinkedList<>();
		
		try (BufferedReader br = new BufferedReader(new FileReader(inputFile))) {

			int numberOfTests = Integer.parseInt(br.readLine());
			for (int i = 0; i < numberOfTests; i++) {
				
				long testNumber = Long.parseLong(br.readLine());
				CountingResult solution = SleepCounter.startFrom(testNumber, maxTries);

				String line;
				if(solution.isSuccesfull())
				{
					line = "Case #" + (i + 1) + ": " + solution.getLargestNumber();
				}
				else
				{
					line = "Case #" + (i + 1) + ": INSOMNIA"; 
				}
				
				outputLines.add(line);
			}
		}
		
		Path outputPath = Paths.get(outputFileName);
		Files.write(outputPath, outputLines, Charset.forName("UTF-8"));

	}
	
}
