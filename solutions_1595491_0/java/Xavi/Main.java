import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.io.Reader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Set;


public class Main 
{
	
	public static HashMap<Character,Character> mapp = new HashMap<Character,Character>();
	
	public static void main(String[] args) throws Exception
	{
		PrintWriter writer = new PrintWriter(new FileWriter("output.txt"));
		BufferedReader input = new BufferedReader(new FileReader("B-small-attempt0.in"));
		int size=Integer.parseInt(input.readLine());
		for(int i=0; i<size; i++)
		{
			String testCase = input.readLine();
			String tokens[] = testCase.split(" ");
			int N = Integer.parseInt(tokens[0]);
			int S = Integer.parseInt(tokens[1]);
			int p = Integer.parseInt(tokens[2]);
			int count=0;
			//ArrayList<Integer> google = new ArrayList<Integer>();
			for(int j=3; j<N+3; j++)
			{
				int testNum = Integer.parseInt(tokens[j]);
				if((testNum - p) >= 2*(p-1) && (testNum-p)>=0)
				{
					count++;
				}
				else if((testNum - p) < 2*(p-1) && (testNum-p)>=0)
				{
					if(S!=0 && (testNum - p) >= 2*(p-2) )
					{
						count++;
						S--;
					}
				}
			}
			writer.println("Case #"+(i+1)+": "+count);
			
		}
		writer.close();
		input.close();
	}

}
