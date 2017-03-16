package Round1C;
import java.io.*;
import java.lang.reflect.Array;
import java.util.*;

import Round1A.Q1.SortedPair;
/**
 * @author Amit Jacob
 *
 */
public class Q1 {

	/**
	 * @param args - Input File Path
	 * @throws IOException 
	 */
	private class Fraction { 
		int numerator; 
		int denominator; 
		public Fraction(){}
		public void reduce() { 
			int n = numerator; 
			int d = denominator; 
	
			while (d != 0) { 
			int t = d; 
			d = n % d; 
			n = t; 
			} 
	
			int gcd = n; 
	
			numerator /= gcd; 
			denominator /= gcd; 
		} 
	}
	public static void main(String[] args) throws IOException {
		//Reading the input file:
		String path=args[0];
		File file = new File(path);
		BufferedReader br = new BufferedReader(new FileReader(file));
		String line;
		//Writing the output file:
		File fileout = new File("output.txt");
		fileout.createNewFile();
	    FileWriter writer = new FileWriter(fileout);
	    //var declarations:
	    String[] nums;
	    int P,Q;
	    Fraction f = new Q1().new Fraction();
	    double log2 = Math.log(2);
	    //Begin reading:
  		line=br.readLine();
  		int nTests = Integer.parseInt(line);
  		for(int j=0;j<nTests;++j)
  		{
  			line=br.readLine();
  			nums=line.split("/");
  			P=Integer.parseInt(nums[0]);
  			Q=Integer.parseInt(nums[1]);
  			f.numerator=P;
  			f.denominator=Q;
  			f.reduce();
  			P=f.numerator;
  			Q=f.denominator;
  			if(!checkPowerOfTwo(Q))
  			{
  				writer.write("Case #"+(j+1)+": impossible\n");
  			}
  			else
  			{
  				double d=(Math.log(Q)-Math.log(P))/log2;
  				writer.write("Case #"+(j+1)+": "+(int)Math.ceil(d)+"\n");
  			}
  			writer.flush();
  		}
  		writer.close();
	}
	private static boolean checkPowerOfTwo(int number){
		if(number<=0)
			return false;
		return ((number&(number-1))==0);
	}
	
}
