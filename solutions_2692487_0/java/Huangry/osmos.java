import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class osmos
{

	public static int solve(ArrayList<Integer> motes, int size)
	{
		if (size == 1)
			return (motes.size());
		
		if (motes.size() == 0)
			return 0;
		
		int smallest = motes.get(0);
		while (smallest < size)
		{
			size += smallest;
			
			motes.remove(0);
			
			if (motes.size() == 0)
				return 0;
			else
				smallest = motes.get(0);

		}
		int motesSize = motes.size();
		
		
		
		
		return (Math.min(solve(motes, 2 * size - 1)+1, motesSize));

	}

	/**
	 * @param args2
	 * @throws IOException
	 */
	public static void main(String[] args) throws IOException
	{
		BufferedWriter out;
		out = new BufferedWriter(new FileWriter("osmos.txt"));
		File inFile = new File("A-small-attempt0.in");
		Scanner scan = new Scanner(inFile);

		int T = scan.nextInt();

		for (int test = 1; test <= T; test++)
		{
			int size = scan.nextInt();
			int n = scan.nextInt();
			ArrayList<Integer> motes = new ArrayList<Integer>();
			for (int i = 0; i < n; i++)
				motes.add(scan.nextInt());
			Collections.sort(motes);

			System.out.println ("Case #" + test + ": " + solve(motes, size));
		}

	}

}
