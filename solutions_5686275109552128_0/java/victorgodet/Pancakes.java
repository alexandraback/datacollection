import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.Writer;
import java.util.ArrayList;
import java.util.Scanner;


public class Pancakes {

	public static int time(ArrayList<Integer> pancakes)
	{
		int max = 0, split = 0, min_time, this_time;
			
		for(int elt : pancakes)
		{
			if(elt > max)
				max = elt;
		}
		
		if(max <= 3)
			return max;

		pancakes.remove((Integer)max);
		
		min_time = max - 1;
	
		for(int div = 2; div <= Math.sqrt(max); div++)
		{
			split = (int)(max/div);
		
			pancakes.add(split);
			pancakes.add(max-split);
			
			this_time = time(pancakes);
			if(min_time > this_time)
				min_time = this_time;
			
			pancakes.remove((Integer)split);
			pancakes.remove((Integer)(max-split));
		}
		
		pancakes.add(max);
		
		
		return min_time + 1;
				
	}
	
	public static void main(String[] args)
	{
		
		Scanner scan = new Scanner(System.in);
		try {
			scan = new Scanner(new FileReader("input.txt"));
		} catch (FileNotFoundException e) {
			e.printStackTrace();
			scan.close();
			return;
		}
		
		Writer out = null;
		
		try {
			out = new BufferedWriter(new OutputStreamWriter(
	              new FileOutputStream("output.txt"), "utf-8"));
		}
		
		catch ( IOException e ) {
            e.printStackTrace();
        }
		
		
		int t = scan.nextInt();
		
		for(int i = 0; i < t; i++)
		{
			int d = scan.nextInt();
			ArrayList<Integer> pancakes = new ArrayList<Integer>();
			
			for(int j = 0; j < d; j++)
				pancakes.add(scan.nextInt());
		
			try {
			out.write("Case #"+(i+1)+": " + time(pancakes) + "\n");
			}
			catch ( IOException e ) {
	            e.printStackTrace();
	        }
		}
		
		
		
		try {
		out.close();
		}
		catch ( IOException e ) {
            e.printStackTrace();
        }
		
		scan.close();
		
	}
}
