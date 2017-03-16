import java.io.*;
import java.util.Scanner;
public class q2{
	static int i,j,c,v,d,x,a[];
	public static void main(String[]args) throws UnsupportedEncodingException,FileNotFoundException{
		FileInputStream fis = new FileInputStream("C-small-attempt0.in") ;
		Scanner sc = new Scanner(fis);
		PrintWriter writer = new PrintWriter("out2.txt", "UTF-8");
		int count;
		int sum;
		int test = sc.nextInt();
		for(i=1;i<=test;i++){
			c=sc.nextInt();
			d=sc.nextInt();
			v=sc.nextInt();
			a=new int[d];
			for(j=0;j<d;j++)
				a[j]=sc.nextInt();
			sum=0;
			j=1;x=0;
			count=0;
			while(j<=v){
				if(x<d)
				if(a[x]==j){
					sum=sum+a[x];
					x++;
				}
				
				if(sum<j){
					sum+=j;
					count++;
				}
				j++;
			}
			
			writer.println("Case #"+i+": "+count);
			System.out.println("Case #"+i+": "+count);
		}
		writer.close();
	}
}