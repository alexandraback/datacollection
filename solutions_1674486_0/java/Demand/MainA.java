import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.util.ArrayList;


public class MainA {


	
	
	/**
	 * @param args
	 * @throws IOException 
	 * @throws NumberFormatException 
	 */
	public static void main(String[] args) throws NumberFormatException, IOException {
		
		class Diamond
		{
			ArrayList<Diamond> links = new ArrayList<Diamond>();
			
			public int find(Diamond target)
			{
				int a = 0;
				if (this == target)
					return 1;
				
				for (int i =0; i<links.size(); i++)
					 a+=links.get(i).find(target);
				
				return a;
			}
		}
		
		BufferedReader reader = new BufferedReader(new InputStreamReader(new FileInputStream("/Users/alexander/Downloads/A-small-attempt2.in")));
		//BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		PrintStream writer = new PrintStream("a.txt");
		//PrintStream writer = System.out;
		int N = Integer.parseInt(reader.readLine());
		for (int i =1; i<=N; i++)
		{
			int diamondCount = Integer.parseInt(reader.readLine());
			ArrayList<Diamond> diamonds = new ArrayList<Diamond>();
			for (int j =1; j<=diamondCount; j++)
			{
				diamonds.add(new Diamond());
			}
			
			for (int j =1; j<=diamondCount; j++)
			{
				String[] links = reader.readLine().split(" ");
				for (int k = 1; k<= Integer.parseInt(links[0]); k++)
				{
					int linkTo = Integer.parseInt(links[k]);
					diamonds.get(j-1).links.add(diamonds.get(linkTo-1));
				}
			}
			
			boolean f = false;
			for (int p = 0; p<diamonds.size(); p++)
			{
				for (int t = 0; t<diamonds.size(); t++)
				{
					if (diamonds.get(p).find(diamonds.get(t))>1)
					{
						f = true;
						break;
					}
				}
				if (f)
					break;
			}
			if (f)
				writer.println("Case #"+i+": Yes");
			else
				writer.println("Case #"+i+": No");
		}
		writer.flush();
		writer.close();
	}
	
	
	
}


