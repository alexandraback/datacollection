import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigInteger;
import java.util.Scanner;


public class Bullsey {
	static Scanner in;
	static BigInteger r,t;
	static BigInteger two = new BigInteger("2");
	static BigInteger one = new BigInteger("1");
	
	static BufferedWriter out;
	static BigInteger bs(BigInteger low,BigInteger high) {
		BigInteger med = low.add(high).divide(two);
		BigInteger t_val = med.multiply(med).multiply(new BigInteger("2")).add((two.multiply(r).subtract(one)).multiply(med));
		if(low.compareTo(high)==0)
			return low;
		if(t_val.compareTo(t)==0 ||t_val.compareTo(t)>0)
			return bs(low,med);
		return bs(med.add(one),high);
	}
	/**
	 * @param args
	 * @throws IOException 
	 * @throws FileNotFoundException 
	 */
	static void process(int test) throws IOException {
		out.write("Case #"+test+": ");
		r = new BigInteger(in.next());
		t = new BigInteger(in.next());
		BigInteger n = bs(one,new BigInteger("2000000000"));
		BigInteger tmp = n.multiply(n).multiply(new BigInteger("2")).add((two.multiply(r).subtract(one)).multiply(n));
		if(tmp.compareTo(t)==0){
			out.write(n.toString());
		}
		else {
			out.write(n.subtract(one).toString());
		}
		out.newLine();
	}
	
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		in = new Scanner(new FileReader("A-small-attempt0.in"));
		out = new BufferedWriter(new FileWriter("out.txt"));
		int T = in.nextInt();
		for(int t=1;t<=T;t++)
			process(t);
		out.close();
	}

}
