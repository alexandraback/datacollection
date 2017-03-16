import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;


public class C {
	static BigInteger big;
	static int[] digits = new int[120];
	static List<BigInteger> values = new ArrayList<BigInteger>();
	static List<BigInteger> ps = new ArrayList<BigInteger>();
	
	static boolean isP(BigInteger n)
	{
		int pos = 0;
		while (n.compareTo(BigInteger.ZERO) != 0)
		{
			digits[pos++] = n.mod(BigInteger.TEN).intValue();
			n = n.divide(BigInteger.TEN);
		}
		for (int i = 0; i < pos / 2; i++)
			if (digits[i] != digits[pos - i - 1])
				return false;
		return true;
	}
	
	static BigInteger getP(BigInteger n, boolean oddP)
	{
		int pos = 0;
		BigInteger t = BigInteger.ZERO.add(n);
		while (n.compareTo(BigInteger.ZERO) != 0)
		{
			digits[pos++] = n.mod(BigInteger.TEN).intValue();
			n = n.divide(BigInteger.TEN);
		}
		int start = 0;
		if (oddP) start = 1;
		for (int i = start; i < pos; i++)
		{
			t = t.multiply(BigInteger.TEN).add(BigInteger.valueOf(digits[i]));
		}
		return t;
	}
	
	static void search(int digitCount, int currentDigit,
			BigInteger currentNumber, int currentSum, boolean oddP)
	{
		if (digitCount == currentDigit)
		{
			values.add(getP(currentNumber, oddP));
			return;
		}
		
		search(digitCount, currentDigit + 1, 
				currentNumber.multiply(BigInteger.TEN), currentSum, oddP);
		if (digitCount - 1 == currentDigit && oddP)
		{
			if (currentSum + 1 < 10)
			{
				search(digitCount, currentDigit + 1, 
						currentNumber.multiply(BigInteger.TEN).add(BigInteger.ONE), currentSum + 1, oddP);
			}
			if (currentSum + 4 < 10)
			{
				search(digitCount, currentDigit + 1, 
						currentNumber.multiply(BigInteger.TEN).add(BigInteger.valueOf(2)), currentSum + 4, oddP);
			}
		}
		else
		{
			if (currentSum + 2 < 10)
			{
				search(digitCount, currentDigit + 1, 
						currentNumber.multiply(BigInteger.TEN).add(BigInteger.ONE), currentSum + 2, oddP);
			}
		}
	}
	
	static void seekAll(int digitCount)
	{
		search(digitCount, 0, BigInteger.ONE, 2, true);
		BigInteger v = BigInteger.valueOf(2);
		for (int i = 0; i < digitCount; i++)
			v = v.multiply(BigInteger.TEN);
		values.add(getP(v, true));
		values.add(getP(v.add(BigInteger.ONE), true));
		search(digitCount, 0, BigInteger.ONE, 2, false);
		v = BigInteger.valueOf(2);
		for (int i = 0; i < digitCount; i++)
			v = v.multiply(BigInteger.TEN);
		values.add(getP(v, false));
	}
	
	public static void main(String[] args)
	{
		for (int i = 0; i <= 26; i++)
			seekAll(i);
		for (BigInteger v : values)
		{
			BigInteger vv = v.multiply(v);
			if (isP(vv) == false)
			{
				int k = 0;
			}
			ps.add(vv);
		}
		Collections.sort(ps);
		BufferedReader input;
		try {
			input = new BufferedReader(new FileReader("C-large-1.in"));
			BufferedWriter output = new BufferedWriter(new FileWriter("c.txt"));
			
			String line = input.readLine();
			int t = Integer.parseInt(line);
			for (int it = 0; it < t; it++)
			{
		        line = input.readLine();
	        	String[] strs = line.split(" ");
	        	BigInteger a = new BigInteger(strs[0]);
	        	BigInteger b = new BigInteger(strs[1]);
	        	int ida = -1;
	        	int idb = -1;
	        	for (int i = 0; i < ps.size(); i++)
	        		if (ps.get(i).compareTo(a) >= 0)
	        		{
	        			ida = i;
	        			break;
	        		}
	        	for (int i = 0; i < ps.size(); i++)
	        		if (ps.get(i).compareTo(b) > 0)
	        		{
	        			idb = i - 1;
	        			break;
	        		}
	        	
	        	output.write("Case #" + (it + 1) + ": " + (idb - ida + 1) + System.lineSeparator());
			}
			output.flush();
	        output.close();
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}
