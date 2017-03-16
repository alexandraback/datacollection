package codejam.tic_tac_toe_tomek;

import java.io.IOException;
import java.util.ArrayList;

import codejam.filestuff.FileStuff;

public class TicTacToeTomek {
	
	static int countCharInString(String strMain, char chrCheck)
	{
		int xRes = 0;
		for (int i=0;i<strMain.length();i++)
		{
			if (strMain.charAt(i) == chrCheck) xRes++;
		}
		return xRes;
	}
	
	public static void main(String[] args) throws IOException 
	{
		FileStuff fs = new FileStuff("A-small.in","A-small.out","tic_tac_toe_tomek");
		ArrayList<String> input = new ArrayList<String>();
		input = fs.ReadFromFile();
		
		ArrayList<String> output = new ArrayList<String>();
		
		int xCase = Integer.parseInt(input.get(0));
		int xPointer = 1;
		
		for (int i=1;i<=xCase;i++)
		{
			String strOut = "Case #" + String.valueOf(i) + ":";
			
			String[] arrBoard = new String[4];
			String[] arrBoardVer = new String[4];
			String[] arrBoardDiag = new String[2];
			int countDot = 0;
			for (int a=0;a<4;a++)
			{
				arrBoard[a] = input.get(xPointer);
				countDot += countCharInString(arrBoard[a],'.');
				for (int b=0;b<4;b++) arrBoardVer[b] += arrBoard[a].charAt(b);
				arrBoardDiag[0] += arrBoard[a].charAt(a);
				arrBoardDiag[1] += arrBoard[a].charAt(3-a);
				xPointer++;
			}
			xPointer++;
			
			boolean boolWon = false;
			String strWon = "";
			
			for (int a=0;a<4;a++)
			{
				int numX = countCharInString(arrBoard[a],'X');
				if (numX > 3)
				{
					boolWon = true;
					strWon = "X won";
				} else if (numX == 3)
				{
					if (countCharInString(arrBoard[a],'T') >= 1)
					{
						boolWon = true;
						strWon = "X won";
					}
				}
				
				int numO = countCharInString(arrBoard[a],'O');
				if (numO > 3)
				{
					boolWon = true;
					strWon = "O won";
				} else if (numO == 3)
				{
					if (countCharInString(arrBoard[a],'T') >= 1)
					{
						boolWon = true;
						strWon = "O won";
					}
				}
				
				if (boolWon) break;
			}
			
			if (boolWon == false)
			{
				for (int a=0;a<4;a++)
				{
					int numX = countCharInString(arrBoardVer[a],'X');
					if (numX > 3)
					{
						boolWon = true;
						strWon = "X won";
					} else if (numX == 3)
					{
						if (countCharInString(arrBoardVer[a],'T') >= 1)
						{
							boolWon = true;
							strWon = "X won";
						}
					}
					
					int numO = countCharInString(arrBoardVer[a],'O');
					if (numO > 3)
					{
						boolWon = true;
						strWon = "O won";
					} else if (numO == 3)
					{
						if (countCharInString(arrBoardVer[a],'T') >= 1)
						{
							boolWon = true;
							strWon = "O won";
						}
					}
					
					if (boolWon) break;
				}
			}
			
			if (boolWon == false)
			{
				for (int a=0;a<2;a++)
				{
					int numX = countCharInString(arrBoardDiag[a],'X');
					if (numX > 3)
					{
						boolWon = true;
						strWon = "X won";
					} else if (numX == 3)
					{
						if (countCharInString(arrBoardDiag[a],'T') >= 1)
						{
							boolWon = true;
							strWon = "X won";
						}
					}
					
					int numO = countCharInString(arrBoardDiag[a],'O');
					if (numO > 3)
					{
						boolWon = true;
						strWon = "O won";
					} else if (numO == 3)
					{
						if (countCharInString(arrBoardDiag[a],'T') >= 1)
						{
							boolWon = true;
							strWon = "O won";
						}
					}
					
					if (boolWon) break;
				}
			}
			
			if (boolWon)
			{
				strOut += " " + strWon;
			} else
			{
				if (countDot <= 0)
				{
					strOut += " Draw";
				} else
				{
					strOut += " Game has not completed";
				}
			}
			
			output.add(strOut);
		}
		
		fs.WriteToFile(output);
		System.out.print("Done!!!");
	}

}
