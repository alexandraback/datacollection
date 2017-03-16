import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;


public class RecycledNumbers {
	 String inputFilePath = "C:\\Temp\\Google\\C-large.in";
	 String outputFilePath = "C:\\Temp\\Google\\output.txt";
	
	
	public static void main(String[] args)  throws NumberFormatException, IOException{

		new RecycledNumbers().go();
		
	}
	
	public void go() throws NumberFormatException, IOException{
		
		
		FileReader input = new FileReader(inputFilePath);
		BufferedReader reader = new BufferedReader(input);
		
	   int numTests = Integer.parseInt(reader.readLine());
		
		ArrayList<Integer> results = new ArrayList<Integer>();
		
		
		for (int i = 0; i < numTests; i++){
			String[] details = reader.readLine().split(" ");
			int low = Integer.parseInt(details[0]);
			int high = Integer.parseInt(details[1]);
			
			results.add(solve(low, high));
		}
		
		 PrintWriter out = new PrintWriter(new FileOutputStream(outputFilePath));
		for (int i = 0; i<results.size(); i++){
			String line = "Case #" +(i+1) + ": " + results.get(i) + "\r\n";
			out.write(line);
		}
		out.flush();
			
		System.out.println("Done");
	}

	private Integer solve(int low, int high) {
		int numberPossible = 0;
		for (int i = low; i<high; i++){
			//can i take a certain num of digits from the end of i to the beginning to make a number less than high
			String num = String.valueOf(i);
			ArrayList<Integer> used = new ArrayList<Integer>();
			for (int j = 1; j<num.length(); j++){
				//remove the last j digits and move to beginning
				int secondHalfStartIndex = num.length() - j;
				String newNum = num.substring(secondHalfStartIndex) + num.substring(0, secondHalfStartIndex);
				
				int test = Integer.parseInt(newNum);
				if (test <= high && test > i && (!used.contains(test))){
					numberPossible++;
					used.add(test);
				}
			}
		}
		
		return numberPossible;
	}
}
