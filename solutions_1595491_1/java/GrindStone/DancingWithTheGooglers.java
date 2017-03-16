package codejam.dancing_with_the_googlers;

import java.io.IOException;
import java.util.ArrayList;

import codejam.filestuff.FileStuff;

public class DancingWithTheGooglers {
	
	public static void main(String[] args) throws IOException {
		FileStuff fs = new FileStuff("B-large.in","B-large.out","dancing_with_the_googlers");
		ArrayList<String> input = new ArrayList<String>();
		input = fs.ReadFromFile();
		
		ArrayList<String> output = new ArrayList<String>();
		
		int xCase = Integer.valueOf(input.get(0));
		int xPointer = 1;
		
		for (int i=1;i<=xCase;i++)
		{
			String strOut = "Case #" + String.valueOf(i) + ":";
			String strLine = input.get(xPointer);
			xPointer++;
			String[] arrLine = strLine.split(" ");
			int xN = Integer.valueOf(arrLine[0]);
			int xS = Integer.valueOf(arrLine[1]);
			int xp = Integer.valueOf(arrLine[2]);
			int xRes = 0;
			for (int a=0;a<xN;a++)
			{
				int xScore = Integer.valueOf(arrLine[a+3]);
				if (xScore != 0)
				{
					int xDiv = xScore;
					while (xDiv % 3 != 0) xDiv++;
					int xSub = xDiv - xScore;
					xDiv /= 3;
					if (xDiv >= xp)
					{
						xRes++;
					} else
					{
						if (xS > 0)
						{
							if (xSub < 2) xDiv++;
							if (xDiv >= xp) 
							{
								xRes++;
								xS--;
							}
						}
					}
				} else
				{
					if (xp == 0) xRes++;
				}
			}
			strOut += " " + String.valueOf(xRes);
			output.add(strOut);
		}
		fs.WriteToFile(output);
		System.out.print("Done!!!");
	}

}
