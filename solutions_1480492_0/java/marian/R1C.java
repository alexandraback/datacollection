package jam2012;
import java.io.*;
import java.util.*;
import java.text.*;

// Marian G Olteanu
public class R1C
{
	
	public static Car getCar(int idx, String str)
	{
		String lineT[] = tokenize(str);
		boolean leftLane = lineT[0].toUpperCase().equals("L");
		double speed = Double.parseDouble(lineT[1]);
		double position = Double.parseDouble(lineT[2]);
		return new Car(idx, leftLane, speed, position);
	}
	
	static class Point
	implements Comparable<Point>
	{
		public Point(double speed, double position)
		{
			this.speed = speed;
			this.position = position;
		}
		
		double speed, position;
		
		public int compareTo(Point other)
		{
			if (this.position != other.position)
				return Double.compare(this.position, other.position);
			return Double.compare(this.speed, other.speed);
		}
		
	}
	
	public static class CompCar implements Comparator<Car>
	{
		public int compare(R1C.Car p1, R1C.Car p2)
		{
			if (p1.position == p2.position)
			{
				// sort by lane; l first
				if (p1.leftLane == p2.leftLane)
					return 0;
				if (p1.leftLane)
					return -1;
				return 1;
			}
			else
				return p1.compareTo(p2);
		}
		
		
	}
	
	
	static class Car
	extends Point
	{
		
		public int idx;
		
		public Car(int idx, boolean left, double speed, double position)
		{
			super(speed, position);
			this.idx = idx;
			this.leftLane = left;
		}
		

		boolean leftLane;

		
	}
	public static void main(String[] args)
	throws Exception
	{
		BufferedReader inputFile = new BufferedReader(new InputStreamReader(new FileInputStream(args[0])));
		int cases = Integer.parseInt(inputFile.readLine());
		
		PrintStream outFile = new PrintStream(new FileOutputStream(args[1]));
		for (int i = 1; i <= cases; i++)
		{
			int n = Integer.parseInt(inputFile.readLine());
			
			Car[] cars = new Car[n];
			for (int j = 0; j < n; j++)
				cars[j] = getCar(j, inputFile.readLine());
			
			sort(cars);
			moveCarsToRightLane(cars);
			printCars(cars);
			
			String out = null;
			if (n <= 2)
				out = "Possible";
			else
			{
				double time = 0;
				
				while (true)
				{
					//double nextCollision = calculateNextCollision(cars);
					double t = calculateNextEdgeAlignment(cars);// includes collision
					if (Double.isNaN(t))
					{
						out = "Possible";
						break;
					}
					addTime(cars, t);
					sort(cars);
					printCars(cars);
					
					time += t;
					moveCarsToRightLane(cars);
					sort(cars);
					printCars(cars);
					
					boolean success = passToAvoidCollision(cars, time);
					if (!success)
					{
						break;// cannot pass any more... game over
					}
					printCars(cars);
					
				}
				
				if (out == null)
					out = formatDouble(time, "0.000000");
			}
			
			outFile.println("Case #" + i + ": " + out);
		}
		
		
		outFile.close();
		inputFile.close();
	}
	

	private static double calculateNextEdgeAlignment(Car[] cars)
	{
		Point[] p = new Point[cars.length * 2];
		for (int i = 0; i < cars.length; i++)
		{
			p[i * 2] = new Point(cars[i].speed, cars[i].position);
			p[i * 2 + 1] = new Point(cars[i].speed, cars[i].position + 5.0);
		}
		Arrays.sort(p);
		
		double time = Double.NaN;
		for (int i = 1; i < p.length; i++)
		{
			Point a = p[i - 1];
			Point b = p[i];
			
			if (a.position != b.position)
				if (a.speed > b.speed)
				{
					double t = (b.position - a.position) / (a.speed - b.speed);
					
					if (Double.isNaN(time) || time > t)
						time = t;
				}
			
		}
		return time;
	}
	
	private static boolean passToAvoidCollision(R1C.Car[] cars, double time)
	{
		for (int i = cars.length - 2; i >= 0; i--)
			for (int j = i; j < cars.length; j++)
				if (distance(cars[i], cars[j]) <= 5)
					if (cars[i].speed > cars[j].speed
						&& cars[i].leftLane == cars[j].leftLane)
					{
						// i need to pass
						if (boxedIn(cars, i))
							return false;
						
						cars[i].leftLane = !cars[i].leftLane;
					}
		return true;
	}
	
	private static boolean boxedIn(R1C.Car[] cars, int i)
	{
		for (int j = 0; j < cars.length; j++)
			if (cars[j].leftLane != cars[i].leftLane)
				if (distance(cars[i], cars[j]) < 5)
					return true;
		
		return false;
	}
	
	private static void addTime(Car[] cars, double t)
	{
		for (R1C.Car car : cars)
			car.position += t * car.speed;
	}
	
	
	private static void printCars(Car[] cars)
	{
	}
	
	private static void moveCarsToRightLane(Car[] cars)
	{
		for (int i = 0; i < cars.length; i++)
			if (cars[i].leftLane)
			{
				Car nextCar = getNextCar(cars, i);
				Car prevCar = getPrevCar(cars, i);
				
				if (nextCar == null || notTouching(nextCar, cars[i]))
					if (prevCar == null || notTouching(prevCar, cars[i]))
						cars[i].leftLane = false;
			}
	}
	
	private static boolean notTouching(Car a, Car b)
	{
		return distance(a, b) >= 5.0;
	}
	private static boolean overlapping(Car a, Car b)
	{
		return distance(a, b) <= 4.9999999999;
	}
	private static double distance(Car a, Car b)
	{
		return Math.abs(a.position - b.position);
	}
	
	private static Car getNextCar(Car[] cars, int i)
	{
		if (i + 1 < cars.length)
			return cars[i + 1];
		return null;
	}
	private static Car getPrevCar(Car[] cars, int i)
	{
		if (i > 0)
			return cars[i - 1];
		return null;
	}
	
	private static void sort(Car[] cars)
	{
		Arrays.sort(cars);
	}
	
	
	
	
	public static String[] tokenize(String input)
	{
		StringTokenizer st = new StringTokenizer(input);
		String[] k = new String[st.countTokens()];
		for (int i = 0; i < k.length; i++)
			k[i] = st.nextToken();
		return k;
	}
	public static String[] tokenize(String input, String sep)
	{
		StringTokenizer st = new StringTokenizer(input , sep);
		String[] k = new String[st.countTokens()];
		for (int i = 0; i < k.length; i++)
			k[i] = st.nextToken();
		return k;
	}
	
	
	public static String formatDouble(double myDouble , String format)
	{
		DecimalFormat dfFormat = new DecimalFormat(format);
		FieldPosition f = new FieldPosition(0);
		StringBuffer s = new StringBuffer();
		dfFormat.format(myDouble, s, f);
		return s.toString();
	}
}

