import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;


public class OminousOmino {

	public static void main(String[] args)  throws IOException{
		// TODO Auto-generated method stub
//		String inputFile = "input.txt";
		String inputFile = "D-small-attempt2.in";
		String outputFile = "output.txt";
		FileInputStream fstream = new FileInputStream(inputFile);
		BufferedReader br = new BufferedReader(new InputStreamReader(fstream));

		PrintWriter writer = new PrintWriter(outputFile, "UTF-8"); //result
		
		String strLine;
		strLine = br.readLine();
		int numCase = Integer.parseInt(strLine);
		
		for( int i = 0;i<numCase;i++){
			
			strLine = br.readLine();
			String[] strArray = strLine.split(" ");
			int X = Integer.parseInt(strArray[0]);
			int R = Integer.parseInt(strArray[1]);
			int C = Integer.parseInt(strArray[2]);

			boolean result = worker(X, R, C);
			
			String result_str;
			if(result == false){
				result_str ="Case #"+(i+1)+": "+"RICHARD";
			}else{
				result_str ="Case #"+(i+1)+": "+"GABRIEL";
			}
			writer.println(result_str);
			System.out.println("Case: " + (i+1) + ": "  + " (" + X +", " + R + ", " + C+") "+ result);
		}
		

		//Close the input stream
		br.close();
		writer.close();
	}
	public static boolean worker(int X, int R, int C){
		// true if can cover R *C grid
		if(X == 1){
			return true;
		}
		if(R*C%X != 0 ){
			return false;
		}


		if(Math.min(R, C) == 1 && X>=3){
			return false;
		}
		if(X>Math.max(R, C)){
			return false;
		}

		if(X>= 7){
			return false;
		}
		if(X == 4 && Math.min(R, C)<=2){
			return false;
		}
		
		return true;
	}
}
