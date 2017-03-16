import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.text.DecimalFormat;


public class Problem1 {

	private static String fileDirectory = "files/";

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		//Solve(fileDirectory + "sample.in",fileDirectory + "sample.out");
		Solve(fileDirectory + "A-small-attempt7.in",fileDirectory + "A-small-attempt7.out");
		//Solve(fileDirectory + "A-large.in",fileDirectory + "A-large.out");
	}
	
	public static void Solve(String inFile, String outFile)
	{
		try {
			//Initialize IO
			BufferedReader br = new BufferedReader(new FileReader(inFile));
			BufferedWriter bw = new BufferedWriter(new FileWriter(outFile));
			
			//Read the number of cases
			int cases = Integer.parseInt(br.readLine());
			
			//Loop through test cases
			for (int i = 0; i < cases; i++)
			{
				//Most likely we only want to newline after the first test case
				if (i > 0)
				{
					bw.newLine();
				}
				
				//Almost always want to read the line this way
				String line = br.readLine();
				
				//If multiple values per line, use this to split and store them.
				String[] numbers = line.split(" ");
				int N = Integer.parseInt(numbers[0]);
				
				double[] s = new double[N];
				double sum = 0;
				int zeroes = 0;
				for (int j = 1; j <= N; j++)
				{
					s[j-1] = Double.parseDouble(numbers[j]);
					sum += s[j-1];
					if (s[j-1] == 0)
						zeroes++;
				}
				
				double goal = (sum * 2) / N;
				//System.out.println(goal);
				
				String results = "";
				DecimalFormat form = new DecimalFormat("0.000000");
				for (int j = 0; j < s.length; j++)
				{
					
					if (j > 0)
					{
						results += " ";
					}
					double output = ((goal - s[j]) / sum) * 100.0;
					if (i == 16)
						System.out.println(goal + " " + s[j] + " " + sum + " " + output);
					if (output < 0)
					{
						output = 0.000000;
					}
					if (zeroes > 1 && s[j] == 0)
					{
						output = 100.0 / zeroes;
					}
					results += output;
				}
				
				//Often times we will want to count the number of something for the results
				//int count = 0;
				
				
				//START LOGIC HERE
	
				//END LOGIC HERE
				
				//Print out test case number
				bw.write("Case #" + (i+1) + ": ");
				//Write the result
				bw.write(results);
			}
			
			
			
			
			//Clean up IO
			bw.close();
			br.close();
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	

}
