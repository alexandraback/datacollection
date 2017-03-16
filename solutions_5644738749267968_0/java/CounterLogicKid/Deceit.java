package qualifying_round_2014;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Deceit {

	public static void main(String[] args) throws IOException {
		BufferedReader f = new BufferedReader(new FileReader("War.in"));
		PrintWriter out = new PrintWriter(new FileWriter("C:/Users/David/Desktop/War.txt"));
		StringTokenizer t = new StringTokenizer(f.readLine());
		int testCases = Integer.parseInt(t.nextToken());
		for (int i = 0; i < testCases; i++)
		{
			t = new StringTokenizer(f.readLine());
			int cards = Integer.parseInt(t.nextToken());
			double[] player = new double[cards];
			double[] opponent = new double[cards];
			t = new StringTokenizer(f.readLine());
			for (int j = 0; j < cards; j++)
				player[j] = Double.parseDouble(t.nextToken());
			t = new StringTokenizer(f.readLine());
			for (int j = 0; j < cards; j++)
				opponent[j] = Double.parseDouble(t.nextToken());
			Arrays.sort(player);
			Arrays.sort(opponent);
			int winWar = optimalWar(player, opponent);
			int winDeception = optimalDeception(player,opponent);
			String ans = "Case #" + (i+1) + ": " + winDeception + " " + winWar;
			System.out.println(ans);
			out.println(ans);
		}

		out.close(); f.close(); System.exit(0);
	}
	
	public static int optimalWar(double[] you, double[] opponent)
	{
		int hisWins = 0;
		//ArrayList<Double> u = new ArrayList<Double>();
		//for (double d: you) u.add(d);
		ArrayList<Double> him = new ArrayList<Double>();
		for (double d: opponent) him.add(d);
		
		for (int i = 0; i < you.length; i++)
		{
			double num = you[i];
			int his = -1;
			for (int j = 0; j < him.size(); j++)
				if (him.get(j) > num)
				{
					his = j;
					break;
				}
			if (his == -1)
			{
				him.remove(0);
			}
			else
			{
				him.remove(his);
				hisWins++;
			}
		}
		
		return you.length - hisWins;
	}
	
	public static int optimalDeception(double[] you, double[] opponent)
	{
		int wins = 0;
		ArrayList<Double> u = new ArrayList<Double>();
		for (double d: you) u.add(d);
		ArrayList<Double> him = new ArrayList<Double>();
		for (double d: opponent) him.add(d);
		
		for (int i = 0; i < you.length; i++)
		{
			if (u.get(0) > him.get(0))
			{
				u.remove(0); him.remove(0);
				wins++;
			}
			else
			{
				u.remove(0); him.remove(him.size()-1);
			}	
		}
		
		return wins;
	}
	
}
