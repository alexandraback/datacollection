package com.google.jam;


import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;

public class Q2 {

	private static int count = 0;
	public static void main(String[] args) {
		String input="g:\\B-small-attempt0.in";
        String output="g:\\output.out";
        
        try {
            Scanner sc = new Scanner(new FileReader(input));
            PrintWriter pw = new PrintWriter(output);
            
            int n = sc.nextInt();
            sc.nextLine();
            for (int c=0; c<n; c++) {
            	count = 0;
                //System.out.println("Test case " + (c+1) + "...");
                pw.print("Case #" + (c+1) + ": ");
                test(sc, pw);
            }
            pw.println();
            pw.flush();
            pw.close();
            sc.close();
            System.out.println("done");
        } catch (FileNotFoundException ex) {
            Logger.getLogger(Magic.class.getName()).log(Level.SEVERE, null, ex);
        }
	}
	
	private static void test(Scanner sc, PrintWriter pw) {
		
		int n = sc.nextInt();
		sc.nextLine();
		
    	String line = sc.nextLine();
    	String[] carts = line.trim().split(" ");
    	ArrayList<String> all = new ArrayList<String>();
    	for(int i =0;i<n;i++)
    	{
    		all.add(carts[i]);
    	}
    	 
    	check(new StringBuilder(), all);
    	
    	
    	pw.println(count);
	}

	private static void check(StringBuilder sb, ArrayList<String> all) {
		
		if(all.size() == 0)
		{
			if(isGood(sb.toString()))
				count ++;
		}
		else {
			for(String s : all)
			{
				if(sb.length() == 0 || sb.toString().lastIndexOf(s.charAt(0)) < 0 || sb.toString().lastIndexOf(s.charAt(0)) == sb.toString().length() - 1)
				{
					
					StringBuilder nBuilder = new StringBuilder(sb.toString());
					nBuilder.append(s);
					ArrayList<String> next = (ArrayList<String>) all.clone();
					next.remove(s);
					
					check(nBuilder, next);
				}
			}
		}
	}

	private static boolean isGood(String s) {
		
		HashSet<Character> cc = new HashSet<Character>();
		cc.add(s.charAt(0));
		for(int i = 1;i<s.length();i++)
		{
			char c = s.charAt(i);
			if(c != s.charAt(i-1) && cc.contains(c))
				return false;
			else {
				cc.add(c);
			}
		}
		return true;
	}
	
	

}
