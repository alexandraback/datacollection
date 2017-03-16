
import java.io.*;
import java.util.*;

public class ProblemB
{
	public static void main(String[] args)
	{
		try { System.setIn(new FileInputStream("B-large.in")); } catch (Exception e) { }
		try { System.setOut(new PrintStream("B-large-out.txt")); } catch (Exception e) { }
		
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for (int t = 1; t <= T; t++)
		{
			int N = sc.nextInt();
			int S = sc.nextInt();
			int P = sc.nextInt();
			
			int[] score = new int[N];
			for (int i = 0; i < N; i++) score[i] = sc.nextInt();
			
			int c = 0, s = 0;
			for (int i = 0; i < N; i++)
			{
				int[] tr = getBests(score[i]);
				if (P <= tr[0])
				{
					c++;
				}
				else if (P <= tr[1])
				{
					s++;
				}
			}
			c += Math.min(s, S);
			System.out.printf("Case #%d: %d\r\n", t, c);
		}
	}
	
	private static int[] makeTriple(int n)
	{
		int b = n / 3;
		int[] tr = { b, b, b };
		for (int i = 0; i < n % 3; i++) tr[i]++;
		return tr;
	}
	
	private static int[] getBests(int n)
	{
		int k = n / 3;
		int a = k, b = k + 1;
		if (n % 3 != 0) a++;
		if (n % 3 == 2) b++;
		else if (k - 1 < 0) b = 0;
		return new int[] { a, b };
	}
}
/*
4
3 1 5 15 13 11
3 0 8 23 22 21
2 1 1 8 0
6 2 8 29 20 8 18 18 21
*/