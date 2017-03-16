import java.io.*;
import java.util.*;
//import java.math.*;

public class c {

	public static void main(String[] args) throws IOException
	{
		Scanner qwe = new Scanner(new File("c.in"));
		BufferedWriter out = new BufferedWriter(new FileWriter("c.out"));
		int t = qwe.nextInt();
		for(int i = 1; i <= t; i++)
		{
			int a = qwe.nextInt();
			int b = qwe.nextInt();
			int[] been = new int[2000001];
			long count = 0;
			
			for(Integer j =a; j <= b; j++)
			{
				//if(been[j] > 1 && i == 4)
					//System.out.println(i + " " +j +  " " + been[j]);
				if(been[j] > 0)
					count += been[j];
				String s = j.toString();
				ArrayList<String> tocheck = new ArrayList<String>();
				for(int k = 1; k < s.length(); k++)
				{
					String torec = s.substring(k);
					String end = s.substring(0,k);
					String combin = torec+end;
					if(!tocheck.contains(combin))
						been[Integer.parseInt(combin)] += 1;
					tocheck.add(combin);
				}
				
			}
			
			out.write("Case #" + i + ": " + count +  "\n");
		}
		out.close();
	}
}

