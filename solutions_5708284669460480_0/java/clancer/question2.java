package gcj;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.*;


public class question2 {

	static ArrayList<String> p = new ArrayList<String>();
	
	public static void permutation(String str, int length) { 
	    permutation("", str, length); 
	}

	private static void permutation(String prefix, String str, int length) {
	    if (length == 0) p.add(prefix);
	    else {
	        for (int i = 0; i < str.length(); i++)
	            permutation(prefix + str.charAt(i), str, length-1);
	    }
	}
	
	public static void main(String[] args) throws FileNotFoundException, IOException {	
		String file = "small2.in";
		
		try (BufferedReader br = new BufferedReader(new FileReader(file))) {
		    String line;
		    Integer N = Integer.parseInt(br.readLine());
		    for (int n = 0; n < N; n++) {
		    	String[] KLS = br.readLine().split(" ");
		    	Integer K = Integer.parseInt(KLS[0]);
		    	Integer L = Integer.parseInt(KLS[1]);
		    	Integer S = Integer.parseInt(KLS[2]);
		    	
		    	String keys = br.readLine();
		    	String target = br.readLine();
		    	
		    	p = new ArrayList<String>();
		    	
		    	permutation(keys, S);
		    	
		    	float sum = 0;
		    	float count = 0;
		    	int max = 0;
		    	for (String word : p) {
		    		int num_b = 0;
		    		for (int i = 0; i < word.length()-L+1; i++) {
		    			if (word.substring(i, i+L).equals(target)) {
		    				num_b++;
		    			}
		    		}
		    		sum = sum + num_b;
		    		count += 1;
		    		if (num_b > max) {
		    			max = num_b;
		    		}
		    	}
		    	
		    	float keep = max - (sum/count);
		    	
		    	
		    	double factor = 1e7; // = 1 * 10^5 = 100000.
		    	double result = Math.round(keep * factor) / factor;

		    	System.out.println("Case #" + (n+1) + ": " + result);	

		    }
		}
		

	}
	
	
}
