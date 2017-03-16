package jc2012c;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Enumeration;
import java.util.Hashtable;
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
			
			int[][] erbt = new int[N][10];
			int[] anzErb = new int[N];
			for(int i=0;i<N;i++)
			{
				int M =sc.nextInt();
				anzErb[i] =M;
				for(int j=0;j<M;j++)
				{
					erbt[i][j] =sc.nextInt()-1; 
					//System.out.println(erbt[i][j]);
				}
				//System.out.println();
			}
			Hashtable reachableFrom[] = new Hashtable[N];
			Boolean FoundDiamond=false;
			for(int i=0;i<N;i++)
			{
				FoundDiamond = addReachables(reachableFrom, erbt, anzErb, i);
				if (FoundDiamond) break;
			}
			
			
			if(FoundDiamond)
			{
				wc("Yes");
			}
			else
			{
				wc("No");
			}
			
	}
		
	
		pw.close();
		sc.close();
		System.out.println("finished");
	}
	


	private static Boolean addReachables(Hashtable[] reachableFrom, int[][] erbt,
			int[] anzErb, int i) {
		
		if (reachableFrom[i]!=null && reachableFrom[i].contains("yes"))
		{
			return false;
		}
		if(anzErb[i]>0)
		{
			if (reachableFrom[i]== null)
			{
				reachableFrom[i] = new Hashtable(10);
			}
			for(int j=0;j<anzErb[i];j++)
			{
				if (reachableFrom[i].contains(erbt[i][j]))
				{
					return true;
				}
				reachableFrom[i].put(erbt[i][j], erbt[i][j]);
				addReachables(reachableFrom, erbt, anzErb, erbt[i][j]);
				Enumeration e=reachableFrom[erbt[i][j]].elements();
				while(e.hasMoreElements())
				{
					Object x = e.nextElement();
					if (x!="yes")
					{
						if (reachableFrom[i].contains(x))
						{
							return true;
						}
						else
						{
							reachableFrom[i].put(x, x);
						}
					}
				}
			}
			reachableFrom[i].put("done", "yes");
		}
		else
		{
			if (reachableFrom[i]== null)
			{
				reachableFrom[i] = new Hashtable(10);
			}
			reachableFrom[i].put("done", "yes");
		}
		return false;
	}



	private static void wc(String text) {
		String tt="Case #" + testOut++ + ": " + text;
		pw.print(tt);
		pw.println();
		System.out.println(tt);
	}
}
