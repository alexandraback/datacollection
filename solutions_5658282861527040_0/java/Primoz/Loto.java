package Round1b2014;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class Loto 
{
	public static void main(String[] args) throws FileNotFoundException {
		Scanner sc = new Scanner(new File ("B-small-attempt0 -1.in"));
		PrintWriter pw = new PrintWriter(new File("loto_out"));
		
		int t = sc.nextInt();
		
		for (int i = 0; i < t; i++)
		{
			int sum = 0;
			int a = sc.nextInt();
			int b = sc.nextInt();
			int k = sc.nextInt();
			
			
			
			for (int j = 0; j < a; j++)
				for (int l = 0; l < b; l++)
					if ( (j&l) < k)
						sum++;
			pw.printf("Case #%d: %d\n", i+1, sum);
		}
		pw.close();
		
		System.out.println("done");
	}
	
	
}
