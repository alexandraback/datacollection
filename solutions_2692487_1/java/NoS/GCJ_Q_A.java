package org.nos.gcj;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Calendar;

public class GCJ_Q_A {
	
	static final String path = "/home/novserj/gcj/a";
	
	class TestCase
	{
		int[][] row = new int[4][4];
		int[][] col = new int[4][4];
		int[][] dia = new int[2][4];
	}
	
	public TestCase readTestCase(BufferedReader br) throws Exception
	{
		TestCase tc = new TestCase();
		for (int i=0; i<4; i++)
		{
			String line = br.readLine();
			for (int j=0; j<4; j++)
			{
				char c = line.charAt(j);
				int index = -1;
				if (c == 'X')
					index = 0;
				else if (c == 'O')
					index = 1;
				else if (c == 'T')
					index = 2;
				else if (c == '.')
					index = 3;
				
				tc.row[i][index]++;
				tc.col[j][index]++;
				if (i == j)
					tc.dia[0][index]++;
				if (i + j == 3)
					tc.dia[1][index]++;
			} 
		}
		br.readLine();
		return tc;
	}
	
	public void writeTestResult(BufferedWriter bw, TestCase tc) throws Exception
	{
		boolean freeSlots = false;
		for (int i=0; i<4; i++)
		{
			if (tc.row[i][0]+tc.row[i][2] == 4)
			{
				bw.write("X won");
				return;
			}
			else
			if (tc.row[i][1]+tc.row[i][2] == 4)
			{
				bw.write("O won");
				return;
			}
			if (tc.row[i][3] > 0)
				freeSlots = true;
		}
		for (int i=0; i<4; i++)
		{
			if (tc.col[i][0]+tc.col[i][2] == 4)
			{
				bw.write("X won");
				return;
			}
			else
			if (tc.col[i][1]+tc.col[i][2] == 4)
			{
				bw.write("O won");
				return;
			}
			if (tc.col[i][3] > 0)
				freeSlots = true;
		}
		for (int i=0; i<2; i++)
		{
			if (tc.dia[i][0]+tc.dia[i][2] == 4)
			{
				bw.write("X won");
				return;
			}
			else
			if (tc.dia[i][1]+tc.dia[i][2] == 4)
			{
				bw.write("O won");
				return;
			}
			if (tc.dia[i][3] > 0)
				freeSlots = true;
		}
		if (freeSlots)
			bw.write("Game has not completed");
		else
			bw.write("Draw");
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
		GCJ_Q_A jam = new GCJ_Q_A();
		jam.solve();
	}
}
