package qr2016;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.util.Scanner;

public class C {
	public static void main(String[] args) throws FileNotFoundException, UnsupportedEncodingException
	{
		PrintWriter writer = new PrintWriter("output/qr2016/C/test.out", "UTF-8");

		Scanner sc = new Scanner(new File("input/qr2016/C/test.in"));
		sc.nextInt();
		int N = sc.nextInt();
		int J = sc.nextInt();
		
		writer.println("Case #" + 1 + ": ");
		
		for(int i= 0; i<J; i++)
		{
			String s = Integer.toBinaryString(i) + "1";
			while(s.length()<(N/2)-1)
				s = "0" + s;
			s = "1" + s;
			for(char c : s.toCharArray())
				writer.print(c + "" +  c);
			for(int j=3; j<=11; j++)
				writer.print(" " + j);
			writer.println();
		}
		
		sc.close();
		writer.close();
	}
}
