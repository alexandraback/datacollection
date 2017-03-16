package com.powdercode.codejam.round1;



import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.InputStreamReader;

public class Main {

	private int caser = 1;
	private int numberOfCases = 0;
	

	public void generateResult()
	{
	  try
	  {
		FileInputStream fstream = new FileInputStream("E://in.txt");
		DataInputStream in = new DataInputStream(fstream);
		BufferedReader br = new BufferedReader(new InputStreamReader(in));
		
		String strLine,strLine2;
		//get the number of cases
		strLine = br.readLine();
		if(strLine!=null) numberOfCases = Integer.parseInt(strLine.trim());

		
		for(int i=0;i<numberOfCases;i++)
		{
			strLine2 = br.readLine();
			String[] line = strLine2.trim().split(" ");
			
			Long r = Long.parseLong(line[0]);
			Long t = Long.parseLong(line[1]);
			
			long res = (long)operate(r,t);
			
			
			String text = "Case #"+caser+": "+res;
				
			System.out.println (text);
			
			caser++;
		}
		in.close();
		
		} catch (Exception e){//Catch exception if any
			System.err.println("Error: " + e.getMessage());
			e.printStackTrace();
		}
	} // end of 
	
	public double operate(double r, double t)
	{
		long circles = 0;
		
		while(t>0)
		{
			t-=2*r+1;
			r+=2;
			if(t>=0)circles++;
		}
		
		return circles;
	}

	public static void main(String[] args) 
	{

		Main s=new Main();
		s.generateResult();
	}
	


}