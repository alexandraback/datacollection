import java.util.*;

public class A
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int test = 1, cases = Integer.parseInt(sc.nextLine());
		String str;
		int n;
		long count;

		int[] rep;
		int start, end, lastStart;
		int contains;

		int i;

		while(test <= cases)
		{
			str = sc.next();
			n = Integer.parseInt(sc.nextLine().trim());

			count = 0;

			rep = new int[str.length()];

			for(i = 0; i < str.length(); i++)
			{
				if(str.charAt(i) != 'a' && str.charAt(i) != 'e' && str.charAt(i) != 'i' && str.charAt(i) != 'o' && str.charAt(i) != 'u')
					rep[i] = 1;
				else rep[i] = 0;
			}

			start = 0;
			lastStart = -1;

			while(start <= str.length() - n)
			{
				if(sum(rep, start, start + n) == n)
				{
					count += (start - lastStart) * (str.length() - start - n + 1);

					lastStart = start;
				}

				start++;
			}

			System.out.println("Case #" + test + ": " + count);

			test++;
		}
	}

	public static int sum(int[] a, int b, int e)
	{
		int i;
		int sum = 0;

		for(i = b; i < e; i++)
		{
			sum += a[i];
		}

		return sum;
	}
}