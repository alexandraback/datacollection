package gcj2014;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;

public class Enclosure {

	public String solve(int n, int m, int k)
	{
		if ((n < 3) || (m <  3)) return "" + k;
		//n >= 3 and m >= 3
		if (k <= 4) return "" + k;
		//k >= 5
		int l = 1;
		int p = 1;
		int min = n;
		int max = n;
		if (m < min) min = m;
		else max = m;
		while ((l+2 <= min) && (p+2 <= min))
		{
			int closed = (2*l) + (2*p) + (p*l);
			int stones = 2*l + 2*p;
			if (closed >= k) return "" + stones;
			if (closed+1 == k) return "" + (stones+1);
			if (closed+(l-1) >= k)
			{
				if (l > p)
				{
					return "" + (stones+1);
				}
				else // l == p
				{
					if (l+3 <= min) return "" + (stones+1);
				}
			}
			if (l > p) p += 1;
			else l += 1;
		}
		l -= 1;
		//System.out.println(l + " " + p);
		while ((l+2) <= max)
		{
			int closed = (2*l) + (2*p) + (p*l);
			int stones = 2*l + 2*p;
			if (closed >= k) return "" + stones;
			if (closed+1 == k) return "" + (stones+1);
			if (closed+(l-1) >= k)
			{
				if ((l+3) <= max) return "" + (stones+1);
			}
			l += 1;
		}
		//(l+2) > max
		l -= 1; //(l+2) == max
		//System.out.println(l + " " + p);
		int stones = (2*l) + (2*p);
		int closed = stones + (p*l);
		int extra = (k - closed);
		if (extra < 2) System.out.println("Extra less than 2");
		return "" + (stones + extra);
	}
	
	public static void main(String[] args) 
	{
		try
		{
			String inputName = "input.txt";
			BufferedReader input = new BufferedReader(new FileReader(inputName));
			BufferedWriter output = new BufferedWriter(new FileWriter("output7.txt"));
			//read test case number
			String line = input.readLine();
			int testNr = new Integer(line).intValue();
			
			for (int i = 0; i < testNr; i++)
			{
				Enclosure test = new Enclosure();
				//read test case
				line = input.readLine();
				String[] parts = line.split(" ");
				int n = (new Integer(parts[0])).intValue();
				int m = (new Integer(parts[1])).intValue();
				int k = (new Integer(parts[2])).intValue();
				String res = test.solve(n, m, k);
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
