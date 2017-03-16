package battleship;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.PrintWriter;

public class App {
	public static final String INPUT_FILE_NAME = "input.txt";
	public static final String OUTPUT_FILE_NAME = "output.txt";
	
	public static void main(String[] args) {
		long beginTime = System.currentTimeMillis();
		
		try {
			String inputName = INPUT_FILE_NAME;
			String outputName = OUTPUT_FILE_NAME;
		
			if (args.length > 0)
				inputName = args[0];
		
			if (args.length > 1)
				outputName = args[1];
		
			try (BufferedReader reader = new BufferedReader(new FileReader(new File(inputName)))) {
				try (PrintWriter writer = new PrintWriter(outputName)) {
					int nCases = Integer.parseInt(reader.readLine());
				
					for (int nCase = 0; nCase < nCases; ++nCase) {
						String[] data = reader.readLine().split(" ");
						int r = Integer.parseInt(data[0]);
						int c = Integer.parseInt(data[1]);
						int w = Integer.parseInt(data[2]);
						
					
						int x = (c / w) * r + w - 1; 
						if (c % w > 0) 
							++x;

						writer.println("Case #" + (nCase + 1) + ": " + x);
					}
				}
			}
		} catch (Exception e) {
			e.printStackTrace();
		} 
		
		long endTime = System.currentTimeMillis();
		
		System.out.println(String.format("Done. Spend %d ms", endTime - beginTime));
	}
}
