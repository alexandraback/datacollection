import java.util.Scanner;
import java.math.*;

public class problemA {
public static void main(String[] args)
{
	Scanner sc = new Scanner(System.in);
	int numcases = sc.nextInt();
	for(int casenum=1;casenum<=numcases;casenum++)
	{
		BigDecimal r = new BigDecimal(sc.next());
		BigDecimal t = new BigDecimal(sc.next());
		
//		long r = sc.nextLong();
//		long t = sc.nextLong();
		BigDecimal two = new BigDecimal("2");
		sc.nextLine();
		
		double foo = Math.sqrt(((r.multiply(two).subtract(BigDecimal.ONE).pow(2).add(t.multiply(two.pow(3))))).divide(two.pow(4)).doubleValue());
		//long foo = (long) Math.sqrt((2*r-1)*(2*r-1) - 8*t);
//		double bar = 1 - 2*r + foo;
		double bar = .25 - r.divide(two).doubleValue() + foo;
		
		System.out.println("Case #"+casenum+": "+((long)Math.floor(bar)));
	}
}
}
