

import java.util.Scanner;

public class RecycledNumber {

	public int deal(int A, int B)
	{
		int ans = 0;
		for (int i = A; i<= B ; i ++)
		{
			int left = i;			
			int k = 1;
			int tk = 1;		
			UniqueList newInts = new UniqueList(10);
			while (left >= 10)
			{
				left = left / 10;
				tk = tk * 10;
			}
			left = i;
			while (k * 10 <= left)
			{
				k = k * 10;
				int x = (left % k) * (tk * 10 / k) + (left / k);
				//System.out.println(i + ": " + x);
				if (x > i && x <= B)
					newInts.add(x);
			}
			ans += newInts.getSize();
		}
		return ans;
	}
	
	public void solve()
	{
		Scanner scan = new Scanner(System.in);
		int T = scan.nextInt();scan.nextLine();
		for (int i = 1; i <= T; i ++)
		{
			int A = scan.nextInt();
			int B = scan.nextInt();
			System.out.println("Case #" + i + ": " + this.deal(A, B));
		}
	}
	
	public static void main(String args[])
	{
		RecycledNumber r = new RecycledNumber();
		r.solve();
	}
}
