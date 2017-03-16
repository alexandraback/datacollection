import java.util.Scanner;
import java.io.File;
import java.io.FileWriter;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.FileNotFoundException;

public class Safety {

	public static void main(String[] args) 
	{
		String input = "A-small-attempt2.in";
		String output = "output.txt";
	
		File f = new File(input);
		try
		{
			Scanner scan = new Scanner(f);
			
			int lines = Integer.parseInt(scan.nextLine());
			FileWriter fstream = new FileWriter(output);
			BufferedWriter out = new BufferedWriter(fstream);
						
			for(int i=0; i<lines; i++)
			{
				String line = scan.nextLine();
				String[] arr = line.split(" ");
				
				int n = Integer.parseInt(arr[0]);
				
				int[] points = new int[n];
				
				for(int j=1; j<n+1; j++)
					points[j-1] = Integer.parseInt(arr[j]);
				
				out.write("Case #"+(i+1)+": "+solve(n, points));
				out.newLine();
			}
			out.close();
		}
		catch(FileNotFoundException e)
		{
			e.printStackTrace();
		}
		catch(IOException ex)
		{
			ex.printStackTrace();
		}
		
	}
	
	public static String solve(int n, int[] points)
	{
		double sum=0;
		for(int i=0; i<n; i++)
			sum += points[i];
		
		double target = 2*sum/n;
		
		
		double remaining = 2*sum;
		int contenders = n;
		
		for(int i=0; i<n; i++)
		{
			if(points[i] > target)
			{
				remaining -= points[i];
				contenders--;
			}
		}
		double newtarget = remaining/contenders;

		double[] needed = new double[n];
		
		for(int i=0; i<n; i++)	
		{
			if(points[i] > target)
				needed[i] = 0.0;
			else
				needed[i] = (newtarget-points[i])*100.0/sum;
		}
		
		String out = "";
		for(int i=0; i<n; i++)
		{
			if(i != n-1)
				out += needed[i]+" ";
			else
				out += needed[i];
		}
		
		return out;
	}
}






