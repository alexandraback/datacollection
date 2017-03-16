import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main
{

	public static void main(String[] args) throws IOException
	{
		Main main = new Main();
		main.read();
	}

	/* IO */
	private StringBuilder ans;
	private BufferedReader in;
	private BufferedWriter out;
	private StringTokenizer tok;

	/* fields */
	private int R;
	private int C;
	private int W;

	private void read() throws IOException
	{
		// streams
		String inputFileName = "C:\\Users\\ahmed\\Desktop\\Codejam\\Input.in";
		String outputFileName = "C:\\Users\\ahmed\\Desktop\\Codejam\\Output.txt";
		in = new BufferedReader(new FileReader(inputFileName));
		out = new BufferedWriter(new FileWriter(outputFileName));
		ans = new StringBuilder();

		// read cases
		int nCases = Integer.parseInt(in.readLine());
		for (int cas = 1; cas <= nCases; cas++)
		{
			// read paramas
			tok = new StringTokenizer(in.readLine());
			R = Integer.parseInt(tok.nextToken());
			C = Integer.parseInt(tok.nextToken());
			W = Integer.parseInt(tok.nextToken());

			// solve
			ans.append("Case #" + cas + ": " + solve2() + "\n");
		}

		// output
		System.out.print(ans.toString());
		out.write(ans.toString());
		out.flush();
		out.close();

	}

	private int solve2()
	{
		// first find it
		int countFind = 1;
		int prev = 0;
		int idx = W;
		while (true)
		{
			if (idx + W > C)
				break;
			else
			{
				countFind++;
				idx += W;
				prev += W;
			}
		}

		// till he says not here
		int countRem = countFind;
		int idx2 = idx+1;
		while (true)
		{
			if (idx2 > C)
				break;
			else
			{
				idx2++;
				countRem++;
				if(idx2 - W > prev)
					break;
			}
		}
		
		// discover from after prev
		for (int i = prev+1; i < idx; i++) 
			countRem++;
			

		// sum
		return (R - 1) * countFind + countRem;
	}

}
