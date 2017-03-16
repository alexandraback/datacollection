package test.googlejam.year2012.jam.c0505;

import java.io.IOException;

import test.googlejam.base.ProblemProcessor;

public class A extends ProblemProcessor
{

	static java.util.Map<Integer, Integer> mapping = new java.util.TreeMap<Integer, Integer>();
	public static void main(String[] args) throws java.io.IOException
	{
		A processor;

		final String FILE_BASE = "C:/Users/cjbolanos/workspace/Google Code Jam/src/"
				+ A.class.getName().substring(0, 
						A.class.getName().lastIndexOf('.')).replace('.', '/'); 
		final String FILE_NAME = A.class.getName().substring(
				A.class.getName().lastIndexOf('.') + 1); 
		final String CASE_NAME = "large";
		processor = new A();
		processor.setInputFileName(FILE_BASE + "/" + FILE_NAME + "-" + CASE_NAME + ".in");
		processor.setOutputFileName(FILE_BASE + "/" + FILE_NAME + "-" + CASE_NAME + ".out");
		processor.start();
	}

	@Override
	public String processCase(int caseNumber) throws IOException
	{
		int[] values = this.readIntegerArray(" ");
		int total = 0;
		double requiredVotes;
		for ( int i = 1; i < values.length; i++ )
			total += values[i];
		requiredVotes = (2.0 * total) / values[0];

		int remainingParticipants = 0;
		int remainingTotalVotes = 0;
		for ( int i = 1; i < values.length; i++ )
		{
			if ( values[i] < requiredVotes )
			{
				remainingParticipants++;
				remainingTotalVotes += values[i];
			}
		}

		double remainingRequiredVotes = (1.0 * remainingTotalVotes + total) / remainingParticipants;
		System.out.println(2*total + ", " + values[0] + ", " + requiredVotes
				+ ":" + remainingTotalVotes + "," + remainingParticipants + "," + remainingRequiredVotes);

		double[] percentages = new double[values.length];
		for ( int i = 1; i < values.length; i++ )
		{
			if ( values[i] > requiredVotes )
				percentages[i] = 0;
			else
				percentages[i] = (1.0 * remainingRequiredVotes - values[i]) / total;
		}
		StringBuilder b = new StringBuilder();
		for ( int i = 1; i < values.length; i++ )
			b.append(i > 1 ? " " : "").append(Math.round(100000000 * (percentages[i]))/1000000.0);
		return b.toString();
	}
}
