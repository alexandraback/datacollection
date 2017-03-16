import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;
import java.util.Scanner;
import java.util.Set;
import java.util.TreeSet;


public class RecyclingNumber
{
	public static void main(String[] args)
	{
		try
		{
			BufferedReader input = new BufferedReader(new FileReader("C-small-attempt0.in"));
			BufferedWriter output = new BufferedWriter(new FileWriter("output.txt"));
			
			Integer numCases = Integer.parseInt(input.readLine());
			
			
			for(int i=0; i<numCases; ++i)
			{
				output.write("Case #"+(i+1)+": ");
				
				//output the number
				Scanner in= new Scanner(input.readLine());
				Integer A = in.nextInt();
				Integer B = in.nextInt();
				Integer numDigits = A.toString().length();
				Integer n=0;
				for(int j=A; j<B; ++j)
				{
					Set<Integer> set = new TreeSet<Integer>();
					for(int k=1; k<numDigits; ++k)
					{
						String s = new Integer(j).toString();
						String r = s.substring(numDigits-k) + s.substring(0,numDigits-k);
						set.add(Integer.parseInt(r));
					}
					for(Integer r : set)
					{
						if(j < r && r<=B)
							++n;
					}
				}
				output.write(n.toString());
				
				if(i != numCases-1)
					output.write('\n');
			}
			
			input.close();
			output.close();
		} catch (NumberFormatException e)
		{
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e)
		{
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}
