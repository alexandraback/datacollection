package R2012;

import java.io.File;
import java.io.FileWriter;
import java.util.Scanner;

public class SafetyNumbers {

	public static void main(String[] args) {
		int T,count,n,mc;
		double sum,ju,mv;
		double[] a;
		boolean[] big;
		try {
			FileWriter out = new FileWriter("a.out");  
			//Scanner in=new Scanner(System.in);
			Scanner in=new Scanner(new File("A-small-attempt3.in"));
			T=in.nextInt();
			count=0;
			while((++count)<=T)
			{
				n=in.nextInt();
				a=new double[n];
				big=new boolean[n];
				sum=0;
				for(int i=0;i<n;++i)
				{
					a[i]=in.nextInt();
					sum+=a[i];
				}
				ju=2.0/n;
				mv=0;
				mc=0;
				for(int i=0;i<n;++i)
				{
					if(!big[i])
					{
						if(a[i]/sum>=ju)
						{
							big[i]=true;
						}else
						{
							++mc;
							mv+=a[i];
						}
					}
					
				}
				for(int i=0;i<n;++i)
				{
					if(!big[i])
					{
						a[i]=((sum+mv)/mc-a[i])/sum;
					}
				}
				//ju=2.0/mc;
				out.write("Case #"+count+":");
				for(int i=0;i<n;++i)
				{
					if(big[i])
						out.write(" 0");
					else
						out.write(" "+String.format("%.6f", a[i]*100));
				}
				out.write("\r\n");
			}
			
			in.close(); 
			out.close();  
		} catch (Exception exc) {
			exc.printStackTrace();
		}
	}

}
