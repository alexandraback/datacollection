package solve;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class tile {

	public static long[] gettile(int k,int c,int s) {
		int a=(int) Math.ceil(k/(1.0*c));
		System.out.println(a+"\n");
		long ans[]=new long[a];
		
		int j=0;
		for(int l=0;l<a;l++){
			long temp=0;
			long pow1=1;
			for(int i=0;i<c;i++)
			{
			    temp+=(long) (j*pow1);
			    j=(j+1)%k;
			    pow1=pow1*k;
			}
			ans[l]=temp+1;
		}	
		return ans;
		// TODO Auto-generated constructor stub
	}
	public static void main(String[] args) throws IOException {
		Scanner scanner = new Scanner(new File("D-large.in"));
		//int [] tall = new int [100];
		int total = scanner.nextInt();
		//System.out.println((long)Math.pow(9, 18));
		int k,c,s;
		
		FileWriter fw = new FileWriter("out.txt");
		for(int i=0;i<total;i++){
		   k = scanner.nextInt();
		   c = scanner.nextInt();
		   s = scanner.nextInt();
		   System.out.print(k+" "+c+" "+s+"\n");
		   if((int) Math.ceil(k/(1.0*c))>s){
			   fw.write("Case #"+(i+1)+": IMPOSSIBLE\n");
			   continue;
		   }
		   long[] n=gettile(k,c,s);
		   fw.write("Case #"+(i+1)+":");
		   for(int j=0;j<n.length;j++)
		   {
			   fw.write(" "+n[j]);			   
		   }
		   fw.write("\n");
		}
        fw.close();
		
	}
}
