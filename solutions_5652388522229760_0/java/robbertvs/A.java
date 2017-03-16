package qr2016;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.util.Arrays;
import java.util.Scanner;

public class A {
	public static void main(String[] args) throws FileNotFoundException, UnsupportedEncodingException
	{
		Scanner sc = new Scanner(new File("input/qr2016/test.in"));
		PrintWriter writer = new PrintWriter("input/qr2016/test.out", "UTF-8");
		int T = sc.nextInt();
		
		for(int i = 1; i<=T; i++)
		{
			int N = sc.nextInt();
			if(N == 0)
			{
				writer.println("Case #" + i + ": INSOMNIA");
				continue;
			}
			boolean[] seen = new boolean[10];
			for(int j=1; true; j++)
			{
				int name = N*j;
				while(name!=0)
				{
					seen[name%10]=true;
					name/=10;
				}
				if(seenall(seen))
				{
					writer.println("Case #" + i + ": " + N*j);
					break;
				}
			}
		}
		
		sc.close();
		writer.close();
	}

	private static boolean seenall(boolean[] seen) {
		for(boolean b : seen)
		{
			if(!b)
				return false;
		}
		return true;
	}
}
