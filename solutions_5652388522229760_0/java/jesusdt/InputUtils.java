package es.gmail.jdominguezdetena;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;

public class InputUtils {
	
	public static double[] inputs;

	public static void readInput(){
		// Construct BufferedReader from FileReader
		String fileName = "C://GoogleCodeJam/input.in";
		BufferedReader br;
		try {
			br = new BufferedReader(new FileReader(fileName));
	 
		String line = null;
		int nLine = 0;
		int nCases = 0;
		
		while ((line = br.readLine()) != null) {
			if(nLine > 0){
				if(nLine <= nCases){
				inputs[nLine - 1] = Double.valueOf(line);
				}else{
					break;
				}
			}else{
				nCases = Integer.valueOf(line);
				inputs = new double[nCases];
			}
			nLine++;
		}
	 
		br.close();
		
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}

	}
}
