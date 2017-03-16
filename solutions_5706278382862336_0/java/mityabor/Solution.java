
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.Random;
import java.util.Scanner;
import java.util.StringTokenizer;


public class Solution
{
	public static long gcd(long a,long b)
	{
		while(b !=0)
		{
			long t = b;
			b = a %b;
			a= t;
		}
		return a;
	}
	public static boolean ispower(long a)
	{
		while(a>1&& a%2 ==0)
		{
			a = a/2;
		}
		if(a == 1) return true;
		return false;
	}
	
	public static long log(long a)
	{
		return (long)(Math.log((double)a)/Math.log(2));
	}
	public static long power(long a, long b)
	{
//		long result = 1;
		long number = 0;
		while(a<b)
		{
			b = b/2;
			number++;
		}
		return number;
	}
	public static void main(String[]  args) throws FileNotFoundException
	{
		

//		Scanner sc = new Scanner(new FileInputStream("D:/Users/Митя/workspace/JAM_2014_1A_C/src/C-small-attempt6.in"));
		Scanner sc = new Scanner(new FileInputStream("A-small-attempt0.in"));
//		Scanner sc = new Scanner(new FileInputStream("input"));
		int TEST_CASE_NUMBER = sc.nextInt();
//		PrintStream out = new PrintStream("D:/Users/Митя/workspace/JAM_2014_1C_A/src/output.txt");
		System.setOut(new PrintStream("D:/Users/Митя/workspace/JAM_2014_1C_A/src/output.txt"));
		for(int test_case=1; test_case <= TEST_CASE_NUMBER;test_case++)
		{
//			int M = sc.nextInt();
//			int N = sc.nextInt();
			String str = sc.next();
			StringTokenizer tokenizer = new StringTokenizer(str,"/");
			long N = Long.parseLong(tokenizer.nextToken());
			long M = Long.parseLong(tokenizer.nextToken());
//			System.out.println(N+"\t"+M);
			long a = gcd(M,N);
			if(a>1)
			{
				M = M/a;
				N = N/a;
			}
			
//			System.out.println(gcd(4,18));
			
			String Answer = "";
			if(N<M && ispower(M))
			{
				Answer += power(N,M);
			}
			else
			{
				Answer = "impossible";
			}
//			System.out.println(log(M)+"\t" + M);
			System.out.println("Case #"+test_case+": "+ Answer);

		}
	}

}
