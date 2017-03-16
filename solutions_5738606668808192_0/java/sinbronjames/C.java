import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class C {

	
	public static int convertBinaryToBase (int n, int base)
	{
		int basePower = 1;
		int ans = 0;
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
		Scanner in = new Scanner (new File ("C-small-attempt1.in"));
		PrintWriter out = new PrintWriter (new FileWriter ("C-small.txt"));
		int T = in.nextInt();
		for (int test =1 ;test<=T; test++)
		{
			out.println("Case #"+test+": ");
			int N = in.nextInt();
			int J = in.nextInt();
			for (int i=0; i<=J-1; i++)
			{
				int val = 128+2*i+1;
				for (int j = 1; j<=2 ;j++)
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
