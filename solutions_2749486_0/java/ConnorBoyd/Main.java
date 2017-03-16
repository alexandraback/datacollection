import java.util.Scanner;
import java.io.FileReader;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class Main {


	private static String in  = "B-small-attempt0.in.txt" ;
	private static String out = "output.txt";
	private static int sampleSize;
	private static ArrayList<Pogo> pogos;
	public static void main(String[] args)
	{
		System.out.println("Starting! Reading...");
		
		readFromFile();
		
		System.out.println("Done reading!\nStarting writing...");
		
		long time1 = System.currentTimeMillis();
		writeToFile();
		long time2 = System.currentTimeMillis();
		
		System.out.println("Done!");
		
		System.out.println((time2 - time1)/1000.0D + " Seconds");
	}
	
	private static void readFromFile()
	{
		Scanner myScanner;
		try{
			myScanner = new Scanner(new FileReader(in));
			
			sampleSize = myScanner.nextInt();
			pogos = new ArrayList<Pogo>(sampleSize);
			
			for(int i = 0; i < sampleSize; ++i)
			{
				int x = myScanner.nextInt();
				int y = myScanner.nextInt();
				pogos.add(new Pogo(x, y));
			}
			
			myScanner.close();
		}
		catch(FileNotFoundException e)
		{
			System.err.println("File not found!");
			System.exit(0);
		}

	}

	private static void writeToFile()
	{
		try
		{
			FileWriter myFW = new FileWriter(out);
			
			for(int i = 0; i < sampleSize; ++i)
			{
				myFW.write("Case #" + (i + 1) + ": ");
				myFW.write(pogos.get(i).getMoves());
				myFW.write("\n");	//Add newline
				
			}
			
			
			myFW.close();
		}
		catch(IOException e)
		{
			System.err.println("IOException in writeToFile! Stack trace:");
			e.printStackTrace();
			System.exit(0);
		}
		
	}
	
}
