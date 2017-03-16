import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;


public class CookieClicker {

	public final static String INPUT_FILE_NAME = "B-small-attempt0.in";
	public final static String OUTPUT_FILE_NAME = "CookieOut.txt";
	
	public static void main(String[] args) {
		try(Scanner in = new Scanner(new FileReader(INPUT_FILE_NAME));
				PrintWriter out = new PrintWriter(new FileWriter(OUTPUT_FILE_NAME)))
		{
			int numT = in.nextInt();
			for(int t = 1; t <= numT; t ++)
			{
				double cookieRate = 2;
				double farmCost = in.nextDouble();
				double farmBonus = in.nextDouble();
				double target = in.nextDouble();
				
				double totalTime = 0;
				while(target/cookieRate > farmCost/cookieRate + target/(cookieRate + farmBonus))
				{
					totalTime += farmCost/cookieRate;
					cookieRate += farmBonus;
				}
				totalTime += target/cookieRate;
				out.println("Case #" + t + ": " + totalTime);
			}
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

	}

}
