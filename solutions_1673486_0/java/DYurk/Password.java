import java.util.*;
import java.io.*;
public class Password
{
	static double[] prob;
	static double val;
	
	public static void main(String[] args)throws IOException
	{
		Scanner oScan = new Scanner(new File("password.in"));
		System.setOut(new PrintStream(new File("password.out")));
		int o_0 = oScan.nextInt();oScan.nextLine();
		for(int run=0;run<o_0;run++)
		{
			int A = oScan.nextInt(), B = oScan.nextInt();oScan.nextLine();
			prob = new double[A];
			for(int i=0;i<A;i++)
				prob[i]=oScan.nextDouble();
			if(oScan.hasNextLine())oScan.nextLine();
			double min=Double.MAX_VALUE;
			for(int back=0;back<=A;back++)
			{
				val=0;
				//System.out.println("Deleting "+back);
				getEx(0,A-back,B+1,1,false);
				val+=back;
				if(val<min)min=val;
			}
			min = Math.min(min, B+2);
			System.out.printf("Case #"+(run+1)+": %.6f\n",min);
		}
	}
	
	static void getEx(int i, int lim, int len, double runP, boolean wrong)
	{
		if(i==lim)
		{
			val+=((len-lim)+(wrong?len:0))*runP;
			//System.out.println(val+" "+wrong);
			return;
		}
		getEx(i+1,lim,len,runP*prob[i],wrong);
		getEx(i+1,lim,len,runP*(1-prob[i]),true);
	}
}
