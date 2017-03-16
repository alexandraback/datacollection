package jam;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.math.BigInteger;
import java.util.Scanner;

public class B{

	/**
	 * @param args
	 * @throws FileNotFoundException
	 */
	
	static int v[] ;
	static int e;
	static int r;
	static int n;
	
	public static void main(String[] args) throws FileNotFoundException {
		Scanner s = new Scanner(new File("in.in"));
		PrintStream ps = new PrintStream("out.out");

		// loop for the number of test cases
		int T = Integer.parseInt(s.nextLine());

		for (int z = 1; z <= T; z++) {
			ps.print("Case #" + z + ": ");
			totalgain=0;
			
			
			
			e = s.nextInt();r = s.nextInt(); n = s.nextInt();
			
			
			if(r > e) r= e;
			
			 v = new int[n];
			
			
			
			int maxindex  = 0;
			
			
			for(int i=0;i< v.length;i++)
			{
				v[i] = s.nextInt();
				if(v[maxindex]< v[i]) maxindex =i;
				
			}
			

			
			//int totalgain =0;
			
			
			
			
//			
//			for(int i=0;i<v.length;i++)
//				if(i!=maxindex) totalgain += v[i]*r;
				
				recurse(0,e,0);
			
			ps.println(totalgain);
		}

	}

	static int totalgain =0;
	
	public static void recurse(int level,int j,int prev)
	{

		if(level == n) 
			
			{if(prev > totalgain)totalgain =prev;return;}
		int availableE = j + r;
		if(availableE > e)availableE=e;
		
			for(int k=0;k<=availableE;k++)
			{
				//System.out.println(level);
				recurse(level+1,availableE-k, prev + k*v[level]);
				
			}
			
		
		
		
	}
	

}



