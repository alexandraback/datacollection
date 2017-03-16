import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class FashionPolice {
	public static void main(String[]args)
	{
		try
		{
			Scanner sc = new Scanner(new FileReader("C-small-attempt1.in"));
			FileWriter fw = new FileWriter(new File("Output.txt"));
			PrintWriter pw = new PrintWriter(fw);
				
			int t = sc.nextInt();
				
			for(int r = 1; r <= t; r++)
			{
				int j  = sc.nextInt();
				int p  = sc.nextInt();
				int s  = sc.nextInt();
				int k  = sc.nextInt();
				
				int d = j * p * k;
				if(j * p * k > j * p * s)
				{
					d = j * p * s;
					k = s;
				}
				//System.out.println("Case " + r + ": " + j + " " + p + " " + s + " " + k);
				pw.print("Case #" + r + ": " + d);	
				
				
				//int count = 0;
				for(int a = 1; a <= j; a++)
				{
					int start = a;
					for(int b = 1; b <= p; b++)
						for(int c = 1; c <= k; c++)
						{
							if(start > s)
								start =1; 
							pw.println();
							pw.print(a + " " + b + " " + start++);
							//count++;
						}
				}
					
				pw.println();
				//if(count == d)
					//System.out.println("Correct: " + r);
			}
			pw.flush();	
			pw.close();
		}
			catch(IOException ioe){System.out.print(ioe);}
	}
}
