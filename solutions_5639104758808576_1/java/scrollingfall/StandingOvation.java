import java.io.*;
import java.util.*;

public class StandingOvation {
	private static int[]audience;
	public static void main(String[]args) throws Exception
	{
		PrintWriter o=new PrintWriter(new File("standingovationgout2.txt"));
		Scanner scan=new Scanner(new File("A-large.in"));
		int n=Integer.parseInt(scan.nextLine());
		for(int i=1;i<=n;i++)
		{
			String s=scan.nextLine().split(" ")[1];
			if(s.length()>1)
			{
				audience=new int[s.length()];
				for(int j=0;j<s.length();j++)
				{
					audience[j]=Integer.parseInt(s.substring(j,j+1));
				}
				ArrayList<Integer>needed=new ArrayList<Integer>();
				int lessshy=audience[0];
				for(int k=1;k<audience.length;k++)
				{
					needed.add(k-lessshy);
					lessshy+=audience[k];
				}
				Collections.sort(needed, Collections.reverseOrder());
				if(needed.get(0)>=0)
					o.println("Case #"+i+": "+needed.get(0));
				else
					o.println("Case #"+i+": 0");
			}
			else
				o.println("Case #"+i+": 0");
		}
		o.close();
	}
}
