package Round1C;

import java.util.*;
import java.io.*;

public class Problem2 {

	public static void main(String... orange) throws Exception {
//		String filename = "practice";
		String filename = "B-small-attempt0";
		Scanner input = new Scanner(new File(filename + ".in"));
		PrintWriter writer = new PrintWriter(filename + ".out", "UTF-8");
		int T = input.nextInt();
		int K, L, S;
		for (int t = 0; t < T; t++) {
			K = input.nextInt();
			L = input.nextInt();
			S = input.nextInt();
			
			String kword = input.next();
			String lword = input.next();
			

			String out = "Case #" + (t + 1) + ": " +solve(K,L,S, kword, lword);
			System.out.println(out);
			writer.println(out);
		}
		writer.close();
	}


	static double count = 1;
	static double max = 0.0;
	static double occurance = 0;
	
	static void Recur(String prefix, String str, int S, String lword)
	{
	 if(prefix.length()== S)
	 { 
	   count++;
	   if(prefix.contains(lword)){
		   int index = prefix.indexOf(lword);
		   int localMax = 0;
		   while (index >= 0) {
		       localMax++;
		       occurance++;
		       index = prefix.indexOf(lword, index + 1);
		   }
		   if(localMax > max){
			   max = localMax;
		   }
	   }		   
		   return; 
	 }

	   for(int i=0; i<str.length(); i++)
	   Recur(prefix+str.charAt(i),str,S,lword);
	 }
	
	static String solve(int K, int L, int S, String kword, String lword) {
		String output = "";
		count = 0;
		max = 0.0;
		occurance = 0;
		Recur("", kword, S, lword);
		double value = max - (occurance/count);
		return output + value;
		
	}
}
