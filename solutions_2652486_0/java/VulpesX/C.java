import java.util.*;
import java.math.*;

public class C
{

	public static void main(String args[])
	{
		Scanner scan = new Scanner(System.in);

		int T = scan.nextInt(); // lol
		System.out.println("Case #1:");

		int R = scan.nextInt();
		int N = scan.nextInt();
		int M = scan.nextInt();
		int K = scan.nextInt();

		while(R --> 0)
		{
			int[] prods = new int[K];
			for(int i=0;i < K;i++)
				prods[i] = scan.nextInt();
			
			int[] a = new int[3];

			String sol = "";

			for(a[0]=2;a[0] <= 5;a[0]++)
			for(a[1]=2;a[1] <= 5;a[1]++)
			for(a[2]=2;a[2] <= 5;a[2]++)
			{
				HashSet<Integer> h = new HashSet<Integer>();
				h.add(1);
				h.add(a[0]);
				h.add(a[1]);
				h.add(a[2]);
				h.add(a[0]*a[1]);
				h.add(a[0]*a[2]);
				h.add(a[2]*a[1]);
				h.add(a[0]*a[1]*a[2]);

				boolean good = true;
				for(int i=0;i < K;i++)
					if(!h.contains(prods[i]))
						good = false;

				if(good)
					sol = a[0] + "" + a[1] + ""  + a[2];
			}

			System.out.println(sol);
		}
		
	}
}