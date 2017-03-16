import java.math.*;
import java.io.*;
import java.util.*;

public class checker
{
	public static void main(String[] args) throws Exception
	{
		BufferedReader in = new BufferedReader(new FileReader(new File("out")));
		in.readLine(); // skip the Case #1
		int num = Integer.parseInt(args[args.length-1]);
		for (int i = 0;i < num;i++)
		{
			String[] s = in.readLine().split(" ");
			boolean ok = true;
			for (int j = 1;j < s.length;j++)
			{
				BigInteger val = new BigInteger(s[0], j+1);
				BigInteger oth = new BigInteger(s[j]);
				if (val.remainder(oth) != BigInteger.ZERO)
				{
					System.out.println(s[0]+" in base "+(j+1)+" is not divisible by "+oth+"!");
					System.exit(0);
				}
				if (val == oth)
				{
					System.out.println(s[0]+" in base "+(j+1)+" is equal to "+oth+"!");
					System.exit(0);
				}
			}
		}
		System.out.println("Seems legit");
	}
}
