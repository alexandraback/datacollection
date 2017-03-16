import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;


public class FallingDiamonds {
	private static final String INPUT_FILE = "input.txt";
	private static final String OUTPUT_FILE = "output.txt";
	
	int totalCases = 0;
	int goodCases = 0;
	int xc;
	int yc;
	int yhigh;
	boolean[][] diamond;
	
	public double probability(int N, int x, int y) {
		System.out.println(N + " " + x + " " + y);

		totalCases = 0;
		goodCases = 0;
		if (Math.abs(x) > 9 || y > 7) return 0;
		xc = x + 10;
		yc = y;
		yhigh = 2;
		diamond = new boolean[20][20];
		
		diamond[10][0] = true;
		if (N >= 14){
			yhigh = 4;
			diamond[12][0]= true;
			diamond[14][0]= true;
			diamond[8][0]= true;
			diamond[6][0]= true;
			diamond[11][1]= true;
			diamond[13][1]= true;
			diamond[9][1]= true;
			diamond[7][1]= true;
			diamond[10][2]= true;
			diamond[12][2]= true;
			diamond[8][2]= true;
			diamond[11][3]= true;
			diamond[9][3]= true;
			probability(N, 10, yhigh,15);
		}
		else {
			probability(N, 10, yhigh,2);
		}	
		return (double) goodCases / totalCases;
	}
	
	public void probability(int N, int x, int y, int c) {
		if (c > N) {
			totalCases++;
			if (diamond[xc][yc]) goodCases++;
			return;
		}
		if (y == 0) {
			diamond[x][y] = true;
			probability(N, 10, yhigh, c+1);
			diamond[x][y] = false;
		}
		else {	
			boolean flag = true;
			if (!diamond[x-1][y-1]){
				flag = false;
				probability(N, x-1, y-1, c);
			}
			if (!diamond[x+1][y-1]){
				flag = false;
				probability(N, x+1, y-1, c);
			}
			if (flag){
				diamond[x][y] = true;
				boolean flag2 = false;
				if (x == 10){ 
					yhigh+= 2;
					flag2 = true;
				}
				probability(N, 10, yhigh, c+1);
				if (flag2)
					yhigh -= 2;
				diamond[x][y] = false;
			}
		}
	}
	
	
	
	public static void main(String[] args) throws NumberFormatException, IOException
	{
		FallingDiamonds diamonds = new FallingDiamonds();
		Parser parser = new Parser();
		String[] input = parser.readInput(INPUT_FILE);
		String[] result = new String[input.length];
		for (int i = 0; i < input.length; i++)
		{
			String[] data = input[i].split(" ");
			int N = Integer.parseInt(data[0]);
			int x = Integer.parseInt(data[1]);
			int y = Integer.parseInt(data[2]);
			result[i] = Double.toString(diamonds.probability(N, x,y));
		
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
			input[i] = reader.readLine();
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
