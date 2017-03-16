package interview;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;

public class Solution_GJ {
	
	private Solution_GJ(){}
	
	public static void main(String[] args) throws IOException{
		String file = "C:/zfeng/A-small-attempt0.in";
		String output = "C:/zfeng/A-small-attempt0.out";
		//String file = "C:/zfeng/test1.txt";
		//String output = "C:/zfeng/output.txt";
		BufferedReader content =  new BufferedReader(new FileReader(file));	
		PrintWriter outputFile = new PrintWriter(new FileWriter(output));
		
		int num_cases = Integer.parseInt( content.readLine() );
		
		for( int i = 1; i<=num_cases; i++ ){
			//int N = Integer.parseInt( content.readLine() );
			String dataRow = content.readLine();
			String[] data = dataRow.split(" ");
			int A = Integer.parseInt(data[0]);
			int B = Integer.parseInt(data[1]);
			int K = Integer.parseInt(data[2]);
			int num = 0;
			for( int k=0; k<A; k++){
				for( int j=0; j<B; j++){
					int temp = k&j;
					if( temp<K )
						num++;
				}
			}
			
			//if( num ==-1 )
				//outputFile.println("Case #"+i+": Fegla Won");
			//else
			outputFile.println("Case #"+i+": "+num);
			
		}
		
		content.close();
		outputFile.close();		
	}
	
	
}
