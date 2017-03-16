import java.io.BufferedReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class RevengeOfThePancakes {
	public static void main(String[] args) {
		try
		{
			BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
			int t = Integer.parseInt(f.readLine());
			FileWriter fout = new FileWriter("revengeofthepancakes.out");
			for(int i = 1; i <= t; i++)
			{
				String s = f.readLine() + "+";
				int numFlips = 0;
				for(int j = 0; j < s.length() - 1; j++)
				{
					if(s.charAt(j) != s.charAt(j + 1))
						numFlips++;
				}
				System.out.println("Case #" + i + ": " + numFlips);
				fout.write("Case #" + i + ": " + numFlips + "\n");
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
