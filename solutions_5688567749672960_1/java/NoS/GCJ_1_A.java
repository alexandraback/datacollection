import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.Set;

public class GCJ_1_A {
	
	static final String path = ".";
	
	
	class TestCase
	{
		long N;
	}
	
	
	public TestCase readTestCase(BufferedReader br) throws Exception
	{
		TestCase tc = new TestCase();
		String s = br.readLine();
		tc.N = Long.valueOf(s);
		return tc;
	}
	
	private static long flip(long N)
	{
		long res = 0;
		while (N > 0)
		{
			res *= 10;
			res += (N % 10);
			N /= 10;
		}
		return res;
	}
	
	private static long normalPiece(long N)
	{
		long num = N;
		long digits = Math.round(Math.ceil(Math.log10(num)));
		if (Math.ceil(Math.log10(num)) == Math.log10(num))
			digits++;
		long tail = Math.round(Math.pow(10, digits / 2));
		long res = (N / tail) * tail;
		return res + 1;
	}
	
	public void writeTestResult(BufferedWriter bw, TestCase tc) throws Exception
	{
		long counter = 0;
		long N = tc.N;
		while (N > 10) {
			long np = normalPiece(N);
			if (np < N) {
				counter += (N - np);
				N = np;
				
				if (N != flip(N)) {
					N = flip(N);
					counter++;
				}
				
				np = normalPiece(N);
				counter += (N - np);
				N = np;
				
				counter += 2;
				N -= 2;
			} else if (np == N) {
				if (N <= flip(N)) {
					counter += 2;
					N -= 2;
				} else {
					counter++;
					N = flip(N);
				}
			} else {
				counter++;
				N--;
			}
		}
		counter += (N);
		bw.write(counter+"");
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
		GCJ_1_A jam = new GCJ_1_A();
		jam.solve();
	}
}
