// Code by PepeOfMath
//
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.*;

public class Problem1 {
    public static void main(String[] args) throws FileNotFoundException {
    	
        //hard code the file location
        //open file
        //get number of test cases
        File f = new File("A-large.in");
        Scanner s = new Scanner(f);
        String line = s.nextLine();
        int T = Integer.parseInt(line);
        
        //open output file
        File f2 = new File("largeoutput.txt");
        PrintWriter p = new PrintWriter(f2);
        
        
        for ( int j = 1; j <= T; j++) {
        	String ss = s.next();
        	String ans = ss.charAt(0) + "";
        	for (int i = 1; i < ss.length(); i++) {
        		if (ss.charAt(i) >= ans.charAt(0)) {
        			ans = ss.charAt(i) + ans;
        		} else {
        			ans = ans + ss.charAt(i);
        		}
        	}	
			p.println("Case #" + j + ": " + ans);
		   	
        
        }
        
        p.close();
        s.close();
    }
    
}
