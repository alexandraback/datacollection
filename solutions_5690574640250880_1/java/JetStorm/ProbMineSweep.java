import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;

public class ProbMineSweep
{
	public static void main(final String[] args) throws IOException
	{
		BufferedReader reader = new BufferedReader(new FileReader(new File(
				"data22.txt")));
		PrintWriter writer = new PrintWriter(new FileWriter(new File(
				"out22.txt")));
		int noCases = Integer.parseInt(reader.readLine());
		for (int testCase = 1; testCase <= noCases; testCase++) {
			String[] c_f_x = reader.readLine().split(" ");
			double c = Double.parseDouble(c_f_x[0]);
			double f = Double.parseDouble(c_f_x[1]);
			double x = Double.parseDouble(c_f_x[2]);
			double t = calculate(c, f, x);
			writer.printf("Case #%d: %.7f%n", testCase, t);
		}
		writer.close();
		reader.close();
	}

	private static double calculate(double c, double f, double x)
	{
		double totalTime = 0.0;
		for (int noFarms = 0; noFarms * c < x; noFarms++) {
			double farmTime = c / (2.0 + f * noFarms);
			double nextTime = farmTime + x / (2.0 + f * (noFarms+1));
			double currTime = x / (2.0 + f * noFarms);
			if(currTime <= nextTime)
				return totalTime+currTime;
			totalTime+= farmTime;
		}
		return 0;
	}
}
