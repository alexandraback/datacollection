import java.io.BufferedReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class GettingTheDigits {
	public static int charToIndex(char c)
	{
		return c - 'A';
	}
	/*public static boolean passes(int[] digitCount)
	{
		for(int i = 0; i < 10; i++)
		{
			if(digitCount[i] != 0)
				return false;
		}
		return true;
	}*/
	public static void main(String[] args) {
		try
		{
			BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
			int t = Integer.parseInt(f.readLine());
			FileWriter fout = new FileWriter("gettingthedigits.out");
			for(int i = 1; i <= t; i++)
			{
				String s = f.readLine();
				int[] letterCount = new int[26];
				int[] digitCount = new int[10];
				for(int j = 0; j < s.length(); j++)
					letterCount[s.charAt(j) - 'A']++;
				//ZERO
				digitCount[0] += letterCount[charToIndex('Z')];
				letterCount[charToIndex('E')] -= letterCount[charToIndex('Z')];
				letterCount[charToIndex('R')] -= letterCount[charToIndex('Z')];
				letterCount[charToIndex('O')] -= letterCount[charToIndex('Z')];
				letterCount[charToIndex('Z')] -= letterCount[charToIndex('Z')];
				//EIGHT
				digitCount[8] += letterCount[charToIndex('G')];
				letterCount[charToIndex('E')] -= letterCount[charToIndex('G')];
				letterCount[charToIndex('I')] -= letterCount[charToIndex('G')];
				letterCount[charToIndex('H')] -= letterCount[charToIndex('G')];
				letterCount[charToIndex('T')] -= letterCount[charToIndex('G')];
				letterCount[charToIndex('G')] -= letterCount[charToIndex('G')];				
				//SIX
				digitCount[6] += letterCount[charToIndex('X')];
				letterCount[charToIndex('S')] -= letterCount[charToIndex('X')];
				letterCount[charToIndex('I')] -= letterCount[charToIndex('X')];
				letterCount[charToIndex('X')] -= letterCount[charToIndex('X')];
				//TWO
				digitCount[2] += letterCount[charToIndex('W')];
				letterCount[charToIndex('T')] -= letterCount[charToIndex('W')];
				letterCount[charToIndex('O')] -= letterCount[charToIndex('W')];
				letterCount[charToIndex('W')] -= letterCount[charToIndex('W')];
				//SEVEN
				digitCount[7] += letterCount[charToIndex('S')];
				letterCount[charToIndex('E')] -= letterCount[charToIndex('S')];
				letterCount[charToIndex('V')] -= letterCount[charToIndex('S')];
				letterCount[charToIndex('E')] -= letterCount[charToIndex('S')];
				letterCount[charToIndex('N')] -= letterCount[charToIndex('S')];
				letterCount[charToIndex('S')] -= letterCount[charToIndex('S')];		
				//FIVE
				digitCount[5] += letterCount[charToIndex('V')];
				letterCount[charToIndex('F')] -= letterCount[charToIndex('V')];
				letterCount[charToIndex('I')] -= letterCount[charToIndex('V')];
				letterCount[charToIndex('E')] -= letterCount[charToIndex('V')];
				letterCount[charToIndex('V')] -= letterCount[charToIndex('V')];
				//FOUR
				digitCount[4] += letterCount[charToIndex('F')];
				letterCount[charToIndex('O')] -= letterCount[charToIndex('F')];
				letterCount[charToIndex('U')] -= letterCount[charToIndex('F')];
				letterCount[charToIndex('R')] -= letterCount[charToIndex('F')];
				letterCount[charToIndex('F')] -= letterCount[charToIndex('F')];
				//THREE
				digitCount[3] += letterCount[charToIndex('R')];
				letterCount[charToIndex('T')] -= letterCount[charToIndex('R')];
				letterCount[charToIndex('H')] -= letterCount[charToIndex('R')];
				letterCount[charToIndex('E')] -= letterCount[charToIndex('R')];
				letterCount[charToIndex('E')] -= letterCount[charToIndex('R')];
				letterCount[charToIndex('R')] -= letterCount[charToIndex('R')];
				//ONE
				digitCount[1] += letterCount[charToIndex('O')];
				letterCount[charToIndex('N')] -= letterCount[charToIndex('O')];
				letterCount[charToIndex('E')] -= letterCount[charToIndex('O')];
				letterCount[charToIndex('O')] -= letterCount[charToIndex('O')];
				//NINE
				digitCount[9] += letterCount[charToIndex('I')];
				letterCount[charToIndex('N')] -= letterCount[charToIndex('I')];
				letterCount[charToIndex('N')] -= letterCount[charToIndex('I')];
				letterCount[charToIndex('E')] -= letterCount[charToIndex('I')];
				letterCount[charToIndex('I')] -= letterCount[charToIndex('I')];
				
				StringBuffer s1 = new StringBuffer("");
				for(int j = 0; j < 10; j++)
				{
					for(int k = 0; k < digitCount[j]; k++)
					{
						s1.append(j);
					}
				}
				String output = s1.toString();
				System.out.println("Case #" + i + ": " + output);
				fout.write("Case #" + i + ": " + output + "\n");
				//if(passes(digitCount))
				//	System.out.println("AAAAAAAAAAAAAAA");
			}
			f.close();
			fout.close();
		}
		catch(IOException e)
		{
			e.printStackTrace();
		}


	}

}

