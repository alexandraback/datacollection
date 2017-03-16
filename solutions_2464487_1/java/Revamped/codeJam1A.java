import java.util.*;
import java.math.BigInteger;

public class codeJam1A
{
	static BigInteger area1;
	static BigInteger FOUR, TWO, t;
	
	public static void main(String args[])
	{
		FOUR = new BigInteger("4");
		TWO = new BigInteger("2");
		Scanner sc = new Scanner(System.in);
		int test = sc.nextInt();
		
		
		for(int testNo = 1; testNo <= test; testNo++)
		{
			BigInteger r = new BigInteger(sc.next());
			t = new BigInteger(sc.next());
			r = r.add(BigInteger.ONE);
			
			area1 = getArea(r);
			BigInteger area = getArea(r);
			BigInteger count = BigInteger.ZERO;
			
			BigInteger max = t.divide(FOUR);
			

			
			// while(t.compareTo(area) >= 0)
			// {
				// t = t.subtract(area);
				// r = r.add(new BigInteger("2"));
				// area = getArea(r);
				// System.out.println("Area " + area + " | " + r);
				// count = count.add(BigInteger.ONE);
			// }
			System.out.printf("Case #%d: %s\n", testNo, binarySearch(BigInteger.ONE, max).toString());
		}
	}
	
	public static BigInteger getArea(BigInteger n)
	{
		BigInteger area = n.pow(2);
		area = area.subtract(n.subtract(BigInteger.ONE).pow(2));
		return area;
	}
	
	public static BigInteger binarySearch(BigInteger from, BigInteger to)
	{
		if(from.compareTo(to) >= 0)
		{
			if(getSum(BigInteger.ONE, to).compareTo(t) > 0)
				return to.subtract(BigInteger.ONE);
			else
				return to;
		}	
		BigInteger mid = from.add(to).divide(TWO);
		BigInteger sum = getSum(BigInteger.ONE, mid);
		if(sum.compareTo(t) == 0)
			return mid;
		else if(sum.compareTo(t) < 0)
			return binarySearch(mid.add(BigInteger.ONE), to);
		else
			return binarySearch(from, mid.subtract(BigInteger.ONE));
	}
	
	public static BigInteger getSum(BigInteger a1, BigInteger a2)
	{
		BigInteger sum = a2.multiply(getTerm(a1).add(getTerm(a2))).divide(TWO);
		return sum;
	}
	
	public static BigInteger getTerm(BigInteger n)
	{
		BigInteger term = area1.add(n.subtract(BigInteger.ONE).multiply(FOUR));
		return term;
	}
	
}