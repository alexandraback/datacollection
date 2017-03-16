import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;


public class Ex1 {
	
	

	public static void main(String[] args) throws IOException 
	{
		
		
		
		
		File input = new File(args[0]);
		File output = new File(args[1]);
		
		Scanner s = new Scanner(input);
		FileWriter fstream = new FileWriter(output);
		BufferedWriter out = new BufferedWriter(fstream);

		
		int numOfCases = s.nextInt();
		s.nextLine();
		//System.out.println(numOfCases);
		for(int i=1; i<=numOfCases; i++)
		{
			List<Integer> mobes = new ArrayList<Integer>();
			long A = s.nextInt();
			int N = s.nextInt();
			System.out.println(A + " " + N);
			for (int j=0; j<N; j++)
			{
				int temp = s.nextInt();
				//System.out.println(temp);
				mobes.add(temp);
			}
			Collections.sort(mobes);
			
			for (int j=0; j<N; j++)
			{
				System.out.print(mobes.get(j) + "  ");
			}			
			
			int min = N;
			
			int mooves = 0;
			
			while (mobes.size()>0 && A>1)
			{
				A = eatMobes(mobes,A);
				if (min > mobes.size() + mooves && mobes.size()==0)
				{
					min = mooves;
				}
				else if (min > mobes.size() + mooves)
				{
					min = mobes.size() + mooves;
				}
				
				A = A + A - 1;
				mooves++;
			}
			System.out.println();
			System.out.println(min);
			writeResult(""+min,i,out);
		
			
		}
		
		out.close();

		 
	}
	
	public static long eatMobes(List<Integer> mobes, long A)
	{
		boolean eaten = true;
		while (eaten && mobes.size()>0)
		{
			if (mobes.get(0) < A)
			{
				A = A + mobes.get(0);
				mobes.remove(0);
			}
			else
				eaten = false;
		}
		
		return A;
	}
	
	public static void writeResult(String s, int index, BufferedWriter out)
	{
		try {
			out.write("Case #" + index + ": " +s +"\n");
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

}
