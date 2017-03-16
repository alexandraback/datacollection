import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.math.BigInteger;
import java.util.Date;
import java.util.Scanner;


public class CodeJam {

	/**
	 * @param args
	 */
	
	static File in=new File("C:/Users/SHANTANU/Documents/codejam/inp.in");
	static File out=new File("C:/Users/SHANTANU/Documents/codejam/output.txt");
	
	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		BufferedWriter bw=new BufferedWriter(new FileWriter(out));
		Scanner sc=new Scanner(in);
		
		int count=sc.nextInt();
		long max=0;
		for(int i=1; i<=count; i++){
			max=0;
			
			long r=sc.nextLong(), t=sc.nextLong();
			long t1=2*r-1;
			BigInteger t2=new BigInteger(""+t1);
			BigInteger b1=t2.multiply(t2), b2=new BigInteger(""+t);
			b2=b2.multiply(new BigInteger("8"));
			b1=b1.add(b2);
			long te=sqrt(b1).longValue();
			max=(long) ((-1*t1+te)/4);
			bw.write("Case #"+i+": "+max);
			
			if(i!=count)
				bw.newLine();
		}
		bw.close();
		sc.close();
	}
	
	public static BigInteger sqrt(BigInteger n)
	{
	    {
	        final int bitLength = n.bitLength();
	        BigInteger root = BigInteger.ONE.shiftLeft(bitLength / 2);

	        while (!isSqrt(n, root))
	        {
	            root = root.add(n.divide(root)).divide(TWO);
	        }
	        return root;
	    }
	    
	}
	
	private static final BigInteger TWO = BigInteger.valueOf(2);
	
	private static boolean isSqrt(BigInteger n, BigInteger root)
	{
	    final BigInteger lowerBound = root.pow(2);
	    final BigInteger upperBound = root.add(BigInteger.ONE).pow(2);
	    return lowerBound.compareTo(n) <= 0
	        && n.compareTo(upperBound) < 0;
	}
}
