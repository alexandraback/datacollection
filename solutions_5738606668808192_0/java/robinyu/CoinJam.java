import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.lang.String;
import java.lang.StringBuffer;
import java.lang.Long;
import java.math.BigInteger;

public class CoinJam {
	
    public static boolean odd(BigInteger val)
    {
        return (!val.mod(new BigInteger("2")).equals(BigInteger.ZERO));
    }
    
    public static final BigInteger sqrt(BigInteger n)
    {
        BigInteger a = BigInteger.ONE;
        BigInteger b = new BigInteger(n.shiftRight(5).add(new BigInteger("8")).toString());
        while(b.compareTo(a) >= 0)
        {
            BigInteger mid = new BigInteger(a.add(b).shiftRight(1).toString());
            if(mid.multiply(mid).compareTo(n) > 0) b = mid.subtract(BigInteger.ONE);
            else a = mid.add(BigInteger.ONE);
        }
        return a.subtract(BigInteger.ONE);
    }

    private static final BigInteger smallestPF(BigInteger n)
    {
        BigInteger root = sqrt(n);
            
        long maxlimit = root.compareTo(BigInteger.valueOf(Long.MAX_VALUE)) > 0 ? Long.MAX_VALUE : root.longValue();
            
        for( long i = 2; i <= maxlimit ; i++)
        {
            if( n.mod(BigInteger.valueOf(i)).equals(BigInteger.ZERO) )
            {
                return BigInteger.valueOf(i);
            }
        }
        // it's prime!
        return n;
    }
	
	public static void main(String[] args) throws IOException
    {
		InputStreamReader ir = new InputStreamReader(System.in);
		BufferedReader in = new BufferedReader(ir);
		
		int len, coins;
		
        int p[] = new int [2];
		String line = in.readLine();
		String[] strs = line.trim().split("\\s+");
		for (int i = 0; i < 2; i++)
		{
			p[i] = Integer.parseInt(strs[i]);
		}
		
        len = p[0];
        coins = p[1];
		
        StringBuffer temp = new StringBuffer(len);
        temp.append("1");
        for (int i = 0; i < len-1; i++)
        {
            temp.append("0");
        }
        BigInteger d = new BigInteger(temp.toString(), 2);
        
        while (coins > 0)
        {   
            d = d.add(BigInteger.valueOf(1));
            if (odd(d))
            {
                String s = d.toString(2);
                
                BigInteger b2 = new BigInteger(s.toString(), 2);
                BigInteger b3 = new BigInteger(s.toString(), 3);
                BigInteger b4 = new BigInteger(s.toString(), 4);
                BigInteger b5 = new BigInteger(s.toString(), 5);
                BigInteger b6 = new BigInteger(s.toString(), 6);
                BigInteger b7 = new BigInteger(s.toString(), 7);
                BigInteger b8 = new BigInteger(s.toString(), 8);
                BigInteger b9 = new BigInteger(s.toString(), 9);
                BigInteger b10 = new BigInteger(s.toString(), 10);
                
                if (b2.equals(smallestPF(b2))) continue;
                if (b3.equals(smallestPF(b3))) continue;
                if (b4.equals(smallestPF(b4))) continue;
                if (b5.equals(smallestPF(b5))) continue;
                if (b6.equals(smallestPF(b6))) continue;
                if (b7.equals(smallestPF(b7))) continue;
                if (b8.equals(smallestPF(b8))) continue;
                if (b9.equals(smallestPF(b9))) continue;
                if (b10.equals(smallestPF(b10))) continue;
                
                System.out.printf(s);
                System.out.printf(" ");
                System.out.printf((smallestPF(b2)).toString());
                System.out.printf(" ");
                System.out.printf((smallestPF(b3)).toString());
                System.out.printf(" ");
                System.out.printf((smallestPF(b4)).toString());
                System.out.printf(" ");
                System.out.printf((smallestPF(b5)).toString());
                System.out.printf(" ");
                System.out.printf((smallestPF(b6)).toString());
                System.out.printf(" ");
                System.out.printf((smallestPF(b7)).toString());
                System.out.printf(" ");
                System.out.printf((smallestPF(b8)).toString());
                System.out.printf(" ");
                System.out.printf((smallestPF(b9)).toString());
                System.out.printf(" ");
                System.out.printf((smallestPF(b10)).toString());
                System.out.printf("\n");
                coins--;
            }
        }
	}
}
