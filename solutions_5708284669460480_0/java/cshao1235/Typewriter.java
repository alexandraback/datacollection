import java.io.BufferedReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


public class Typewriter
{
	public static void main(String[] args) {
		try
		{
			BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
			int t = Integer.parseInt(f.readLine());
			FileWriter fout = new FileWriter("typewriter.out");
			for(int i = 1; i <= t; i++)
			{
				StringTokenizer st = new StringTokenizer(f.readLine());
				int k = Integer.parseInt(st.nextToken());
				int l = Integer.parseInt(st.nextToken());
				int s = Integer.parseInt(st.nextToken());
				String keys = f.readLine();
				String target = f.readLine();
				double[] probabilities = new double[26];
				for(int j = 0; j < k; j++)
					probabilities[keys.charAt(j) - 'A'] += 1.0/k;
				boolean canBeFormed = true;
				for(int j = 0; j < l; j++)
				{
					if(probabilities[target.charAt(j) - 'A'] == 0)
					{
						canBeFormed = false;
						break;
					}
				}
				if(!canBeFormed)
				{
					System.out.println("Case #" + i + ": " + 0.0);
					fout.write("Case #" + i + ": " + 0.0 + "\n");
				}
				else
				{
					double wordProbability = 1;
					for(int j = 0; j < l; j++)
						wordProbability *= probabilities[target.charAt(j) - 'A'];
					double expectedToLose = (s - l + 1) * wordProbability;
					int substringLength = 0;
					for(int j = 1; j < l; j++)
					{
						if(target.substring(0, j).equals(target.substring(l - j)))
							substringLength = j;
					}
					int maxBananas = (s-l)/(l - substringLength) + 1;
					double expectedToKeep = maxBananas - expectedToLose;
					System.out.println("Case #" + i + ": " + expectedToKeep + " " + maxBananas);
					fout.write("Case #" + i + ": " + expectedToKeep + "\n");
				}
			}
			f.close();
			fout.close();
		}
		catch(IOException e)
		{
			System.out.println(e);
		}
	}

}
