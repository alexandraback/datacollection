package org.nos.gcj;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.Calendar;
import java.util.List;
import java.util.StringTokenizer;

public class GCJ_Q_03 {
	
//	static final String path = "F:/GCJ/GCJ_Qalification_03/Small_1";
	static final String path = "F:/GCJ/GCJ_Qalification_03/Large";
	
	class TestCase
	{
		int A,B;
	}
	
	public TestCase readTestCase(BufferedReader br) throws Exception
	{
		TestCase tc = new TestCase();
		
		String line = br.readLine();
		StringTokenizer st = new StringTokenizer(line);
		tc.A = Integer.valueOf(st.nextToken());
		tc.B = Integer.valueOf(st.nextToken());
		return tc;
	}
	
	public void writeTestResult(BufferedWriter bw, TestCase tc) throws Exception
	{
		int rpCount = 0;
		
		for (int i = tc.A; i < tc.B; i++)
		{
			int digits  = Long.valueOf(Math.round(Math.floor(Math.log10(i)))).intValue()+1;
			List<Integer> local = new ArrayList<Integer>();
			for (int d = 1; d <= digits - 1; d++)
			{
				int recycled = Integer.valueOf((""+i).substring(d, digits) +(""+i).substring(0, d));
				int rdigits  = Long.valueOf(Math.round(Math.floor(Math.log10(recycled)))).intValue()+1;
				
				if (rdigits != digits)
					continue;
				if (recycled < i)
					continue;
				if (recycled > tc.B)
					continue;
				if (recycled == i)
					continue;
				if (local.contains(recycled))
					continue;
				else
					local.add(recycled);
				rpCount++;
			}
		}
		bw.write(""+rpCount);
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
		GCJ_Q_03 jam = new GCJ_Q_03();
		jam.solve();
	}

}
