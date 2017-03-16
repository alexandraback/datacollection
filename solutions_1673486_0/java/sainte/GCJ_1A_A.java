
import java.io.*;
import java.util.*;

public class GCJ_1A_A
{
//	public static String 
//	public static int 
//	ArrayList list = new ArrayList();
//	HashMap map = new HashMap();
//	HashSet set = new HashSet();
	
//	for(int i=0;i<;i++)
	
//	for(int j=0;j<;j++)
	
//	for(int k=0;k<;k++)
	
//	System.out.println();
//	System.out.print();
//	System.out.printf("", new Object{});
//	System.out.printf("", new Integer{});
//	System.out.printf("", new Long{});
	
	public static void main(String[] args) throws Exception
	{
	//	Scanner scanner = new Scanner(new FileInputStream("A.txt"));
		Scanner scanner = new Scanner(new FileInputStream("A-small-attempt2.in"));
		//	Scanner scanner = new Scanner(new FileInputStream("A-large.in"));
		
		BufferedWriter writer = new BufferedWriter(new FileWriter("A.out"));
		
		int N = scanner.nextInt();
		//	scanner.nextLine();
		for(int q=1;q<=N;q++)
		{
			int a = scanner.nextInt();
			int b = scanner.nextInt();
			double[] r = new double[a];
			for(int i=0;i<a;i++)
				r[i] = scanner.nextDouble();
			String ans = answer(b, r);
			System.out.printf("Case #"+q+": %.6f\n", new Double[]{new Double(ans)});
			writer.write("Case #"+q+": "+ans);
			writer.newLine();
		}
		
		writer.close();
		scanner.close();
	}
	
	public static String answer(int b, double[] r) throws Exception
	{
		double[] rates = new double[(int)Math.pow(2, r.length)];
		
		if(rates.length==8)
		{
			rates[0] =    r[0]	*	   r[1]		*    r[2];
			rates[1] =    r[0]	*	   r[1]		* (1-r[2]);
			rates[2] =    r[0]	*	(1-r[1])	*    r[2];
			rates[3] = (1-r[0])	*	   r[1]		*    r[2];
			rates[4] =    r[0]	*	(1-r[1])	* (1-r[2]);
			rates[5] = (1-r[0])	*      r[1]		* (1-r[2]);
			rates[6] = (1-r[0])	*	(1-r[1])	*    r[2];
			rates[7] = (1-r[0])	*	(1-r[1])	* (1-r[2]);

			double sumr = (rates[0]+rates[1]+rates[2]+rates[4]);
			double n2 = (2*2+b-r.length+1)*sumr+(2*2+2*b-r.length+2)*(1-sumr);
			sumr = (rates[0]+rates[1]);
			double n1 = (2+b-r.length+1)*sumr+(2+2*b-r.length+2)*(1-sumr);
			double clear = b+2;
			double go = rates[0]*(b-r.length+1) + (1-rates[0])*(2*b-r.length+1);
			
			double min = go;
			if(min > clear)
				min = clear;
			if(min > n2)
				min = n2;
			if(min > n1)
				min = n1;
			
			return min+"";
		}
		
		if(rates.length==4)
		{
			rates[0] =    r[0]	*	   r[1]	;
			rates[1] =    r[0]	*	(1-r[1]);
			rates[2] = (1-r[0])	*	   r[1]	;
			rates[3] = (1-r[0])	*	(1-r[1]);

			double sumr = (rates[0]+rates[1]);
			double n1 = (2*2+b-r.length+1)*sumr+(2*2+2*b-r.length+1)*(1-sumr);
			double clear = b+2;
			double go = rates[0]*(b-r.length+1) + (1-rates[0])*(2*b-r.length+1);
			
			double min = go;
			if(min > clear)
				min = clear;
			if(min > n1)
				min = n1;
			
			return min+"";
		}
		
		if(rates.length==2)
		{
			rates[0] =    r[0];
			rates[1] =    1-r[0];

			double clear = b+2;
			double go = rates[0]*(b-r.length+1) + (1-rates[0])*(2*b-r.length+1);
			
			double min = go;
			if(min > clear)
				min = clear;
			
			return min+"";
		}
		
		
		return null;
	}
	
	
	
}

