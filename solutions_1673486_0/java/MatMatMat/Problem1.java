import java.io.*;
import java.util.*;

public class Problem1
{
	public static void main(String[] args) throws Exception
	{
		String base = "A-small-attempt0";
		BufferedReader reader = new BufferedReader(new FileReader(base+".in"));
		reader.readLine();
		int place=0;
		while (reader.ready())
		{
			String line = reader.readLine();
			String[] arr = line.split(" ");
			int num = Integer.parseInt(arr[0]);
			int total = Integer.parseInt(arr[1]);
			double[] probs = new double[num];
			line = reader.readLine();
			arr = line.split(" ");
			for (int i=0;i<arr.length;i++)
				probs[i]=Double.parseDouble(arr[i]);
			System.out.println("Case #" + (++place) + ": " + solve(num,total,probs));
		}
		reader.close();
	}
	public static double solve(int num, int total, double[] probs)
	{
		double expectedRedo = total+2;

		double chanceAllRight = 1.0;
		for (double chance : probs)
			chanceAllRight*=chance;
		double expectedContinue = ((total-num+1)*chanceAllRight)+((total-num+1+total+1)*(1-chanceAllRight));
		double[] backExpect = new double[num];
		for (int i=1;i<=num;i++)
		{
			double chanceOtherRight = 1;
			for (int j=0;j<num-i;j++)
				chanceOtherRight*=probs[j];
			backExpect[i-1]=((total-num+(2*i)+1)*chanceOtherRight)+((total-num+(2*i)+1+total+1)*(1-chanceOtherRight));
		}
		double min = expectedRedo < expectedContinue ? expectedRedo : expectedContinue;
		for (double expected : backExpect)
			min = expected < min ? expected : min;
		return min;
	}
}
