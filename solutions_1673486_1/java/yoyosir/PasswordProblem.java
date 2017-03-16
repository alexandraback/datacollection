import java.io.*;
import java.text.DecimalFormat;


public class PasswordProblem {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		try {
			FileReader fileReader = new FileReader("A-large.in");
			FileWriter fileWriter = new FileWriter("out.txt");
			BufferedReader reader = new BufferedReader(fileReader);
			BufferedWriter writer = new BufferedWriter(fileWriter);
			int testCaseCount = Integer.parseInt(reader.readLine());
			for (int testCase = 1; testCase <= testCaseCount; testCase++)
			{
				String output = "Case #" + testCase + ": ";
				String read = reader.readLine();
				String[] input = read.split(" ");
				int a = Integer.parseInt(input[0]);
				int b = Integer.parseInt(input[1]);
				double p[] = new double[a];
				double m[] = new double[a];
				input = reader.readLine().split(" ");
				for (int i = 0; i < a; i++)
				{
					p[i] = Double.parseDouble(input[i]);
					if (i == 0) m[i] = p[i];
					else m[i] = m[i - 1] * p[i];
				}
				double min = 2 + b;
				for (int i = a - 1; i > a / 2 - 1; i--)
				{
					if (i < 0) break;
					double count = a - 1 - i;
					count += b - i;
					count += (1 - m[i]) * (b + 1);
					if (count < min) min = count;
				}
				DecimalFormat df = new DecimalFormat("0.000000");
				output += df.format(min);
				output +="\n";

				writer.write(output);
				System.out.print(output);
			}
			reader.close();
			writer.close();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

}
