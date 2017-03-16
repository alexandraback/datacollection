package midnighter.googlejam;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.DataInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.Writer;


public class Round1B_A 
{
	public static int count;
	public static void main(String[] args) throws NumberFormatException, IOException
	{
		FileInputStream fstream = new FileInputStream("inputs/Round1B/A-large.in");
	    DataInputStream in = new DataInputStream(fstream);
	    BufferedReader reader = new BufferedReader(new InputStreamReader(in));
	    Writer writer = new BufferedWriter(new FileWriter(new File("outputs/output")));
	    int cases = Integer.parseInt(reader.readLine());
	    
	    for (int i = 0; i < cases; i++)
	    {
	    	System.out.println("Case "+i);
	    	String[] ar = reader.readLine().split(" ");
	    	int n = Integer.parseInt(ar[0]);
	    	long M = Long.parseLong(ar[7]);
	    	long A = Long.parseLong(ar[1]);
	    	long B = Long.parseLong(ar[2]);
	    	long C = Long.parseLong(ar[3]);
	    	long D = Long.parseLong(ar[4]);
	    	
	    	long[][] points = new long[n][2];
	    	long x = points[0][0] = Integer.parseInt(ar[5]);
	    	long y = points[0][1] = Integer.parseInt(ar[6]);
	    	count = 0;
	    	
	    	for (int k = 0; k < n-1; k++)
	    	{
	    		x = (A*x + B) % M;
	    		y = (C*y + D) % M;
	    		points[k+1][0] = x % 3;
	    		points[k+1][1] = y % 3;
	    		check(points, k + 1);
	    	}
	    	
	    	writer.write("Case #"+(i+1)+": "+count+"\n");
	    }
	    writer.close();
	}
	
	public static void check(long[][] points, int last)
	{
		for (int i = 0; i < last - 1; i++)
			for (int k = i + 1; k < last; k++)
				if ((points[i][0] + points[k][0] + points[last][0]) % 3 == 0 &&
						(points[i][1] + points[k][1] + points[last][1]) % 3 == 0)
					count++;
	}
	
}