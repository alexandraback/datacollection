import java.io.BufferedReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class CloseMatch {
	public static String pad(int number, int length)
	{
		String sNumber = number + "";
		while(sNumber.length() < length)
			sNumber = "0" + sNumber;
		return sNumber;
	}
	public static boolean match(int number, String check)
	{
		String sNumber = pad(number, check.length());
		for(int i = 0; i < check.length(); i++)
		{
			if(check.charAt(i) != '?')
			{
				if(check.charAt(i) != sNumber.charAt(i))
					return false;
			}
		}
		return true;
	}
	public static int[] solve(int length, String c, String j)
	{
		int max = (int) Math.pow(10, length);
		int minDiff = Integer.MAX_VALUE;
		int[] output = new int[2];
		for(int i = 0; i < max; i++)
		{
			if(!match(i, c))
				continue;
			for(int k = 0; k < max; k++)
			{
				if(!match(k, j))
					continue;
				if(Math.abs(i - k) < minDiff)
				{
					minDiff = Math.abs(i - k);
					output[0] = i;
					output[1] = k;
				}
			}
		}
		return output;
	}
	public static void main(String[] args) {
		try
		{
			BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
			int t = Integer.parseInt(f.readLine());
			FileWriter fout = new FileWriter("closematch.out");
			for(int i = 1; i <= t; i++)
			{
				StringTokenizer st = new StringTokenizer(f.readLine());
				String c = st.nextToken();
				String j = st.nextToken();
				int[] scores = solve(c.length(), c, j);
				String[] output = new String[2];
				output[0] = pad(scores[0], c.length());
				output[1] = pad(scores[1], c.length());
				System.out.println("Case #" + i + ": " + output[0] + " " + output[1]);
				fout.write("Case #" + i + ": " + output[0] + " " + output[1] + "\n");
			}
			f.close();
			fout.close();
		}
		catch(IOException e)
		{
			e.printStackTrace();
		}


	}

}
