package gcj2014;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;

public class PartElf {

	private long gcd(long p, long q)
	{
		long p1 = p;
		long q1 = q;
		while (p1 != q1 && p1 > 1 && q1 > 1)
		{
			if (p1 > q1)
			{
				p1 = p1%q1;
				if (p1 == 0) return q1;
			}
			else
			{
				q1 = q1%p1;
				if (q1 == 0) return p1;
			}
		}
		if (q1 < p1) p1 = q1;
		//System.out.println(p1 + " " + q1);
		return p1;
	}
	
	private boolean power2(long q)
	{
		long r = 1;
		while (r < q) r = r+r;
		return (r == q);
	}
	
	private long powers2(long q)
	{
		long result = 0;
		while (q > 1)
		{
			result += 1;
			q = q/2;
		}
		return result;
	}
	
	private long most(long p)
	{		
		long res = 2;
		long count = 0;
		while (p > res)
		{
			res = res + res;
			count += 1;
		}
		return count;
	}
	public String solve(long p, long q)
	{
		long gcd = gcd(p, q);
		long p1 = p/gcd;
		long q1 = q/gcd;
		
		if (power2(q1) == false) return "impossible";
		
		long res = powers2(q1);
		long res2 = most(p1);
		//System.out.println(res + " " + res2);
		return "" + (res-res2);
	}
	
	public static void main(String[] args) 
	{
		try
		{
			String inputName = "input.txt";
			BufferedReader input = new BufferedReader(new FileReader(inputName));
			BufferedWriter output = new BufferedWriter(new FileWriter("output6b.txt"));
			//read test case number
			String line = input.readLine();
			int testNr = new Integer(line).intValue();
			
			for (int i = 0; i < testNr; i++)
			{
				PartElf test = new PartElf();
				//read test case
				line = input.readLine();
				String[] parts = line.split("/");
				long p = (new Long(parts[0])).longValue();
				long q = (new Long(parts[1])).longValue();
				String res = test.solve(p, q);
				String toWrite = "Case #" + (i+1) + ": " + res;
				System.out.println(toWrite);
				output.write(toWrite + "\n");
			}
			output.flush();
			output.close();
			input.close();
		}
		catch (Exception e)
		{
			e.printStackTrace();
		}
	}
}
