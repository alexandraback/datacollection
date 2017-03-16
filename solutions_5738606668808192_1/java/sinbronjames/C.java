import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class C {

	
	public static long convertBinaryToBase (int n, int base)
	{
		long basePower = 1;
		long ans = 0;
          while (n > 0)
          {
        	  int digit = n%2;
        	  ans+=digit*basePower;
        	  n=n/2;
        	  basePower*=base;
        	  
          }
        return ans;
	}
	
	public static void main(String[] args) throws IOException {
		// Scanner in = new Scanner (System.in);
		Scanner in = new Scanner (new File ("C-large.in"));
		PrintWriter out = new PrintWriter (new FileWriter ("C-large.txt"));
		int T = in.nextInt();
		for (int test =1 ;test<=T; test++)
		{
			out.println("Case #"+test+": ");
			int N = in.nextInt();
			int J = in.nextInt();
			for (int i=0; i<=J-1; i++)
			{
				int val = 32768+2*i+1;
				for (int x = 1; x<=2 ;x++)
				{
					out.print(Integer.toBinaryString(val));
				}
				for (int k=2; k<=10; k++)
				{
					out.print(" ");
					out.print(convertBinaryToBase(val,k));
				}
				out.println();
			}
			
		}
		out.close();

	}

}
