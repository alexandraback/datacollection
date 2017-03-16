import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Scanner;


public class PasswordProblem {

	/**
	 * @param args
	 */
	private static Scanner input;
	private static int n;
	private static double[] probs;
	private static int a;
	private static int b;
	private static double num;
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		try {
			input = new Scanner(new FileReader(args[0]));
		} catch (FileNotFoundException e) {
			e.printStackTrace();
			System.exit(-1);
		}
		n = input.nextInt();
		try
		{
			FileWriter fstream = new FileWriter("out.txt");
			BufferedWriter out = new BufferedWriter(fstream);
			for(int i=0; i<n; i++)
			{
				parseFile();
				num = Double.MAX_VALUE;
				for(int x=0; x<=a; x++)
				{
					num = Math.min(runCase(x), num);
				}
				out.write(("Case #" + (i+1) + ": " + num));
				out.write("\n");
			}
			out.close();
		}
		catch (Exception e){//Catch exception if any
			  System.err.println("Error: " + e.getMessage());
			  }
		
	}
	
	public static void parseFile()
	{
		a = input.nextInt();
		b = input.nextInt();
		probs = new double [a];
		for(int i=0; i<a; i++)
		{
			probs[i] = input.nextDouble();
		}
		
	}
	
	public static double runCase(int j)
	{
		double min = 0;
		if(j == 0)
		{
			
			if(a==0)
			{
				return b+1;
			}
			double sum = 1.0;
			for(int y=0;y<a;y++)
			{
				sum *= probs[y];
			}
			min += sum* ((double)(b-a+1));
			min+= ((double) (1.0-sum)) * ((double) (b-a+b+2));
			
		}
		else if(j==a)
		{
			min = b+2;
		}
		else
		{
			double sum = 1.0;
			for(int y=0;y<a-j;y++)
			{
				sum *= probs[y];
			}
			min = sum* ((double) (b-a+(2*j)+1));
			min += ((double) (1.0-sum)) * ((double) (b-a+(2*j)+2+b));
		}
		return min;
		
	}

}
