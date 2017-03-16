package com.zccicy;

import java.io.FileInputStream;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;

public class Main4 {


	 
	
	public static void main (String[] args)  throws Exception
	{
	 
		FileWriter writer=new FileWriter("d:/DeceitfulWarOutput2.txt");
		Scanner scanner=new Scanner(new FileInputStream("d:/D-small-attempt0.in"));
	    
		int count_case = scanner.nextInt();
		
		 
		//System.out.println("case count "+count_case);
		 
	 		 
		for (long i =0;i<count_case;i++)
		{
			ArrayList<Double> naomi = new ArrayList<Double>();
			ArrayList<Double> ken = new ArrayList<Double>();
			int  count_block =  scanner.nextInt();
			 
			for (int j = 0; j < count_block; j++)
			{
				naomi.add(new Double(scanner.nextDouble()));
			}
			
			for (int j = 0; j < count_block; j++)
			{
				ken.add(new Double(scanner.nextDouble()));
			}
			
			
			Collections.sort(naomi,comparator);
			Collections.sort(ken,comparator);
			
			
			  
			 
			int count_war = count_block;
			int count_dwar = 0;
			int last_position = 0;
			for (int j = 0; j<ken.size();j++)
				
			{
				for (int k = last_position; k<naomi.size();k++)
				{
					if (ken.get(j).doubleValue()> naomi.get(k).doubleValue())
					{
						count_war--;
						last_position = k+1;
						break;
					} 
				}
				
			}
			last_position = 0;
			for (int j = 0; j<naomi.size();j++)
			{
				for (int k = last_position; k<ken.size();k++)
				{
					if (naomi.get(j).doubleValue()> ken.get(k).doubleValue())
					{
						count_dwar++;
						last_position = k+1;
						break;
					} 
				}
			}
 			writer.write("Case #"+(i+1)+": "+count_dwar+" "+count_war+"\n");
 
 
			
		}
		
		writer.close();
	}
	
	static Comparator<Double> comparator = new Comparator<Double>(){
		   public int compare(Double d1, Double d2) {
		     
			   return -d1.compareTo(d2);
		   }
		  };
	
}
