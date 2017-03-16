package Round_1C;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigInteger;
import java.util.Scanner;

public class Elves2 {
	
	public static int f(BigInteger p, BigInteger q){
		BigInteger temp = new BigInteger(q.toString());
		
			// Test for possibility
			while(temp.and(BigInteger.ONE).equals(BigInteger.ZERO)){
				temp = temp.shiftRight(1);
			}
			if(!temp.equals(BigInteger.ONE)){
				return -1;
			}
		
		int count = 0;
		while(q.and(BigInteger.ONE).equals(BigInteger.ZERO)){
			q = q.shiftRight(1);
			count++;
			if(p.compareTo(q) >= 0){
				return count;
			}
		}
		
		return count;
	}
	
	public static void main(String[] args) 
	{
		try{
			String readFrom = "1C/A-small-attempt0.in";
			Scanner sc = new Scanner(new File(readFrom));
			FileWriter out = new FileWriter(new File("1C/A-small.out"));
			
		
			
			int testCases = sc.nextInt();
			//System.out.println(testCases);
			String[] ss;
			BigInteger GCD, p, q;
			int res;
			for(int k=1; k<=testCases; k++)
			{
				ss = (sc.next()).split("/");
				p = new BigInteger(ss[0]);
				q = new BigInteger(ss[1]);
				GCD = p.gcd(q);
				p = p.divide(GCD);
				q = q.divide(GCD);
				
				
				res = f(p,q);
				
				System.out.println("Case #" + k + ": " + ((res == -1) ? "impossible" : res));
				out.write("Case #" + k + ": " + ((res == -1) ? "impossible" : res) + "\n");
			}

			out.close();
		}catch(IOException e)
		{
			System.out.println("IO error");
		}

	}
}
