package R2012;

import java.io.File;
import java.io.FileWriter;
import java.util.Scanner;

public class DiamondInheritance {

	public static int[][] copy(int[][] a,int n) {
		int[][] te=new int[n][n];
		for(int i=0;i<n;++i)
			for(int j=0;j<n;++j)
				te[i][j]=a[i][j];
		return te;
	}
	public static boolean add(int[][] ps,int[][] as,int n) {
		
		for(int i=0;i<n;++i)
			for(int j=0;j<n;++j)
			{
				ps[i][j]+=as[i][j];
				if(ps[i][j]>1)
					return true;
			}
		return false;
	}
	public static boolean two(int[][] a,int[][] as,int n) {
		int[][] te=copy(as,n);
		int tem;
		for(int i=0;i<n;++i)
			for(int j=0;j<n;++j)
			{
				tem=0;
				for(int k=0;k<n;++k)
					tem+=te[i][k]*a[k][j];
				as[i][j]=tem;
				if(as[i][j]>1)
					return true;
			}
		return false;
	}
	public static void main(String[] args) {
		int T,count,n,m,num;
		int[][] a;
		int[][] as;
		int[][] ps;
		try {
			FileWriter out = new FileWriter("a.out");  
			//Scanner in=new Scanner(System.in);
			Scanner in=new Scanner(new File("A-small-attempt0.in"));
			T=in.nextInt();
			count=0;
			while((++count)<=T)
			{
				n=in.nextInt();
				a=new int[n][n];
				
				num=0;
				for(int i=0;i<n;++i)
				{
					m=in.nextInt();
					num+=m;
					for(int j=0;j<m;++j)
						a[i][in.nextInt()-1]=1;
				}
				as=copy(a,n);
				ps=copy(a,n);
				while((--num)>=0)
				{
					if(two(a,as,n))
						break;
					if(add(ps,as,n))
						break;
				}
				if(num>=0)
					out.write("Case #"+count+": Yes\r\n"); 
				else
					out.write("Case #"+count+": No\r\n"); 
			}
			
			in.close(); 
			out.close();  
		} catch (Exception exc) {
			exc.printStackTrace();
		}
		
	}

}
