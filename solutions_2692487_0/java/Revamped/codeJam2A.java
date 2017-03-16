import java.util.*;
import java.math.BigInteger;

public class codeJam2A
{
	static ArrayList<BigInteger> toEat;
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		int testCase = sc.nextInt();
		
		for(int caseNo = 1; caseNo <= testCase; caseNo++)
		{
			BigInteger mySize = new BigInteger(sc.next());
			int motes = sc.nextInt();
			toEat = new ArrayList<BigInteger>();
			
			for(int i = 0; i < motes; i++)
				toEat.add(new BigInteger(sc.next()));
			
			Collections.sort(toEat);
			
			int ans = recurse(mySize ,0, 0);
			
			System.out.printf("Case #%d: %d\n", caseNo, ans);
		}
	}
	
	public static int recurse(BigInteger mySize, int pos, int count)
	{
		if(pos >= toEat.size())
			return count;
		if(toEat.get(pos).compareTo(mySize)<0)
		{
			return recurse(mySize.add(toEat.get(pos)), pos+1, count);
		}
		else if(!mySize.equals(BigInteger.ONE))
		{
			int add = recurse(mySize.add(mySize).subtract(BigInteger.ONE), pos, count+1);
			int remove = recurse(mySize, pos+1, count+1);
			return Math.min(add, remove);
		}
		else
		{
			int remove = recurse(mySize, pos+1, count+1);
			return remove;
		}
	}
}