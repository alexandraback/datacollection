import java.io.BufferedReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Fractiles {
	public static long tileNumber(long[] baseK, long k)
	{
		long output = 0;
		for(int i = 0; i < baseK.length; i++)
			output = (output*k) + baseK[i];
		output++;
		return output;
	}
	public static void main(String[] args) {
		try
		{
			BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
			int t = Integer.parseInt(f.readLine());
			FileWriter fout = new FileWriter("fractiles.out");
			for(int i = 1; i <= t; i++)
			{
				StringTokenizer st = new StringTokenizer(f.readLine());
				int k = Integer.parseInt(st.nextToken());
				int c = Integer.parseInt(st.nextToken());
				int s = Integer.parseInt(st.nextToken());
				if(k == 1)
				{
					System.out.println("Case #" + i + ": " + 1);
					fout.write("Case #" + i + ": " + 1 + "\n");
					continue;
				}
				else if(s * c < k)
				{
					System.out.println("Case #" + i + ": IMPOSSIBLE");
					fout.write("Case #" + i + ": IMPOSSIBLE\n");
					continue;
				}
				int counter = 0;
				StringBuffer output = new StringBuffer("");
				while(counter < k)
				{
					long[] baseK = new long[c];
					for(int j = 0; j < c; j++)
					{
						if(counter == k)
							baseK[j] = 0;
						else
							baseK[j] = counter;
						counter = Math.min(counter + 1, k);
					}
					output.append(tileNumber(baseK, k) + " ");
				}
				String set = output.toString().trim();
				System.out.println("Case #" + i + ": " + set);
				fout.write("Case #" + i + ": " + set + "\n");
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
