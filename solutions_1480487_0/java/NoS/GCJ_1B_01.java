package org.nos.gcj;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Calendar;
import java.util.StringTokenizer;

public class GCJ_1B_01 {
	static final String path = "F:/GCJ/GCJ_1B_01/Small_1";
//	static final String path = "F:/GCJ/GCJ_1B_01/Large";
	
	class TestCase
	{
		double[] points;
	}
	
	public TestCase readTestCase(BufferedReader br) throws Exception
	{
		TestCase tc = new TestCase();
		
		String line = br.readLine();
		StringTokenizer st = new StringTokenizer(line);
		int total = Integer.valueOf(st.nextToken());
		tc.points = new double[total];
		
		for (int i=0; i<tc.points.length; i++)
			tc.points[i] = Double.valueOf(st.nextToken());
		
		return tc;
	}
	
	public void writeTestResult(BufferedWriter bw, TestCase tc) throws Exception
	{
		double N = tc.points.length;
		double sum = 0;
		double sumexit = 0;
		for (int i=0; i<tc.points.length; i++)
			sum += tc.points[i];
		double[] result = new double[tc.points.length];
		int change = 1;
		while (change > 0)
		{		
			change = 0;
			for (int i=0; i<tc.points.length; i++)
			{
				if (result[i] == -1D)
					continue;
				
				result[i] = (2D/N - sumexit/(N*sum) - tc.points[i]/sum)*100;
				
				if (result[i] < 0)
				{
					change++;
					result[i] = -1D;
					sumexit += tc.points[i];
				}
			}
			N -= change;
		}
		for (int i=0; i<result.length; i++)
			bw.write(" "+(result[i]>0 ? result[i] : 0));
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
		GCJ_1B_01 jam = new GCJ_1B_01();
		jam.solve();
	}

}
