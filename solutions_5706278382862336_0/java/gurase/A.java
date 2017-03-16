import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

/**
 * 
 * @author gmann
 */
public class A
{

	private BufferedReader reader;
	private BufferedWriter writer;

	/**
	 * @param args
	 *            the command line arguments
	 */
	public static void main(String[] args)
	{
		A a = new A(args[0]);
		a.runTests();
	}

	public A(String fileName)
	{
		// Open file
		File file = new File(fileName);
		try
		{
			reader = new BufferedReader(new FileReader(file));
			writer = new BufferedWriter(new FileWriter(file + ".out"));
		}
		catch (IOException e)
		{
			// Failed to open new buffered reader
			System.err.println("Failed to open FileReader");
			e.printStackTrace();
			System.exit(-1);
		}
	}

	private void runTests()
	{
		// Read number of test cases
		int numberOfTests = 0;

		try
		{
			// Read number of tests (first line)
			numberOfTests = Integer.parseInt(reader.readLine());
		}
		catch (NumberFormatException | IOException e)
		{
			// Failed to read a line
			System.err.println("Failed to read a line");
			e.printStackTrace();
			System.exit(-1);
		}

		for (int testCase = 1; testCase <= numberOfTests; testCase++)
		{
			try
			{
				String[] input = reader.readLine().split("/");
				Rational elfness = new Rational(Integer.parseInt(input[0]), Integer.parseInt(input[1]));
				Integer numGens = numGens(elfness, 1);
				
				String response = "impossible";
				if (numGens > -1)
				{
					response = numGens.toString();
				}
				
				writer.write("Case #" + testCase + ": " + response);
				writer.newLine();
			}
			catch (IOException e)
			{
				e.printStackTrace();
			}
		}

		try
		{
			reader.close();
			writer.flush();
			writer.close();
		}
		catch (IOException e)
		{
			e.printStackTrace();
		}
	}
	
	private Integer numGens(Rational elfness, Integer currGen)
	{
		if (currGen > 40)
		{
			return -1;
		}
		else if (elfness.numerator == elfness.denominator || elfness.numerator == 0)
		{
			return currGen;
		}
		
		Rational parents = elfness.multiply(new Rational(2, 1));
		
		if (parents.numerator >= parents.denominator)
		{
			Rational difference = parents.add(new Rational(-1, 1));
			
			if (numGens(difference, currGen + 1) > -1)
			{
				return currGen;
			}
			else
			{
				return -1;
			}
		}
		else
		{
			return numGens(parents, currGen + 1);
		}
	}

	private class Rational
	{
	    public int numerator;
	    public int denominator;

	    public Rational(int numerator, int denominator)
	    {
	        int gcd = gcd(numerator, denominator);
	        this.numerator = numerator / gcd;
	        this.denominator = denominator / gcd;
	    }

	    public Rational multiply(Rational r)
	    {
	        return new Rational(this.numerator * r.numerator, this.denominator * r.denominator);
	    }
	    
	    public Rational add(Rational r) {
	        int numerator   = (this.numerator * r.denominator) + (this.denominator * r.numerator);
	        int denominator = this.denominator * r.denominator;
	        return new Rational(numerator, denominator);
	    }
	    
	    private int gcd(int a, int b)
	    {
	        if (b == 0)
	        {
	        	return a;
	        }
	        else
	        {
	        	return gcd(b, a % b);
	        }
	    }
	}
}
