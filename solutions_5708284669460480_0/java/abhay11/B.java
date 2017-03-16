import java.io.*;
import java.util.*;

public class B
{
	public static void main(String[] args) throws IOException
	{
		Scanner in=new Scanner(System.in);
		int numRuns=in.nextInt();
		for (int run=1; run<=numRuns; run++)
		{
			int k=in.nextInt(), l=in.nextInt(), s=in.nextInt();
			
			double[] count=new double[26];
			String keys=in.next();
			for (int i=0; i<k; i++)
				count[keys.charAt(i)-'A']++;
			
			String target=in.next()+" ";
			int[] next=new int[l+1];
			// INIT NEXT FROM KMP
			{
				int i, j;
				next[0]=-1;
				for (i=0, j=-1; i<l; i++, j++, next[i]=(target.charAt(i)==target.charAt(j))?next[j]:j)
					while ((j>=0)&&(target.charAt(i)!=target.charAt(j))) j=next[j];
//				for (int www: next)
	//				System.out.print(www+" ");
		//		System.out.println();
			}
			
			int max=(s-next[l])/(l-next[l]);
			for (int i=0; i<l; i++)
				if (count[target.charAt(i)-'A']==0)
					max=0;
			
			double[][] dp=new double[s+1][l+1];
			dp[0][l]=1;
			for (int i=1; i<=s; i++)
			{
				for (int j=0; j<l; j++)
				{
					for (int m=0; m<26; m++)
					{
						if (count[m]==0) continue;
						
						int ind=j;
						while (ind>=0 && (target.charAt(ind)-'A')!=m) ind=next[ind];
						dp[i][j]+=(count[m]/k)*dp[i-1][ind+1];
					}
				}
				dp[i][l]=1+dp[i][next[l]];
			}
			System.out.println("Case #"+run+": "+(max-dp[s][0]));
		}
	}
}