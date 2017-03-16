
import java.io.FileInputStream;
import java.util.Scanner;
import java.util.Set;
import java.util.TreeSet;

public class ProblemCSmall
{
	public static void main(String[] args)
	{
		try { System.setIn(new FileInputStream("C-small-attempt0.in")); } catch (Exception e) { }
		
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for (int t = 1; t <= T; t++)
		{
			int A = sc.nextInt(), B = sc.nextInt();
			int c = 0;
			int D = 1 + (int)Math.log10(A);
			int M = (int)Math.pow(10, D - 1);
			Set<Integer> set = new TreeSet<Integer>();
			for (int a = A; a < B; a++)
			{
				int aa = a;
				set.clear();
				for (int d = 1; d < D; d++)
				{
					aa = aa / 10 + M * (aa % 10);
					if (a < aa && aa <= B && !set.contains(aa))
					{
						c++;
						set.add(aa);
					}
				}
			}
			System.out.printf("Case #%d: %d\n", t, c);
		}
	}
}
/*
4
1 9
10 40
100 500
1111 2222
*/
