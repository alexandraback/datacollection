import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.*;


public class RoundCProb1 {
public static void main(String[] args) throws IOException {
	Scanner sc = new Scanner(new File("RCP1.in"));
//	BufferedWriter out = new BufferedWriter(new FileWriter(new File("p1.out")));
	
	int T = sc.nextInt();
	for(int t=1; t<=T; ++t)
	{
		String[] input = sc.next().split("[/]");
		long P = Long.parseLong(input[0]), Q = Long.parseLong(input[1]);
		long gcd = gcd(P, Q);
		P/=gcd;
		Q/=gcd;
		if(Q==((~Q+1)&Q) && 0<P && P<=Q) //Q is power of two
		{
			int L=0;
			do
			{
				Q/=2;
				++L;
			}while(P<Q);
			System.out.println("Case #"+t+": "+L);
		}
		else
			System.out.println("Case #"+t+": impossible");
	}
}

static long gcd(long a, long b)
{
	return (b==0)?a:gcd(b, a%b);
}
}
