package org.nos.gcj;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Calendar;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

public class GCJ_1C_01 {
	static final String path = "F:/GCJ/GCJ_1C_01/Small";
//	static final String path = "F:/GCJ/GCJ_1C_01/Large";
	
	class TestCase
	{
		int [][] inh;
		
		Object[][] cache;
	}
	
	public TestCase readTestCase(BufferedReader br) throws Exception
	{
		TestCase tc = new TestCase();
		
		String line = br.readLine();
		StringTokenizer st = new StringTokenizer(line);
		int size = Integer.valueOf(st.nextToken());
		tc.inh = new int[size][];
		tc.cache = new Object[size][size];
		for (int i=0; i<tc.inh.length; i++)
		{
			line = br.readLine();
			st = new StringTokenizer(line);
			int sz = Integer.valueOf(st.nextToken());
			if (sz == 0)
				continue;
			tc.inh[i] = new int[sz];
			for (int j=0; j<tc.inh[i].length; j++)
				tc.inh[i][j] = Integer.valueOf(st.nextToken());
		}
		
		return tc;
	}
	
	Set<String> getPaths(TestCase tc, int a, int b)
	{
		if (a == b)
		{
			String s = b+"_";
			Set<String> hs = new HashSet<String>();
			hs.add(s);
			return hs;
		}
		
		if (tc.cache[a][b] != null)
			return (Set<String>)tc.cache[a][b];
		
		Set<String> newPaths = new HashSet<String>();
		if (tc.inh[a] != null)
		for (int i=0; i<tc.inh[a].length; i++)
		{
			Set<String> paths = getPaths(tc,tc.inh[a][i]-1,b);
			for (String path : paths) 
				newPaths.add(a+"_"+path);
		}
		tc.cache[a][b] = newPaths;
//		System.out.println("["+a+","+b+"]:"+newPaths);
		return newPaths;
	}
	
	boolean hasDiamond(TestCase tc, int a, int b)
	{
		Set<String> set = getPaths(tc, a, b);
		if (set.size() > 1)
			System.out.println("\n["+a+","+b+"]:"+set);
		return (set.size() > 1);
	}
	
	public void writeTestResult(BufferedWriter bw, TestCase tc) throws Exception
	{
		for (int i=0; i<tc.inh.length; i++)
			for (int j=0; j<tc.inh.length; j++)
				if (hasDiamond(tc,i,j))
				{
					bw.write("Yes");
					return;
				}
		bw.write("No");
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
		GCJ_1C_01 jam = new GCJ_1C_01();
		jam.solve();
	}

}
