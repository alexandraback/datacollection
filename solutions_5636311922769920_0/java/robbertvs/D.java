package qr2016;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.util.Scanner;

public class D {
	public static void main(String[] args) throws FileNotFoundException, UnsupportedEncodingException
	{
		Scanner sc = new Scanner(new File("input/qr2016/D/D-small-attempt1.in"));
		PrintWriter writer = new PrintWriter("output/qr2016/D/D-small-attempt1.out", "UTF-8");
		
		int T = sc.nextInt();
		for(int casenr = 1; casenr<=T; casenr++)
		{
			int K = sc.nextInt();
			int C = sc.nextInt();
			int S = sc.nextInt();
			
			if((K-1)/C + 1 > S)
			{
				writer.println("Case #" + casenr + ": IMPOSSIBLE");
				continue;
			}

			writer.print("Case #" + casenr + ": ");
			
			long curr = 1;
			for(int i=1; i<=K; i++)
			{
				curr = (curr-1)*K+i;
				if(i%C==0 || i==K)
				{
					writer.print(" " + curr);
					curr=1;
				}
			}
			writer.println();
		}
		sc.close();
		writer.close();
	}
}
