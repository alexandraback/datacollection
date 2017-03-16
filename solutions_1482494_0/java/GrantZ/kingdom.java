import java.util.*;
import java.io.*;
public class kingdom {

	public static void main(String[] args) throws Exception {
		Scanner sc=new Scanner(new File("input"));
		int size=sc.nextInt();
		for(int w=0;w<size;w++)
		{
			int t=sc.nextInt();
			int[][] arr=new int[t][2];
			for(int x=0;x<t;x++)
			{
				arr[x][0]=sc.nextInt();
				arr[x][1]=sc.nextInt();
				
			}
			
			for(int x=0;x<t;x++)
			{
				int a=arr[x][0];
				int b=arr[x][1];
				int i=x;
				for(int y=x+1;y<t;y++)
				{
					if(arr[y][1]<b)
					{
						i=y;
						b=arr[y][1];
						a=arr[y][0];
					}
					else if(arr[y][1]==b)
					{
						if(arr[y][0]<a)
						{
							i=y;
							b=arr[y][1];
							a=arr[y][0];
						}
					}
				}
				arr[i][0]=arr[x][0];
				arr[i][1]=arr[x][1];
				arr[x][0]=a;
				arr[x][1]=b;
			}
		//	for(int[] a:arr)System.out.println(Arrays.toString(a));
			
			
			int i=solve(arr);
			System.out.println("Case #"+(w+1)+": "+((i==-1)?"Too Bad":i));
			
		}
		
	}
	public static int solve(int[][] arr)
	{
		int stars=0;
		int iter=0;
		boolean chg=true;
		boolean[][] b=new boolean[arr.length][2];
		o:while(stars<arr.length*2 && chg)
		{
			chg=false;
			iter++;
			//for(boolean[] ba:b)System.out.println(Arrays.toString(ba));
			for(int x=0;x<arr.length;x++)
			{
				if(!b[x][1] && arr[x][1]<=stars)
				{
					chg=true;
					b[x][1]=true;
					if(b[x][0])stars++;
					else stars+=2;
					continue o;
				}
			}
			int best=-1;
			int dif=0;
			int i=0;
			for(int x=0;x<arr.length;x++)
			{
				if(!b[x][0] && !b[x][1] && arr[x][0]<=stars && (arr[x][1]-arr[x][0])>=best )
				{
					best=arr[x][1]-arr[x][0];
					i=x;
					
				}
			}
			if(best!=-1)
			{
				chg=true;
				stars++;
				b[i][0]=true;
			}
			
			
		}
		if(stars==arr.length*2)return iter;
		return -1;
	}
}
