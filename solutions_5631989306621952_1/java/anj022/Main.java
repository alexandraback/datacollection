import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
	
	public static void main(String[] args) throws FileNotFoundException {
        Scanner sc=new Scanner(System.in);
        String loopS = sc.nextLine();
        
        int loops = Integer.parseInt(loopS);
        for (int j=0; j<loops; j++) {
	        String line = sc.nextLine();
	        List<Character> sol = new ArrayList<Character>(); 
	        sol.add(line.charAt(0));
	        for (int i=1; i<line.length();i++) {
	        	if (line.charAt(i) < sol.get(0).charValue()) {
	        		sol.add(line.charAt(i));
	        	} else {
	        		sol.add(0, line.charAt(i));
	        	}
	        }
	        print (j, sol);
        }
        sc.close();        

	}
	
	public static void print (int counter, List<Character> res) {
		counter++;
		System.out.println("Case #"+ counter + ": " + getStringRepresentation(res));
//    	for (int i = 0; i < res.size(); i++) {
//    		System.out.print(res.get(i)?1:0);
//    	}
//    	System.out.println("");
	}
	
	static String getStringRepresentation(List<Character> list)
	{    
	    StringBuilder builder = new StringBuilder(list.size());
	    for(Character ch: list)
	    {
	        builder.append(ch);
	    }
	    return builder.toString();
	}


}