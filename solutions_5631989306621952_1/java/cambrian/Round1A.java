import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;

public class Round1A {
	public static void main(String[] args) throws NumberFormatException, IOException
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream("input")));
		
		int test_no = Integer.parseInt(br.readLine());
		
		BufferedWriter out = new BufferedWriter(new FileWriter("out.txt"));
		
		for(int i = 1; i <= test_no; i++)
		{
			String original = br.readLine();
			StringBuilder result = new StringBuilder();
			result.append(original.charAt(0));
			for(int j = 1;j < original.length(); j++)
			{
				char tt = original.charAt(j);
				if(tt < result.charAt(0))
					result.append(tt);
				else
					result = new StringBuilder(Character.toString(tt)).append(result);
			}
		    out.write("Case #");
			out.write(String.valueOf(i));
			out.write(": ");
			out.write(result.toString());
			out.write("\n");	
		    System.out.println(result.toString());
		}
		br.close();
		out.close();		
	}

}
