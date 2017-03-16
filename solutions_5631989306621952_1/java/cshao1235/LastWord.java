import java.io.BufferedReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class LastWord {
	public static String lastWord(String input)
	{
		if(input.length() == 0)
			return input;
		int max = 0;
		int maxIndex = 0;
		for(int i = 0; i < input.length(); i++)
		{
			int offset = input.charAt(i) - 'A';
			if(offset >= max)
			{
				max = offset;
				maxIndex = i;
			}
		}
		String output = "" + input.charAt(maxIndex) + lastWord(input.substring(0, maxIndex)) + input.substring(maxIndex + 1, input.length());
		return output;
	}
	public static void main(String[] args) {
		try
		{
			BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
			int t = Integer.parseInt(f.readLine());
			FileWriter fout = new FileWriter("lastword.out");
			for(int i = 1; i <= t; i++)
			{
				String s = f.readLine();
				String output = lastWord(s);
				System.out.println("Case #" + i + ": " + output);
				fout.write("Case #" + i + ": " + output + "\n");
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
