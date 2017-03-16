package codejam.lawnmower;

import java.io.IOException;
import java.util.ArrayList;

import codejam.filestuff.FileStuff;

public class Lawnmower {
	
	public static void main(String[] args) throws IOException 
	{
		FileStuff fs = new FileStuff("B-large.in","B-large.out","lawnmower");
		ArrayList<String> input = new ArrayList<String>();
		input = fs.ReadFromFile();
		
		ArrayList<String> output = new ArrayList<String>();
		
		int xCase = Integer.parseInt(input.get(0));
		int xPointer = 1;
		
		for (int i=1;i<=xCase;i++)
		{
			String strOut = "Case #" + String.valueOf(i) + ":";
			
			String[] arrLine = input.get(xPointer).split(" ");
			xPointer++;
			int xN = Integer.parseInt(arrLine[0]);
			int xM = Integer.parseInt(arrLine[1]);
			
			int[] arrHeight = new int[100];
			for (int a=0;a<100;a++) arrHeight[a] = 0;
			int[][] arrBoard = new int[xN][xM];
			int[] arrAllHor = new int[xN];
			int[] arrAllVer = new int[xM];
			
			for (int a=0;a<xN;a++)
			{
				arrLine = input.get(xPointer).split(" ");
				xPointer++;
				int xPrev = 0;
				for (int b=0;b<xM;b++)
				{
					arrBoard[a][b] = Integer.parseInt(arrLine[b]);
					if (b==0) xPrev = arrBoard[a][b];
					if (arrBoard[a][b] == xPrev) 
						arrAllHor[a] = arrBoard[a][b]; 
					else 
					{
						arrAllHor[a] = 0;
						xPrev = 0;
					}
					if (a==0) 
						arrAllVer[b] = arrBoard[a][b];
					else
					{
						if (arrBoard[a-1][b] != arrBoard[a][b]) arrAllVer[b] = 0;
					}
					arrHeight[arrBoard[a][b]-1]++;
				}
			}
			
			ArrayList<Integer> arrElem = new ArrayList<Integer>(); 
			
			for (int a=0;a<100;a++)
			{
				if (arrHeight[a] > 0) arrElem.add(a);
			}
			
			boolean boolPossible = true;
			
			for (int a=0;a<arrElem.size()-1;a++)
			{
				int xCurr = arrElem.get(a) + 1;
				
				for (int b=0;b<xN;b++)
				{
					if (arrAllHor[b] != xCurr)
					{
						for (int c=0;c<xM;c++)
						{
							if (arrBoard[b][c] == xCurr)
							{
								if (arrAllVer[c] != xCurr)
								{
									boolPossible = false;
									break;
								}
							}
						}
						if (boolPossible == false) break;
					}
				}
				
				if (boolPossible == false) break;
			}
			
			if (boolPossible)
			{
				strOut += " YES";
			} else
			{
				strOut += " NO";
			}
			
			output.add(strOut);
		}
		
		fs.WriteToFile(output);
		System.out.print("Done!!!");
	}
}
