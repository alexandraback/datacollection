import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;

public class GCJ_1C_B {
	
	static final String path = ".";
	
	
	class TestCase
	{
		Long K, L, S;
		String twriter;
		String tword;
		String reuseWord = "";
	}
	
	public TestCase readTestCase(BufferedReader br) throws Exception
	{
		TestCase tc = new TestCase();
		String s = br.readLine();
		Scanner sc = new Scanner(s);
		tc.K = sc.nextLong();
		tc.L = sc.nextLong();
		tc.S = sc.nextLong();
		sc.close();
		tc.twriter = br.readLine();
		tc.tword = br.readLine();
		return tc;
	}
	
	private long wcs(TestCase tc)
	{
		Set<Character> s = new HashSet<>();
		for (int i = 0; i < tc.twriter.length(); i++)
			s.add(tc.twriter.charAt(i));
		for (int i = 0; i < tc.tword.length(); i++)
			if (!s.contains(tc.tword.charAt(i)))
				return 0;
		long reusable = 0;
		for (int i = 1; i < tc.tword.length(); i++) {
			String p = tc.tword.substring(i);
			if (tc.tword.startsWith(p)) {
				reusable = tc.tword.length() - i;
				tc.reuseWord = p;
				break;
			}
		}
		long chars = tc.S;
		long bananas = 0;
		chars -= tc.tword.length();
		bananas += 1;
		bananas += (chars / (tc.tword.length() - reusable));
		return bananas;
	}
	
	private double computeBanana(Map<Character, Integer> m, String soFar, Long keysLeft, TestCase tc) {
//		System.out.println(soFar);
		double result = 0;
		if (keysLeft == 0)
			return 0;
		
		for (Map.Entry<Character, Integer> e : m.entrySet()) {
			int newBanana = 0;
			String newSoFar  = soFar + e.getKey();
			if (!tc.tword.startsWith(newSoFar))
				newSoFar = "";
			else if (tc.tword.equals(newSoFar)) {
				newSoFar = tc.reuseWord;
				newBanana = 1;
			}
			result += (e.getValue().doubleValue() / tc.K.doubleValue()) * (newBanana + computeBanana(m, newSoFar, keysLeft - 1, tc));
		}
		return result;
	}
	
	public void writeTestResult(BufferedWriter bw, TestCase tc) throws Exception
	{
		Long worstCase = wcs(tc);
		if (worstCase == 0) {
			bw.write("0.0");
			return;
		}
		Map<Character, Integer> m = new HashMap<>();
		for (int i = 0; i < tc.twriter.length(); i++)
		{
			char c = tc.twriter.charAt(i);
			if (m.containsKey(c))
				m.put(c, m.get(c) + 1);
			else
				m.put(c, 1);
		}
		
		double banana = computeBanana(m, "", tc.S, tc);
		bw.write(""+(worstCase.doubleValue() - banana));
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
		GCJ_1C_B jam = new GCJ_1C_B();
		jam.solve();
	}
}
