package countingsheep;

import java.util.Scanner;

public class Main {
	
	static private int findLastNumber(int start)
	{
		boolean[] seen = new boolean[10];
		for (int i = 0; i < 10; i++) seen[i] = false;
		int current = 0;
		outerloop:
			while (true)
			{
				current += start;
				// break current into digits
				int temp = current;
				while (temp > 0)
				{
					seen[temp % 10] = true;
					temp /= 10;
				}
				for (int i = 0; i < 10; i++)
				{
					if (!seen[i]) continue outerloop;
				}
				return current;
			}
	}
	
	public static void main(String[] args)
	{
		Scanner in = new Scanner(System.in);
		int cases = in.nextInt();
		for(int i = 0; i < cases; i++)
		{
			int start = in.nextInt();
			if (start == 0)
			{
				System.out.println("Case #" + (i + 1) + ": INSOMNIA");
			}
			else
			{
				System.out.println("Case #" + (i + 1) + ": " + findLastNumber(start));
			}
			
		}
		in.close();
	}
}
