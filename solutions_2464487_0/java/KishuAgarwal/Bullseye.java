import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;
import java.util.StringTokenizer;


public class Bullseye {

	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader buffer = new BufferedReader(new FileReader("A-small-attempt0.in"));
		PrintWriter writer = new PrintWriter(new BufferedWriter(new FileWriter("output.txt")));
		int test = Integer.parseInt(buffer.readLine());
		long currentArea;
		long r,t;
		long currentRadius;
		long count;
		StringTokenizer token;
		for(int i = 1; i <= test; i++)
		{
			token = new StringTokenizer(buffer.readLine());
			r = Long.parseLong(token.nextToken());
			t = Long.parseLong(token.nextToken());
			count = 0;
			currentRadius = r;
			for(int k = 1; ; k++)
			{
				currentArea = ((currentRadius+1)*(currentRadius+1) - (currentRadius)*(currentRadius));
			    if(t >= currentArea)
			    {
			    	t = t- currentArea;
			    	count++;
			    	currentRadius += 2;
			    }
			    else
			    	break;
			   
			
			}
			writer.println("Case #"+ i+": "+ count);
		}
		writer.close();
		buffer.close();
	
	}

}
