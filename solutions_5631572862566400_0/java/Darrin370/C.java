import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;

public class C {
		static int best = 0;
		static int[] ints;
		public static void main(String[] args) throws IOException
		{
			PrintWriter out = new PrintWriter(new FileWriter(new File("out.txt")));
			Scanner file = new Scanner(new File("c-small.in"));
			int zz = file.nextInt();
			for(int i = 1;i<=zz;i++)
			{
				best = 0;
				ints = new int[file.nextInt()];
				for(int j = 0;j<ints.length;j++)
				{
					ints[j] = file.nextInt()-1;
				}
				for(int j = 0;j<ints.length;j++)
				{
					bruteForce(new boolean[ints.length],1,j,j,false);
				}
				out.printf("Case #%d: %d%n",i,best);
			}
			out.close();
		}
		
		public static void bruteForce(boolean[] used, int length, int current, int first,boolean isSatisfied)
		{
			used[current] = true;
			//add loop check or satisfied check to update best
			if(ints[current]==first||isSatisfied){
				best = Math.max(best,length);

			}
				
			if(isSatisfied)
			{
				for(int i = 0;i<used.length;i++)
				{
					if(!used[i])
					{
						bruteForce(used,length+1,i,first,ints[i]==current);
					}
				}
			}else if(!used[ints[current]])
			{
				bruteForce(used,length+1,ints[current],first,ints[ints[current]]==current);
			}
			used[current] = false;
		}
}
