import java.util.Scanner;

public class DLarge {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int nt = in.nextInt();
		for(int t = 1; t <= nt; t++)
		{
			int k = in.nextInt();
			int c = in.nextInt();
			int s = in.nextInt();
			int[] seq = solve(k,c);
			if (seq.length <= s) {
				System.out.print("Case #" + t + ":");
				for (int i = 0; i < seq.length; i++)
					System.out.print(" " + seq[i]);
				System.out.println();
			}else
			{
				System.out.println("Case #" + t + ": IMPOSSIBLE");
			}
			
		}
	}
	
	static int[] solve(int k, int c)
	{
		int[] res;
		if(c == 1)
		{
			res = new int[k];
			for(int i = 1; i <= k; i++)
				res[i-1] = i;
		}else
		{
			res = new int[k-1];
			for(int i = 2; i <= k; i++)
				res[i-2] = i;
		}
		return res;
	}
}
