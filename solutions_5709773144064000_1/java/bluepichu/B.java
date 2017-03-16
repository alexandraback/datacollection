// Java Shell by Matthew Savage

import java.io.*;
import java.math.*;
import java.util.*;

public class B{
	public static void main (String [] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(System.out);
		
		int cases = Integer.parseInt(br.readLine());
		
		for(int t = 1; t <= cases; t++){
			StringTokenizer st = getst(br);
			
			double c = Double.parseDouble(st.nextToken());
			double f = Double.parseDouble(st.nextToken());
			double x = Double.parseDouble(st.nextToken());
			
			double min = Double.MAX_VALUE;
			
			double start = 0;
			double production = 2;
			int i = 0;
			while(start <= min){
				i++;
				min = Math.min(min, start + x/production);
				start += c/production;
				production += f;
			}
			
			pw.println("Case #" + t + ": " + min);
		}
		
		br.close();
		pw.close();
	}
	
	public static int nextInt(BufferedReader br) throws Exception{
		return Integer.parseInt(br.readLine());
	}
	
	public static int nextInt(StringTokenizer st) throws Exception{
		return Integer.parseInt(st.nextToken());
	}
	
	public static StringTokenizer getst(BufferedReader br) throws Exception{
		return new StringTokenizer(br.readLine(), " ");
	}
}