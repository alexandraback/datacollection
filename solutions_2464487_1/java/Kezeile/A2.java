import java.util.*;
import java.io.*;
import java.math.BigInteger;
public class A2
{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int tt = sc.nextInt();
		for(int kk=1;kk<=tt;kk++)
		{
			long r = sc.nextLong();
			long t = sc.nextLong();
			BigInteger rr = new BigInteger(r+"");
			BigInteger r1 = rr.add(BigInteger.ONE);
			BigInteger t1 = new BigInteger(t+"");
			BigInteger two = new BigInteger("2");
			BigInteger four = new BigInteger("4");
			BigInteger eight = new BigInteger("8");
			BigInteger aa1 = (r1.pow(2)).subtract(rr.pow(2));
			BigInteger d = (aa1.pow(2)).subtract(aa1.multiply(four)).add(four).add(eight.multiply(t1));
			BigInteger nn = (two.subtract(aa1).add(bigIntSqRootFloor(d))).divide(four);
			System.out.printf("Case #%d: %s\n",kk,nn.toString());
			
			//long a1 = Long.parseLong(aa1.toString());
			//System.out.printf("%d\n",a1);
			//double n = (double)(((2.0-a1) + (Math.sqrt((a1*a1*1.0) - (4*a1) + 4.0 + (8*t))))/(4.0));
			//System.out.printf("Case #%d: %.2f\n",kk,n);
		}
	}

	public static BigInteger bigIntSqRootFloor(BigInteger x)
        throws IllegalArgumentException {
    
    if (x == BigInteger.ZERO || x == BigInteger.ONE) {
        return x;
    } // end if
    BigInteger two = BigInteger.valueOf(2L);
    BigInteger y;
    // starting with y = x / 2 avoids magnitude issues with x squared
    for (y = x.divide(two);
            y.compareTo(x.divide(y)) > 0;
            y = ((x.divide(y)).add(y)).divide(two));
    return y;
}
}
