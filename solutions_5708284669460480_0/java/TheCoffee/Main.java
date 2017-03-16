import java.io.*;
import java.util.*;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Main
{
	public static void main(String args[]) throws Exception
	{
		BufferedReader br = new BufferedReader(new FileReader("B-small-attempt0.in"));
		
		int cases = Integer.parseInt(br.readLine());
		
		for(int i = 0; i < cases; i++)
		{
			System.out.print("Case #" + (i+1) + ": ");
			
			StringTokenizer st = new StringTokenizer(br.readLine());
			st.nextToken();
			st.nextToken();
			int length = Integer.parseInt(st.nextToken());
			
			String keyboard = br.readLine();
			String target = br.readLine();
			
			process(keyboard, target, length);
		}
	}
	
	static int maxBananas;
	static List<Integer> bananaList;
	
	public static void process(String keyboard, String target, int length)
	{
		// RESET GLOBALS
		maxBananas = 0;
		bananaList = new ArrayList<Integer>();
		
		// PRINT INPUT
		//System.out.println(keyboard);
		//System.out.println(target);
		//System.out.println("" + length);
		
		// GET UNIQUE KEYBOARD
		//String uniqueKeyboard = removeDuplicates(keyboard);
		
		// GET MAX TIMES TARGET CAN APPEAR IN LENGTH (sets: maxBananas)
		printAllKLength(keyboard.toCharArray(), length, target);
		
		//System.out.println("MAX BANANAS: " + maxBananas);
		double taken = calculateAverage(bananaList);
		//System.out.println("TAKEN: " + taken);
		
		double answer = maxBananas - taken;
		System.out.println(answer);
	}
	
	static String removeDuplicates(String s)
	{
	    StringBuilder noDupes = new StringBuilder();
	    for (int i = 0; i < s.length(); i++) {
	        String si = s.substring(i, i + 1);
	        if (noDupes.indexOf(si) == -1) {
	            noDupes.append(si);
	        }
	    }
	    return noDupes.toString();
	}
	
    static void printAllKLength(char set[], int k, String target) {
        int n = set.length;        
        printAllKLengthRec(set, "", n, k, target);
    }
 
    static void printAllKLengthRec(char set[], String prefix, int n, int k, String target) {
         
        // Base case: k is 0, print prefix
        if (k == 0) {
            //System.out.println(prefix);
            // WE HAVE THE STRING
            // Check how many times target appears in it.
            int lastIndex = 0;
            int count = 0;

            while(lastIndex != -1){

                   lastIndex = prefix.indexOf(target, lastIndex);

                   if( lastIndex != -1){
                         count++;
                         lastIndex++;
                  }
            }
            
            bananaList.add(count);
            if(count > maxBananas)
            {
            	maxBananas = count;
            }
            return;
        }
 
        // One by one add all characters from set and recursively 
        // call for k equals to k-1
        for (int i = 0; i < n; ++i) {
            String newPrefix = prefix + set[i]; 
             
            printAllKLengthRec(set, newPrefix, n, k - 1, target); 
        }
    }
    
    static double calculateAverage(List<Integer> marks)
    {
		Integer sum = 0;
		if(!marks.isEmpty())
		{
			for (Integer mark : marks)
			{
				sum += mark;
			}
			return sum.doubleValue() / marks.size();
	  }
	  return sum;
	}
    
}