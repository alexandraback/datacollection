import java.io.*;
import java.util.*;

public class StandingOvation {
	private static int[]audience;
	public static void main(String[]args) throws Exception
	{
		Scanner scan=new Scanner(new File("A-small-attempt0.in"));
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
				for(int k=audience.length-1;k>0;k--)
				{
					needed.add(k-lessshypeople(k));
				}
				Collections.sort(needed, Collections.reverseOrder());
				if(needed.get(0)>=0)
					System.out.println("Case #"+i+": "+needed.get(0));
				else
					System.out.println("Case #"+i+": 0");
			}
			else
				System.out.println("Case #"+i+": 0");
		}

	}
	private static int lessshypeople(int pos)
	{
		int count=0;
		for(int i=pos-1;i>=0;i--)
		{
			count+=audience[i];
		}
		return count;
	}
}
