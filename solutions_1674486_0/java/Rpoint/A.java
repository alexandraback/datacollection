package RoundC2012;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;
import java.util.Stack;

public class A
{
	public static void main(String[] args)
	{
		try
		{
			BufferedReader input = new BufferedReader(new FileReader("A-small-attempt2.in"));
			BufferedWriter output = new BufferedWriter(new FileWriter("output"));
			
			Integer numCases = Integer.parseInt(input.readLine());			
			
			for(int i=0; i<numCases; ++i)
			{
				output.write("Case #"+(i+1)+":");				
				int N = Integer.parseInt(input.readLine());
				int[][] matrix = new int[N][N];
				
				for(int j=0; j<N; ++j)
				{
					Scanner in= new Scanner(input.readLine());
					int M = in.nextInt();
					for(int k=0; k<M; ++k)
						matrix[j][in.nextInt()-1] = 1;
				}
				
				boolean diamond = false;
				for(int j=0; j<N && !diamond; ++j)
				{
					//BFS
					boolean[] visited = new boolean[N];
					Stack<Integer> stack = new Stack<Integer>();
					stack.push(j);
					while(!stack.empty())
					{
						int current = stack.pop();
						if(visited[current])
						{
							diamond = true;
							break;
						}
						else
						{
							visited[current] = true;
							for(int k=0; k<N; ++k)
								if(matrix[current][k] == 1)
									stack.push(k);
						}
					}
					
				}
				
				if(diamond)
					output.write(" Yes");
				else
					output.write(" No");
				
				if(i != numCases-1)
					output.write('\n');
			}
			
			input.close();
			output.close();
		} catch (NumberFormatException e)
		{
			e.printStackTrace();
		} catch (IOException e)
		{
			e.printStackTrace();
		}
	}
}
