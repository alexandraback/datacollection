package org.nos.gcj;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Calendar;
import java.util.StringTokenizer;

public class GCJ_Q_01 {
	static final String map = "F:/GCJ/GCJ_Qalification_01/mapping.txt";
	static final String path = "F:/GCJ/GCJ_Qalification_01/Small_1";
//	static final String path = "F:/GCJ/GCJ_Qualification_01/Large";
	String from = "abcdefghijklmnopqrstuvwxyz";
	String to = "yhesocvxduiglbkrztnwjpfmaq";
	
	class TestCase
	{
		String line;
	}
	
	public TestCase readTestCase(BufferedReader br) throws Exception
	{
		TestCase tc = new TestCase();
		
		tc.line = br.readLine();
		
		return tc;
	}
	
	public void writeTestResult(BufferedWriter bw, TestCase tc) throws Exception
	{
		String res = "";
		for (int i=0; i<tc.line.length(); i++)
		{
			char c = tc.line.charAt(i);
			if (c != ' ')
			{
				int index = from.indexOf(c);
				res += to.charAt(index);
			} else res += " ";
			
		}
		
		bw.write(""+res);
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
		GCJ_Q_01 jam = new GCJ_Q_01();
		jam.solve();
	}

}
