/*
ID: abhi1
LANG: JAVA
TASK: gift1
*/

import java.util.List;
import java.util.ArrayList;
import java.io.*;
import java.util.Map;
import java.util.HashMap;


public class standingovation {
	public static void main(String[] args)
	{
		
		try
		{
			BufferedWriter bw = new BufferedWriter(new FileWriter("test1.out"));
			BufferedReader br = new BufferedReader(new FileReader("test.in"));
			
			int T = Integer.parseInt(br.readLine());	
			
			for(int i = 0; i < T; i++)
			{
				String[] temp = br.readLine().split(" ");
				int smax = Integer.parseInt(temp[0]);
				int[] nums = new int[smax + 1];
				for(int j = 0; j <= smax; j++)
					nums[j] = Integer.parseInt(temp[1].substring(j, j + 1));
				
				
				int total = 0;
				int addPeople = 0;
				
				for(int j = 0; j <= smax; j++)
				{
					int t = total;
					if(total < j)
					{
						addPeople += (j - t);
						total += (j - t + nums[j]);
					}
					else
						total += nums[j];
				}
				
				
				bw.write("Case #" + (i + 1) + ": " + addPeople);
				bw.newLine();
			}
			
			
			
			
			
			//bw.newLine();
			
			bw.close();
			br.close();
			
		}
		catch (Exception ex) 
		{
			System.out.println(ex.getMessage());
		}
	}
}
