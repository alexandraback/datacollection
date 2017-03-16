import java.util.*;
import java.io.*;
public class pass {

	public static void main(String[] args) throws Exception {
		Scanner sc=new Scanner(new File("inpu1"));
		int size=sc.nextInt();
		for(int w=0;w<size;w++)
		{
			int a=sc.nextInt();
			int b=sc.nextInt();
			
			double[] p=new double[a];
			for(int x=0;x<a;x++)p[x]=sc.nextDouble();
			System.out.println("Case #"+(w+1)+": "+ex(a,b,p));
			
		}
	}
	public static double ex(int a,int b,double[] p)
	{
		double best=b+2;
		for(int bs=0;bs<=a;bs++)
		{
			double prob=1;
			for(int x=0;x<a-bs;x++)prob*=p[x];
			double s1=bs*2+b-a+1;
			double s2=bs*2+b-a+b+2;
			double ex=s1*prob+s2*(1-prob);
			best=Math.min(ex, best);
			//System.out.println(best+" "+ex+" "+s1+" "+s2);
		}
		return best;
	}
}
