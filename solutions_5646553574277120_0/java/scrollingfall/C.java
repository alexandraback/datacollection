import java.io.*;
import java.util.*;
public class C {
	public static void main(String[]args) throws Exception
	{
		Scanner scan=new Scanner(new File("C-small-attempt1.in"));
		PrintWriter o=new PrintWriter(new File("Cout1.txt"));
		int n=Integer.parseInt(scan.nextLine());
		for(int i=1;i<=n;i++)
		{
			String[]cs=scan.nextLine().split(" ");
			int c=Integer.parseInt(cs[0]);
			int d=Integer.parseInt(cs[1]);
			int v=Integer.parseInt(cs[2]);
			String[]vs=scan.nextLine().split(" ");
			int[] is=new int[vs.length];
			ArrayList<Integer>ia=new ArrayList<Integer>();
			for(int j=0;j<is.length;j++)
			{
				is[j]=Integer.parseInt(vs[j]);
				ia.add(Integer.parseInt(vs[j]));
			}
			Collections.sort(ia);
			int ans=0;
			if(ia.get(0)!=1)
			{
				ia.add(1);
				Collections.sort(ia);
				ans++;
			}
			ia.add(v);
			for(int j=1;j<ia.size();j++)
			{
				int diff=0;
				for(int k=0;k<j;k++)
					diff+=ia.get(k);
				int diff2=ia.get(j)-diff;
				if(diff2>1)
				{
					ia.add(diff+1);
					Collections.sort(ia);
					ans++;
				}
			}
			int sum=0;
			for(int j=0;j<ia.size()-1;j++)
				sum+=ia.get(j);
			if(v-sum==1)
				ans++;
			o.println("Case #"+i+": "+ans);	
		}
		scan.close();
		o.close();
	}
}
