import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;
import java.math.BigInteger;

public class Main {
	public static final BigInteger two = new BigInteger("2");
	public static BigInteger calc(BigInteger n, BigInteger r) {
		BigInteger temp = n;
		temp = temp.pow(2);
		temp = temp.multiply(two);
		BigInteger temp2 = r.multiply(two);
		temp2 = temp2.subtract(BigInteger.ONE);
		temp2 = temp2.multiply(n);
		return temp2.add(temp);
	}
	
	public static String solve(Scanner in) {
		String ss = new String();
		BigInteger r = in.nextBigInteger();
		BigInteger t = in.nextBigInteger();
		BigInteger n = BigInteger.ZERO;
		BigInteger maxN = t;
		BigInteger minN = n;
		BigInteger val = calc(n,r);
		//val bigger than t
		if (val.compareTo(t)==1) return BigInteger.ZERO.toString();
		//val not t
		while (val.compareTo(t)!=0) {
			if (maxN.compareTo(minN.add(BigInteger.ONE))==0) {
				return minN.toString();
			}
			if (maxN.compareTo(minN)==0)
				return minN.toString();
			//val less than t
			while (val.compareTo(t)==-1) {
				minN = n;
				n = maxN.add(minN).divide(two);
				if (n.compareTo(minN)==0) n = minN.add(BigInteger.ONE);
				val = calc(n,r);
				System.out.println(n+"   "+minN+"   "+maxN);
			}
			//val greater than t
			while (val.compareTo(t)==1) {
				maxN = n;
				n = maxN.add(minN).divide(two);
				if (n.compareTo(maxN)==0) n = maxN.subtract(BigInteger.ONE);
				val = calc(n,r);
			}
		}
		ss = n.toString();
		return ss;
	}
	
	public static void main(String[] args) {
		try {
		Scanner in = new Scanner(new File("/home/steven/workspace/Codejam/Ain"));
		PrintWriter out = new PrintWriter(new FileWriter("/home/steven/workspace/Codejam/Aout")); 
		int cases;
		cases = in.nextInt();
		for (int i = 0; i < cases; i++) {
			System.out.println("Trying case "+(i+1)+"...");
			out.println("Case #"+(i+1)+": "+solve(in));
			System.out.println("Success!");
		}
		in.close();
		out.close();
		} catch (IOException e) {
			System.out.println("IO Problems");
		}
		System.out.println("Done!");
	}
}

