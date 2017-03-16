package codejam2014;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;

public class B {
	 public static void main(String[] args) throws FileNotFoundException {
	        Scanner in = new Scanner(new File("c:\\codejam\\b\\large.in"));
	        PrintWriter out = new PrintWriter(new File("c:\\codejam\\b\\large.out"));
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
	 	
	 	static long validCount;
	 	
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
	        
	        validCount = getSubSets(cars);
	        return "" + validCount;
	    }
	    
	    
	    static long getSubSets(java.util.List<char[]> arr)
        {
	    	
	    	 Map<Character, Set<char[]>> m = new HashMap<Character, Set<char[]>>();
		    
		     Map<char[], Set<char[]>> m2 = new HashMap<char[], Set<char[]>>();
		    
		    Set<Integer> facts = new HashSet<Integer>();
	    	
	    	for(char[] s: arr)
	    	{
	    		for(char c : s)
	    		{
	    			Set<char[]> prev = m.get(c);
	    			if(prev == null)
	    			{
	    				prev = new HashSet<char[]>();
	    				m.put(c, prev);
	    			}
	    			prev.add(s);
	    		}
	    	}
	    	
	    	
	    	
	    	for(Map.Entry<Character, Set<char[]>> e : m.entrySet())
	    	{
	    		char[] start = null;
	    		
	    		char[] end = null;
	    	
	    		int fact = e.getValue().size();
	    		
	    		if(e.getValue().size() > 1)
	    		{
	    			for(char[] v : e.getValue())
	    			{
	    				if(v[0] != e.getKey())
	    				{
	    					fact --;
	    					if(start!= null)
	    					{
	    						//impossible case 0.
	    						return 0;
	    						
	    					}
	    					
	    					start = v;
	    				}
	    				
	    				else if(v[v.length - 1] != e.getKey())
	    				{
	    					fact --;
	    					if(end!= null)
	    					{
	    						//impossible case 0.
	    						return 0;
	    					}
	    					
	    					end = v;
	    					
	    				}
	    				
	    				else
	    				{
	    					for(char c : v)
	    					{
	    						if(c != e.getKey())
	    						{
	    							return 0;
	    						}
	    					}
	    					
	    				}
	    			}
	    		}
	    		
	    		fact = Math.max(fact, 1);
	    		
	    		if(fact > 1)
	    		{
	    			facts.add(fact);
	    		}
	    	}
	    	
	    	if(facts.size() > 0)
	    	{
	    		long val = 1;
	    		for(int f : facts)
	    		{
	    			val = val * modulo(f);
	    			if(val > 1000000007)
	    			{
	    				val = val % 1000000007;
	    			}
	    		}
	    		
	    		return val;
	    	}
	    	
	    	return 1;
	    	
        }
	    
	    
	    static long modulo(int n)
	    {
	    
	    	long res = 1;
		    for(int i = 1; i <= n; i++)
		    {
		    res *= i; 
		    if(res > 1000000007) // check if the number exceeds mod
		    res%=1000000007; // so as to avoid the modulo as it is costly operation 
		    }
		    
		    return res;
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
