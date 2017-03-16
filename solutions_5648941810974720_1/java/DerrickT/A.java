import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

public class A
{
	static String FILE_IN = "A-large.in";
	static String FILE_OUT = "A.out";

	static String solve(BufferedReader in) throws IOException
	{
		String s = in.readLine();
		int l = s.length();
		
		int [] letters = new int [27];
		for(int i = 0; i < l; i++)
			letters[s.charAt(i) - 'A' + 1]++;
				
		// A  B  C  D  E  F  G  H  I  J  K  L  M  N  O  P  Q  R  S  T  U  V  W  X  Y  Z 
		// 1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26
		
		int [] digits = new int [10];
		
		digits[0] = letters[26]; // z
		
		letters[26] -= digits[0];
		letters[5] -= digits[0];
		letters[18] -= digits[0];
		letters[15] -= digits[0];
		
		digits[2] = letters[23]; // w
		
		letters[20] -= digits[2];
		letters[23] -= digits[2];
		letters[15] -= digits[2];
		
		digits[6] = letters[24]; // x
		
		letters[19] -= digits[6];
		letters[9] -= digits[6];
		letters[24] -= digits[6];
		
		digits[8] = letters[7]; // g
		
		letters[5] -= digits[8];
		letters[9] -= digits[8];
		letters[7] -= digits[8];
		letters[8] -= digits[8];
		letters[20] -= digits[8];
		
		digits[4] = letters[21]; // u
			
		letters[6] -= digits[4];
		letters[15] -= digits[4];
		letters[21] -= digits[4];
		letters[18] -= digits[4];
		
		digits[1] = letters[15]; // o
		
		letters[15] -= digits[1];
		letters[14] -= digits[1];
		letters[5] -= digits[1];
		
		digits[3] = letters[8]; // h
		
		letters[20] -= digits[3];
		letters[8] -= digits[3];
		letters[18] -= digits[3];
		letters[5] -= 2 * digits[3];
		
		digits[5] = letters[6]; // f
		
		letters[6] -= digits[5];
		letters[9] -= digits[5];
		letters[22] -= digits[5];
		letters[5] -= digits[5];
						
		digits[7] = letters[19]; // s
		
		letters[19] -= digits[7];
		letters[5] -= 2 * digits[7];
		letters[22] -= digits[7];
		letters[14] -= digits[7];
		
		digits[9] = letters[9]; // i
		
		StringBuilder str = new StringBuilder();
		
		for(int i = 0 ; i < 10 ; i ++)
		{
			int  n = digits[i];
			for (int j = 0; j < n; j++)
				str.append(i);
		}
		
		return str.toString();
	}

	public static void main(String[] args) throws IOException
	{
		BufferedReader in = new BufferedReader
				(new FileReader("files/" + FILE_IN));
		PrintWriter out = new PrintWriter(new BufferedWriter
				(new FileWriter("files/" + FILE_OUT)));

		int T = Integer.parseInt(in.readLine());
		for (int t = 1; t <= T; t++)
		{
			String result = solve(in);
			System.out.printf("Case #%d: %s%n", t, result);
			out.printf("Case #%d: %s%n", t, result);
		}

		System.out.println("Complete");
		in.close();
		out.close();
	}
}
