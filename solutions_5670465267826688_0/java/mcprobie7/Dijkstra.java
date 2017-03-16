import java.io.*;
import java.util.Scanner;


public class Dijkstra {
	public static void main(String[] args) throws IOException
	{
		int result[][] = new int[][] {{0, 1, 2, 3}, {1, 0, 3, 2}, {2, 3, 0, 1}, {3, 2, 1, 0}}; 
		int sign[][] = new int[][] {{1, 1, 1, 1}, {1, -1, 1, -1}, {1, -1, -1, 1}, {1, 1, -1, -1}};
		Scanner in = new Scanner(new File("C-small-attempt1.in"));
		PrintWriter out = new PrintWriter(new File("outputC.txt"));
		int t = in.nextInt();
		for (int testn = 1; testn <= t; testn++)
		{
			int L = in.nextInt();
			int X = in.nextInt();
			String S = in.next();
			
			int[] a = new int[L];
			for (int i = 0; i < L; i++) a[i] = S.charAt(i) - 'i' + 1;
			
			int curResult = 0;
			int curSign = 1;
			int value = 1;
			for (int i = 0; i < X; i++)
			{	
				for (int j = 0; j < L; j++)
				{
					curSign *= sign[curResult][a[j]];
					curResult = result[curResult][a[j]];
					if (curResult == value && curSign == 1 && value < 3) 
					{ 
						value++;
						curResult = 0;
						curSign = 1;
					}	
				}
			}
		
			if (value == 3 && curResult == 3 && curSign == 1) out.println("Case #" + testn + ": YES");
			else out.println("Case #" + testn + ": NO");
		}
		in.close();
		out.close();
	}
}
