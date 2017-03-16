import java.io.*;
import java.util.*;
public class PartElf
{
	public static void main(String args[])throws IOException
	{
	Scanner sc = new Scanner(new File("PE_l.in"));
	PrintWriter pw = new PrintWriter(new FileWriter("PE_l.out"));
	int T=sc.nextInt();
	int i,count,ctr;
	boolean flag;
	String s="";
	double P,Q,ratio;
	for(i=1;i<=T;i++)
	{
		s=sc.next();
		P=Long.parseLong(s.substring(0,s.indexOf('/')));
		Q=Long.parseLong(s.substring(s.indexOf('/')+1));
		count=0;
		ctr=0;
		ratio=P/Q;
		flag=true;
		while(ratio!=1&&ctr<=40)
		{

			if(ratio<1)
			{
				if(flag)
				count++;
			}
			else
			{
				flag=false;
				ratio-=1;
			}
			ratio*=2;
			ctr++;
		}
		if(ratio-1==0)
		pw.println("Case #"+i+": "+count);
		else
		pw.println("Case #"+i+": impossible");


	}
	sc.close();
	pw.close();
	}
}