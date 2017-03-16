import java.io.File;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;


public class GCJ2013A1 {


	public static boolean isEnough(long r,long t,long R) // inner circle, paint, res
	{
		BigInteger b_r = BigInteger.valueOf(r);
		BigInteger b_R = BigInteger.valueOf(R);
		BigInteger b_t = BigInteger.valueOf(t);
		
		BigInteger n = b_r.add(b_R).multiply(BigInteger.valueOf(2)).subtract(BigInteger.ONE).multiply(b_R);
		
//		BigInteger d = n.subtract(BigInteger.valueOf(t));
		return n.compareTo(b_t) < 1;
		
		
//		return ((2*(R+r)-1)*R <= t);
//		return ((4*(R-1)*R)/2+(2*r+1)*R <= t);
	}
	
	public static  long solveFor(long r, long t, long a, long b) {
		if (b==a+1)
			return a;

		long m = (a+b)/2;
		if (isEnough(r,t,m))
			return solveFor(r,t,m,b);
		else
			return solveFor(r,t,a,m);
	}
	
	public static void main(String[] args) throws Exception{
//		String fname = "A_example";
		String fname = "A_small";
//		String fname = "A_large";
		
		File file = new File(fname+"_in.txt");
		Scanner scanner = new Scanner(file);

		FileWriter outFile = new FileWriter(fname+"_out.txt");
		PrintWriter outp = new PrintWriter(outFile);
		
		int T = scanner.nextInt();
		
		long maxRes = 1;
		for (int i=0;i<18;i++)
			maxRes = maxRes * 10;
		
		for (int i=1;i<=T;i++)
		{
			long r = scanner.nextLong();
			long t = scanner.nextLong();
			outp.printf("Case #%d: %d\n",i,solveFor(r,t,0,maxRes));
			
//			for (int j=0;j<100;j++) System.out.printf("%d:%b ",j,isEnough(r,t,j));
//			System.out.printf("\n\n");
		}
		
		outp.close();


	}

}
