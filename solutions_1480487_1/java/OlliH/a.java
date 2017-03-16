package jc2012b;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class a {

	static PrintWriter pw;
	static int testOut=1;
	
	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(new FileReader("C://CODEJAM//2012//A-small-attempt0.in"));
		pw = new PrintWriter(new FileWriter("C://CODEJAM//2012//A.out"));
		
		int ntest = sc.nextInt();
		sc.nextLine();
		
		for(int test=1;test<=ntest;++test) {
			int N= sc.nextInt(); 
			
			int[] as = new int[N];
			long sum_s=0;
			for(int i=0;i<N;i++)
			{
				as[i] =sc.nextInt(); 
				sum_s+=as[i];
				//System.out.println(s);
			}
			int[] as_sort = Arrays.copyOf(as, as.length);
			Arrays.sort(as_sort);
			
			double min=as_sort[0];
			double voted=1;
			String result="";
			long sum_st = sum_s;
			for(int i=1;i<N;i++)
			{
				if (as_sort[i]==min)
				{
					voted++;
					continue;
				}
				double diff=(as_sort[i]-min);
				
				if(diff*voted>sum_st)
				{
					min+=sum_st/voted;
					sum_st=0;
					break;
				}
				min=as_sort[i];
				sum_st -=diff*voted;
				voted++;
				
			}
			min+= sum_st/voted;
			
			
			//System.out.println(min);
			
			for(int i=0;i<N;i++)
			{
				if (as[i]>=min)
				{
					result += "0.0 ";
				}
				else
				{
					result += ((min-as[i])/sum_s)*100 + " ";
				}
			}
			
			wc(result);
			
		}
		
	
		pw.close();
		sc.close();
		System.out.println("finished");
	}
	


	private static void wc(String text) {
		String tt="Case #" + testOut++ + ": " + text;
		pw.print(tt);
		pw.println();
		System.out.println(tt);
	}
}
