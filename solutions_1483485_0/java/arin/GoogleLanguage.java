package qual;

import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class GoogleLanguage {

	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		
	        Map<Character, Character> mapping = new HashMap<Character, Character>();
	        mapping.put('y','a');
	        mapping.put('e','o');
	        mapping.put('q','z');
	        mapping.put('j','u');
	        mapping.put('p','r');
	        mapping.put('m','l');
	        mapping.put('s','n');
	        mapping.put('l','g');
	        mapping.put('c','e');
	        mapping.put('k','i');
	        mapping.put('d','s');
	        mapping.put('x','m');
	        mapping.put('v','p');
	        mapping.put('n','b');
	        mapping.put('r','t');
	        mapping.put('i','d');
	        mapping.put('f','c');
	        mapping.put('w','f');
	        mapping.put('b','h');
	        mapping.put('u','j');
	        mapping.put('o','k');
	        mapping.put('g','v');
	        mapping.put('t','w');
	        mapping.put('a','y');
	        mapping.put('h','x');
	        mapping.put('z','q');
	        
	        
			Scanner in = new Scanner(System.in);
	        
			int T = in.nextInt();
			
			in.nextLine();
			
		    for(int t=0;t<T;t++)
		    {
		    	String s = in.nextLine();
		    	StringBuffer buffer = new StringBuffer();
		    	for (char c : s.toCharArray()) 
		    	{
		    		if(c!=' ')
		    		{
		    			buffer.append(mapping.get(c));
		    		}
		    		else
		    		{
		    			buffer.append(c);
		    		}
				}
		    	
		    	System.out.println("Case #" + (t+1) + ":" + " " + buffer.toString());
		    	
		    }		  
		    
	}

}
