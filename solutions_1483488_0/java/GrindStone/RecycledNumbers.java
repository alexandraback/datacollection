package codejam.recycled_numbers;

import java.io.IOException;
import java.util.ArrayList;
import codejam.filestuff.FileStuff;

public class RecycledNumbers {
	
	public static void main(String[] args) throws IOException {
		FileStuff fs = new FileStuff("C-small-attempt0.in","C-small.out","recycled_numbers");
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
			int xA = Integer.valueOf(arrLine[0]);
			int xB = Integer.valueOf(arrLine[1]);
			int xRec = 0;
			for (int a=xA;a<=xB;a++)
			{
				int xLen = String.valueOf(a).length();
				int xLimit = 1;
				for (int b=1;b<=xLen;b++) xLimit *= 10;
				if (xLimit > xB) xLimit = xB+1;
				for (int b=a+1;b<xLimit;b++)
				{
					if (RecycledNumbers.isRecycled(a, b)) xRec++;
				}
			}
			strOut += " " + String.valueOf(xRec);
			output.add(strOut);
		}
		fs.WriteToFile(output);
		System.out.print("Done!!!");
	}
	
	public static boolean isRecycled(int num1,int num2)
	{
		String str1 = String.valueOf(num1);
		String str2 = String.valueOf(num2);
		boolean boolRes = false;
		if (str1.length() == str2.length())
		{
			for (int i=1;i<str1.length();i++)
			{
				String strRec = str1.substring(i) + str1.substring(0,i);
				if (strRec.equals(str2))
				{
					boolRes = true;
					break;
				}
			}
		}
		return boolRes;
	}

}
