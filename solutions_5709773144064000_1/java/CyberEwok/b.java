
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class b
{
	static String path="C:\\CodeJam14\\";
	static String fileInput="inputLarge.txt";
	static String fileOutput="output.txt";
	static Scanner sc;
	static BufferedWriter bw;
	
	public static void main(String args[]) throws IOException
	{
		sc=new Scanner(new FileReader(path+fileInput));
		bw=new BufferedWriter(new FileWriter(path+fileOutput));
	
		int numCases=sc.nextInt();
		for(int cur=0;cur<numCases;cur++)
		{
			double farmCost=sc.nextDouble();
			double farmRate=sc.nextDouble();
			double goal=sc.nextDouble();
			double time=0;
			double rate=2;
			while(secTo(rate,goal)>secTo(rate,farmCost)+secTo(rate+farmRate,goal))
			{
				time+=secTo(rate,farmCost);
				rate+=farmRate;
			}
			time+=secTo(rate,goal);
			bw.write("Case #"+(cur+1)+": "+String.format("%.7f", time)+"\n");
		}
		
		bw.close();
	}
	
	public static double secTo(double rate, double goal)
	{
		return goal/rate;
	}
}
