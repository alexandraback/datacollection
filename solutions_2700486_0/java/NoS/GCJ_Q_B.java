package org.nos.gcj;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Calendar;
import java.util.StringTokenizer;

public class GCJ_Q_B {
	
	static final String path = "/home/novserj/gcj/b";
	
	class TestCase
	{
		int[][] lawn;
	}
	
	public TestCase readTestCase(BufferedReader br) throws Exception
	{
		TestCase tc = new TestCase();
		String line = br.readLine();
		StringTokenizer st = new StringTokenizer(line);
		int m = Integer.valueOf(st.nextToken());
		int n = Integer.valueOf(st.nextToken());
		tc.lawn = new int[m][n];
		for (int i=0; i<m; i++)
		{
			line = br.readLine();
			st = new StringTokenizer(line);
			for (int j=0; j<n; j++)
				tc.lawn[i][j] =Integer.valueOf(st.nextToken());  
		}
		return tc;
	}
	
	public void writeTestResult(BufferedWriter bw, TestCase tc) throws Exception
	{
		for (int i=0; i<tc.lawn.length; i++)
		{
			for (int j=0; j<tc.lawn[i].length; j++)
			{
				int height = tc.lawn[i][j];
				boolean rowok = true, colok = true;
				for (int ii = 0; ii < tc.lawn.length; ii++)
					if (tc.lawn[ii][j] > height)
					{
						rowok = false;
						break;
					}
				for (int jj = 0; jj < tc.lawn[i].length; jj++)
					if (tc.lawn[i][jj] > height)
					{
						colok = false;
						break;
					}
				if (!rowok && !colok)
				{
					bw.write("NO");
					return;
				}
			}
		}
		bw.write("YES");
		return;
	}
	
	public void solve() throws Exception
	{
		BufferedReader br = new BufferedReader(new FileReader(path+"/input.in"));
		BufferedWriter bw = new BufferedWriter(new FileWriter(path+"/output.out"));
		int testCases = new Integer(br.readLine());
		for (int i=0; i<testCases; i++)
		{
			System.out.print("Test case "+(i+1)+": ");
			long time = Calendar.getInstance().getTimeInMillis();
			TestCase testCase = readTestCase(br);
			System.out.print(" read in "+(Calendar.getInstance().getTimeInMillis()-time)+"ms, ");
			time = Calendar.getInstance().getTimeInMillis();
			bw.write("Case #"+(i+1)+": ");
			writeTestResult(bw, testCase);
			bw.write("\n");
			System.out.println("solved in "+(Calendar.getInstance().getTimeInMillis()-time)+"ms");
		}
		bw.flush();
		bw.close();
		br.close();
	}
	public static void main(String[] args) throws Exception 
	{
		GCJ_Q_B jam = new GCJ_Q_B();
		jam.solve();
	}
}
