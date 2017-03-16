import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.StringTokenizer;

public class RecycledNumbers {

	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub

		BufferedReader f = new BufferedReader(new FileReader("test.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("recycled.out")));
		
		int numberCases = Integer.parseInt(f.readLine());
		String log;
		StringTokenizer st;
		int lower;
		int upper;
		int pairs;
		
		for (int i = 1; i <= numberCases; i++)
		{
			log = "Case #" + i + ": ";
			st = new StringTokenizer(f.readLine());
			lower = Integer.parseInt(st.nextToken());
			upper = Integer.parseInt(st.nextToken());
			pairs = calculatePairs(lower,upper);
			
			out.println(log + pairs);
		}
		
		out.close();
		System.exit(0);
	}

	private static int calculatePairs(int lower, int upper) {
		
		String baseString;
		int base;
		String tempString;
		int temp;
		int pairs = 0;
		HashSet<String> h = new HashSet<String>();
		
		//i = n
		for (int i = lower; i <= upper; i++)
		{
			base = i;
			baseString = Integer.toString(base);
			h.clear();
			
			//j = number of digits to swap
			//if leading 0, then automatically smaller/not valid
			for (int j = 1; j < baseString.length(); j++)
			{
				tempString = baseString;
				tempString = shiftDigits(tempString, j);
				temp = Integer.parseInt(tempString);
				
				if ((temp > base) &&
						(temp <= upper))
				{
					if (!h.contains(tempString))
					{
						h.add(tempString);
						pairs++;
					}
				}
			}
		}
		
		return pairs;
	}

	private static String shiftDigits(String temp, int n) 
	{
		return temp.substring(temp.length() - n) + temp.substring(0, temp.length() - n);
	}

}
