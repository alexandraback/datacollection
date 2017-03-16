package Round_1C;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.util.Scanner;
import java.util.regex.Pattern;

public class ProblemA {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		
		Scanner scanner = new Scanner(new File("inp_1A.txt"));
		//InputStreamReader in = new InputStreamReader(new FileInputStream("inp_1A.txt"));

	    PrintWriter writer = new PrintWriter("soln_1A.txt", "UTF-8");
	    
	    int T = scanner.nextInt();
	    
	    System.out.println(T);
	    
	    for(int t=1;t<=T;t++) {
	    	long n = scanner.nextInt();
	    	int d = scanner.nextInt();
	    	
	    	double f = (double)n/(double)d;
	    	//System.out.println(f);
	    	
	    	int check=0;
	    	for(int i=0;i<=40;i++) {
	    		
	    		if(d==Math.pow(2, i)) {
	    			check=1;
	    			break;
	    		}
	    		
	    	}
	    	if(check!=1) {
    			writer.println("Case #" + t + ": " + "impossible");
    			continue;
    		}
	    	
	    	
	    	if(f == 1) {
    			writer.println("Case #" + t + ": " + 0);
    			continue;
    		}
	    	
	    	int i=0;
	    	for (i=0;i<40;i++) {
	    		
	    		if((double)n/d < 0.5 ) {
	    			n=n*2;
	    		}
	    		else {
	    			writer.println("Case #" + t + ": " + (i+1));
	    			break;
	    		}
	    	}
	    	
	    	if(i>=40) {
	    		writer.println("Case #" + t + ": " + "impossible");
	    	}
	    	
	    	
	    }
	    
	    scanner.close();
	    writer.close();

	}

}
