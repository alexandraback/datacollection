package com.google.jam;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;

import javax.naming.InitialContext;

public class Q1 {

	
	public static void main(String[] args) {
		String input="g:\\A-small-attempt1.in";
        String output="g:\\output.out";
        
        try {
            Scanner sc = new Scanner(new FileReader(input));
            PrintWriter pw = new PrintWriter(output);
            //getInit();
            int n = sc.nextInt();
            sc.nextLine();
            for (int c=0; c<n; c++) {
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
	
    	String line = sc.nextLine();
    	String[] numbers = line.trim().split("/");
    	int first = Integer.parseInt(numbers[0]);
    	int second = Integer.parseInt(numbers[1]);
    	
    	double d = first/(double)second;
    	if(d == 0)
    	{
    		pw.println(1);
    		return;
    	}
    	
    	int counter = 0;
		int met = 0;
		while(counter <= 40)
		{
			counter ++;
			if(second%2 == 0)
				second /=2;
			else
				first*=2;
			
			if(first>second)
			{
				if(met == 0)
					met = counter;
				
				first -= second;
			}
			else if(first == second)
			{
				if(met == 0)
					met = counter;
				
				break;
			}			
		}
		
		if(counter > 40)
			pw.println("impossible");
    	
		else
			pw.println(met);
	}


}
