import java.io.*;
import java.util.*;

public class GCJ_A {
	
	public static double minp(int[] ss,int sums) {
		int le = 0;
		int ule = 0;
		int ps = 0;
		for (int i=0;i<ss.length;i++)
		{
			ps += ss[i];
			int need = ss[i]*(i+1) - ps;
//			System.out.printf("ps: %d   ss:%d   need:%d   sums:%d\n",ps,ss[i],need,sums);
			if (need < sums)
			{
				le = i;
				ule = need;
			}
		}
//		System.out.printf("le: %d   ule: %d   sums: %d" ,le,ule,sums);
		
		return (double)(ss[le]) + (double)(sums - ule) / (double)(le+1.0);
	}

	public static void main(String[] args) throws Exception {
		String fname = "A-large";
		Scanner scanner = new Scanner(new File(fname+".in"));
		PrintWriter writer = new PrintWriter(new FileWriter(fname+".out"));
		
		int tt = Integer.parseInt(scanner.next());
		System.out.println(tt);
		for (int ii=1;ii<=tt;ii++)
		{
			int n = Integer.parseInt(scanner.next());
			int[] s = new int[n];
			int[] ss = new int[n];
			int[] so = new int[n];			
			int sums = 0;
			for (int i=0;i<n;i++)
			{
				s[i] = Integer.parseInt(scanner.next());
				ss[i] = s[i];
				sums += s[i];
			}
			
			Arrays.sort(ss);
			double mp = minp(ss,sums);
			
			writer.printf("Case #%d:",ii);
			
			for (int i=0;i<n;i++)
			{				
				double r = (mp-(double)s[i]) / (double)(sums)*100.0;
				if (r<0.0) r = 0.0;
				writer.printf(" %1.6f",r);
			}	
			writer.printf("\n");
		}		
		writer.close();
		scanner.close();
		System.out.println("OK");
	}

}
