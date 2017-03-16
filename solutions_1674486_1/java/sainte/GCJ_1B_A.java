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
	//		Scanner scanner = new Scanner(new FileInputStream("A.txt"));
	//		Scanner scanner = new Scanner(new FileInputStream("A-small-attempt4.in"));
	Scanner scanner = new Scanner(new FileInputStream("A-large.in"));
		BufferedWriter writer = new BufferedWriter(new FileWriter("A.out"));
		
		int N = scanner.nextInt();
		//	scanner.nextLine();
		for(int q=1;q<=N;q++)
		{
			int n = scanner.nextInt();
			
			list = new int[n][];
			for(int i=0;i<n;i++)
			{
				int num = scanner.nextInt();
				list[i] = new int[num];
				for(int j=0;j<num;j++)
					list[i][j] = scanner.nextInt();
			}

			
			
			String ans = answer();
			System.out.println("Case #"+q+": "+ans);
			writer.write("Case #"+q+": "+ans);
			writer.newLine();
/*
			for(int i=0;i<count.length;i++)
				System.out.println("c "+(i+1)+" "+count[i]);
			for(int i=0;i<list.length;i++)
			{
				System.out.print("l "+(i+1));
				
				for(int j=0;j<list[i].length;j++)
					System.out.print(" "+list[i][j]);
				
				System.out.println();
			}
			*/
		}
		
		writer.close();
		scanner.close();
	}
	
	public static int[] count;
	public static int[][] list;
	
	public static String answer() throws Exception
	{
		if(list.length<=2)
			return "No";

		//	for(int i=0;i<list.length;i++)
		for(int i=list.length-1;i>=0;i--)
		{
			count = new int[list.length];
			if(search(i+1))
				return "Yes";
		}
		
		return "No";
	}
	
	public static boolean search(int index)
	{
		for(int j=0;j<list.length;j++)
		{
			for(int k=0;k<list[j].length;k++)
			{
				if(list[j][k] == index)
				{
					if(++count[j]>=2)
						return true;
					
					if(search(j+1))
						return true;
					
					break;
				}
			}
		}
		
		return false;
	}
	
}
