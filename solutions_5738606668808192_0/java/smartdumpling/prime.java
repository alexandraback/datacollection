package solve;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class prime {

	public static void getprime(int n,int j) throws IOException {
		// TODO Auto-generated constructor stub
		
		
		int c=1;
		int d=2;
		FileWriter fw = new FileWriter("out.txt");
		fw.write("Case #"+1+":"+"\n");
		int count=0;
		for(;c < n-1; c=c+2)
		{
			for(d=c+1;d < n-1; d=d+2)
			{
			
			for(int x=d+1;x < n-1; x=x+2)
			{
				for(int y=x+1;y < n-1; y=y+2)
				{
					int[] a=new int[n];
					a[0]=1;
					a[n-1]=1;
					a[c]=1;
					a[d]=1;
					a[x]=1;
					a[y]=1;
					for(int i=0;i<a.length;i++){
						System.out.println(a[i]);
						fw.write(""+a[i]);
					}
					fw.write(" ");
					fw.write("3 2 3 2 7 2 3 2 3\n");
					count++;
					if(count==j){
						fw.close();
						return;
					}
						
				}
			}
			}
		}
	}
	public static void main(String[] args) throws IOException {
		Scanner scanner = new Scanner(new File("C-small-attempt0.in"));
		//int [] tall = new int [100];
		int total = scanner.nextInt();
		System.out.println(total);
		int n,j;
		
		
		for(int i=0;i<total;i++){
		   n = scanner.nextInt();
		   System.out.println(n);
		   j = scanner.nextInt();
		   System.out.println(j);
		   getprime(n,j);		   
		   
		}
        
	}
}
