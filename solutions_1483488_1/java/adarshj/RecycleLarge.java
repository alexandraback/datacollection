
import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.LinkedHashSet;
import java.util.Scanner;
import java.util.Set;


public class RecycleLarge {
	
	public static void main (String[] args){

			String output = "";
			try {
				System.out.println("start : "  + new java.util.Date().toString());
				FileOutputStream fo = null;
				FileInputStream fi = null;
				fi = new FileInputStream("F:\\adarsh\\codejam10\\codejam12\\src\\C-large.in");
				BufferedReader reader = new BufferedReader(new InputStreamReader(fi));
				Scanner sc = new Scanner(reader);
				int testCases = sc.nextInt();
				System.out.println("test cases : " + testCases);
				 
				fo = new FileOutputStream("F:\\adarsh\\codejam10\\codejam12\\src\\C-large.out");
				PrintStream ps = new PrintStream(fo);
				sc.nextLine();
				
				for (int i = 1; i <= testCases;  i++) {
					output = "";
					int j = 0;
					String data = sc.nextLine();
					System.out.println("data : " + data);
					String[] dataarray = data.split(" ");
					int lowerlimit = Integer.parseInt(dataarray[j++]);
					int upperlimit = Integer.parseInt(dataarray[j++]);
					//sout("lowerlimit" , ""+lowerlimit);
					//sout("upperlimit" , ""+upperlimit);
					int out = performWork(lowerlimit , upperlimit);	
					//sout("out" , ""+out);
					ps.println("Case #"+i+": "  + out);
				}
				ps.close();
				fo.close();
				System.out.println("end : " + new java.util.Date().toString());

			} catch (Exception e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			} 
		}
	
		private static int performWork(int lowerlimit , int upperlimit)
		{
			int output = 0;
			java.util.ArrayList pairs = new ArrayList();
			boolean[] usednum = new boolean[upperlimit - lowerlimit+1];
			int templow = lowerlimit;
			for(; templow<= upperlimit ; templow++)
			{
				//sout("templow" , ""+templow);
				//sout("lowerlimit" , ""+lowerlimit);
				if(!usednum[templow-lowerlimit])
				{
					usednum[templow-lowerlimit] = true;
					java.util.LinkedHashSet tempset = new java.util.LinkedHashSet(); 
					int noofcombinations = 1;
					String temp = ""+templow;
					tempset.add(temp);
					//sout("temp" , temp);
					for(int i = 1 ; i < temp.length() ; i++)
					{
						int newnumber = Integer.parseInt(temp.substring(i) + temp.substring(0, i));
						
						if(newnumber >= lowerlimit && newnumber <= upperlimit && !((""+newnumber).equals(temp)))
						{
							//sout("" , "" + temp + " " + newnumber);
							tempset.add(""+newnumber);
							usednum[newnumber-lowerlimit] = true;
							noofcombinations++;
						}
					}
					
					//sout("noofcombinations" , ""+noofcombinations);
					output+= calcuatecombinations(tempset.size());
					//sout("output" , ""+output);
				}
				
				
			}
			return output;
		}

		private static int calcuatecombinations(int noofcombinations)
		{
			int total= ((noofcombinations * noofcombinations ) - noofcombinations)/2;
			//sout("sub total" , ""+total);
			return total;
		}
		
		private static void sout(String str1 , String str2)
		{
			System.out.println(str1 + " : " + str2);
		}
	}
			


	

