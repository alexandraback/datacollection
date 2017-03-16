import java.util.*;

public class C
{
	public static void main(String args[])
	{
		Scanner scan = new Scanner(System.in);

		int T = scan.nextInt();
		for(int ca=1;ca <= T;ca++)
		{
			int A = scan.nextInt();
			int B = scan.nextInt();

			int rtn = 0;
			String str = "1";
			while(str.length() < (A+"").length()) str += "0";
			int MOD = Integer.parseInt(str);

			for(int i=A;i <= B;i++)
			{
				int k = i;
				HashSet<Integer> h = new HashSet<Integer>();
				for(int j=0;j < str.length();j++)
				{
					//str = str.substring(1) + str.substring(0,1);
					//int k = Integer.parseInt(str);
					k = (k % MOD) * 10 + (k / MOD);

					if(k > i && k <= B && !h.contains(k))
						rtn++;
					
					h.add(k);
				}
			}

			System.out.println("Case #" + ca + ": "+ rtn);
		}
		

	}
}