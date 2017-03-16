import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;

public class p1
{
	public static int getOrbs1(int mySize, ArrayList<Integer> orbs)
	{
		for (int i = 0; i < orbs.size(); i++)
		{
			int currentOrb = orbs.get(i);
			if (currentOrb < mySize)
			{
				mySize += currentOrb;
				orbs.remove(i);
			}
		}
		return mySize;
	}

	public static int getOrbs2(int mySize, ArrayList<Integer> orbs)
	{
		int currentSize = orbs.size();
		mySize = getOrbs1(mySize, orbs);
		while (currentSize != orbs.size())
		{
			currentSize = orbs.size();
			mySize = getOrbs1(mySize, orbs);
		}
		return mySize;
	}

	public static int add(int mySize, ArrayList<Integer> orbs)
	{
		mySize += mySize - 1;
		mySize = getOrbs2(mySize, orbs);
		return mySize;
	}

	public static int findMoves(int mySize, ArrayList<Integer> orbs)
	{
		int minMoves = orbs.size();
		int carry=mySize;
		for (int i = 0;  orbs.size()>0;i++)
		{
			mySize = add(mySize, orbs);
			int currentMoves = i+1 + orbs.size();
			if (currentMoves < minMoves)
				minMoves = currentMoves;
		}
		return minMoves;
	}

	/**
	 * @param args
	 * @throws FileNotFoundException
	 */
	public static void main(String[] args) throws FileNotFoundException
	{
		// ///////////////////////////////////////////////////////////////////
		long start = System.nanoTime();
		// ///////////////////////////////////////////////////////////////////
	//	Scanner inFile = new Scanner(new File("p1.txt"));
		// Scanner inFile = new Scanner(new File("A-small-attempt0.in"));
		 Scanner inFile = new Scanner(new File("A-Large.in"));
		PrintWriter out = new PrintWriter("p1out.txt");
		int numberOfTimes = inFile.nextInt();

		for (int times = 1; times <= numberOfTimes; times++)
		{
			int mySize = inFile.nextInt();
			int orbNum = inFile.nextInt();
			ArrayList<Integer> orbs = new ArrayList<Integer>(orbNum);
			for (int i = 0; i < orbNum; i++)
			{
				orbs.add(inFile.nextInt());
			}
			if (mySize <= 1)
			{
				//System.out.println("Case #" + times + ": " + orbs.size());
				out.println("Case #" + times + ": " + orbs.size());
			}
			else
			{
				mySize = getOrbs2(mySize, orbs);

				if (orbs.size() == 0)
				{
					//System.out.println("Case #" + times + ": 0");
					out.println("Case #" + times + ": 0");
				}
				else
				{
					int moves = findMoves(mySize, orbs);
					//System.out.println("Case #" + times + ": " + moves);
					out.println("Case #" + times + ": " + moves);

				}
			}
		}
		inFile.close();
		out.close();
		// ///////////////////////////////////////////////////////////////////
		long stop = System.nanoTime();
		System.out.printf("Run time: %.1f ms%n", (stop - start) / 1000000.0);
		System.out.println("End of Program");
		// ///////////////////////////////////////////////////////////////////

	}

}
