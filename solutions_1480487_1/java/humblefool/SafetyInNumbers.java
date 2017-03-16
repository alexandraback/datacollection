import java.io.*;
import java.math.*;
import java.util.*;

public class SafetyInNumbers
{
	static Scanner sc = new Scanner(System.in);
	public static void main(String[] args)
	{
		for(int caseId=1,totalCases=sc.nextInt();caseId<=totalCases;caseId++)
		{
			System.out.print("Case #"+caseId+": ");
			
			//Add logic here
			System.out.println(solveCase());
			
			System.out.flush();
		}
	}
	
	public static String solveCase() {
		int N = sc.nextInt();
		int[] s = new int[N]; int sum = 0;
		for(int i=0;i<N;i++) {
			s[i] = sc.nextInt();
			sum += s[i];
		}
		double[] res = new double[N];
		for(int i=0;i<N;i++) {
			double lower = 0.0, upper = 1.0;
			for(int times=0;times <= 100;times++) {
				double middle = (lower + upper)/2.0;
				if (possible(s, sum, i, middle))
					upper = middle;
				else
					lower = middle;
			}
			res[i] = lower * 100.0;
		}
		String str = "" + res[0];
		for(int i=1;i<N;i++)
			str = str + " " + res[i];
		return str;
	}
	
	public static boolean possible(int[] s, int sum, int index, double fraction) {
		double score = fraction * sum + s[index];
		double rem = 1.0 - fraction;
		for (int i=0; i < s.length;i++) {
			if (i == index || s[i] >= score)
				continue;
			double req = (score - s[i])/ sum;
			if (req <= rem)
				rem -= req;
			else
				return true;
		}
		return false;
	}
}
