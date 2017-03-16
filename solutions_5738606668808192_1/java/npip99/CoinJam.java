import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Random;
import java.util.Scanner;

public class CoinJam {
	public static void main(String[] args) throws FileNotFoundException {
		Scanner in = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);
		//Scanner in = new Scanner(new File("\\in"));
		//PrintWriter out = new PrintWriter(new File("\\out"));
		
		int T = in.nextInt();
		in.nextLine();
		for (int t = 1; t <= T; t++) {
			out.print("Case #" + t + ":");
			
			out.println();
			
			Random r = new Random();
			int N = in.nextInt();
			int J = in.nextInt();
			
			StringBuilder coin = new StringBuilder("");
			coin.ensureCapacity(N);
			
			ArrayList<String> coins = new ArrayList<String>();
			while( coins.size() < J )
			{
				boolean works = true;
				for( int i = 0; i < N; i++ )
				{
					if( i == 0 || i == N - 1 )
						coin.append("1");
					else
					{
						coin.append( r.nextInt() % 2 == 0 ? "1" : "0");
					}
				}
				
				if( coins.contains(coin) )
					continue;
				
				int[] divisors = new int[9];
				for( int i = 2; i <= 10; i++ )
				{
					BigInteger num = new BigInteger(coin.toString(), i);
					
					boolean found = false;
					int d = 0;
					for( d = 2; d < 10000 && BigInteger.valueOf(d * d).compareTo(num) <= 0; d++ )
					{
						if( num.mod( BigInteger.valueOf(d) ).equals(BigInteger.ZERO) )
						{
							found = true;
							break;
						}
					}
					
					if( !found )
					{
						works = false;
						break;
					}
					
					divisors[i-2] = d;
				}
				if( works )
				{
					coins.add(coin.toString());
					out.println(coin.toString() + " " + Arrays.toString(divisors).replaceAll("[\\[\\],]", ""));
				}
				coin = new StringBuilder("");
			}
		}

		in.close();
		out.close();
	}

	public static void debug(Object o) {
		System.out.println("\t\tDEBUG: " + o.toString().replace("\n", "\n\t\tDEBUG: "));
	}
}
