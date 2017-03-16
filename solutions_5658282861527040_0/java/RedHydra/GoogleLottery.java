import java.util.*;
import java.io.*;

public class GoogleLottery
{
	public static void main(String[] args) throws Exception
	{
		Scanner infile = new Scanner(new File("lot.in"));
		PrintWriter w = new PrintWriter(new BufferedWriter(new FileWriter("lot.out")));
		int iterations = infile.nextInt();
		for(int loop = 1; loop <= iterations; loop++)
		{
			int a1 = infile.nextInt();
			int b1 = infile.nextInt();
			int c1 = infile.nextInt();
			
			Binary one = new Binary(0);
			Binary two = new Binary(0);
			Binary three = new Binary(c1);
			
			int number = 0;
			for(int d = 0; d < a1; d++)
			{
				for(int e = 0; e < b1; e++)
				{
					if(three.compareTo(one.union(two)) > 0)
						number++;
					two.increment();
				}
				one.increment();
				two = new Binary(0);
			}
			w.println("Case #" + loop + ": " + number);
		}
		w.close();
	}
}
class Binary
{
	ArrayList<Integer> digits;
	
	public Binary(int a)
	{
		digits = new ArrayList<Integer>();
		setDigits(a);
	}
	public Binary(ArrayList<Integer> digit5)
	{
		digits = digit5;
	}
	public Binary union(Binary b)
	{
		ArrayList<Integer> yes = new ArrayList<Integer>();
		int a = Math.min(digits.size(), b.getB().size());
		for(int i = 0; i < a; i++)
		{
			if(digits.get(i) == 1 && b.getB().get(i) == 1)
				yes.add(1);
			else
				yes.add(0);
		}
		return new Binary(yes);
	}
	private void setDigits(int a)
	{
		if(a == 0)
			return;
		else
		{
			if(a%2 == 0)
				digits.add(0);
			else
				digits.add(1);
			setDigits(a/2);
		}
	}
	public void increment()
	{
		incrementHelper(0);
	}
	private void incrementHelper(int a)
	{
		if(a >= digits.size())
			digits.add(1);
		else if(digits.get(a) == 0)
			digits.set(a, 1);
		else
		{
			digits.set(a, 0);
			incrementHelper(a+1);
		}
	}
	public ArrayList<Integer> getB()
	{
		return digits;
	} 
	public int compareTo(Binary b)
	{
		if(digits.size() > b.getB().size())
			return 1;
		else if(digits.size() < b.getB().size())
			return -1;
		else
		{
			for(int a = digits.size() - 1; a >= 0; a--)
			{
				if(digits.get(a) == 1 && b.getB().get(a) == 0)
					return 1;
				else if(digits.get(a) == 0 && b.getB().get(a) == 1)
					return -1;
			}
		}
		return 0;
	}
}
