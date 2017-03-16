import java.util.*;

public class B
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int test = 1, cases = Integer.parseInt(sc.nextLine());
		int A, B, K;
		int[] weights;

		int count;

		int i, j;

		while(test <= cases)
		{
			count = 0;

			A = sc.nextInt();
			B = sc.nextInt();
			K = sc.nextInt();

			for(i = 0; i < A; i++)
			{
				for(j = 0; j < B; j++)
				{
					if((i & j) < K)
						count++;
				}
			}

			System.out.println("Case #" + test + ": " + count);

			test++;
		}
	}
}