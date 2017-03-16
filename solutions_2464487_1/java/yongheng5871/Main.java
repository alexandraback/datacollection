import java.util.*;
import java.math.*;
import java.io.*;

public class Main
{
	BigInteger r, t;
	BigInteger two = new BigInteger("2");
	BigInteger f(BigInteger x)
	{
		return r.multiply(two).add(x.multiply(two)).subtract(BigInteger.ONE).multiply(x);
	}
	BigInteger solve()
	{
		BigInteger L = BigInteger.ZERO, R = new BigInteger("10000000000000000000");
		while( L.compareTo(R) <= 0)
		{
			BigInteger mid = L.add(R).divide(two);
			BigInteger result = f(mid);
			if (result.compareTo(t) <= 0) L = mid.add(BigInteger.ONE);
			else R = mid.subtract(BigInteger.ONE);
		}
		return R;
	}
	void main()throws Exception
	{
		FileInputStream stdin = new FileInputStream("in.txt");
		FileOutputStream stdout = new FileOutputStream("out.txt");  
        System.setOut(new PrintStream(stdout)); 
		System.setIn(stdin);
		Scanner cin=new Scanner(System.in);//example
		int T = cin.nextInt();
		for (int cas = 1; cas <= T; ++cas)
		{
			System.out.printf("Case #%d: ", cas);
			r = cin.nextBigInteger();
			t = cin.nextBigInteger();
			System.out.println(solve());
		}
	}
	public static void main(String[] args)throws Exception
	{
		new Main().main();
		
	}
}