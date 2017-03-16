import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Scanner;

public class Fractiles {	
	public static void main(String[] args) throws FileNotFoundException {
		Scanner in = new Scanner(new File("\\in"));
		PrintWriter out = new PrintWriter(new File("\\out"));
		//Scanner in = new Scanner(System.in);
		//PrintWriter out = new PrintWriter(System.out);
		
		int T = in.nextInt();
		in.nextLine();
		for (int t = 1; t <= T; t++) {
			out.print("Case #" + t + ": ");

			int K = in.nextInt();
			int C = in.nextInt();
			int S = in.nextInt();
			
			if( Math.ceil((double)K / C) > S )
			{
				out.println("IMPOSSIBLE");
				continue;
			}
			if( K == 1 )
			{
				out.println("1");
				continue;
			}
			
			ArrayList<BigInteger> powers = new ArrayList<BigInteger>();
			BigInteger mult = new BigInteger("1");
			
			for( int i = 0; i < C; i++ )
			{
				powers.add(new BigInteger(mult.toString()));
				mult = mult.multiply(BigInteger.valueOf(K));
			}
			
			BigInteger ind = new BigInteger("0");
			
			for( int i = 0; i < K || i % C != 0; i++ )
			{
				ind = ind.add(powers.get(C-1-(i%C)).multiply(BigInteger.valueOf(Math.min(K-1, i))));
				if( (i+1) % C == 0 )
				{
					out.print(ind.add(BigInteger.ONE)+" ");
					ind = new BigInteger("0");
				}
				System.out.println(ind);
			}
			out.println();
		}

		in.close();
		out.close();
	}

	public static void debug(Object o) {
		System.out.println("\t\tDEBUG: " + o.toString().replace("\n", "\n\t\tDEBUG: "));
	}
}
