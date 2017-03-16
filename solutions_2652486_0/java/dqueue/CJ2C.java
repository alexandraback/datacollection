import java.util.*;
import java.io.*;

public class CJ2C
{

	public static void main(String[] args) throws Exception 
	{
		File infile = new File("/Users/dennisqin/Downloads/CodeJam/C-small-1-attempt2.in.txt");
		File outfile = new File("/Users/dennisqin/Downloads/CodeJam/outputC.txt");
		BufferedReader br = new BufferedReader(new FileReader(infile));
		BufferedWriter bw = new BufferedWriter(new FileWriter(outfile));
		String s;
		String t;
		int cases = Integer.parseInt(br.readLine());
		s = br.readLine();
		String[] splits = s.split(" ");
		int r = Integer.parseInt(splits[0]); //number of lines
		int n = Integer.parseInt(splits[1]); //number of integers
		int m = Integer.parseInt(splits[2]); //largest number
		int k = Integer.parseInt(splits[3]); //number of products
		bw.write("Case #1:\n");
		for(int i = 0; i < r; i++)
		{

			ArrayList list = new ArrayList();
			s = br.readLine();
			splits = s.split(" ");
			int[] prods = new int[n];
			t = "";
			outerloop:
			for (int l = 0; l < n; l++)
			{
				ArrayList list2 = new ArrayList();
				prods[l] = Integer.parseInt(splits[l]);
				while(prods[l] != 1)
				{
					for (int z = m; z > 1; z--)
					{
						if(prods[l] % z == 0)
						{
							list.add(list.size(), Integer.valueOf(z));
							list2.add(list2.size(), Integer.valueOf(z));
							prods[l] = prods[l]/z;
						}
					}
					if (list2.size() == n)
					{
						for (int z = 0; z < n; z++)
						{
							//System.out.println("here");
							t = t + list2.get(z);
						}
						break outerloop;
					}
				}
			}
			
			if(t.equals(""))
			{
				for (int j = 0; j < n; j++)
				{
					 if(j < list.size())
						 t = t + list.get(j);
					 else
						 t = t + "2";
				}
					
			}

			bw.write(t);
			if((i + 1) < r)
			{
				bw.write("\n");
			}
			bw.flush();
		}
	}

}