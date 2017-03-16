import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.Calendar;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class GCJ_1C_B {
	
	static final String path = ".";
	
	class TestCase
	{
		String[] cars;
	}
	
	public boolean isValid(String s)
	{
		char[] alphabet = new char['z'-'a' + 1];
		char c = s.charAt(0);
		alphabet[c - 'a'] = 1;
		for (int i=1; i<s.length(); i++)
		{
			char cc = s.charAt(i);
			if (alphabet[cc - 'a'] > 0)
			{
				if (c != cc)
					return false;
				else
					alphabet[cc - 'a']++;	
			} else
			{
				alphabet[cc - 'a']++;
				c = cc;
			}
		}
		return true;
	}
	
	public String compact(String c)
	{
		String r = ""+c.charAt(0);
		for (int i=1; i<c.length(); i++)
			if (c.charAt(i) != r.charAt(r.length()-1))
				r+=c.charAt(i);
		return r;
	}
	
	public TestCase readTestCase(BufferedReader br) throws Exception
	{
		TestCase tc = new TestCase();
		br.readLine();
		String cars = br.readLine();
		tc.cars = cars.split(" ");
		for (int i=0; i<tc.cars.length; i++)
			tc.cars[i] = compact(tc.cars[i]);
		return tc;
	}
	
	public List<String> generateCombinarions(String[] cars, Set<Integer> usedIndices, String prefix)
	{
		List<String> globalList = new ArrayList<String>();
		if (cars.length == usedIndices.size())
		{
			globalList.add(prefix);
		} else
		{
		for (int i=0; i<cars.length; i++)
			if (!usedIndices.contains(i))
			{
				String p = prefix+cars[i];
				usedIndices.add(i);
				globalList.addAll(generateCombinarions(cars, usedIndices, p));
				usedIndices.remove(i);
			}
		}
		return globalList;
	}
	
	public void writeTestResult(BufferedWriter bw, TestCase tc) throws Exception
	{
		int counter = 0;
		Set<Integer> usedIndices = new HashSet<Integer>();
		List<String> allCombinations = generateCombinarions(tc.cars, usedIndices, "");
//		System.out.println(allCombinations);
		System.out.println(allCombinations.size());
		for (int i=0; i<allCombinations.size(); i++)
			if (isValid(allCombinations.get(i)))
				counter++;
		bw.write(""+counter);
	}
	
	public void solve() throws Exception
	{
		BufferedReader br = new BufferedReader(new FileReader(path+"/input"));
		BufferedWriter bw = new BufferedWriter(new FileWriter(path+"/output"));
		int testCases = Integer.valueOf(br.readLine()).intValue();
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
		GCJ_1C_B jam = new GCJ_1C_B();
		jam.solve();
	}
}
