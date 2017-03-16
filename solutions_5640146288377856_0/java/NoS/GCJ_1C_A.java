import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Scanner;

public class GCJ_1C_A {
	
	static final String path = ".";
	
	
	class TestCase
	{
		long R, C, W;
	}
	
	
	public TestCase readTestCase(BufferedReader br) throws Exception
	{
		TestCase tc = new TestCase();
		String s = br.readLine();
		Scanner sc = new Scanner(s);
		tc.R = sc.nextLong();
		tc.C = sc.nextLong();
		tc.W = sc.nextLong();
		sc.close();
		return tc;
	}
	
	public void writeTestResult(BufferedWriter bw, TestCase tc) throws Exception
	{
		long turnCounter = 0;
		turnCounter += tc.R * (tc.C / tc.W);
		turnCounter += tc.W;
		if (tc.C % tc.W == 0)
			turnCounter--;
		bw.write(""+turnCounter);
	}
	
	public void solve() throws Exception
	{
		BufferedReader br = new BufferedReader(new FileReader(path+"/input"));
		BufferedWriter bw = new BufferedWriter(new FileWriter(path+"/output"));
		int testCases = Integer.valueOf(br.readLine()).intValue();
		for (int i=0; i<testCases; i++)
		{
			System.out.print("Test case "+(i+1)+": ");
			long time = System.nanoTime();
			TestCase testCase = readTestCase(br);
			System.out.print(" read in "+(System.nanoTime()-time)/1E3+" ms, ");
			time = System.nanoTime();
			bw.write("Case #"+(i+1)+": ");
			writeTestResult(bw, testCase);
			bw.write("\n");
			System.out.println("solved in "+(System.nanoTime()-time)/1E3+" ms");
		}
		bw.flush();
		bw.close();
		br.close();
	}
	public static void main(String[] args) throws Exception 
	{
		GCJ_1C_A jam = new GCJ_1C_A();
		jam.solve();
	}
}
