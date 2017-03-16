package contest;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.LinkedList;

public class B
{
	public static int completeGraph(ArrayList< LinkedList<Integer> > slides, int[] pos, int B, int M, int m, int x)
	{
		for(int y = x+1; y < B; y++)
		{
			if(!slides.get(x).contains(y) && (m + pos[y] <= M))
			{
				slides.get(x).add(y);
				if(y == B-1)
				{
					m++;
				}
				else
				{
					m = completeGraph(slides, pos, B, M, m + pos[y], y);
				}
				pos[x] += pos[y];
				if(m >= M)
					return m;
			}
		}
		return m;
	}
	public static void main(String[] args) throws IOException
	{
		BufferedReader in = new BufferedReader(new FileReader(args[0]));
		BufferedWriter out = new BufferedWriter(new FileWriter(args[1]));
		{
			int nb_cases = Integer.parseInt(in.readLine());
			
			for(int icase = 0; icase < nb_cases; icase++)
			{
				// read input
				String[] S = in.readLine().split(" ");
				int B = Integer.parseInt(S[0]);
				int M = Integer.parseInt(S[1]);
				
				// solve
				ArrayList< LinkedList<Integer> > slides = new ArrayList< LinkedList<Integer> >();
				int[] pos = new int[B];
				for(int b = 0; b < B; b++)
				{
					slides.add(new LinkedList<Integer>());
					pos[b] = 0;
				}
				pos[B-1] = 1;
				
				int m = completeGraph(slides, pos, B, M, 0, 0);
				System.out.println(slides);
				
				// write output
				out.write("Case #"+(icase+1)+": ");
				if(m < M)
				{
					out.write("IMPOSSIBLE\n");
				}
				else
				{
					out.write("POSSIBLE\n");
					for(int ib = 0; ib < B; ib++)
					{
						for(int jb = 0; jb < B; jb++)
						{
							if(slides.get(ib).contains(jb))
								out.write("1");
							else
								out.write("0");
						}
						out.write("\n");
					}
				}
			}
		}
		out.close();
		in.close();
	}
}
