package org.nos.gcj;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Calendar;
import java.util.List;
import java.util.StringTokenizer;

public class GCJ_1B_03 {
	static final String path = "F:/GCJ/GCJ_1B_03/Small_1";
//	static final String path = "F:/GCJ/GCJ_1B_03/Large";
	
	class TestCase
	{
		int[] items;
	}
	
	public TestCase readTestCase(BufferedReader br) throws Exception
	{
		TestCase tc = new TestCase();
		
		String line = br.readLine();
		StringTokenizer st = new StringTokenizer(line);
		int total = Integer.valueOf(st.nextToken());
		tc.items = new int[total];
		for (int i=0; i<total; i++)
			tc.items[i] =  Integer.valueOf(st.nextToken());
		
		return tc;
	}
	
	public int getSum(TestCase tc, int subsetCode)
	{
		int sum = 0;
		for (int i=tc.items.length-1; i>=0; i--)
		{
			if (subsetCode % 2 == 1)
				sum+= tc.items[i];
			subsetCode /= 2;
		}
		return sum;
	}
	
	public List<Integer> getItems(TestCase tc, int subsetCode)
	{
		List<Integer> res = new ArrayList<Integer>();
		for (int i=tc.items.length-1; i>=0; i--)
		{
			if (subsetCode % 2 == 1)
				res.add(tc.items[i]);
			subsetCode /= 2;
		}
		return res;
	}
	
	public void printList(List<Integer> res, BufferedWriter bw) throws Exception
	{
		for (int i=0; i<res.size(); i++)
			bw.write(((i>0)?" ":"")+res.get(i));
	}
	
	public void writeTestResult(BufferedWriter bw, TestCase tc) throws Exception
	{
		List<Integer> sums = new ArrayList<Integer>();
		boolean found = false;
		for (int i=1; i < 0x0FFFFF; i++)
		{
			int sum = getSum(tc,i);
			if (!sums.contains(sum))
				sums.add(getSum(tc,i));
			else
			{
				int index1 = sums.indexOf(sum)+1;
				int index2 = i;
				List<Integer> items1 = getItems(tc,index1);
				List<Integer> items2 = getItems(tc,index2);
				bw.write("\n");
				printList(items1, bw);
				bw.write("\n");
				printList(items2,bw);
				found = true;
				break;
			}
		}
		if (!found)
			bw.write("\nImpossible");
//		bw.write(""+time);
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
		GCJ_1B_03 jam = new GCJ_1B_03();
		jam.solve();
	}

}
