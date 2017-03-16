
import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.util.Scanner;


public class Googlerese {
	
	public static void main (String[] args){

			String output = "";
			try {
				System.out.println("start : "  + new java.util.Date().toString());
				FileOutputStream fo = null;
				FileInputStream fi = null;
				fi = new FileInputStream("F:\\adarsh\\codejam10\\codejam12\\src\\A-small-attempt0.in");
				BufferedReader reader = new BufferedReader(new InputStreamReader(fi));
				Scanner sc = new Scanner(reader);
				int testCases = sc.nextInt();
				System.out.println("test cases : " + testCases);
				 
				fo = new FileOutputStream("F:\\adarsh\\codejam10\\codejam12\\src\\A-small.out");
				PrintStream ps = new PrintStream(fo);
				sc.nextLine();
				String googlerese = " ynficwlbkuomxsevzpdrjgthaq";
				String english = " abcdefghijklmnopqrstuvwxyz";
				for (int i = 1; i <= testCases;  i++) {
					output = "";
					String data = sc.nextLine();
					System.out.println("data : " + data);
					for(int j = 0 ; j < data.length() ; j++)
					{
						char temp = data.charAt(j);
						int index = googlerese.indexOf(temp);
						char newchar = english.charAt(index);
						output =  output + newchar;
					}
					sout("output" , output);
					ps.println("Case #"+i+": "  + output);
				}
				ps.close();
				fo.close();
				System.out.println("end : " + new java.util.Date().toString());

			} catch (Exception e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			} 
		}

		private static void sout(String str1 , String str2)
		{
			System.out.println(str1 + " : " + str2);
		}
	}
			


	

