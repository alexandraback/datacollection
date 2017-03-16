package solution;

import java.math.BigInteger;
import java.util.Arrays;
import java.util.Scanner;
import java.util.SortedSet;
import java.util.TreeSet;

public class C {

	public static void main(String[] args) {

		SortedSet<BigInteger> fairSquareSorted = new TreeSet<BigInteger>();
		fairSquareSorted.addAll(Arrays.<BigInteger> asList(
				BigInteger.valueOf(1), 
				BigInteger.valueOf(4),
				BigInteger.valueOf(9),
				
				BigInteger.valueOf(121),
				BigInteger.valueOf(484),
				
				BigInteger.valueOf(10201),
				BigInteger.valueOf(12321),
				BigInteger.valueOf(14641),
				BigInteger.valueOf(40804),
				BigInteger.valueOf(44944),
				
				BigInteger.valueOf(1002001),
				BigInteger.valueOf(1234321),
				BigInteger.valueOf(4008004),
				
				BigInteger.valueOf(100020001),
				BigInteger.valueOf(102030201),
				BigInteger.valueOf(104060401),
				BigInteger.valueOf(121242121),
				BigInteger.valueOf(123454321),
				BigInteger.valueOf(125686521),
				BigInteger.valueOf(400080004),
				BigInteger.valueOf(404090404),
				
				new BigInteger("10000200001"),
				new BigInteger("10221412201"),
				new BigInteger("12102420121"),
				new BigInteger("12345654321"),
				new BigInteger("40000800004"),
				
				new BigInteger("1000002000001"),
				new BigInteger("1002003002001"),
				new BigInteger("1004006004001"),
				new BigInteger("1020304030201"),
				new BigInteger("1022325232201"),
				new BigInteger("1024348434201"),
				new BigInteger("1210024200121"),
				new BigInteger("1212225222121"),
				new BigInteger("1214428244121"),
				new BigInteger("1232346432321"),
				new BigInteger("1234567654321"),
				new BigInteger("4000008000004"),
				new BigInteger("4004009004004")				
				));
		
		Scanner scanner = new Scanner(System.in);
		
		int T = scanner.nextInt();		
		
		for(int i=1;i<=T;i++) {
			
			BigInteger A = scanner.nextBigInteger();
			BigInteger B = scanner.nextBigInteger();
			
			System.out.println("Case #" + i + ": " + fairSquareSorted.subSet(A, B.add(BigInteger.valueOf(1))).size());
		}
		
		scanner.close();

	}
}
