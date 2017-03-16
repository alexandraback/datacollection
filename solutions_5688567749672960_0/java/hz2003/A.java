package Round1B_2015;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Scanner;


public class A {

	public static BigInteger count(BigInteger n) {
		BigInteger result = new BigInteger("0");
		BigInteger one = new BigInteger("1");
		BigInteger ten = new BigInteger("10");
		if (n.compareTo(one) == 0)
			return one;
		StringBuilder nStr = new StringBuilder(n.toString());
		nStr.setCharAt(nStr.length() - 1, '1');
		BigInteger setToOne = new BigInteger(nStr.toString());
		if (setToOne.compareTo(n) < 0) {
			result = result.add(n.subtract(setToOne));
			n = setToOne;
		}
		
		
		BigInteger r = new BigInteger("1");
		while(true) {
			System.out.println(r);
			BigInteger temp = r.multiply(ten);
			if(temp.compareTo(n) <= 0) {
				System.out.println(result);
				if(r.compareTo(one) > 0) {
					result = result.add(ten);
					result = result.add(r.subtract(one));
				} else
					result = result.add(ten);
				r = temp;
			}
			else
				break;
		}
		if (n.compareTo(r) > 0)
			result = result.add(n.subtract(r));
	
		return result;
	}
	static int c[] = new int[1000001];
	public static int reverse(int n) {
		int r = 0;
		while(n != 0) {
			r *= 10;
			r += n % 10;
			n /= 10;
		}
		return r;
	}
	public static void countI(int n) {
		for(int i = 1; i < n; i++)
			countInt(i);
		
	}
	public static int countInt(int n) {
		int [] c = A.c;
		if(c[n] > 0)
			return c[n];
		if(n == 1) {
			c[n] = 1;
			return c[n];
		}
		int a1 = countInt(n - 1) + 1;
		int a2;
		if (reverse(n) < n && n%10 != 0 )
			a2 = countInt(reverse(n)) + 1;
		else
			a2 = a1;
		c[n] = Math.min(a1, a2);
		return Math.min(a1, a2);		
	}
	
	public static void main(String[] args) {
		File fin = new File("src/Round1B_2015/A_test.in.txt");
		Scanner scan;
		try {
			scan = new Scanner(fin);
		
			PrintWriter output = new PrintWriter("src/Round1B_2015/A_test.out.txt");
			int T = scan.nextInt();
			countI(1000000);
			for(int i = 0; i < T; i++)
			{
				int n = scan.nextInt();
				int r = countInt(n);
				output.println("Case #" + (i + 1) + ": " + r);
				System.out.println("Case #" + (i + 1) + ": " + countInt(n));
			}
			scan.close();
			output.close();
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	public static void main1(String[] args) {
		File fin = new File("src/Round1B_2015/A_test.in.txt");
		Scanner scan;
		try {
			scan = new Scanner(fin);
		
			PrintWriter output = new PrintWriter("src/Round1B_2015/A_test.out.txt");
			int T = scan.nextInt();
			for(int i = 0; i < T; i++)
			{
				BigInteger n = scan.nextBigInteger();
				BigInteger r1 = count(n);
				String s = n.toString();
				BigInteger r2;
				if(s.charAt(s.length() - 1) == '0')
					r2 = r1;
				else
					r2 = count(new BigInteger(new StringBuilder(n.toString()).reverse().toString())).add(new BigInteger("1"));
				output.println("Case #" + (i + 1) + ": " + (r1.compareTo(r2) < 0 ? r1: r2));
				System.out.println("Case #" + (i + 1) + ": " + (r1.compareTo(r2) < 0 ? r1: r2));
			}
			scan.close();
			output.close();
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}
