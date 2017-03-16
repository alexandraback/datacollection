package codejam2014;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.Set;

public class B {
	 public static void main(String[] args) throws FileNotFoundException {
	        Scanner in = new Scanner(new File("c:\\codejam\\b\\small.in"));
	        PrintWriter out = new PrintWriter(new File("c:\\codejam\\b\\small.out"));
	        int T = in.nextInt();
	        for (int i = 0; i < T; i++) {
	            String s = "Case #" + (i + 1) + ": " + solve(in);
	            out.println(s);
	            System.out.println(s);
	        }
	        out.close();
		 
//		 for (int k = 10; k < 40; k++)
//		 {
//			 int[] set = new int[k];
//			 
//			 
//			 for (int i = 0; i < k; i++) 
//			 {
//	
//				 for (int j = 0; j < k; j++)
//				 {
//					 set[i & j]++;
//				 }
//				 
//			 }
//			 System.out.println(Arrays.toString(set));
//		    }
	 	}
	 
	 	static List<char[]> cars ;
	 	static int n;
	 	
	 	static int validCount;
	 	
	    private static String solve(Scanner in) {
	    	
	    	validCount =0;
	    	
	        n = in.nextInt();
	        cars = new ArrayList<char[]>(n);
	        
	        for(int i = 0; i < n ; i++)
	        {
	        	String str = in.next();
//	        	cars.add(new char[]{str.charAt(0), str.charAt(str.length() - 1)});
	        	cars.add(str.toCharArray());
	        }
	        
	        permute(cars, 0);
	        return "" + validCount;
	    }
	    
	    
//	    static int solve(List<char[]> cs)
//	    {
//	    	return 
//	    }
	    
	    
        static void permute(java.util.List<char[]> arr, int k)
        {
            for(int i = k; i < arr.size(); i++){
                java.util.Collections.swap(arr, i, k);
                permute(arr, k+1);
                java.util.Collections.swap(arr, k, i);
            }
            if (k == arr.size() -1){
            	checkValid(arr);
            }
        }
        
        static void checkValid(List<char[]> arr)
        {
        	
        	Set<Character> s = new HashSet<Character>();
        	
        	char[] prev = arr.get(0);
        	
        	char cur = 0;
        	for(char[] cc : arr)
        	{
        		for(char c : cc)
        		{
        			if(c != cur)
        			{
        				if(s.contains(c))
        				{
        					return;
        				}
        				s.add(c);
        				cur = c;
        			}
        		}
        	}
        	
        	validCount++;
        }
        
		
}
