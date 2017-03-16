package codejam2014;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class A {

	 public static void main(String[] args) throws FileNotFoundException {
	        Scanner in = new Scanner(new File("c:\\codejam\\a\\small.in"));
	        PrintWriter out = new PrintWriter(new File("c:\\codejam\\a\\small.out"));
	        int T = in.nextInt();
	        for (int i = 0; i < T; i++) {
//	        	System.out.println("Solving: " + (i + 1));
	            String s = "Case #" + (i + 1) + ": " + solve(in);
	            out.println(s);
	            System.out.println(s);
	        }
	        out.close();
	    }

	 	static int p;
	 	static int q;
	 	
	    private static String solve(Scanner in) {
	    	
	    	String str = in.next();
	    	
	    	String[] ss = str.split("/");
	    	
	        p = Integer.parseInt(ss[0]);
	        q = Integer.parseInt(ss[1]);
	        
	        int gcd = findGCD(p, q);
	        
	        if(gcd > 1)
	        {
	        	p = p / gcd;
	        	q = q /gcd;
	        }
	        
	        System.out.println("gcd: " + gcd);
	        
	        if(isPowerOfTwo(q))
	        {
	        	int gen = 0;
	        	
	        	while(true)
	        	{
	        		q = q >> 1;
	        		gen++;
	        		if(q <= p)
	        		{
	        			break;
	        		}
	        	}
	        	
	        	return "" + gen;
	        }
	        else
	        {
	        	//impossible.
	        	return "impossible";
	        }
	      
	    }
	    
	    
	    private static int findGCD(int number1, int number2) {
	        
	        if(number2 == 0){
	            return number1;
	        }
	        return findGCD(number2, number1 % number2);
	    }
	  
	    private static boolean isPowerOfTwo(int number) {
	        if(number <=0){
	            throw new IllegalArgumentException("number: " + number);
	        }
	        if ((number & -number) == number) {
	            return true;
	        }
	        return false;
	    }

    
	    public static int[] readArray(int size, Scanner in)
	    {
	    	int[] arr = new int[size];
	    	
	    	for(int i = 0; i < size; i++)
	    	{
	    		arr[i] = in.nextInt();
	    	}
	    	return arr;
	    }
		
	    public static int[][] read2dArray(int r, int c, Scanner in)
	    {
	    	int[][] arr = new int[r][c];
	    	
	    	for(int i = 0; i < r; i++)
	    	{
	    		for(int j = 0; j < c; i++)
		    	{
	    			arr[i][j] = in.nextInt();
		    	}
	    	}
	    	
	    	return arr;
	    }
}
