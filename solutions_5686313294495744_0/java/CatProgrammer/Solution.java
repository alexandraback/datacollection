import java.io.File;
import java.io.PrintWriter;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.Scanner;

public class Solution
{

	public static void main(String[] args) throws Exception
	{
		Scanner s = new Scanner(System.in);
		int N = Integer.parseInt(s.nextLine());
		//s.nextLine();
		
		PrintWriter pW = new PrintWriter(new File("output.out"));

		for(int index = 0;index<N;index++)
		{
			int N2 = Integer.parseInt(s.nextLine());
			int nums = 0;
			LinkedList<String> firstWords = new LinkedList<String>();
			LinkedList<String> secondWords = new LinkedList<String>();
			for(int a = 0;a<N2;a++)
			{
				String[] thing = s.nextLine().split(" ");
				firstWords.add(thing[0]);
				secondWords.add(thing[1]);
			}
			for(int a = 0;a<firstWords.size();a++)
			{
				if(contains(firstWords.get(a),firstWords,a))
				{
					if(contains(secondWords.get(a),secondWords,a))
					{
						firstWords.remove(a);
						secondWords.remove(a);
						nums++;
						a--;
					}
				}
			}
			pW.println("Case #"+(index+1)+": "+nums);
		}
		
		pW.flush();
		pW.close();
	}

	public static boolean contains(String thing, LinkedList<String> words, int index)
	{
		for(int a = 0;a<words.size();a++)
		{
			String toTest = words.get(a);
			if(a==index)
			{
				continue;
			}
			if(toTest.equals(thing))
			{
				return true;
			}
			
		}
		
		return false;
	}
	
}