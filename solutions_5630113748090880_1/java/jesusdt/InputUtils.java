package es.gmail.jdominguezdetena;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;

public class InputUtils {
	
	public static String[][] inputs;

	public static void readInput(){
		// Construct BufferedReader from FileReader
		String fileName = "C://GoogleCodeJam/input.in";
		BufferedReader br;
		try {
			br = new BufferedReader(new FileReader(fileName));
	 
		String line = null;
		int nLine = 0;
		int nCases = 0;
		
		int currentCase = 0;
		int currentN = 0;
		int N = 0;
		boolean readN = false;
		
		while ((line = br.readLine()) != null) {
			if(nLine > 0){
				if(currentCase < nCases){
				//System.out.println(line);
				if(!readN){
					N = Integer.valueOf(line);
					inputs[currentCase] = new String[2*N-1];
					readN = true;
				}else{
					inputs[currentCase][currentN] = line;
					currentN++;
					if(currentN >= 2*N-1){
						currentN = 0;
						readN = false;
						N = 0;
						currentCase++;
					}
				}
				}else{
					break;
				}
			}else{
				nCases = Integer.valueOf(line);
				inputs = new String[nCases][];
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
