package b;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;


public class main {

	/**
	 * @param args
	 */
	
	
	Double calc(int amount, int x, int y)
	{
		int n= Math.abs(x)+y-1;
		int base = getBase(x, y);
		int hull= getHull(x, y);
		int neededOneSide=y+1;
		
		if(base+(hull/2)+neededOneSide<=amount)
			return 1D;
		
		int availible = amount-base;
		
		if(x==0)
		{
			if(amount<hull+base)
				return 0D;
			else
				return 1D;
		}
		
		
		
		Double r=0D;
		for(int i=neededOneSide;i<=availible;i++)
		{
			r+=bin(availible, i)*Math.pow(0.5, neededOneSide)*Math.pow(0.5, availible-neededOneSide);
		}
		return r;
		
		
		
		
	}
	
	int getBase(int x, int y)
	{
		int n = (Math.abs(x)+y)/2-1;
		return 1+n*(2*n+3);
	}
	
	int getHull(int x, int y)
	{
		int n = (Math.abs(x)+y)/2;
		return 1+n*(2*n+3)-getBase(x, y);
	}
	
	
	
	public double bin(int n, int k)
	{
		double b;
		
		if(k>n)
			return 0;
		if(k==0||k==n)
			return 1;
		b=1;
		for(int i=1;i<=k;i++)
		{
			b*=(n-i+1)/i;
		}
		return b;
		
		
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
				line=br.readLine();
				split=line.split(" ");
				bw.write("Case #"+t+": "+m.calc(Integer.parseInt(split[0]), Integer.parseInt(split[1]), Integer.parseInt(split[2])));
				
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
