import java.io.*;
import java.util.*;
import java.math.*;

//         java -jar cj.jar test.txt
//         java -jar cj.jar A-small.practice.in.txt > as.txt
//         java -jar cj.jar A-large.practice.in.txt > al.txt

public class A2 {
	
	public static void main(String[] args){
		assert(args.length == 1);
		parseTXT(args[0]);
	}
	
	private static void parseTXT(String file){
 		try{
			BufferedReader infile = new BufferedReader(new FileReader(file));
			int T = Integer.parseInt(infile.readLine()); // number of test cases
			for(int i = 0; i < T; i++){
				//parse test case to get input data for getReult function
				String[] s = infile.readLine().split("\\s+");
				double c, f, x;
				c= Double.parseDouble(s[0]);
				f= Double.parseDouble(s[1]);
				x= Double.parseDouble(s[2]);
				// print result
				int id = i+1;
				System.out.printf("Case #%d: %2.7f\n", id, getResult(c, f, x, 2.0));
				
			}
			infile.close();
		}catch(IOException e){
			System.err.println("check input file " + file );
		}
	}
	
	private static double getResult(double c, double f, double x, double in){
		if((x-c)/in < x/(in+f)) return notBuy(x, in);
		else return Math.min(notBuy(x, in), buy(c, in) + getResult(c, f, x, f+in));
	}
	
	private static double notBuy(double x, double in){
		return x/in;
	}
	
	private static double buy(double c, double in){
		return c/in;
	}

}




