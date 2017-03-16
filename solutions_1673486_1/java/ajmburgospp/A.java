import java.io.*;
import java.util.*;
import java.math.*;
import static java.lang.System.*;

public class A
{
	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(in));
		PrintStream ps = new PrintStream(new BufferedOutputStream(out));
		int cases = Integer.parseInt(br.readLine());
		for (int c = 1; c <= cases; c++)
		{
			String[] arr = br.readLine().split("\\s+");
			int a = Integer.parseInt(arr[0]);
			int b = Integer.parseInt(arr[1]);
			arr = br.readLine().split("\\s+");
			double[] darr = new double[a];
			for (int i = 0; i < a; i++)
			{
				darr[i] = Double.parseDouble(arr[i]);
			}
			
			double[] prod = new double[a+1];
			prod[0] = 1;
			for (int i = 1; i <= a; i++) prod[i] = prod[i-1]*darr[i-1];
			
			double min = b+2;
			for (int i = 0; i <= a; i++)
			{
				double ok = (2*i+b-a+1) * (prod[a-i]);
				double not = (2*i+2*b-a+2) * (1-prod[a-i]);
				min = Math.min(min, ok+not);
			}
			
			ps.printf("Case #%d: %.6f\n", c, min);
		}
		ps.flush();
	}
}
