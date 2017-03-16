import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Scanner;

public class C
{

	static int [] wall = new int[200000010];
	/**
	 * @param args
	 * @throws IOException
	 */
	public static void main(String[] args) throws IOException
	{
		String fileName = "C-small0";
		Scanner in = new Scanner(new File(fileName + ".in"));
		PrintWriter out = new PrintWriter(new FileWriter(fileName + ".out"));

		int noOfCases = in.nextInt();
		for (int caseNo = 1; caseNo <= noOfCases; caseNo++)
		{
			int N = in.nextInt();
			
			Queue<Tribe> tribes = new PriorityQueue<Tribe>();
			for (int i = 0; i < N; i++)
				tribes.add(new Tribe(in.nextInt(), in.nextInt(),in.nextInt(),in.nextInt(),
						in.nextInt(),in.nextInt(),in.nextInt(),in.nextInt()));
			

			int noOfSucesses = 0;
			List <Tribe> attacking = new ArrayList<Tribe>();
			while (!tribes.isEmpty())
			{
				Tribe next = tribes.remove();
				attacking.add(next);
				int day = next.day;
				while (!tribes.isEmpty() && tribes.peek().day == day)
				{
					attacking.add(tribes.remove());
				}
				// Attack
				for (Tribe tribe : attacking)
					if (tribe.attachSucess(wall))
						noOfSucesses++;
				
				// Update wall and tribes
				for (Tribe tribe : attacking)
				{
					//System.out.print(tribe + " " + tribe.attachSucess(wall));
					tribe.updateWall(wall);
					tribe.next();
					if (tribe.noOfAttacks> 0)
						tribes.add(tribe);
				}
			   // System.out.println();
				// Clear out attaching
				attacking.clear();
			}
			

			System.out.printf("Case #%d: %d%n", caseNo, noOfSucesses);
			out.printf("Case #%d: %d%n", caseNo, noOfSucesses);
			
			// Clear the wall
			for (int i = 0; i < wall.length;i++)
				wall[i]= 0;
		}
		in.close();
		out.close();
	}
}

class Tribe implements Comparable<Tribe>
{
	final static int OFFSET = 100000004;
	static int nextTribe = 0;
	int tribeNo;
	int day;
	int noOfAttacks;
	int west, east;
	int strength;
	int dayNext;
	int posChange;
	int strengthChange;
	public Tribe(int day, int noOfAttacks, int west, int east, int strength,
			int dayNext, int posChange, int strengthChange)
	{
		tribeNo = ++nextTribe;
		this.day = day;
		this.noOfAttacks = noOfAttacks;
		this.west = west;
		this.east = east;
		this.strength = strength;
		this.dayNext = dayNext;
		this.posChange = posChange;
		this.strengthChange = strengthChange;
	}
	@Override
	public int compareTo(Tribe other)
	{
		return day - other.day;
	}
	
	public void next()
	{
			day += dayNext;
			west += posChange;
			east += posChange;
			strength += strengthChange;
			noOfAttacks --;
	}
	
	public boolean attachSucess(int [] wall)
	{
		for (int pos = west; pos < east; pos++)
		{
			if (wall[pos + OFFSET] < strength)
				return true;
		}
		return false;
	}
	
	public void updateWall(int [] wall)
	{
		for (int pos = west; pos < east; pos++)
		{
			wall[pos + OFFSET] = strength;
		}
	}
	
	public String toString()
	{
		return "" + tribeNo;
	}
}

class WallSection
{
	int start, end;
	int height;
	public WallSection(int start, int end, int height)
	{
		this.start = start;
		this.end = end;
		this.height = height;
	}
	
	
	
}

