import java.util.*;
import java.math.*;
import java.io.*;

public class codeJamC
{
	static BigInteger[] pS;
	public static void main(String args[]) throws IOException
	{
		generate();
		
		Scanner sc = new Scanner(System.in);
		int testCase = sc.nextInt();
		for(int testNo = 1; testNo <= testCase; testNo++)
		{
			BigInteger from = new BigInteger(sc.next());
			BigInteger to = new BigInteger(sc.next());
			
			int fromI = 0;
			int toI = 47;
			while(pS[fromI].compareTo(from) < 0 && fromI < 65)
			{
				fromI++;
			}
			while(pS[toI].compareTo(to) > 0 && toI > -1)
			{
				toI--;
			}
			System.out.println("Case #"+testNo+": " + (toI-fromI + 1));
		}
		
	}
	public static void generate() throws IOException
	{
		pS = new BigInteger[48];
		pS[0] = BigInteger.ONE;
		Scanner input = new Scanner(new File("C-pregen.txt"));
		for(int i = 1; i < 48; i++)
		{
			pS[i] = new BigInteger(input.next());
		}
	}
}