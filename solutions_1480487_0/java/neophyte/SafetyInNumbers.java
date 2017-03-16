package gcj;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.StringTokenizer;

public class SafetyInNumbers {
	
	private static int n,max,sum;
	private static int[] values;
	private static double[] perc;

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		BufferedReader fin = null;
		int t = 0;
		StringTokenizer str = null;
		
		try {
			fin = new BufferedReader(new FileReader(new File("A-small-attempt0.in")));
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		
			
			
			try {
				t = Integer.parseInt(fin.readLine());
				//System.out.println(t);
			} catch (NumberFormatException e) {
				e.printStackTrace();
			} catch (IOException e) {
				e.printStackTrace();
			}
			
			
			
			
			for(int i=0;i<t;i++){
				System.out.print("Case #"+(i+1)+": ");
				try {
					
					str=new StringTokenizer(fin.readLine());
					n = Integer.parseInt(str.nextToken());
					values= new int[n];
					perc = new double[n];
					Arrays.fill(perc,0.0);
					max=0;
					sum =0;
					for(int j=0;j<n;j++){
					
					values[j] = Integer.parseInt(str.nextToken());
					sum+=values[j];
					if(values[j]>max)
						max=values[j];
					}
					
				}
				catch (IOException e) {
					e.printStackTrace();
				}
				
				double percentage =100.0;
				
				for(int j=0;j<n;j++){
					if(values[j]>max)
						continue;
					perc[j]+=(double)((double)(max-values[j])*100)/(double)sum;
					percentage = percentage - perc[j];
					
				}
				double remainder = percentage/(double)n;
				
				for(int j=0;j<n;j++){
					perc[j]+=remainder;
					System.out.print(perc[j]+" ");
					
				}
				System.out.println();
			}
	}
}
