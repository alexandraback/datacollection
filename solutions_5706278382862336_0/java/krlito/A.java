import java.math.BigInteger;
import java.util.Scanner;


public class A {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		
		for(int t = 1; t<= T; t++)
		{
			String[] a = in.next().split("/");
			BigInteger p = new BigInteger(a[0]);
			BigInteger q = new BigInteger(a[1]);
			
			int x = 1;
			while(x <= 40 && p.shiftLeft(x).remainder(q) != BigInteger.ZERO) x++;
		
			if(x > 40)
				System.out.println("Case #" + t + ": impossible");
			else
			{
				BigInteger r = p.shiftLeft(x).divide(q);
				while(!r.equals(BigInteger.ONE))
				{
					r = r.shiftRight(1);
					x --;
				}
				System.out.println("Case #" + t + ": " + x);
			}
		}

	}

}
