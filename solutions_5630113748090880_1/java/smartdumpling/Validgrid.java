import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;


public class Validgrid {
	public static ArrayList<Integer> findmissingnumber(int[][] grid,int n)
	{
		int[] count= new int[2500];
		 ArrayList<Integer> obj = new ArrayList<Integer>();
		for(int i=0;i<2500;i++)
			count[i]=0;
		for(int i=0;i<2*n-1;i++)
		{
			for(int j=0;j<n;j++)
			{
				count[grid[i][j]-1]++;
			}
		}
		
		int k=0;
		for(int i=0;i<2500;i++)
		{
			if(count[i]%2!=0)
				obj.add(i+1);
		}
		Collections.sort(obj);
		
		return obj;
	}
	public static void main(String[] args) throws IOException {
		Scanner scanner = new Scanner(new File("B-large1.in"));
		//int [] tall = new int [100];
		int total = scanner.nextInt();
		
		System.out.println(total);
		
		FileWriter fw = new FileWriter("out.txt");
		for(int i=0;i<total;i++){
		   int n=scanner.nextInt();
		   int[][] grid=new int[2*n-1][n];
		   for(int k=0;k<2*n-1;k++)
			{
				for(int j=0;j<n;j++)
				{
					grid[k][j]=scanner.nextInt();
				}
			}
		   ArrayList<Integer> obj=findmissingnumber(grid,n);
		   fw.write("Case #"+(i+1)+": ");
		   for(int k=0;k<n;k++)
		   {
			   
			   fw.write(obj.get(k)+" ");
		   }
		   fw.write("\n");     
			   
		  
		}
        fw.close();
		
	}
}
