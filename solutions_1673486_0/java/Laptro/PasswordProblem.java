package src2;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class PasswordProblem {

	int A;
	int B;
	
	double[] probabs;
	double[] noMistake;
	
	public PasswordProblem(int A, int B, double[] probs){
		this.A = A;
		this.B = B;
		this.probabs = probs;
		this.noMistake = new double [A];
	}
	
	public void fillNoMistake()
	{
		double noMistake2 = 1;
		
		for (int i=0; i < A; i++)
		{	
			noMistake2 *= probabs[i];
			noMistake[i] = noMistake2;
		}
	}
	
	public double solve()
	{
		fillNoMistake();
		
		double minKeyStroke =  2 + B;
		
		for (int i=0; i<noMistake.length;i++)
		{	
			int bufKeyStroke = 1 + 2*( A - i - 1) + B - A; 
			double res = (1 - noMistake[i]) * (bufKeyStroke + B +1)+ noMistake[i] * (bufKeyStroke);
			if (res < minKeyStroke) minKeyStroke = res;
		}
		return minKeyStroke;
	}
	
	public static void main (String[] args) throws NumberFormatException, IOException
	{
		BufferedReader reader = new BufferedReader(new FileReader("input.txt"));
		FileWriter writer = new FileWriter("output.txt");
		BufferedWriter bufferedWriter = new BufferedWriter(writer);
		int numberOfCases = Integer.parseInt(reader.readLine());
		for (int i = 0; i < numberOfCases; i++)
		{
			String[] buf = reader.readLine().split(" ");
			int A = Integer.parseInt(buf[0]);
			int B = Integer.parseInt(buf[1]);
			String[] buf2 = reader.readLine().split(" ");
			double [] probs = new double [A];
			for (int j=0; j<A;j++){
				probs[j] = Double.parseDouble(buf2[j]);
			}
			PasswordProblem pp = new PasswordProblem(A, B, probs);
			double res = pp.solve();
			bufferedWriter.write("Case #" + (i+1) +": " + res);
			bufferedWriter.newLine();
		}
		bufferedWriter.flush();
		bufferedWriter.close();
		reader.close();
	}
}
