package org.nos.gcj;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Calendar;
import java.util.StringTokenizer;

public class GCJ_Q_02 {
	
//	static final String path = "F:/GCJ/GCJ_Qalification_02/Small_1";
	static final String path = "F:/GCJ/GCJ_Qalification_02/Large";
	
	class TestCase
	{
		int N;
		int S;
		int p;
		int[] t;
	}
	
	public TestCase readTestCase(BufferedReader br) throws Exception
	{
		TestCase tc = new TestCase();
		
		String line = br.readLine();
		StringTokenizer st = new StringTokenizer(line);
		tc.N = Integer.valueOf(st.nextToken());
		tc.S = Integer.valueOf(st.nextToken());
		tc.p = Integer.valueOf(st.nextToken());
		tc.t = new int[tc.N];
		
		for (int i=0; i<tc.N; i++)
			tc.t[i] = Integer.valueOf(st.nextToken());
		return tc;
	}
	
	public void writeTestResult(BufferedWriter bw, TestCase tc) throws Exception
	{
		int total = 0;
		for (int i=0; i<tc.N; i++)
		{
			if (tc.t[i] == 0 )
			{
				if (tc.p == 0)
					total++;
			} else
			if ( tc.t[i] >= (3*tc.p-2) )
				total++;
			else if ((tc.t[i] >= (3*tc.p - 4)) && (tc.S > 0))
			{
				tc.S--;
				total++;
			}
		}

		bw.write(""+total);
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
		GCJ_Q_02 jam = new GCJ_Q_02();
		jam.solve();
	}

}
