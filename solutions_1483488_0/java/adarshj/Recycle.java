
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


public class Recycle {
	
	public static void main (String[] args){

			String output = "";
			try {
				System.out.println("start : "  + new java.util.Date().toString());
				FileOutputStream fo = null;
				FileInputStream fi = null;
				fi = new FileInputStream("F:\\adarsh\\codejam10\\codejam12\\src\\C-small-attempt0.in");
				BufferedReader reader = new BufferedReader(new InputStreamReader(fi));
				Scanner sc = new Scanner(reader);
				int testCases = sc.nextInt();
				System.out.println("test cases : " + testCases);
				 
				fo = new FileOutputStream("F:\\adarsh\\codejam10\\codejam12\\src\\C-small.out");
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
					sout("lowerlimit" , ""+lowerlimit);
					sout("upperlimit" , ""+upperlimit);
					int out = performWork(lowerlimit , upperlimit);	
					sout("out" , ""+out);
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
			
			int templow = lowerlimit;
			for(; templow<= upperlimit ; templow++)
			{
				String temp = ""+templow;
				sout("temp" , temp);
				for(int i = 1 ; i < temp.length() ; i++)
				{
					int newnumber = Integer.parseInt(temp.substring(i) + temp.substring(0, i));
					sout("newnumber" , ""+newnumber);
					if(newnumber >= lowerlimit && newnumber <= upperlimit && !((""+newnumber).equals(temp)))
					{
						if(!pairexists(pairs , temp , ""+newnumber))
						{
							String[] t = new String[2];
							t[0] = temp;
							t[1] = ""+newnumber;
							pairs.add(t);
							output++;
						}
					}
				}
				
			}
			sout("output" , ""+output);
			return output;
		}

		private static boolean pairexists(java.util.ArrayList pairs , String temp , String newnumber)
		{
			for(int i = 0 ; i < pairs.size(); i++)
			{
				String[] t = (String[]) pairs.get(i);
				if((t[0].equals(temp) && t[1].equals(newnumber)) || (t[1].equals(temp) && t[0].equals(newnumber)))
				{
					sout("pair exists" , "true");
					return true;
				}
			}
			sout("pair exists" , "false");
			return false;
		}
		
		private static void sout(String str1 , String str2)
		{
			System.out.println(str1 + " : " + str2);
		}
	}
			


	

