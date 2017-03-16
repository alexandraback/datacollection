
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class c
{
	static String path="C:\\CodeJam14\\";
	static String fileInput="C-large.in";
	static String fileOutput="output.txt";
	static Scanner sc;
	static BufferedWriter bw;
	static boolean possible;
	
	public static void main(String args[]) throws IOException
	{
		sc=new Scanner(new FileReader(path+fileInput));
		bw=new BufferedWriter(new FileWriter(path+fileOutput));
	
		int numCases=sc.nextInt();
		for(int cur=0;cur<numCases;cur++)
		{
			bw.write("Case #"+(cur+1)+":");
			boolean flag=false;
			possible=true;
			int x=sc.nextInt();
			int y=sc.nextInt();
			int num=sc.nextInt();
			if(x>y){int t=x;x=y;y=t;flag=true;}
			//x<=y
			char[][] grid=fill(x,y,num);
			if(possible)
				bw.write("\n"+stringify(grid,flag));
			else
				bw.write("\nImpossible\n");
		}
		//1,4,6,8,9
		bw.close();
	}
	
	public static char[][] fill(int x, int y, int num)
	{
		if(num==0)
		{
			return pop(x,y);
		}
		if(x==1)
		{
			return caseSingle(y,num);
		}
		
		if(x==2)
		{
			return caseDouble(y,num);
		}
		
		return caseGen(x,y,num);
	}
	
	public static char[][] caseGen(int x, int y, int num)
	{
		char[][] grid=pop(x,y);
		int bomb=0;
		for(int j=0;j<y-2;j++)
		{
			for(int i=0;i<x-2;i++)
			{
				grid[i][j]='*';
				bomb++;
				if(bomb==num)
				{
					possible=true;
					return grid;
				}
			}
		}
		if((num-bomb)%2==0)
		{
			for(int i=0;i<x-2;i++)
			{
				for(int j=y-2;j<y;j++)
				{
					grid[i][j]='*';
					bomb++;
				}
				if(bomb==num)
				{
					possible=true;
					return grid;
				}
			}
			for(int j=0;j<y-2;j++)
			{
				for(int i=x-2;i<x;i++)
				{	
					grid[i][j]='*';
					bomb++;
				}
				if(bomb==num)
				{
					possible=true;
					return grid;
				}
			}
			possible=false;
			return null;
		}
		else
		{
			bomb--;
			grid[x-3][y-3]='.';
			for(int i=0;i<x-3;i++)
			{
				for(int j=y-2;j<y;j++)
				{
					grid[i][j]='*';
					bomb++;
				}
				if(bomb==num)
				{
					possible=true;
					return grid;
				}
			}
			for(int j=0;j<y-3;j++)
			{
				for(int i=x-2;i<x;i++)
				{	
					grid[i][j]='*';
					bomb++;
				}
				if(bomb==num)
				{
					possible=true;
					return grid;
				}
			}
			if(num-bomb==8)
			{
				possible=true;
				for(int j=y-3;j<y;j++)
				{
					for(int i=x-3;i<x;i++)
					{	
						grid[i][j]='*';
						bomb++;
					}
				}
				grid[x-1][y-1]='c';
				return grid;
			}
			possible=false;
			return null;
		}
	}
	
	public static char[][] caseDouble(int y, int num)
	{
		char[][] grid=pop(2,y);
		int bomb=0;
		for(int j=0;j<y;j++)
		{
			for(int i=0;i<2;i++)
			{
				grid[i][j]='*';
				bomb++;
				if(bomb==num)
				{
					
					possible=((num%2)==0);
					if(y*2-num<4)
						possible=false;
					if(num==(y*2-1))
						possible=true;
					return grid;
				}
			}
		}
		possible=true;
		return null;
	}
	
	public static char[][] caseSingle(int y, int num)
	{
		char[][] grid=pop(1,y);
		for(int j=0;j<num;j++)
		{
			grid[0][j]='*';
		}
		possible=true;
		return grid;
	}
	
	public static char[][] pop(int x, int y)
	{
		char[][] grid=new char[x][y];
		for(int i=0;i<x;i++)
			for(int j=0;j<y;j++)
				grid[i][j]='.';
		grid[x-1][y-1]='c';
		return grid;
	}
	
	public static String stringify(char[][] grid, boolean flag)
	{
		String ret="";
		if(!flag)
		{
			for(int i=0;i<grid.length;i++)
			{
				for(int j=0;j<grid[i].length;j++)
					ret+=grid[i][j];
				ret+="\n";
			}
		}
		else
		{
			for(int i=0;i<grid[0].length;i++)
			{
				for(int j=0;j<grid.length;j++)
					ret+=grid[j][i];
				ret+="\n";
			}
		}
		return ret;
	}
}
