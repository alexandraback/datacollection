package a;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

import javax.crypto.spec.PSource;


public class main {

	
	public int calc(int start,int position ,int[] values)
	{
		if(position==values.length)
			return 0;
		
		if(values[position]<start)
			return calc(start+values[position],position+1,values);
		else
		{
			return Math.min(calcAdd(start, position, values),calcRem(start, position, values));
		}
	}
	
	public int calcAdd(int start, int position, int[] values)
	{
		int n=0;
		if(start-1==0)
			return Integer.MAX_VALUE;
		
		while(start<=values[position])
		{
			start+=start-1;
			n++;
		}
		return calc(start+values[position], position+1, values)+n;
		
	}
	
	public int calcRem(int start, int position, int[] values)
	{
		return calc(start, position+1, values)+1;
	}
	
	
	
	
	
	
	
	
	
	public static void main(String[] args) {
		
		
		main m = new main();
		
		
		BufferedWriter bw = null;
		try {
			BufferedReader br = new BufferedReader(new FileReader(new File("A-large.in")));
			bw = new BufferedWriter(new FileWriter(new File("output.txt")));
		
			int T = Integer.parseInt(br.readLine());
			int start;
			String line;
			String[] split;
			int[] a;
			
			for(int t=1;t<=T;t++)
			{
				line = br.readLine();
				split=line.split(" ");
				start=Integer.parseInt(split[0]);
				line = br.readLine();
				split=line.split(" ");
				
				a = new int[split.length];
				for(int i=0;i<a.length;i++)
				{
					a[i]=Integer.parseInt(split[i]);
				}
				java.util.Arrays.sort(a);
				
				bw.write("Case #"+t+": "+m.calc(start, 0, a));
				bw.newLine();
				
				
			}
			bw.close();
			
			
		
		
		
		
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
			try {
				bw.close();
			} catch (IOException e1) {
				// TODO Auto-generated catch block
				e1.printStackTrace();
			}
		}
		
	}
}
