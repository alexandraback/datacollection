import java.util.*;
import java.io.*;
import java.math.BigInteger;

public class a {
	public static void main(String[] args) throws Exception{
		Scanner reader = new Scanner(System.in);
		PrintWriter out = new PrintWriter(new File("bbig.out"));
		int times = reader.nextInt();
		for(int t = 1; t <= times; t++){
			BigInteger r = BigInteger.valueOf(reader.nextLong());
			BigInteger p = BigInteger.valueOf(reader.nextLong());
			
			BigInteger[][] base = {{BigInteger.ONE,BigInteger.valueOf(2),BigInteger.ZERO},
					         {BigInteger.ZERO,BigInteger.ONE,BigInteger.ZERO},
					         {BigInteger.valueOf(2),BigInteger.ONE,BigInteger.ONE}};
			BigInteger[][] sol = {{r},{BigInteger.ONE},{BigInteger.ZERO}};
			
			long low = 0;
			long high = (long)1e15;
			long best = 0;
			while(high > low){
				long mid = (low + high)/2;
				BigInteger[][] pow = fastExpo(base,mid);
				
				BigInteger[][] res = mult(pow,sol);
				if(res[2][0].compareTo(p) > 0){
					high = mid;
				}else{
					low = mid+1;
					best = Math.max(best, mid);
				}
			}
			
			if(best == (long)1e15 - 1)
				System.out.println("!");
			
			out.println("Case #"+t+": "+best);
		}
		out.close();
	}
	
	public static BigInteger[][] mult (BigInteger[][] a, BigInteger[][] b) {
		BigInteger[][] x = new BigInteger[a.length][b[0].length];
		
		for(int r = 0; r < x.length; r++)
			for(int c = 0; c < x[0].length; c++)
				x[r][c] = BigInteger.ZERO;
		
		for (int r=0; r<x.length; r++)
			for (int c=0; c<x[r].length; c++)
				for (int i=0; i<a[0].length; i++)
					x[r][c] = x[r][c].add(a[r][i].multiply(b[i][c]));
		
		return x;
	}
	
	public static BigInteger[][] fastExpo (BigInteger[][] m, long pow) {
		if (pow == 0) {
			BigInteger[][] i = new BigInteger[m.length][m.length];
			for(BigInteger[] b:i) Arrays.fill(b,BigInteger.ZERO);
			for (int t=0; t<i.length; t++)
				i[t][t] = BigInteger.ONE;
			return i;
		}
		
		if (pow%2 == 1)
			return mult(m, fastExpo(m, pow-1));
		
		BigInteger[][] temp = fastExpo(m, pow/2);
		return mult(temp, temp);
	}
}
