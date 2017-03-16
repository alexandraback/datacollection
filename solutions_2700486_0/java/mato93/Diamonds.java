package Round_1B;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Random;
import java.util.Scanner;

public class Diamonds
{
	public static Random rand = new Random();
	static int maxLeft=20001;
	static int maxRight=0;
	static int maxUp=0;
	
	public static void slide(boolean[][] a,  int x, int y)
	{
		if(y==0)
		{
			a[x][y]=true;
			a[x-1][y]=true;
			a[x+1][y]=true;
			a[x][y+1]=true;
			
			if(x-1<maxLeft) maxLeft=x-1;
			if(x+1>maxRight) maxRight=x+1;
			if(y+1>maxUp) maxUp=y+1;
				
			return;
		}
		
		if (!a[x][y-1]) slide(a,x,y-1);
		else
		{
			if(a[x-1][y-1] && a[x+1][y-1]) // sth to both sides 
			{
				a[x][y]=true;
				a[x][y+1]=true;
				if(y+1>maxUp) maxUp=y+1;
				return;
			} else
			if(a[x-1][y-1] && !a[x+1][y-1]) // sth to the left
			{
				slide(a,x+1,y-1);
			} else
			if(!a[x-1][y-1] && a[x+1][y-1]) // sth to the right
			{
				slide(a,x-1,y-1);
			} else // both sides clear
			{
				if(rand.nextBoolean())  slide(a,x-1,y-1);
				else					slide(a,x+1,y-1);	
			}
			
		}
	}
	
	
	public static void main(String[] args) 
	{
		try{
			String readFrom = "1B/B-small-attempt0.in";
			Scanner sc = new Scanner(new File(readFrom));
			FileWriter out = new FileWriter(new File("1B/B-small-attempt0.out"));
			
			
			double answer=0;
			int testCases = sc.nextInt();
			
			int interestedX,interestedY;
			double probability = 0;
			boolean[][] a = new boolean[20001][10001];
			int n;
			int num = 100000;
			
			for(int k=1; k<=testCases; k++)
			{
				n = sc.nextInt();
				interestedX = sc.nextInt();
				interestedY = sc.nextInt();
				
				probability = 0;
				
				maxLeft=20001;
				maxRight=0;
				maxUp=0;
				
				for (int t=0; t<num; t++)
				{	
					for(int i=1; i<=n; i++)
						slide(a,10000,20);
					
					if(a[10000+interestedX][interestedY]) probability += 1;
					
					for(int i=maxLeft; i<= maxRight; i++)
						for(int j=0; j<=maxUp; j++)
							a[i][j] = false;
				}
				
				answer = probability/num;
				System.out.println("Case #"+k+": "+answer);
				out.write("Case #"+k+": "+answer+"\n");
			
			}

			out.close();
		}catch(IOException e)
		{
			System.out.println("IO error");
		}

	}

}
