package round1b;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.util.Scanner;

public class A {
	public static void main(String[] args) throws FileNotFoundException, UnsupportedEncodingException
	{
		Scanner sc = new Scanner(new File("input/round1b/A/A-small-attempt0 (2).in"));
		PrintWriter writer = new PrintWriter("output/round1b/test.out", "UTF-8");
		int T = sc.nextInt();
		sc.nextLine();
		for(int casenr = 1; casenr<=T; casenr++)
		{
			String s = sc.nextLine();
			long[] count = new long['Z'+1];
			for(char c: s.toCharArray())
			{
				count[c]++;
			}
			long[] digits = new long[10];
			digits[0] = count['Z'];
			digits[2] = count['W'];
			digits[4] = count['U'];
			digits[6] = count['X'];
			digits[8] = count['G'];
			digits[3] = count['H']-digits[8];
			digits[5] = count['F']-digits[4];
			digits[7] = count['V']-digits[5];
			digits[9] = count['I']-digits[5]-digits[6]-digits[8];
			digits[1] = count['O']-digits[0]-digits[2]-digits[4];
			writer.print("Case #" + casenr + ": ");
			for(int i = 0; i<10; i++)
			{
				for(int j=0; j<digits[i]; j++)
					writer.print(i);
			}
			writer.println();
		}
		sc.close();
		writer.close();
	}
}
