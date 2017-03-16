import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;

public class D
{

	public static void main(String[] args) throws IOException
	{
		String fileName = "D-small0";
		Scanner in = new Scanner(new File(fileName + ".in"));
		PrintWriter out = new PrintWriter(new FileWriter(fileName + ".out"));

		int noOfCases = in.nextInt();
		for (int caseNo = 1; caseNo <= noOfCases; caseNo++)
		{
			int N = in.nextInt();
			ArrayList<Double> naomi = new ArrayList<Double>();
			for (int i = 0; i < N; i++)
				naomi.add(in.nextDouble());

			ArrayList<Double> ken = new ArrayList<Double>();
			for (int i = 0; i < N; i++)
				ken.add(in.nextDouble());

			// System.out.println(naomi);

			ArrayList<Double> kenCopy = new ArrayList<Double>(ken);
			ArrayList<Double> naomiCopy = new ArrayList<Double>(naomi);
			// System.out.println(ken);

			int dWPoints = 0;
			int wPoints = 0;
			Collections.sort(ken);

			// Do war first
			for (int i = 0; i < N; i++)
			{
				double nPlay = naomi.remove(naomi.size() - 1);
				// Find smallest block > play
				int smallIndex = -1;
				for (int j = 0; j < ken.size(); j++)
				{
					double kCheck = ken.get(j);
					if (kCheck > nPlay)
					{
						if (smallIndex == -1)
							smallIndex = j;
						else if (kCheck < ken.get(smallIndex))
							smallIndex = j;
					}
				}
				if (smallIndex == -1)
					smallIndex = 0;
				double kPlay = ken.remove(smallIndex);
				
				// See who wins
				if (nPlay > kPlay)
					wPoints++;

			}

			// Do deceitful war
			naomi  = naomiCopy;
			ken = kenCopy;
			Collections.sort(ken);
			Collections.sort(naomi);
			for (int i = 0; i < N; i++)
			{
				double nTold = ken.get(ken.size() -1) + 0.00000001;
					
				// Find smallest block > play for ken
				int smallIndex = -1;
				for (int j = 0; j < ken.size(); j++)
				{
					double kCheck = ken.get(j);
					if (kCheck > nTold)
					{
						if (smallIndex == -1)
							smallIndex = j;
						else if (kCheck < ken.get(smallIndex))
							smallIndex = j;
					}
				}
				if (smallIndex == -1)
					smallIndex = 0;
				double kPlay = ken.remove(smallIndex);
				
				
				// Find smallest block > play for naomi
				 smallIndex = -1;
				for (int j = 0; j < naomi.size(); j++)
				{
					double nCheck = naomi.get(j);
					if (nCheck > kPlay)
					{
						if (smallIndex == -1)
							smallIndex = j;
						else if (nCheck < naomi.get(smallIndex))
							smallIndex = j;
					}
				}
				if (smallIndex == -1)
					smallIndex = 0;
				double nPlay = naomi.remove(smallIndex);
				
				// See who wins
				if (nPlay > kPlay)
					dWPoints++;

			}

			System.out.printf("Case #%d: %d %d%n", caseNo, dWPoints, wPoints);
			out.printf("Case #%d: %d %d%n", caseNo, dWPoints, wPoints);
		}
		in.close();
		out.close();

	}

}
