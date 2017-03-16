import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.io.Reader;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Set;


public class Main 
{
	
	public static HashMap<Character,Character> mapp = new HashMap<Character,Character>();
	
	public static void main(String[] args) throws Exception
	{
		PrintWriter writer = new PrintWriter(new FileWriter("output.txt"));
		BufferedReader input = new BufferedReader(new FileReader("C-small-attempt0.in"));
		int size=Integer.parseInt(input.readLine());
		for(int i=0; i<size; i++)
		{
			Set<String> mySet = new HashSet<String>();
			String tokens[] = input.readLine().split(" ");
			int lowLimit = Integer.parseInt(tokens[0]);
			int highLimit = Integer.parseInt(tokens[1]);
			int count=0;
			for(int j=lowLimit; j<highLimit; j++)
			{
				for(int k=j+1; k<=highLimit; k++)
				{
					Integer num1 = j;
					Integer num2 = k;
					String str1 = num1.toString();
					String str2 = num2.toString();
					if(str1.length()!=str2.length())
					{
						continue;
					}
					else
					{
						for(int x=0; x<str1.length(); x++)
						{
							String temp = (String)str1.subSequence(str1.length()-1-x, str1.length()) + (String)str1.subSequence(0, (str1.length()-1-x));
							
							//System.out.println("temp="+temp+"	Str2="+str2);
							if(Integer.parseInt(temp)==Integer.parseInt(str2))
							{
								mySet.add(str1+str2);
							}
						}
					}
				}
			}
			writer.println("Case #"+(i+1)+": "+mySet.size());
		}
		writer.close();
		input.close();
	}

}
