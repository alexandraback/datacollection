import java.io.File;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;




public class Main
{
	
	static ArrayList<String> possC = new ArrayList<String>();
	static ArrayList<String> possJ = new ArrayList<String>();
	
	public static void main(String[] args) throws Exception
	{
		Scanner s = new Scanner(System.in);
		int N = s.nextInt();
		s.nextLine();
		
		PrintWriter pW = new PrintWriter(new File("output.out"));
		
		for(int index = 0;index<N;index++)
		{
			String[] separate = s.nextLine().split(" ");
			possC = new ArrayList<String>();
			possJ = new ArrayList<String>();
			add("",separate[0],0,true);
			add("",separate[1],0,false);
			int smallestDiff = Integer.MAX_VALUE;
			int smallestC = Integer.MAX_VALUE;
			int smallestJ = Integer.MAX_VALUE;
			
			int indexC = 0;
			int indexJ = 0;
			
			//System.out.println(possC);
			//System.out.println(possJ);
			
			for(int a = 0;a<possC.size();a++)
			{
				for(int b = 0;b<possJ.size();b++)
				{
					int first = Integer.parseInt(possC.get(a));
					int second = Integer.parseInt(possJ.get(b));
					int diff = Math.abs(first-second);
					if(diff<smallestDiff)
					{
						smallestDiff = diff;
						smallestC = first;
						smallestJ = second;
						indexC = a;
						indexJ = b;
					}
					else if(diff==smallestDiff)
					{
						if(first<smallestC)
						{
							smallestC = first;
							smallestJ = second;
							indexC = a;
							indexJ = b;
						}
						else if(first==smallestC)
						{
							if(second<smallestJ)
							{
								smallestJ = second;
								indexC = a;
								indexJ = b;
							}
						}
					}
				}
			}
			
			pW.println("Case #"+(index+1)+": "+possC.get(indexC)+" "+possJ.get(indexJ));
			
		}
		pW.flush();
		pW.close();
	}
	public static void add(String past, String original, int index, boolean C)
	{
		for(;;index++)
		{
			if(index==original.length())
			{
				if(C)
				{
					possC.add(past);
				}
				else
				{
					possJ.add(past);
				}
				break;
				
			}
			
			if(original.charAt(index)=='?')
			{
				for(int a = 0;a<10;a++)
				{
					add(past+a,original,index+1,C);
				}
				break;
			}
			else
			{
				past+=original.charAt(index);
			}
		}
	}
	
}