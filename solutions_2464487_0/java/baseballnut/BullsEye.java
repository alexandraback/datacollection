package gcj2013;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;

public class BullsEye 
{
	public String solve(String line, int caseNr)
	{
		StringBuffer sb = new StringBuffer("");
		sb.append("Case #");
		sb.append(caseNr);
		sb.append(": ");
		sb.append(getCircleCount(line));
		return sb.toString();
	}

	private int getCircleCount(String input)
	{
		String[] parts = input.split(" ");
		long r = new Long(parts[0]).longValue();
		long t = new Long(parts[1]).longValue();
		int result = 0;
		long used = 0;
		long nextLayer = 2*r + 1;
		while (used + nextLayer <= t)
		{
			result += 1;
			used += nextLayer;
			nextLayer += 4;
		}
		return result;
	}
	/**
	 * @param args
	 */
	public static void main(String[] args) 
	{
		BullsEye test = new BullsEye();
		String fileName = "A-small-attempt0.in.txt";
		String outName = "outAsmall.txt";
		try
		{
			BufferedReader br = new BufferedReader(new FileReader(fileName));
			String line = br.readLine();
			BufferedWriter bw = new BufferedWriter(new FileWriter(outName));
			int tests = new Integer(line).intValue();
			for (int i = 0; i < tests; i++)
			{
				line = br.readLine();
				String line2 = test.solve(line, i+1);
				System.out.println(line2);
				bw.write(line2+"\n");
			}
			bw.flush();
		}
		catch (Exception e)
		{
			e.printStackTrace();
		}		
	}

}

