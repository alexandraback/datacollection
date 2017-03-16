import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.Writer;
import java.util.Scanner;


public class StandingOvation {
	
	
	public static int numberOfFriends(int[] shyness)
	{
		int max = 0, sum = 0, l = shyness.length;
		
		for(int n = 0; n < l; n++)
		{
			sum += shyness[n];
			
			if(max < n+1 - sum)
				max = n+1 - sum;
		}
		return max;
	}
	
	public static void main(String[] args)
	{
		
		Scanner scan = new Scanner(System.in);
		try {
			scan = new Scanner(new FileReader("input.txt"));
		} catch (FileNotFoundException e) {
			e.printStackTrace();
			scan.close();
			return;
		}
		
		Writer out = null;
		
		try {
			out = new BufferedWriter(new OutputStreamWriter(
	              new FileOutputStream("output.txt"), "utf-8"));
		}
		
		catch ( IOException e ) {
            e.printStackTrace();
        }
		
		
		
		int t = scan.nextInt();
		
		
		for(int i = 0; i < t; i++)
		{ 	
			System.out.println("Case #" + (i+1));
			
			int sMax = scan.nextInt();
			
			int[] shyness = new int[sMax+1];
			System.out.println(sMax);
			String s = scan.next();
			for(int j = 0; j < sMax + 1; j++)
				shyness[j] = (int)(s.charAt(j)) - (int)('0');
			
			
			try {
				out.write("Case #"+(i+1)+": " + numberOfFriends(shyness) + "\n");
			}
			catch ( IOException e ) {
	            e.printStackTrace();
	        }
		}
		
		
		
		try {
		out.close();
		}
		catch ( IOException e ) {
            e.printStackTrace();
        }
		
		scan.close();
		
	}
}
