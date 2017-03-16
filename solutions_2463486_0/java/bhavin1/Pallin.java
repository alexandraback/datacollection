import static java.lang.Integer.parseInt;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Pallin {

	boolean pending = false;
	boolean complete = false;
	public void output(BufferedWriter out, int caseNum, int string) throws IOException{
		out.write("Case #" + caseNum + ": " + string + "\n");		
	}
	public void output(BufferedWriter out, int caseNum, String string) throws IOException{
		out.write("Case #" + caseNum + ": " + string + "\n");		
	}

	
	public void solve() throws IOException{
		
		BufferedReader in = new BufferedReader(new FileReader("C:\\Users\\Bhavin\\workspace\\Test\\src\\store.in"));
		BufferedWriter out = new BufferedWriter(new FileWriter("C:\\Users\\Bhavin\\workspace\\Test\\src\\store.out"));
		
		Double max = Math.pow(10, 3);
		Double sqRoot = Math.sqrt(max);
		
		System.out.println("sqRoot: " +sqRoot);
		
		ArrayList<BigInteger> pallind = new ArrayList();
		
		int numbers = (int)Math.round(sqRoot);
		System.out.println("numbers: " +numbers);
		BigInteger square = null;
		BigInteger num = null;
		for(int i=0; i<=numbers;i++) {
			
			if(istPalindrom((i+""))) {
				
				num = new BigInteger(""+i);
				square = num.multiply(num);
				//System.out.println("check' "+num );
				if(istPalindrom(square.toString())) {
					//System.out.println(square);
					pallind.add(square);
				}
			}
		}
		
//		if(true) return;
//		for(BigDecimal i=0; i++) {
//			
//		}
		//BigInteger numbers = sqRoot.d
		int numCases = parseInt(in.readLine());
		
		for (int i = 1; i <= numCases; i++) {
			
			StringTokenizer input = new StringTokenizer(in.readLine());
			
			BigInteger low = new BigInteger(input.nextToken());
			BigInteger high = new BigInteger(input.nextToken());

			int count=0;
			
			for(BigInteger val:pallind) {
				if(val.compareTo(low) >=0 && val.compareTo(high) <=0) {
					count++;
				}
			}
			
			output(out, i, count);
		}
		out.close();
	}
	
	public static boolean istPalindrom(String original){

			String reverse="";
	 
	      int length = original.length();
	 
	      for ( int i = length - 1 ; i >= 0 ; i-- )
	         reverse = reverse + original.charAt(i);
	 
	      if (original.equals(reverse))
	         return true;
	      else
	         return false;
	}
	public static void main(String[] args) throws IOException{
		Pallin s = new Pallin();
		s.solve();
		
	}

}


