package de.pompedl.codejam2013_1C_B;

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
		long x, y, x2, y2;
		long n;
		boolean success;
		String result = "";
		// for every case
		for(int actCase=0; actCase<numberCases; ++actCase){
//			System.out.println("case "+(actCase+1));
			fileWriter.write("Case #"+(actCase+1)+": ");
			// reset
			success = false;
			// read input
			if((line = bufferedReader.readLine()) == null){
				System.err.println("bad format");
				return;
			}
			input = line.split(" ");
			x = Integer.parseInt(input[0]);
			y = Integer.parseInt(input[1]);
			n = (long) Math.ceil(-0.5 + Math.sqrt(2.0 * (Math.abs(x) + Math.abs(y)) + 0.25));
			// compute
			while(!success){
				x2 = x;
				y2 = y;
				result = "";
				for(long i=n; i>0; --i){
					if(Math.abs(x2) > Math.abs(y2)){
						if(x2>0){
							x2 -= i;
							result = "E"+result;
						}
						else{
							x2 += i;
							result = "W"+result;
						}
					}
					else{
						if(y2>0){
							y2 -= i;
							result = "N"+result;
						}
						else{
							y2 += i;
							result = "S"+result;
						}
					}
				}
				if(x2 == 0 && y2 == 0){
					success = true;
				}
				else{
					n++;
				}
			}

			// write output
			fileWriter.append(result +"\n");
		}
		// close streams
		bufferedReader.close();
		fileReader.close();
		fileWriter.flush();
		fileWriter.close();
	}

}
