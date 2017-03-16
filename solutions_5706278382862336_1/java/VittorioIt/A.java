import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.util.Scanner;


public class A {

	public static void main (String[] args) throws Exception
	{
		Scanner input = new Scanner(new File("input"));
		BufferedWriter output = new BufferedWriter(new FileWriter(new File("output")));
		int T = input.nextInt();
		input.nextLine();
		for ( int index = 1; index<=T ; index++)
		{
			//Solve Here
			String s = input.nextLine();
			String[] reads = s.split("/");
			long P = Long.parseLong(reads[0]);
			long Q = Long.parseLong(reads[1]);
			
			double factor = ((double)P)/((double)Q);
			double ans = 1;
			long anss = 0;
			while( ans > factor )
			{
				anss++;
				ans = ans/2;
			}
			long anss1 = anss;
			while ( factor > 0 && anss1 < 41)
			{
				if ( factor >= ans)
				{
					factor -= ans;
				}
				ans = ans/2;
				anss1++;
			}
			if ( anss1 < 41)
			{
				output.write("Case #"+index+": "+anss);
			}
			else
			{
				output.write("Case #"+index+": impossible");
			}
			//Print Answer Here
			output.newLine();
		}
		output.flush();
		input.close();
		output.close();
	}
}
