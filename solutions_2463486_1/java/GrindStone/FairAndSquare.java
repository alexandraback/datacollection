package codejam.fair_and_square;

import java.io.IOException;
import java.math.BigInteger;
import java.util.ArrayList;

import codejam.filestuff.FileStuff;

public class FairAndSquare {
	
	public static void main(String[] args) throws IOException 
	{
		FileStuff fs = new FileStuff("C-large1.in","C-large1.out","fair_and_square");
		ArrayList<String> input = new ArrayList<String>();
		input = fs.ReadFromFile();
		
		FileStuff fsPalin = new FileStuff("palindrome.txt","C-small.out","fair_and_square");
		ArrayList<String> arrPalin = new ArrayList<String>();
		arrPalin = fsPalin.ReadFromFile();
		
		ArrayList<String> output = new ArrayList<String>();
		
		int xCase = Integer.parseInt(input.get(0));
		int xPointer = 1;
		
		for (int i=1;i<=xCase;i++)
		{
			String strOut = "Case #" + String.valueOf(i) + ":";
			
			String[] arrLine = input.get(xPointer).split(" ");
			xPointer++;
			
			BigInteger xA = new BigInteger(arrLine[0]);
			BigInteger xB = new BigInteger(arrLine[1]);
			
			int xPointerPalin = 0;
			while (true)
			{
				BigInteger xPalin = new BigInteger(arrPalin.get(xPointerPalin));
				if (xPalin.compareTo(xA) >= 0) break;
				xPointerPalin++;
			}
			
			int xRes = 0;
			
			while (true)
			{
				BigInteger xPalin = new BigInteger(arrPalin.get(xPointerPalin));
				if (xPalin.compareTo(xB) > 0) break;
				xPointerPalin++;
				xRes++;
			}
			
			strOut += " " + String.valueOf(xRes);
			output.add(strOut);
		}
		
		fs.WriteToFile(output);
		System.out.print("Done!!!");
	}

}
