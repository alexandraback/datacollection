import java.util.*;

public class A
{
	public static int[] stepsToReachDigit = {-1, 0, 10, 29, 138, 337, 1436, 3435, 14434, 34433, 144432, 344431, 1444430, 3444429, 14444428, 34444427}; 
	public static void main(String[] args)
	{
		A a = new A();
		Scanner in = new Scanner(System.in);
		int t = in.nextInt();
		for (int test = 1; test <= t; ++test)
		{
			long n = in.nextLong();
			long solution = a.solveBig(n);
			System.out.printf("Case #%d: %d\n", test, solution);
		}
	}
	
	public void solveWeak()
	{
		Scanner in = new Scanner(System.in);
		//int t = in.nextInt();
		int t = 1000000;
		int[][] solution = bruteForce(t);
		for (int test = 1; test <= t; ++test)
		{
			long bruteAns = solution[test][0];
			long smartAns = solveBig(test);
			
			if (bruteAns != smartAns)
			{
				System.out.printf("For test=%d, bruteAns = %d, smartAns = %d\n", test, bruteAns, smartAns);
			}
		}
	}
	
	public int[][] bruteForce(int upperLimit)
	{
		int[][] output = new int[upperLimit*5][2];
		// output[i][0] = min # steps to reach i
		// output[i][1] = previous step location
		
		output[1][0] = 1;
		output[1][1] = -1;
		
		Queue<Integer> q = new LinkedList<Integer>();
		q.add(1);
		while (!q.isEmpty())
		{
			int next = q.poll();
			if (next+1 < upperLimit && output[next+1][0] == 0)
			{
				output[next+1][0] = output[next][0] + 1;
				output[next+1][1] = next;
				q.add(next+1);
			}
			
			int rev = Integer.parseInt(reverse("" + next));
			if (rev < upperLimit && output[rev][0] == 0)
			{
				output[rev][0] = output[next][0] + 1;
				output[rev][1] = next;
				q.add(rev);
			}
		}
		
		return output;
	}
	
	public long solveBig(long n)
	{
		String nAsString = ("" + n);
		int digitCount = nAsString.length();
		if (digitCount == 1)
			return n;
		long total = stepsToReachDigit[digitCount];
		if (n == Math.pow(10, digitCount-1))
			return total;
			
		if (digitCount % 2 == 0)
		{
			String leftHalf = nAsString.substring(0, digitCount/2);
			String rightHalf = nAsString.substring(digitCount/2, digitCount);
			
			// WAS BUG: was not account for rightHalf being 0 (when flipped, the resulting right half will never be 0)
			if (Long.parseLong(rightHalf) == 0)
			{
				String temp = "" + (n-1);
				leftHalf = temp.substring(0, digitCount/2);
				rightHalf = temp.substring(digitCount/2, digitCount);
				total += 1;
			}
			
			// WAS BUG: was subtracting 1 because I was accounting for the leading 1, but not the cost of the flip
			total += (Long.parseLong(rightHalf) + Long.parseLong(reverse(leftHalf)));
			
			if (Long.parseLong(reverse(leftHalf)) == 1)
				total -= 1; // WAS BUG: did not have to flip
		}
		else
		{
			String leftHalf = nAsString.substring(0, digitCount/2);
			String rightHalf = nAsString.substring(digitCount/2, digitCount);
			int delta = 0;
			if (Long.parseLong(rightHalf) == 0)
			{
				String temp = "" + (n-1);
				leftHalf = temp.substring(0, digitCount/2);
				rightHalf = temp.substring(digitCount/2, digitCount);
				delta += 1;
			}
			
			if (Long.parseLong(reverse(leftHalf)) == 1)
				delta -= 1; // WAS BUG: did not have to flip
			
			long subtotal = (Long.parseLong(rightHalf) + Long.parseLong(reverse(leftHalf)));
			subtotal += delta;
			
			delta = 0;
			
			leftHalf = nAsString.substring(0, digitCount/2 + 1);
			rightHalf = nAsString.substring(digitCount/2 + 1, digitCount);
			if (Long.parseLong(rightHalf) == 0)
			{
				String temp = "" + (n-1);
				leftHalf = temp.substring(0, digitCount/2 + 1);
				rightHalf = temp.substring(digitCount/2 + 1, digitCount);
				delta += 1;
			}
			
			if (Long.parseLong(reverse(leftHalf)) == 1)
				delta -= 1; // WAS BUG: did not have to flip
			
			subtotal = Math.min((Long.parseLong(rightHalf) + Long.parseLong(reverse(leftHalf))) + delta, subtotal);
			total += subtotal;
		}
		
		return total;
	}
	
	public String reverse(String input)
	{
		return (new StringBuilder(input)).reverse().toString();
	}
}