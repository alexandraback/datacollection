import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class Problem
{
	public static void main(String[] args) throws IOException
	{
		Scanner scan = new Scanner(new File("test.in"));
		int numCases = scan.nextInt();
		scan.nextLine();
		BufferedWriter writer = new BufferedWriter(new FileWriter(new File("test.out")));
		
		for(int caseN = 1; caseN <= numCases; caseN++)
		{
			writer.write("Case #" + caseN + ": ");
			String[] line = scan.nextLine().split("/");
			long a = Long.parseLong(line[0]), b = Long.parseLong(line[1]);
			long f = b / gcf(a, b);
			if((f & (f - 1)) != 0) writer.write("impossible\n");
			else
			{
//				System.out.println("Case #" + caseN);
//				System.out.println(Math.log(b / (double) a) / Math.log(2));
				int ans = (int) Math.ceil(Math.log(b / (double) a) / Math.log(2));
				if(ans > 40) writer.write("impossible\n");
				else writer.write(Math.max(1, ans) + "\n");
			}
		}
		
		scan.close();
		writer.close();
	}
	
	public static long gcf(long a, long b)
	{
		while(a > 0)
		{
			long aa = a;
			a = b % a;
			b = aa;
		}
		return b;
	}
}