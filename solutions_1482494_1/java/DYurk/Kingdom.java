import java.util.*;
import java.io.*;
public class Kingdom
{	
	static int[][] stars;
	static boolean[][] done;
	
	public static void main(String[] args)throws IOException
	{
		Scanner oScan = new Scanner(new File("kingdom.in"));
		System.setOut(new PrintStream(new File("kingdom.out")));
		int o_0 = oScan.nextInt();oScan.nextLine();
		for(int run=0;run<o_0;run++)
		{
			int lev=oScan.nextInt();oScan.nextLine();
			stars = new int[lev][3];
			for(int i=0;i<lev;i++)
			{
				//System.out.println(i);
				stars[i][0]=oScan.nextInt();
				stars[i][1]=oScan.nextInt();
				if(oScan.hasNextLine())oScan.nextLine();
				stars[i][2]=i;
			}
			done = new boolean[lev][2];
			//if(oScan.hasNextLine())oScan.nextLine();
			int starC=0,count=0;
			System.out.print("Case #"+(run+1)+": ");
			Kingdom K = new Kingdom();
			while(lev>0)
			{
				Arrays.sort(stars, K.new levComp(starC));
				if(starC>=stars[0][1])
				{
					starC+=done[stars[0][2]][0]?1:2;
					done[stars[0][2]][0]=true;
					done[stars[0][2]][1]=true;
					stars[0][0]=Integer.MAX_VALUE;
					stars[0][1]=Integer.MAX_VALUE;
					lev--;
				}
				else if(starC>=stars[0][0])
				{
					starC+=1;
					done[stars[0][2]][0]=true;
					stars[0][0]=Integer.MAX_VALUE;
				}
				else
				{
					System.out.println("Too Bad");
					break;
				}
				count++;
			}
			if(lev==0)System.out.println(count);
			/*int min=Integer.MAX_VALUE;
			for(int i=0;i<lev;i++)
				min = Math.min(min, doLev(i,0,lev,0));
			System.out.println(min==Integer.MAX_VALUE?"Too Bad":min);*/
		}
	}
	
	class levComp implements Comparator<int[]>
	{
		int star;
		
		public levComp(int s)
		{
			star=s;
		}
		
		public boolean equals(int[] i1, int[] i2)
		{
			return i1[2]==i2[2];
		}
		
		public int compare(int[] i1, int[] i2)
		{
			if(star>=i1[1]&&star>=i1[0])return -1;
			if(star>=i2[1]&&star>=i2[0])return 1;
			if(star>=i1[1])return -1;
			if(star>=i2[1])return 1;
			if(star>=i1[0])
			{
				if(star>=i2[0])return i2[1]-i1[1];
				return -1;
			}
			if(star>=i2[0])return 1;
			return 0;
		}
	}
}
/*static int doLev(int i, int star, int lev, int count)
{
	if(lev==0)return count;
	int min = Integer.MAX_VALUE;
	if(star>=stars[i][1]&&star>=stars[i][0])
	{
		int temp1=stars[i][1];
		stars[i][1]=Integer.MAX_VALUE;
		int temp0=stars[i][0];
		stars[i][0]=Integer.MAX_VALUE;
		for(int a=0;a<stars.length;a++)
			min = Math.min(min, doLev(a,star+2,lev-1,count+1));
		stars[i][1]=temp1;
		stars[i][0]=temp0;
	}
	else if(star>=stars[i][1])
	{
		int temp1=stars[i][1];
		stars[i][1]=Integer.MAX_VALUE;
		for(int a=0;a<stars.length;a++)
			min = Math.min(min, doLev(a,star+1,lev-1,count+1));
		stars[i][1]=temp1;
	}
	else if(star>=stars[i][0])
	{
		int temp0=stars[i][0];
		stars[i][0]=Integer.MAX_VALUE;
		for(int a=0;a<stars.length;a++)
			min = Math.min(min, doLev(a,star+1,lev,count+1));
		stars[i][0]=temp0;
	}
	return min;
}*/