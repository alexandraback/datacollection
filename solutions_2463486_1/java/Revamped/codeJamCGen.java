import java.util.*;
import java.math.*;

public class codeJamCGen 
{
	public static void main(String args[])
	{
		BigInteger b = new BigInteger("1");
		BigInteger curr = new BigInteger("1");
		while(curr.compareTo((new BigInteger("10")).pow(8)) < 0)
		{
			b = b.add(curr.multiply(new BigInteger("2"))).add(BigInteger.ONE);
			curr = curr.add(BigInteger.ONE);
			if(check(b))
			{
				//System.out.println(b);
				if(check(sqrtN(b)))
					System.out.println(b);
			}
		}
	}
	public static boolean check(BigInteger c)
	{
		String s = c.toString();
		for(int i = 0; i < s.length()/2; i++)
		{
			if(s.charAt(i) != s.charAt(s.length()-1-i))
				return false;
		}
		return true;
	}
	
	//taken from http://social.msdn.microsoft.com/Forums/en-US/csharplanguage/thread/c13d3fec-21d9-4f74-92de-a6132d5e9915/
	public static BigInteger sqrtN(BigInteger N)
    {
      BigInteger G = new BigInteger((N.shiftRight((N.bitLength() + 1) / 2)).toString());
      BigInteger LastG = null;
      BigInteger One = new BigInteger("1");
      while (true)
      {
        LastG = G;
        G = N.divide(G).add(G).shiftRight(1);
        int i = G.compareTo(LastG);
        if (i == 0) return G;
        if (i < 0)
        {
          if (LastG.subtract(G).compareTo(One) == 0)
            if (G.multiply(G).compareTo(N) < 0 && LastG.multiply(LastG).compareTo(N) > 0) return G;
        }
        else
        {
          if (G.subtract(LastG).compareTo(One) == 0)
            if (LastG.multiply(LastG).compareTo(N) < 0 && G.multiply(G).compareTo(N) > 0) return LastG;
        }
      }
    }
}