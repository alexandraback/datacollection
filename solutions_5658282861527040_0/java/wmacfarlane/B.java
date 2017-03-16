import java.util.*;

public class B
{
	static StringBuilder out = new StringBuilder();
	
	public static void main(String [] args)
	{
		Scanner sc = new Scanner(System.in);
		int numTests = sc.nextInt();
		for(int test = 1; test <= numTests; test++)
		{
			out.append(String.format("Case #%d: ", test));
			
			int x = sc.nextInt();
			int y = sc.nextInt();
			int z = sc.nextInt();
			
			int count = 0;
			for(int i = 0; i < x; i++)
			{
				for(int j = 0; j < y; j++)
				{
					if((i & j) < z)
						count++;
				}
			}
			
			out.append(count + "\n");

			
			
			//out.append(sc.nextInt() + "\n");
		}
		System.out.print(out.toString());
	}
}