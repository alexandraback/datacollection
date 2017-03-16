import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;
import java.util.Scanner;


public class Dancers
{
	public static void main(String[] args)
	{
		try
		{
			BufferedReader input = new BufferedReader(new FileReader("B-small-attempt0.in"));
			BufferedWriter output = new BufferedWriter(new FileWriter("output.txt"));
			
			Integer numCases = Integer.parseInt(input.readLine());
			
			
			for(int i=0; i<numCases; ++i)
			{
				output.write("Case #"+(i+1)+": ");
				
				//output the number
				Scanner in= new Scanner(input.readLine());
				int N = in.nextInt();
				int S = in.nextInt();
				int P = in.nextInt();
				int[] scores = new int[N];
				for(int j=0; j<N; ++j) scores[j]=in.nextInt();
				Arrays.sort(scores);
				
				Integer n=0;
				for(int j=N-1; j>=0; --j)
				{
					if(bestScoreWithoutSuprise(scores[j])>=P)
						++n;
					else if(S!=0 && bestScoreWithSuprise(scores[j])>=P)
					{
						++n;
						--S;
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
	
	public static int bestScoreWithoutSuprise(int totalScore)
	{
		if(totalScore%3==0) return totalScore/3;
		else return totalScore/3 + 1;
	}
	
	public static int bestScoreWithSuprise(int totalScore)
	{
		if(totalScore == 0) return 0;
		if(totalScore%3==0) return totalScore/3 + 1;
		else if(totalScore%3==1) return totalScore/3 + 1;
		else return totalScore/3 + 2;
	}
}
