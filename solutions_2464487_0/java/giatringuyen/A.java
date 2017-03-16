import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.math.BigInteger;
import java.util.Scanner;


public class A {
	public static void main(String[] args) throws Exception{
		Scanner sc = new Scanner (new File("A-small-attempt0.in"));
		FileWriter fstream = new FileWriter("A-small-attempt0-out.txt");
		BufferedWriter out = new BufferedWriter(fstream);
		
//		Scanner sc = new Scanner (System.in);
		
		int tstSz = sc.nextInt();
		for (int i = 1; i <= tstSz; ++i) {
			long r = sc.nextLong();
			long t = sc.nextLong();
			long max = t/(2*r);
			long min = 0;
			while ( max > min) {
				long mid = (max + min)/2;
				int comp = BigInteger.valueOf(mid+1).multiply(BigInteger.valueOf(2*r + 2*mid + 1)).compareTo(BigInteger.valueOf(t));
				if ( comp == 1)
					max = mid;
				else if (comp == -1)
					if (min == mid)
						max = min = mid;
					else
						min = mid;
				else 
					max = min = mid;
			}
//			System.out.println("Case #" + i + ": " + (min+1));
			out.write("Case #" + i + ": " + (min+1) + "\n");
		}
		
		out.close();
	}
}
