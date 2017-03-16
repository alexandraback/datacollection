import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;


public class Osmos {
	private static final String INPUT_FILE = "input.txt";
	private static final String OUTPUT_FILE = "output.txt";
	
	int best = Integer.MAX_VALUE;
	
	public int count(String input) {
		best = Integer.MAX_VALUE;
		System.out.println(input);
		String[] buf = input.split(" ");
		int size = Integer.parseInt(buf[0]);
		int[] sizes = new int[buf.length - 2];
		for (int i = 2; i < buf.length; i++) {
			sizes[i-2] =  Integer.parseInt(buf[i]);
		}
		
		Arrays.sort(sizes);
		if (size == 1) return sizes.length;
		count(sizes, size, 0,0);
		return best;
	}
	
	public void count(int[] sizes, int size, int total, int j) {
		if (sizes == null || sizes.length == 0 || j == sizes.length) {
			if (total < best)  best = total;
			return;
		}
		for (int k = j; k < sizes.length; k++) {
			if (size > sizes[k]) 
				size += sizes[k];
			else {
				count(sizes,size,sizes.length - k + total, sizes.length);
				int steps = 0;
				int x = size;
				while(x <= sizes[k]) {
					x += x-1;
					steps++;
				}
				count(sizes,x, total + steps, k);	
				return;
			}
		}
		if (total < best)  best = total;
		return;
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException
	{
		Osmos osmos = new Osmos();
		Parser parser = new Parser();
		String[] input = parser.readInput(INPUT_FILE);
		String[] result = new String[input.length];
		for (int i = 0; i < input.length; i++)
		{
			String[] data = input[i].split(" ");
			result[i] = Integer.toString(osmos.count(input[i]));
		
			System.out.println(result[i]);
		}
		parser.writeOutput(result, OUTPUT_FILE);
	}
}


class Parser
{
	public String[] readInput(String fileName) throws NumberFormatException, IOException
	{
		BufferedReader reader = new BufferedReader(new FileReader(fileName));
		int numberOfCases = Integer.parseInt(reader.readLine());
		String[] input = new String[numberOfCases];
		for (int i = 0; i < numberOfCases; i++)
		{
			String buf = reader.readLine();
			String buf2 = reader.readLine();
			input[i] = buf + " " + buf2;
		}
		reader.close();
		return input;
	}
	
	public void writeOutput(String[] result, String file) throws IOException
	{
		FileWriter writer = new FileWriter(file);
		BufferedWriter bufferedWriter = new BufferedWriter(writer);
		for (int i = 0; i < result.length; i++)
		{
			bufferedWriter.write("Case #" + (i+1) +": " + result[i]);
			bufferedWriter.newLine();
		}
		bufferedWriter.flush();
		bufferedWriter.close();
	}
}

