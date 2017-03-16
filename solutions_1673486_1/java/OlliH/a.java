package jc2012a;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class a {

	static PrintWriter pw;
	static int testOut=1;
	
	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(new FileReader("C://CODEJAM//2012//A-large.in"));
		pw = new PrintWriter(new FileWriter("C://CODEJAM//2012//A.out"));
		
		int ntest = sc.nextInt();
		sc.nextLine();
		
		for(int test=1;test<=ntest;++test) {
			int a= sc.nextInt(); //typed
			int b = sc.nextInt(); // total chars
			double l=0,l4=0,newl;
			
			double wwrong,wcorrect=1;
			double bestl=0;
			bestl=b+2;
			for(int i=1;i<a+1;i++)
			{
				double p = sc.nextDouble();
				wcorrect = wcorrect * p;
				if (wcorrect==0)
				{
					sc.nextLine();
					break;
					
				}
				wwrong=1-wcorrect;
				newl= ((a-i)+b+1-i) + (wwrong*(b+1));
				if (newl<bestl || bestl==0)
				{
					bestl=newl;
				}
				
			}
			
			wc(bestl+"");
			
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
