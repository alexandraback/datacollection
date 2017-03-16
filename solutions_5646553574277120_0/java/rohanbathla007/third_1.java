package coding;

import java.util.Scanner;


public class third_1 {
	
	int solve(int c, int d, int v, int arr[])
	{
		int ans=0,i;
		int count[]=new int[arr[d-1]+1];
		for(i=0;i<d;i++)
			++count[arr[i]];
		for(i=1;i<=v;i++)
		{
			
		}
		return ans;
	}
	
	void count_all(int x, int j, int arr[], int count[], int c, int d, int v, int sum)
	{
		int i;
		if(sum>v)
			return;
		if(x==1)
		{
			for(i=j+1;i<d;i++)
			{
				System.out.print(arr[i]);
				System.out.println();
				int val=sum+arr[i];
				if(val>v)
					break;
				++count[val];
			}
			System.out.println();
		}
		else
		{
			for(i=j+1;i<d;i++)
			{
				System.out.print(arr[i]+" ");
				count_all(x-1,i,arr,count,c,d,v,sum+arr[i]);
			}
		}
	}
	
	void count_all2(int x,int j,int c, int d, int v, int arr[], int count[], int sum)
	{
		int i;
		if(x<1)
			return;
		for(i=j+1;i<d;i++)
		{
			int val=sum+arr[i];
			if(val>v)
				break;
			count_all2(x-1,i+1,c,d,v,arr,count,val);
			++count[val];
		}
	}
	
	int solve_small(int c, int d, int v, int arr[])
	{
		int ans=0,i,j,count[]=new int[v+1];
		for(i=1;i<=d;i++)
		{
			count_all2(i,-1,c,d,v,arr,count,0);
		}
		for(i=1;i<=v;i++)
		{
			if(count[i]==0)
				++ans;
		}
		return ans;
	}
	
	void read()
	{
		Scanner in=new Scanner(System.in);
		int t=in.nextInt(),ca=1;
		while((t--)!=0)
		{
			System.out.print("Case #"+ca+": ");
			++ca;
			int c=in.nextInt(),d=in.nextInt(),v=in.nextInt();
			int arr[]=new int[d],i;
			for(i=0;i<d;i++)
				arr[i]=in.nextInt();
			System.out.println(solve_small(c,d,v,arr));
		}
	}

	public static void main(String[] args) {
		
		third_1 obj=new third_1();
		obj.read();

	}

}
