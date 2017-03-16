import java.util.*;

public class B
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int test = 1, cases = sc.nextInt();
		int n, s, p, g, score, count, even, extra;

		while(test <= cases)
		{
			count = 0;
			n = sc.nextInt();
			s = sc.nextInt();
			p = sc.nextInt();

			for(g = 0; g < n; g++)
			{
				score = sc.nextInt();
				even = score / 3;
				extra = score - even * 3;

				if(extra > 0)
					even++;

				if(even >= p)
					count++;
				else	if(s > 0)
					{
						score--;
						even = score / 3;
						extra = score - even * 3;

						if(extra > 0)
							even += 2;

						if(even >= p)
						{
							count++;
							s--;
						}
					}
			}

			System.out.println("Case #" + test + ": " + count);

			test++;
		}
	}
}