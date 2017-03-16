import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.StringReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashSet;
import java.util.List;
import java.util.Set;


public class Cars {

	
	public static void main(String [] args) throws NumberFormatException, IOException
	{

		//BufferedReader in = new BufferedReader(new FileReader("src/kingdom.input"));
		BufferedReader in = new BufferedReader(new StringReader(args[0]));
		int rows = Integer.parseInt(in.readLine());
		for ( int i = 1; i <= rows; i++)
		{
			String line = in.readLine();
			String[] vals = line.split(" ");
			
			int carCount = Integer.parseInt(vals[0]);
			
			Car [] cars = new Car[carCount];
			for ( int j = 0; j < carCount; j++)
			{
				line = in.readLine();
				vals = line.split(" ");
				Car c = new Car();
				c.index=j;
				c.lane=vals[0].charAt(0);
				c.speed=Integer.parseInt(vals[1]);
				c.position=Double.parseDouble(vals[2]);
				cars[j]=c;
				
			}
			
			Comparator<Car> order = new Comparator<Car>(){

				@Override
				public int compare(Car arg0, Car arg1) {
					return Double.valueOf(arg0.position).compareTo(arg1.position);
				}
				
			};
			
			List<Car> left = new ArrayList<Car>();
			List<Car> right = new ArrayList<Car>();
			
			for ( Car c : cars)
			{
				if (c.lane=='L')
				{
					left.add(c);
				}
				else
				{
					right.add(c);
				}
			}
			
			Collections.sort(left,order);
			Collections.sort(right,order);
			


			double totalTime = 0;
			
			while ( true )
			{
//				System.out.println("Left: ");
//				print(left);
//				System.out.println("Right: ");
//				print(right);
				if ( listOK(left) && listOK(right) )
				{
					System.out.println("Case #" + i + ": Possible");
					break;
				}
				
				Collision lCollision = nextCollision(left);
				Collision rCollision = nextCollision(right);
				Collision collision = null;
				if (lCollision == null)
				{
					collision = rCollision;
				}
				else if (rCollision == null)
				{
					collision = lCollision;
				}
				else if ( lCollision.time < rCollision.time )
				{
					collision = lCollision;
				}
				else
				{
					collision = rCollision;
				}
				
				for (Car c : left)
				{
					c.position+=c.speed*collision.time;
				}
				for (Car c : right)
				{
					c.position+=c.speed*collision.time;
				}
				
				totalTime+=collision.time;
				
				List<Car> toCheck = left.contains(collision.car)?right:left;
				boolean move = true;
				for ( Car c : toCheck )
				{
					if ( Math.abs(collision.car.position - c.position) <= 5 )
					{
						move=false;
						break;
					}
				}
				
				if ( move == false)
				{
					System.out.println("Case #" + i + ": " + totalTime);
					break;
				}
				
				if ( collision.car.lane=='L' )
				{
					collision.car.lane='R';
					left.remove(collision.car);
					right.add(collision.car);
					Collections.sort(right,order);
				}
				else
				{
					collision.car.lane='L';
					right.remove(collision.car);
					left.add(collision.car);
					Collections.sort(left,order);
				}
			}
						
		}
	}
	
	private static Collision nextCollision(List<Car> c)
	{
		Double next = null;
		Car car = null;
		for ( int i = 1; i < c.size(); i++ )
		{
			if ( c.get(i).speed < c.get(i-1).speed )
			{
				double collision =  ((c.get(i).position) - (c.get(i-1).position) - 5) / ((c.get(i-1).speed) - (c.get(i).speed))  ; 
				if ( next == null || collision < next )
				{
					next = collision;
					car = c.get(i-1);
				}
			}
		}
		if ( next == null )
		{
			return null;
		}
		Collision coll = new Collision();
		coll.car=car;
		coll.time=next;
		return coll;
	}
	
	private static boolean listOK(List<Car> c)
	{
		for ( int i = 1; i < c.size(); i++ )
		{
			if ( c.get(i).speed < c.get(i-1).speed )
			{
				return false;
			}
		}
		return true;
	}
	
	private static void print(List<Car> cars)
	{
		for ( Car c : cars)
		{
			System.out.print("[position: "+c.position+", speed: "+c.speed+"], ");
		}
		System.out.println();
	}

	
}
class Car
{
	public int index;
	public char lane;
	public double position;
	public int speed;
}
class Collision
{
	public Car car;
	public double time;
}
