package com.zccicy;

import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.Writer;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;

public class Main5 {
	public static class Mine
	{
		public Mine(int r,int c,int m)
			{
				this.r = r;
				this.c = c;
				this.m = m;
				this.mine_field = new char[r][c];
			}
		 
			char[][] mine_field;
			int r;
			int c;
			int m;
		
	}

	 
	public static void build_minefield(Mine mine,int r,int c)
	{
		for (int j = 0;j < mine.r; j++)
		{
			for (int k = 0;k < mine.c;k++)
			{
				mine.mine_field[j][k]='*';
			}
		}
		
		for (int j = 0;j < r; j++)
		{
			for (int k = 0;k < c;k++)
			{
				mine.mine_field[j][k]='.';
			}
		}
		mine.mine_field[0][0]='c';
	}
	
	public static void build_final_line(Mine mine,int r ,int c,int remain_mine)
	{
		int min_one = Math.min(r, c);
		System.out.println("mine_remain"+remain_mine+"\n");
		if (r == 2 || c ==2)
		{
			System.out.println("hhg");
		}
		for (int j = c-1;((j >= 2) && (remain_mine>0)); j--)
		{
			mine.mine_field[r-1][j]='*';
			remain_mine--;
		}
		for (int j = r-2;((j >= 2) && (remain_mine>0)); j--)
		{
			mine.mine_field[j][c-1]='*';
			remain_mine--;
		}
		 
		
		
		
	}
			

	
	public static boolean findsolution(Mine mine,int r,int c)
	{
		int remain_r = (mine.r - r);
		int remain_c = (mine.c - c);
		
		int mine_used = mine.r*mine.c - r*c ;
		int mine_remain =  mine.m - mine_used;
		
		if ((mine.r*mine.c-mine.m) == 1)
		{
			build_minefield(mine,1,1);
			return true;
		}
		
		if (r-1 >= 2 && c >= 2 && c <= mine_remain)
		{
			
			if (findsolution(mine, r-1, c))
			{
				return true;
			}
			 
		}
		if (r >= 2 && c-1 >= 2  && r <= mine_remain)
		{
			if (findsolution(mine, r, c-1))
			{
				return true;
			}
		}
		
		if (mine_remain == 0)
		{
			build_minefield(mine,r,c);
			return true;
		}
		if (r==2 && c ==2)
		{
			return false;
		}
		
		if ((r==2 || c ==2) )
		{
			return false;
		}
		
		if (mine_remain >= r + c - 4)
		{
			return false;
		}
		
		 
		build_minefield(mine, r, c);
		build_final_line(mine, r, c, mine_remain);
		//System.out.println("r "+r+"c "+c+"\n");
		return true;
		
	}
	
	public static void WriteResult(Mine mine,Writer writer,int i) throws Exception
	{
		
		writer.write("Case #"+(i+1)+":\n");
		for (int j = 0;j < mine.r; j++)
		{
			for (int k = 0;k < mine.c;k++)
			{
				writer.write(mine.mine_field[j][k]);
			}
			writer.write("\n");
		}
		
	}
	
	public static void main (String[] args)  throws Exception
	{
	 
		FileWriter writer=new FileWriter("d:/MineOutput3.txt");
		Scanner scanner=new Scanner(new FileInputStream("d:/C-small-attempt2.in"));
	    
		int count_case = scanner.nextInt();
		
		
	 		 
		for (int i =0;i<count_case;i++)
		{
			int r = scanner.nextInt();
			int c = scanner.nextInt();
			int count_mine = scanner.nextInt();
			Mine mine = new Mine(r,c,count_mine); 
			 
			
			 
			
			if ( (r == 1 || c == 1))
			{
				if (r*c <count_mine + 1) 
				{
					writer.write("Case #"+(i+1)+":\n"+"Impossible"+"\n");
				}
				else
				{
					
					for (int j = 0;j < r; j++)
					{
						 for (int k = 0;k < c;k++)
						 {
							 mine.mine_field[j][k]='*';
						 }
					}
					mine.mine_field[0][0]='c';
					int count_blank = r*c - 1 - count_mine;
					
					if (r == 1)
					{
						for (int k = 1;k <= count_blank;k++)
						 {
							mine.mine_field[0][k]='.';
						 }
					}
					else
					{
						for (int k = 1;k <= count_blank;k++)
						 {
							mine.mine_field[k][0]='.';
						 }
					}
					WriteResult(mine, writer, i);
					
				}
				continue;
			}
			System.out.println("i "+i+"\n");
			if (i == 9)
			{
				System.out.println("");
			}
			if (findsolution(mine,mine.r,mine.c))
			{
				WriteResult(mine,writer,i);
			}
			else
			{
				writer.write("Case #"+(i+1)+":\n"+"Impossible"+"\n");
			}
			
			 
			
		}
		
		writer.close();
	}
	
	static Comparator<Double> comparator = new Comparator<Double>(){
		   public int compare(Double d1, Double d2) {
		     
			   return -d1.compareTo(d2);
		   }
		  };
	
}
