import java.io.*;
import java.math.*;
import java.util.*;

public class C
{
	static ArrayList<BigInteger> nums;
	static ArrayList<BigInteger> nums2;
	
	static boolean isPal( BigInteger x )
	{
	    String dig = x.toString();

	    int m = dig.length();
	    for ( int i = 0; i < m/2; i ++ )
	        if ( dig.charAt(i) != dig.charAt(m - 1 - i) )
	            return false;

	    return true;
	}

	static void initImpares(String d, int size, int n1s)
	{
	    if ( d.length() > size/2 )
	    {
	    	int nc = 0;

	        while (nc < d.length() && d.charAt(nc) == '0') nc++;
	        
	        for ( int i = d.length() - 2 ; i >= nc; i -- )
	            d += d.charAt(i);
	        
	        BigInteger N = new BigInteger(d);
	        BigInteger N2;
	        
	        N2 = N.pow(2);

	        if ( isPal(N2) )
	        {
	            nums.add(N2);
	            nums2.add(N);
	        }

	        return;
	    }
	    
	    if ( d.length() == size/2 )
	    	for ( char i = '0'; i <= '2'; i ++ )
	    		initImpares(d + i, size, n1s + ((i == '1')?1:0));
	    else
	    	for ( char i = '0'; i <= '1'; i ++ )
	    		if ( n1s == 4 && i == '1' )
	    			continue;
	    		else
	    			initImpares(d + i, size, n1s + ((i == '1')?1:0));
	}

	static void initPares(String d, int size, int n1s)
	{
	    if ( d.length() >= size/2 )
	    {
	        int nc = 0;

	        while (nc < d.length() && d.charAt(nc) == '0') nc++;

	        for ( int i = d.length() - 1; i >= nc; i -- )
	            d += d.charAt(i);

	        BigInteger N = new BigInteger(d);
	        BigInteger N2;
	        
	        N2 = N.pow(2);
	        
	        if ( isPal(N2) )
	        {
	            nums.add(N2);
	            nums2.add(N);
	        }

	        return;
	    }

	    for ( char i = '0'; i <= '1'; i ++ )
	    	if ( n1s == 4 && i == '1' )
    			continue;
    		else
    			initPares(d + i, size, n1s + ((i == '1')?1:0));
	}
	
	static void faltan()
	{
		String n = "2", pal;
		StringBuilder build;
		for ( int i = 0; i < 25; i ++ )
		{
			build = new StringBuilder(n);
			pal = n;
			pal += build.reverse().toString();
			
			nums.add(new BigInteger(pal).pow(2));
			nums2.add(new BigInteger(pal));
			
			pal = n;
			pal += "0";
			pal += build.toString();
			
			nums.add(new BigInteger(pal).pow(2));
			nums2.add(new BigInteger(pal));
			
			pal = n;
			pal += "1";
			pal += build.toString();
			
			nums.add(new BigInteger(pal).pow(2));
			nums2.add(new BigInteger(pal));
			
			n += "0";
		}
	}

	static void init()
	{
		nums = new ArrayList<BigInteger>();
		nums2 = new ArrayList<BigInteger>();
	    
	    nums.add(new BigInteger("9"));
	    nums2.add(new BigInteger("3"));

	    initImpares("", 51, 0);
	    initPares("", 50, 0);
	    faltan();

	    Collections.sort(nums);
	    Collections.sort(nums2);
	    /*
	    writer.println(nums.size());

	    for ( int i = 0; i < nums.size(); i ++ )
	        writer.println(nums.get(i) + " " + nums2.get(i));
	    */
	}

	static int count(String x, boolean menos)
	{
	    int ini = 0, fin = nums.size() - 1, mit;
	    BigInteger X = new BigInteger(x);
	    
	    if ( menos )
	    	X = X.subtract(BigInteger.ONE);
	    
	    while ( ini < fin )
	    {
	        mit = (ini + fin)/2;
	        if(nums.get(mit).compareTo(X) == 1)
	            fin = mit;
	        else
	            ini = mit + 1;
	    }

	    return ini;
	}
	
	static FileWriter f;
	static PrintWriter writer;
	
	public static void main(String args[]) throws IOException
	{
		Scanner reader = new Scanner(new File("c.in"));
		f = new FileWriter("CSmall.txt");
		writer = new PrintWriter(f);
		
		int ntc = reader.nextInt();
		String A, B;
		
		init();
		
		for ( int tc = 1; tc <= ntc; tc ++ )
		{
			A = reader.next();
			B = reader.next();
			
			int ans = count(B, false) - count(A, true);
			
			writer.println("Case #" + tc + ": " + ans );
			// System.out.println("Case #" + tc + ": " + ans );
		}
		
		f.close();
	}
	
}
