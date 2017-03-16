import java.io.*;
import java.util.*;

public class GCJ_1B_A
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
	//		Scanner scanner = new Scanner(new FileInputStream("A-small-attempt3.in"));
		Scanner scanner = new Scanner(new FileInputStream("A-large.in"));
		
		BufferedWriter writer = new BufferedWriter(new FileWriter("A.out"));
		
		int N = scanner.nextInt();
		//	scanner.nextLine();
		for(int q=1;q<=N;q++)
		{
			int n = scanner.nextInt();
			int[] s = new int[n];
			for(int i=0;i<n;i++)
				s[i] = scanner.nextInt();
		//	int k = scanner.nextInt();
			String ans = answer(s);
			System.out.println("Case #"+q+": "+ans);
			writer.write("Case #"+q+": "+ans);
			writer.newLine();
		}
		
		writer.close();
		scanner.close();
	}
	
	public static String answer(int[] s) throws Exception
	{
		int sum = 0;
		
		for(int i=0;i<s.length;i++)
			sum += s[i];
		
		StringBuffer ans = new StringBuffer();
		double bunbo = (double)(sum*s.length);
		boolean[] win100 = new boolean[s.length];
		boolean has100 = false;
		double[] answers = new double[s.length];
		
		int newSum = sum;
		int newCount = s.length;
		
		for(int i=0;i<s.length;i++)
		{
			double bunsi = sum-s[i]+sum-(s.length-1)*s[i];
			double a = (100*bunsi/bunbo);
			if(a<0)
			{
				win100[i] = true;
				has100 = true;
				a = 0;
				newSum -= s[i];
				newCount--;
			}
			
			answers[i] = a;
		}
		
		if(has100)
		{
			bunbo = (double)(sum*newCount);
			
			for(int i=0;i<s.length;i++)
			{
				if(!win100[i])
				{
					double bunsi = newSum-s[i]+sum-(newCount-1)*s[i];
					double a = (100*bunsi/bunbo);
					answers[i] = a;
				}
			}
		}
		
		for(int i=0;i<answers.length;i++)
		{
			ans.append(answers[i]);
			if(i+1!=s.length)
				ans.append(" ");
		}
		
		return ans.toString();
	}
	
	
	
}
