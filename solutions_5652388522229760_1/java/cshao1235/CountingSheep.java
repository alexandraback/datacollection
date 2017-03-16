import java.io.BufferedReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class CountingSheep {
	public static boolean allSeen(boolean[] seen)
	{
		for(int i = 0; i < seen.length; i++)
		{
			if(!seen[i])
				return false;
		}
		return true;
	}
	public static void main(String[] args) {
		try
		{
			BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
			int t = Integer.parseInt(f.readLine());
			FileWriter fout = new FileWriter("countingsheep.out");
			for(int i = 1; i <= t; i++)
			{
				int n = Integer.parseInt(f.readLine());
				if(n == 0)
				{
					System.out.println("Case #" + i + ": INSOMNIA");
					fout.write("Case #" + i + ": INSOMNIA\n");
					continue;
				}
				boolean[] seen = new boolean[10];
				//boolean found = false;
				int counter = 1;
				String current = (n*counter) + "";
				while(!allSeen(seen))
				{
					current = (n*counter) + "";
					for(int k = 0; k < current.length(); k++)
						seen[current.charAt(k) - '0'] = true;
					counter++;
				}
				System.out.println("Case #" + i + ": " + current);
				fout.write("Case #" + i + ": " + current + "\n");
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
