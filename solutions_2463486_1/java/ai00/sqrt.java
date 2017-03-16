import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.StringTokenizer;


public class sqrt {

	/**
	 * @param args
	 */
	public static BigInteger sqrt(BigInteger a){
		BigInteger s = BigInteger.ZERO;
		BigInteger t = a;
		while (s.compareTo(t) != 0){
			BigInteger mid = s.add(t).divide(BigInteger.valueOf(2)).add(BigInteger.ONE);
			if (mid.pow(2).compareTo(a) <= 0) s = mid;
			else t = mid.subtract(BigInteger.ONE);
			
		}
		return s;
		
	}
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		//BigInteger a = new BigInteger("123");
		//System.out.println(sqrt(a));
		BufferedReader f = new BufferedReader(new FileReader("in2.txt"));
        int n = Integer.parseInt(f.readLine());
// Use StringTokenizer vs. readLine/split -- lots faster
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("in.txt")));
        out.println(n);
        for (int i = 0; i < n; ++i){
        	String[] input = f.readLine().split(" ");
        	out.println(sqrt(new BigInteger(input[0]).subtract(BigInteger.ONE))+ " " + sqrt(new BigInteger(input[1])));
        }
        out.close();
		//StringTokenizer st = new StringTokenizer(f.readLine());
	}

}
