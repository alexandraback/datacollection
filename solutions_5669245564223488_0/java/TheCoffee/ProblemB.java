import java.io.BufferedReader;
import java.io.FileReader;
import java.util.*;

public class ProblemB
{
	public static void main(String args[])
	{
		try
		{
			BufferedReader br = new BufferedReader(new FileReader("B-small-attempt2.in"));
			
			int cases = Integer.parseInt(br.readLine());
			
			for(int i = 0; i < cases; i++)
			{
				int numCars = Integer.parseInt(br.readLine());
				
				ArrayList<String> al = new ArrayList<String>();
				StringTokenizer st = new StringTokenizer(br.readLine());
				
				for(int j = 0; j < numCars; j++)
				{
					al.add(st.nextToken());
				}
				
				System.out.print("Case #" + (i+1) + ": ");	
				
				process(al);
			}
		}
		catch(Exception e)
		{
			e.printStackTrace();
		}
		
	}
	
	public static void process(ArrayList<String> strings)
	{		
		ArrayList<Car> cars = new ArrayList<Car>();
		for(int i = 0; i < strings.size(); i++)
		{
			cars.add(new Car(strings.get(i)));
		}
		
		processCars(cars);
	}
	
	
	static long answer;
	public static void processCars(ArrayList<Car> cars)
	{
		// Check if valid
		for(int i = 0; i < cars.size(); i++)
		{
			Car c = cars.get(i);
		}
		
		//System.out.println(cars.toString());
		
		answer = 0;
		permutation(cars);
		System.out.println("" + answer);
	}
	
	
	
	public static void permutation(ArrayList<Car> cars)
	{ 
	    permutation("", cars);
	}

	private static void permutation(String prefix, ArrayList<Car> cars)
	{
	    int n = cars.size();
	    if (n == 0)
	    {
	    	isValid(prefix);
	    }
	    else
	    {
	        for (int i = 0; i < n; i++)
	        {
	        	String newPrefix = prefix + cars.get(i).toString();
	        	ArrayList<Car> newCars = new ArrayList<Car>();
	        	for(int j = 0; j < cars.size(); j++)
	        	{
	        		if(j != i)
	        		{
	        			newCars.add( cars.get(j) );
	        		}
	        	}
	        	
	            permutation(newPrefix, newCars);
	        }
	    }
	}
	
	private static void isValid(String s)
	{
		s = reduce(s);
		//System.out.println("    " + s);
		
		for(int i = 0; i < s.length(); i++)
		{
			char now = s.charAt(i);
			int pos = s.indexOf("" + now, i+1);
			if( pos != -1)
			{
				return;
			}
		}
		
		answer++;
	}
	
	private static String reduce(String s)
	{
		StringBuilder newS = new StringBuilder();
		
		for(int i = 0; i < s.length(); i++)
		{
			if((i == 0) || (s.charAt(i) != s.charAt(i-1)))
			{
				newS = newS.append( s.charAt(i) );
			}
		}
		
		return newS.toString();
	}
}

class Car
{
	String s;
	
	public Car(String s)
	{
		this.s = reduce(s);
	}
	
	public String toString()
	{
		return "" + s;
	}
	
	private static String reduce(String s)
	{
		StringBuilder newS = new StringBuilder();
		
		for(int i = 0; i < s.length(); i++)
		{
			if((i == 0) || (s.charAt(i) != s.charAt(i-1)))
			{
				newS = newS.append( s.charAt(i) );
			}
		}
		
		return newS.toString();
	}
}





