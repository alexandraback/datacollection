package com.google.codejam;

import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class ProblemC {

	public ProblemC() {
		super();
		// TODO Auto-generated constructor stub
	}

	
	public void calculate(int numTestCase , int part , int suprise , int max , List<Integer> a){
		int count = 0 ;
		int possible = 0 ;
		for(int i = 0 ; i<part ; i++){
			int score = a.get(i);
			int remain = score - max ;
			if(remain < 0){
				
			}
			else if(2*max <= remain || 2*max <= remain +1 ||2*max <= remain +2 ){
				count ++ ;
			}
			else if ( 2*max <= remain+4 || 2*max <= remain+3 ){
				possible ++ ;
			}
		}
		if(possible <= suprise)
			count = count +possible ;
		else if(possible > suprise)
			count = count +suprise ;
		System.out.println("Case #"+(numTestCase)+": "+(count));
	}
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		ProblemC c = new ProblemC();
		c.fileRead(c) ;
//		List<Integer> l = new ArrayList<Integer>();
//		l.add(29);
//		l.add(20);
//		l.add(8);
//		l.add(18);
//		l.add(18);
//		l.add(21);
//		c.calculate(1,6,2,8,l);
	}

	
	
	public void fileRead(ProblemC cc){
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
							int numpart = Integer.parseInt(array[0]);
							int suprise = Integer.parseInt(array[1]);
							int max =  Integer.parseInt(array[2]);
							List<Integer> l = new ArrayList<Integer>();
							for(int ii = 0; ii<numpart ; ii++){
								l.add(Integer.parseInt(array[3+ii]));
							}
							cc.calculate(1+i ,numpart ,suprise, max , l);
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
