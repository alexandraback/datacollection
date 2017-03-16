import java.util.*;
import java.io.*;
public class CLarge
{
	public static final int n = 32;
	public static final int j = 500;
	
	public static void main(String[] args) throws Exception
	{
//		Scanner in = new Scanner(System.in);
//		PrintWriter out = new PrintWriter(System.out);
		
//		Scanner in = new Scanner(new File("C-small-attempt0.in"));
		PrintWriter out = new PrintWriter(new File("C-large.out"));
		
		out.println("Case #1:");
		
		int count = 0;
		for(int x = 0; x < (1 << (n / 2 - 1)) && count < j; x++)
		{
			char[] num = new char[n];
			Arrays.fill(num, '0');
			num[0] = '1';
			num[n - 1] = '1';
			
			if((Integer.bitCount(x) + 1) % 3 != 0)
			{
				continue;
			}
			
			for(int y = 0; y < Integer.bitCount(x); y++)
			{
				num[n - 3 - 2 * y] = '1';
			}
			
			for(int z = 0; z < n / 2 - 1; z++)
			{
				if((x & (1 << z)) > 0)
				{
					num[n - 2 * (z + 1)] = '1';
				}
			}
			
			out.println(new String(num) + " 3 2 3 2 3 2 3 2 3");
			
			count++;
		}
		
		out.close();
	}
}
