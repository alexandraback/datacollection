import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.math.RoundingMode;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.Scanner;
import java.util.StringTokenizer;
import java.util.TreeSet;


public class Main implements Runnable {
    
	private static Scanner in;
	private static PrintWriter out;

	public static void main(String[] args) throws IOException {
    	in = new Scanner(System.in);
    	out = new PrintWriter(System.out);
    	new Main().run();
    	out.flush();
    	
    }

	public void run() {
		int T=in.nextInt();
		for(int test=1;test<=T;test++)
		{
			int K=in.nextInt();
			int C=in.nextInt();
			int S=in.nextInt();
			BigInteger kBig=BigInteger.valueOf(K);
			ArrayList<BigInteger> nums=new ArrayList();
			
			for(int i=0;i<K;i+=C)
			{
				BigInteger num=BigInteger.ZERO;
				for(int j=0;j<C;j++)
				{
					int id=i+j;
					if(id>=K)
						id=0;
					num=num.multiply(kBig).add(BigInteger.valueOf(id));
				}
				num=num.add(BigInteger.ONE);
				nums.add(num);
			}
			if(nums.size()<=S)
			{
				out.printf("Case #%d:", test);
				for(BigInteger i:nums)
					out.printf(" %d",i);
				out.println();
			}
			else
				out.printf("Case #%d: IMPOSSIBLE\n", test);
		}
	}


}
