package interview;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;

public class Solution {
	
	private Solution(){}
	
	public static void main(String[] args) throws IOException{
		String file = "C:/zfeng/D-small-attempt0.in";
		String output = "C:/zfeng/D-small-attempt0.out";
		//String file = "C:/zfeng/test1.txt";
		//String output = "C:/zfeng/output.txt";
		BufferedReader content =  new BufferedReader(new FileReader(file));	
		PrintWriter outputFile = new PrintWriter(new FileWriter(output));
		
		int num_cases = Integer.parseInt( content.readLine() );
		
		for( int i = 1; i<=num_cases; i++ ){
			int N = Integer.parseInt( content.readLine() );
			String dataRow = content.readLine();
			String[] NaomiStr = dataRow.split(" ");
			dataRow = content.readLine();
			String[] KenStr = dataRow.split(" ");
			
			double[] Naomi = new double[N];
			double[] Ken = new double[N];
			for( int j=0; j<N; j++){
				Naomi[j] = Double.parseDouble( NaomiStr[j] );
				Ken[j] = Double.parseDouble( KenStr[j] );
			}
			
			Arrays.sort( Naomi );
			Arrays.sort( Ken );
			
			int Score_WO = WarOptimally(Naomi, Ken);
			int Score_WD = WarDeceitful(Naomi, Ken);
			
			outputFile.println("Case #"+i+": "+Score_WD+" "+Score_WO);
		}
		
		content.close();
		outputFile.close();		
	}
	
	public static int WarDeceitful(double[] Naomi, double[] Ken){
		int naomi = 0;
		int ken = 0;
		for(naomi=0; naomi<Naomi.length; naomi++){
			if( Naomi[naomi] < Ken[ken])
				continue;
			ken++;
		}		
		return ken;
	}
	
	public static int WarOptimally(double[] Naomi, double[] Ken){
		int naomi = 0;
		int ken = 0;
		for(ken=0; ken<Ken.length; ken++){
			if( Naomi[naomi] < Ken[ken])
				naomi++;
		}		
		return (Naomi.length - naomi);
	}
}
