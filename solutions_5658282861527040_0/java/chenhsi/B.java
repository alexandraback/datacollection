import java.util.*;
import java.io.*;
import java.math.*;

public class B
{
	public static void main(String[] args) throws IOException
	{
		Scanner in = new Scanner(new BufferedReader(new FileReader("B-small-attempt0.in")));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("B-small.out")));
		
		int tt = in.nextInt();
		for (int I = 1; I <= tt; I++)
		{
			out.print("Case #" + I + ": ");
			int a = in.nextInt();
			int b = in.nextInt();
			int k = in.nextInt();
			int count = 0;
			for (int i = 0; i < a; i++)
				for (int j = 0; j < b; j++)
					if ((i & j) < k)
						count++;
			out.println(count);
			System.out.println(count);
		}
		out.flush();
		out.close();
	}
}
