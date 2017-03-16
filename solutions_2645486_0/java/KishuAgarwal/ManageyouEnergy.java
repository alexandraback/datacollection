import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class ManageyouEnergy {

	/**
	 * @param args
	 * @throws IOException 
	 * @throws NumberFormatException 
	 */
	static int e,r,n;
	static int activities[];
	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub

		BufferedReader buffer = new BufferedReader(new FileReader("B-small-attempt0.in"));
		PrintWriter writer = new PrintWriter(new BufferedWriter(new FileWriter("output.txt")));
		int test = Integer.parseInt(buffer.readLine());
		StringTokenizer token;
		for(int i = 1; i <= test; i++)
		{
			token = new StringTokenizer(buffer.readLine());
			e = Integer.parseInt(token.nextToken());
			r = Integer.parseInt(token.nextToken());
			n = Integer.parseInt(token.nextToken());
			activities = new int[n];
			token = new StringTokenizer(buffer.readLine());
			for(int k = 1; k <= n; k++)
			{
				activities[k-1] = Integer.parseInt(token.nextToken());
			}
			
			
			writer.println("Case #"+i+": "+gain(0,e));
		}
		buffer.close();
		writer.close();
		
	}
	public static int gain(int p,int energy)
	{
		int gain = 0;
		if(p >= n)
			return 0;
		int temp;
		if(energy > e)
			energy = e;
		int max = 0 ;
		for(int k = 0; k <= energy ;k++)
		{
			temp =(activities[p]*k + gain(p+1,energy - k + r));
			if(temp > gain)
			{
				gain = temp;
				max = k;
			}
		}
		return gain;
	}
	

}
