package jam;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Writer;
import java.util.ArrayList;

public class Cookie {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub

		 	File file=new File("B-large.in");
	        Writer output = null;
	        File out=new File("B-large.out");
	        output = new BufferedWriter(new FileWriter(out));
	        BufferedReader fileIn = new BufferedReader(new FileReader(file));
	        String fileLine,delims,outs;
	        String[] tokens;
	        int cases,i;
	        double c,x,f;
	        String ans;
	        
	       
	        fileLine=fileIn.readLine();
	        cases = Integer.parseInt(fileLine);
	        delims = "[ ]+";
	        System.out.println("Cases = "+cases);
	        
	        for	(i=0;i<cases;++i)
	        {
	        output.write("Case #");
	        output.write(Integer.toString(i+1));
	        output.write(": ");
	    	fileLine=fileIn.readLine();
	    	tokens = fileLine.split(delims);
	    	c = Double.parseDouble(tokens[0]);
	    	f = Double.parseDouble(tokens[1]);
	    	x = Double.parseDouble(tokens[2]);
	    	
	    	ans = solve(c,f,x);
	        output.write(ans);
	        output.write("\r\n");
	        System.out.println(ans);
	        }
	        output.close();

		
		
	}

	private static String solve(double c, double f, double x) {
		// TODO Auto-generated method stub
		double r = 2,time = 0;
						
		while(x/r > c/r + x/(r+f) )
		{
			time = time + (c/r);
			r = r+f;
		
		}
		
		time = time + x/r;	
		return Double.toString(time);
	}

}
