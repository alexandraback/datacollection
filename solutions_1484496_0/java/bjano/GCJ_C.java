import java.io.*;
import java.util.*;

public class GCJ_C {

	public static void main(String[] args) throws Exception {
		String fname = "C-small";
		Scanner scanner = new Scanner(new File(fname+".in"));
		PrintWriter writer = new PrintWriter(new FileWriter(fname+".out"));
		
		int tt = Integer.parseInt(scanner.next());
		System.out.println(tt);
		boolean dp[][] = new boolean[21][2100000]; // first a can make b diff
		for (int ii=1;ii<=tt;ii++)
		{
			int n = Integer.parseInt(scanner.next());
			int s[] = new int[n];
			for (int i=0;i<n;i++)
				s[i] = Integer.parseInt(scanner.next());
			for (int i=0;i<21;i++)
				for (int j=0;j<2000000;j++)
					dp[i][j] = false;
			dp[0][0] = true;
			for (int i=0;i<n;i++)
			{
				for (int j=0;j<2000000;j++)
					if (dp[i][j])
					{
						if (j >= s[i])
							dp[i+1][j-s[i]] = true;
						dp[i+1][j+s[i]] = true;
						dp[i+1][j] = true;
					}
			}
			writer.printf("Case #%d:\n",ii);
			Vector<Integer> a = new Vector<Integer>();
			Vector<Integer> b = new Vector<Integer>();
			int p = 0;
			boolean ok = false;
			for (int i=20;i>0;i--)
			{
				if (p!=0)
					ok = true;
//				System.out.printf("%d %d %d\n",i-1,p,s[i]);
				if (dp[i-1][p+s[i-1]])
				{
					p = p+s[i-1];
					a.add(s[i-1]);
//					System.out.printf("a add %d\n",s[i-1]);
				}
				else
				if (p-s[i-1]>=0)
					if (dp[i-1][p-s[i-1]])
					{
						p = p-s[i-1];
						b.add(s[i-1]);
//						System.out.printf("b add %d\n",s[i-1]);
					}
			}
			if (!ok)
				writer.print("Impossible\n");
			else
			{
				int s2 = 0;
				for (int i=0;i<a.size();i++)
				{
					writer.printf("%d", a.elementAt(i));
					writer.print(i == a.size()-1 ? "\n" : " ");
					s2 = s2-a.elementAt(i);
				}
				for (int i=0;i<b.size();i++)
				{
					writer.printf("%d", b.elementAt(i));
					writer.print(i == b.size()-1 ? "\n" : " ");
					s2 = s2+b.elementAt(i);
				}
				System.out.println(s2);
			}
		}		
		writer.close();
		scanner.close();
	}

}
