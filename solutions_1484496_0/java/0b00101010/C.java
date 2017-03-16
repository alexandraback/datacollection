import java.util.Scanner;
import java.util.Hashtable;

public class C {
	public static void main (String[] args)
	{
		Scanner scan = new Scanner(System.in);
		int c = scan.nextInt();
		int i, j, k, n;
		for (i = 1; i <= c; i++)
		{
			n = scan.nextInt();
			int[] s = new int[n];
			for (j = 0; j < n; j++)
				s[j] = scan.nextInt();
			System.out.println("Case #" + i + ":");
			long result = test(s, n);
			//System.out.println(Long.toBinaryString(result));
			if (result < 0)
				System.out.println("Impossible");
			else
			{
				for (k = 0; k < n; k++)
				{
					if ((result & 1) == 1)
						System.out.print(s[k] + " ");
					result >>= 1;
				}
				System.out.println();
				for (k = 0; k < n; k++)
				{
					if ((result & 1) == 1)
						System.out.print(s[k] + " ");
					result >>= 1;
				}
				System.out.println();
			}
		}
	}
	public static long test(int[] s, int n)
	{
		int k;
		long sum, temp;
		Hashtable<Long, Long> ht = new Hashtable<Long, Long>();
		for (long j = 1; j < (1 << n); j++)
		{
			temp = j;
			sum = 0;
			for (k = 0; k < n; k++)
			{
				if ((temp & 1) == 1)
					sum += s[k];
				temp >>= 1;
			}
			if (ht.containsKey(sum))
			{
				temp = ht.get(sum).longValue();
				if (temp > 0)
					return (j << n) + temp;
			}
			ht.put(sum, j);
		}
		return -1;
	}
}
