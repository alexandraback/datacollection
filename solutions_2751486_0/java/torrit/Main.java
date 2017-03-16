package de.pompedl.codejam2013_1C_A;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class Main {

	/**
	 * @param args
	 */
	public static void main(String[] args) throws IOException {
		// input
		if(args.length != 1){
			System.out.println("no input parameter");
			return;
		}
		String [] fileLocation = args[0].split("\\.");
		FileReader fileReader = new FileReader(args[0]);
		BufferedReader bufferedReader = new BufferedReader(fileReader);
		FileWriter fileWriter = new FileWriter(fileLocation[0]+".out");
		// read first line
		String line = bufferedReader.readLine();
		int numberCases = Integer.parseInt(line);
		// variables
		String [] input;
		int n = 0;
		String s = "";
		String template = "";
		double count = 0;
		// for every case
		for(int actCase=0; actCase<numberCases; ++actCase){
//			System.out.println("case "+(actCase+1));
			fileWriter.write("Case #"+(actCase+1)+": ");
			// reset
			s = "";
			template = "";
			count = 0;
			// read input
			if((line = bufferedReader.readLine()) == null){
				System.err.println("bad format");
				return;
			}
			input = line.split(" ");
			input[0].toLowerCase();
			n = Integer.parseInt(input[1]);
			for(int i=0; i<input[0].length(); ++i){
				if(input[0].charAt(i) == 'a'
						|| input[0].charAt(i) == 'e'
						|| input[0].charAt(i) == 'i'
						|| input[0].charAt(i) == 'o'
						|| input[0].charAt(i) == 'u'){
					s += "1";
				}
				else{
					s += "0";
				}
			}
			for(int i=0; i<n; ++i){
				template += "0";
			}
			// compute
			for(int i=0; i<s.length()-n+1; ++i){
				for(int j=i+n; j<=s.length(); ++j){
					if(s.substring(i, j).contains(template)){
						count++;
					}
				}
			}
			// write output
			fileWriter.append((int)count +"\n");
		}
		// close streams
		bufferedReader.close();
		fileReader.close();
		fileWriter.flush();
		fileWriter.close();
	}

}
