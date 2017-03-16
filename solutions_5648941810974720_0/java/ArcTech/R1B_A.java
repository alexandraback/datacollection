import java.io.IOException;

public class R1B_A {

	public static void main(String[] args) throws IOException
	
	{
		InputReader in = new InputReader("A-small-attempt0.in");
		OutputWriter out = new OutputWriter("Asmall.txt");
		int cases = Integer.parseInt(in.getCur());	
		for (int num = 1; num <= cases; num++)
		{
			String outline = "";
			String s = in.getNext();
			int[] letters = new int[26];
			for (int i = 0; i < s.length(); i++)
			{
				int letter = s.charAt(i)-'A';
				letters[letter]++;
			}
			int[] digits = new int[10];
			digits[0] = letters[25];
			letters[25] -= digits[0];
			letters['E'-'A'] -= digits[0];
			letters['R'-'A'] -= digits[0];
			letters['O'-'A'] -= digits[0];
			digits[8] = letters['G'-'A'];
			letters['E'-'A'] -= digits[8];
			letters['I'-'A'] -= digits[8];
			letters['G'-'A'] -= digits[8];
			letters['H'-'A'] -= digits[8];
			letters['T'-'A'] -= digits[8];
			digits[6] = letters['X'-'A'];
			letters['S'-'A'] -= digits[6];
			letters['I'-'A'] -= digits[6];
			letters['X'-'A'] -= digits[6];
			digits[2] = letters['W'-'A'];
			letters['T'-'A'] -= digits[2];
			letters['W'-'A'] -= digits[2];
			letters['O'-'A'] -= digits[2];
			digits[4] = letters['U'-'A'];
			letters['F'-'A'] -= digits[4];
			letters['O'-'A'] -= digits[4];
			letters['U'-'A'] -= digits[4];
			letters['R'-'A'] -= digits[4];
			digits[5] = letters['F'-'A'];
			letters['F'-'A'] -= digits[5];
			letters['I'-'A'] -= digits[5];
			letters['V'-'A'] -= digits[5];
			letters['E'-'A'] -= digits[5];
			digits[1] = letters['O'-'A'];
			letters['O'-'A'] -= digits[1];
			letters['N'-'A'] -= digits[1];
			letters['E'-'A'] -= digits[1];
			digits[3] = letters['T'-'A'];
			letters['T'-'A'] -= digits[8];
			letters['H'-'A'] -= digits[8];
			letters['R'-'A'] -= digits[8];
			letters['E'-'A'] -= digits[8];
			letters['E'-'A'] -= digits[8];
			digits[7] = letters['V'-'A'];
			letters['S'-'A'] -= digits[8];
			letters['E'-'A'] -= digits[8];
			letters['V'-'A'] -= digits[8];
			letters['E'-'A'] -= digits[8];
			letters['N'-'A'] -= digits[8];
			digits[9] = letters['I'-'A'];
			letters['N'-'A'] -= digits[8];
			letters['I'-'A'] -= digits[8];
			letters['N'-'A'] -= digits[8];
			letters['E'-'A'] -= digits[8];
		for (int i = 0; i < 10; i++)
			for (int j = 0; j < digits[i]; j++)
				outline += i;	
		
		if (num < cases)
			outline += "\n";
		out.writeCase(outline, num);
		}	
	out.close();
	}
}

		