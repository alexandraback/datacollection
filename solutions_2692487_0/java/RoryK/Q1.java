import java.util.*;
import java.io.*;
import java.lang.reflect.*;

public class Q1
{
	public static void main(String[] args)
	{
		try
		{
			BufferedWriter bw = new BufferedWriter(new FileWriter("out.txt"));

			int cases = 0;
			BufferedReader br = new BufferedReader(new FileReader("A-small-attempt3.in"));
			cases = Integer.parseInt(br.readLine()); 
			System.out.println(cases);

			for(int a = 0; a < cases; a++)
			{

				String line = br.readLine();

				Scanner scan = new Scanner(line);

				int armin = scan.nextInt();

				int motes = scan.nextInt();

				line = br.readLine();

				int[] moteArray = new int[motes];
				scan = new Scanner(line);

				for(int i = 0; i < motes; i++)
				{
					moteArray[i] = scan.nextInt();
				}

				Arrays.sort(moteArray);

				
				String out = "Case #" + (a+1) + ": " + recurse(armin, motes, moteArray);
				System.out.println(out);

				bw.write(out);
				if(a != cases-1)
				{
					bw.newLine();
				}

			}
			bw.close();
			br.close();


		}
		catch(Exception e)
		{
			e.printStackTrace();
		}
	}

	public static int recurse(int armin, int motes, int[] moteArray)
	{
		int totalMoves = 0;
		int betterTotal = 0;

		if(armin == 1)
		{
			return motes;
		}


		for(int i = 0; i < motes; i++)
		{
			int temp = moteArray[i];

			if(armin > temp)
			{
				armin += temp;
				betterTotal++;
			}
			else
			{
				int move = 0;

				while(armin <= temp)
				{
					armin += (armin-1);
					move++;
				}

				armin += temp;
				betterTotal++;
				totalMoves += move;
			}
			if(totalMoves < betterTotal)
			{
				betterTotal = totalMoves;
			}
		}
		return betterTotal;
	} 
}
