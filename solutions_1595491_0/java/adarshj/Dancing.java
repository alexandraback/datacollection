
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


public class Dancing {
	
	public static void main (String[] args){

			String output = "";
			try {
				System.out.println("start : "  + new java.util.Date().toString());
				FileOutputStream fo = null;
				FileInputStream fi = null;
				fi = new FileInputStream("F:\\adarsh\\codejam10\\codejam12\\src\\B-small-attempt0.in");
				BufferedReader reader = new BufferedReader(new InputStreamReader(fi));
				Scanner sc = new Scanner(reader);
				int testCases = sc.nextInt();
				System.out.println("test cases : " + testCases);
				 
				fo = new FileOutputStream("F:\\adarsh\\codejam10\\codejam12\\src\\B-small.out");
				PrintStream ps = new PrintStream(fo);
				sc.nextLine();
				
				for (int i = 1; i <= testCases;  i++) {
					output = "";
					int j = 0;
					String data = sc.nextLine();
					System.out.println("data : " + data);
					String[] dataarray = data.split(" ");
					int noofgooglers = Integer.parseInt(dataarray[j++]);
					int[] totallist = new int[noofgooglers];
					int noofsurprises = Integer.parseInt(dataarray[j++]);
					int highestval = Integer.parseInt(dataarray[j++]);
					int k = 0;
					for(; j < dataarray.length ; j++)
					{
						totallist[k++]= Integer.parseInt(dataarray[j]);
					}
					Arrays.sort(totallist);
					int out = performWork(noofsurprises , highestval , totallist );
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
	
		private static int performWork(int noofsurprises , int p , int[] totallist)
		{
			int output = 0;
			int surprisesfound = 0;
			for(int i = 0 ; i < totallist.length ; i++)
			{
				//int total = Integer.parseInt((String)totallist.get(i));
				int total = totallist[i];
				sout("total" , ""+total);
				
				
				if(surprisesfound < noofsurprises)
				{
					int num1 = (int)Math.ceil((double)total/3);
					if(num1 > 10 ) num1 = 10;
					sout("num1" , "" + num1);
					int num2=  num1;
					int num3 = total - num1 - num2;
					
					if((num1 != 0) && !(Math.abs(num2-num3) == 2))
					{
						num1--;
						num2++;
					}
					
					if(num1 >= p || num2 >= p || num3 >= p)
					{
						surprisesfound++;
						output++;
					}
					sout("output" , ""+output);
					sout("set : ", ""+num1+" "+num2+" "+num3);
				}
				else
				{
					int num1 = (int)Math.round((double)total/3);
					if(num1 > 10 ) num1 = 10;
					sout("num1" , "" + num1);
					int num2=  num1;
					int num3 = total - num1 - num2;
					if(num1 >= p || num3 >= p)
					{
						output++;
					}
					sout("output" , ""+output);
					sout("set : ", ""+num1+" "+num2+" "+num3);
				}
						
			}
			sout("output" , ""+output);
			return output;
		}

		private static void sout(String str1 , String str2)
		{
			System.out.println(str1 + " : " + str2);
		}
	}
			


	

