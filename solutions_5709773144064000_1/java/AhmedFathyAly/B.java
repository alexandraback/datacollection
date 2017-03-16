package Qualification2014;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;

import javax.sql.XADataSource;

/**
 * Open an input file called "input.txt", output file "output.txt" The file
 * begins with n,the number of lines, followed by n lines each line of the n
 * lines has two numbers writes all the number separated be a space in the
 * output file
 * 
 */
public class B
{

	public static void main(String[] args) throws IOException
	{
		// For the Input file
		BufferedReader in = new BufferedReader(new FileReader("input.txt"));

		// For the output file
		BufferedWriter out = new BufferedWriter(new FileWriter("output.txt"));

		// Read the number from the input file and write them to the output file
		int nCases = Integer.parseInt(in.readLine());
		for (int i = 0; i < nCases; i++)
		{
			String[] strs = in.readLine().split(" ");
			double c, f, x;
			c = Double.parseDouble(strs[0]);
			f = Double.parseDouble(strs[1]);
			x = Double.parseDouble(strs[2]);
			out.write("Case #" + (i+1) + ": ");
			out.write(solve(c, f, x));
			out.write("\n");
		}
		out.flush();
		


		// Close the streams
		in.close();
		out.close();
	}

	private static String solve(double c, double f, double x)
	{
		double t = 0;
		double rate = 2.0;
		double nextFarm = c / rate;
		double xAfterFarm = nextFarm + x / (rate + f);
		double xWithoutFarm = x / rate;
		
//		System.out.println("next Farm: "+ nextFarm);
//		System.out.println("xAfterFarm: " +xAfterFarm);
//		System.out.println("xWithoutFarm: " + xWithoutFarm);
		while (xWithoutFarm > xAfterFarm)
		{
			rate += f;
			xWithoutFarm =nextFarm +  x / rate;
			nextFarm += c / rate;
			xAfterFarm = nextFarm +   x / (rate + f);

			
		}

		
		return xWithoutFarm + "";
	}

}
