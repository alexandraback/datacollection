package com.google.codejam;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.HashSet;
import java.util.Iterator;

public class PartElf {

	static String res=null;
	public static void main(String[] args) {
		try {

			// File for input and output
			BufferedReader br = new BufferedReader(new FileReader("A-large.in"));
			FileWriter fstream = new FileWriter("output.out");
			BufferedWriter out = new BufferedWriter(fstream);

			int testcasenum = Integer.parseInt(br.readLine());
			for (int i = 0; i < testcasenum; i++) {

				double n = 0;
				
				
				res = null;
				int resNum=0;
				double n1, n2;
				
				String s = br.readLine();
				n1 = Double.parseDouble(s.split("/")[0]);
				n2 = Double.parseDouble(s.split("/")[1]);
				n = n1/n2;
				//System.out.println("n "+n);
				
				int xyz=0;
				while (n2 % 2 <= 0) {
					n2 /= 2;
					++xyz;
				}
				//System.out.println("xyz "+xyz);
				if (n1 % n2 > 0)
					res = "imposible";
				else
				{
					n1 /= n2; 
					//System.out.println("n1 "+n1);
					n2 = Math.pow(2, xyz);
					//System.out.println("n2 "+n2);
				}
				for (int j = 0;  Math.pow(2, j) <= n1; ++j)
				{
					resNum=xyz-j;
				}
				
				
				
				/*double  a = 1/n;
				//A-small-attempt0 (9).inSystem.out.println("a "+a );
				for(int j=0;j<40;j++)
				{
					double b = Math.pow(2, j);
					//System.out.println("b "+b);
					double c = 1/b;
					if(a==b)
					{
						resNum = j;
						break;
					}
					if(a<b && (b-a)<1)
					{
						resNum = j;
					}
				}
				*/
					
				if(resNum<0)
					res = "impossible";
				else
					res = new Integer(resNum).toString();
				
				// result = new DecimalFormat("#0.0000000").format(totalTime);

				System.out.println("Case #" + (i + 1) + ": " + res);
				out.write("Case #" + (i + 1) + ": " + res + "\n");
			}
			out.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	

}



