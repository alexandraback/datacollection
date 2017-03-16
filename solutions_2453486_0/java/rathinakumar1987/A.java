import java.io.File;
import java.io.FileNotFoundException;
import java.text.DecimalFormat;
import java.util.HashMap;
import java.util.Scanner;

public class A{
	public static void main(String[] args) throws FileNotFoundException
	{
		Scanner sc = new Scanner(new File("A.txt"));
		int testCase = Integer.parseInt(sc.nextLine());
		char[][] arr = new char[4][4]; 
		for(int Case=1; Case<=testCase; Case++)
		{
			int i=0;
			while(i<4)
			{
				String s = sc.nextLine();
				if(s.trim().length()>3)
						arr[i++] = s.trim().toCharArray();
			}
			if(checkWin(arr, 'X'))
				{
					System.out.println("Case #"+Case+": X won");
					continue;
				}
			if(checkWin(arr, 'O'))
			{
				System.out.println("Case #"+Case+": O won");
				continue;
			}
			if(stale(arr))
				{
					System.out.println("Case #"+Case+": Draw");
					continue;
				}
			else
				System.out.println("Case #"+Case+": Game has not completed");
		}
	}
	public static boolean checkWin(char[][] arr, char C)
	{
		for(int i=0;i<4;i++)
		{
			if(checkRow(arr, i, C) || checkCol(arr, i, C))
					return true;
		}
		if(checkDiag1(arr, C) || checkDiag2(arr, C))
			return true;
		return false;
	}
	
	public static boolean checkRow(char[][] arr, int row, char C)
	{
		for(int i=0; i<4; i++)
			if(arr[row][i]!=C && arr[row][i]!='T')
				return false;
		return true;
	}
	public static boolean checkCol(char[][] arr, int col, char C)
	{
		for(int i=0; i<4; i++)
			if(arr[i][col]!=C && arr[i][col]!='T')
				return false;
		return true;
	}
	public static boolean checkDiag1(char[][] arr, char C)
	{
		for(int i=0; i<4; i++)
			if(arr[i][i]!=C && arr[i][i]!='T')
				return false;
		return true;
	}
	public static boolean checkDiag2(char[][] arr, char C)
	{
		for(int i=0; i<4; i++)
			if(arr[i][3-i]!=C && arr[i][3-i]!='T')
				return false;
		return true;
	}
	public static boolean stale(char[][] arr)
	{
		for(int i=0; i<4; i++)
			for(int j=0; j<4; j++)
				if(arr[i][j]=='.')
					return false;
		return true;
	}
}