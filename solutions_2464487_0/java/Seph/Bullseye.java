import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;


public class Bullseye {
	public static void main(String args[]) {
		File file = new File("C:\\Users\\Seph\\Dropbox\\Google Code Jam\\input.txt");
		File out = new File("C:\\Users\\Seph\\Dropbox\\Google Code Jam\\out.txt");
		
		Scanner s = new Scanner(System.in);
		try {
			s = new Scanner(file);
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		
		String output = "";
		
		int numCases = s.nextInt();
		for(int i=1; i<=numCases; i++) {
			double centerRadius = s.nextInt();
			double paintAmount = s.nextInt();
			
			output += "Case #"+i+": " + GetMaxRings(centerRadius, paintAmount);
			
			if(i!=numCases)
				output+="\n";
		}
		
		FileWriter fw;
		try {
			fw = new FileWriter(out);
			fw.write(output);
			fw.close();
		} catch (IOException e) {
			e.printStackTrace();
		}		
	}
	
	public static int GetMaxRings(double centerRadius, double paintRemaining)
	{
		int rings = 0;
		
		double ringOuterRadius = centerRadius + 1;
		
		while(true)
		{
			double paintRequired = GetPaintRequired(ringOuterRadius);
			if(paintRequired<=paintRemaining) {
				rings++;
				paintRemaining -= paintRequired;
			}
			else
			{
				break;
			}
			ringOuterRadius +=2;
		}
		
		return rings;
		
	}
	
	public static double GetRingArea(double outerRadius){
		double outerCircleArea = (Math.pow(outerRadius, 2));
		double innerCircleArea = (Math.pow(outerRadius-1, 2));
		
		return (outerCircleArea - innerCircleArea);
	}
	
	public static double GetPaintRequired(double outerRadius) {
		double ringArea = GetRingArea(outerRadius);
		double paintRequired = (ringArea);
		
		return paintRequired;
	}

}
