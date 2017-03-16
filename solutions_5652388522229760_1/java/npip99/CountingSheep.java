import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.HashSet;
import java.util.Scanner;

public class CountingSheep {
	public static void main(String[] args) throws FileNotFoundException {
		Scanner in = new Scanner(new File("\\in"));
		PrintWriter out = new PrintWriter(new File("\\out"));
		
		int T = in.nextInt();
		for( int t = 1; t <= T; t++ )
		{
			out.print("Case #" + t +": ");
			BigInteger n = in.nextBigInteger();
			if( n.equals(BigInteger.ZERO) )
				out.println("INSOMNIA");
			else
			{
				BigInteger num = new BigInteger("0");
				HashSet<Character> digits = new HashSet<Character>();
				while( digits.size() != 10 )
				{
					num = num.add(n);
					for( char c : num.toString().toCharArray() )
					{
						digits.add(c);
					}
				}
				out.println(num);
			}
			out.flush();
		}
		
		in.close();
		out.close();
	}
	
	public static void debug(Object o)
	{
		System.out.println("\t\tDEBUG: " + o.toString().replace("\n", "\n\t\tDEBUG: "));
	}
}
