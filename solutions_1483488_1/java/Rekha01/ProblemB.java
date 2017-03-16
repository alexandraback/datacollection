package com.google.codejam;

import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class ProblemB {

	/**
	 * @param args
	 */
	
	public void calculate(int numTestCase, int a, int b){
		
			int count = 0 ;
			if(b<10 || a==b)
				count = 0; 
			
			else{
				for ( int i=a ; i <= b; i++){
					String num = String.valueOf(i);
				    String correctNum = String.valueOf(i);
				
					String finalStr ="" ;
					while(!correctNum.equals(finalStr)){
						String first = num.substring(0,1);
						String rest = num.substring(1);
						 finalStr = rest+first ;
							num = finalStr ;
						 if(finalStr.startsWith("0") || first.equals(rest))
							 continue;
						int num2 = Integer.parseInt(finalStr);
						if(num2<=b && num2!=i && i<num2)
							count ++ ; 
					
					}
				}
			}
			
			System.out.println("Case #"+(numTestCase)+": "+(count));
		
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		ProblemB b = new ProblemB();
		//b.calculate(1,17,79);
		b.fileRead(b);
	}

	public void fileRead(ProblemB bb){
		 FileInputStream fstream;
			try {
				fstream = new FileInputStream("D:\\1.txt");
				 DataInputStream in = new DataInputStream(fstream);
				    BufferedReader br = new BufferedReader(new InputStreamReader(in));
				    String strLine;
				    //Read File Line By Line
					int testCase =0 ;
				    while ((strLine = br.readLine()) != null)   {
				    // Print the content on the console
				    	 testCase = Integer.parseInt(strLine);
						 
				    	for(int i = 0 ; i < testCase ; i++){
							String line = br.readLine() ;
							String[]array = line.split(" ");
							int a = Integer.parseInt(array[0]);
							int b = Integer.parseInt(array[1]);
							bb.calculate(1+i ,a ,b);
				    	}
						
				    }
					
				    
				   in.close() ;
				  
			} catch (FileNotFoundException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		    // Get the object of DataInputStream
			catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		   
	 }
}
