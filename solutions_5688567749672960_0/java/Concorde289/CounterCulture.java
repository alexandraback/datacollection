package round1B_2015;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.PriorityQueue;
import java.util.Scanner;

public class CounterCulture {

	public static void main (String [] args) throws IOException{

		//Timing
		//long s = System.currentTimeMillis ();

		//Set up the reader and printer
		Scanner in = new Scanner (new File("IN.txt"));
		PrintWriter out = new PrintWriter (new BufferedWriter (new FileWriter ("OUT.txt")));
		int noCases = in.nextInt();
		
		//Solve the cases
		for (int caseNo = 1; caseNo <= noCases; caseNo++){
			
			long n = in.nextLong();
			HashSet<Long> reached = new HashSet<Long>(10000);
			reached.add((long) 1);
			PriorityQueue<Num> p = new PriorityQueue<Num>(100000);
			p.add(new Num(1, 1));
			
			String answer = "";//TODO put answer here
			while (!p.isEmpty())
			{
				Num next = p.poll();
				long plus = next.value+1;
				long flipped = flip(next.value);
				if (!reached.contains(plus))
				{
					p.add(new Num(plus, next.numTurns+1));
					reached.add(plus);
				}
				if (!reached.contains(flipped) && flipped <= n)
				{
					p.add(new Num(flipped, next.numTurns+1));
					reached.add(flipped);
				}
				if (next.value == n)
				{
					answer = String.valueOf(next.numTurns);
					p.clear();
				}
			}
			
			out.println(String.format("Case #%d: %s", caseNo, answer));
			out.flush();//So I can see how my program is doing
		}

		//Close the files
		in.close();
		out.close();

		//Timing
		//long e = System.currentTimeMillis();
		//System.out.println((e - s) / 1000.0);

		//Terminate the program
		System.exit(0);

	} //Main method
	
	static long flip (long arg)
	{
		long flipped = 0;
		for (long i = 1; i <= arg; i *= 10)
		{
			flipped *= 10;
			flipped += (arg/i)%10;
		}
		return flipped;
	}
	
	static class Num implements Comparable<Num>
	{
		public long value;
		public long numTurns;
		
		public Num(long v, long n)
		{
			value = v;
			numTurns = n;
		}

		public int compareTo(Num other)
		{
			if (numTurns != other.numTurns)
				return numTurns-other.numTurns > 0 ? 1 : -1;
			return value-other.value > 0 ? -1 : 1;
		}
		
		public String toString()
		{
			return String.format("%d/%d",value, numTurns);
		}
		
		
	}
}
