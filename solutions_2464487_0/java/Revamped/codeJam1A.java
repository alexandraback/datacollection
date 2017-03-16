import java.util.*;
import java.math.BigInteger;

public class codeJam1A
{
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		int test = sc.nextInt();
		
		
		for(int testNo = 1; testNo <= test; testNo++)
		{
			BigInteger r = new BigInteger(sc.next());
			BigInteger t = new BigInteger(sc.next());
			r = r.add(BigInteger.ONE);
			
			BigInteger area = getArea(r);
			BigInteger count = BigInteger.ZERO;
			while(t.compareTo(area) >= 0)
			{
				t = t.subtract(area);
				r = r.add(new BigInteger("2"));
				area = getArea(r);
				count = count.add(BigInteger.ONE);
			}
			System.out.printf("Case #%d: %s\n", testNo, count.toString());
		}
	}
	
	public static BigInteger getArea(BigInteger n)
	{
		BigInteger area = n.pow(2);
		area = area.subtract(n.subtract(BigInteger.ONE).pow(2));
		return area;
	}
	
}