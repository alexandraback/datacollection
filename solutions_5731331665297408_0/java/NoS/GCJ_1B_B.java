import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.Calendar;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class GCJ_1B_B {
	
	static final String path = ".";
	
	class City
	{
		Integer zipcode;
		List<City> n = new ArrayList<City>();
	}
	
	class TestCase
	{
		Set<City> visited = new HashSet<City>();
		String zipcode = "";
		List<City> c = new ArrayList<City>();
		
		public TestCase clone()
		{
			TestCase r = new TestCase();
			r.visited.addAll(visited);
			r.c.addAll(c);
			r.zipcode = zipcode;
			return r;
		}
		
		public String toString()
		{
			return zipcode;
		}
	}
	
	public TestCase readTestCase(BufferedReader br) throws Exception
	{
		TestCase tc = new TestCase();
		String[] tmp = br.readLine().split(" ");
		int N = Integer.valueOf(tmp[0]);
		int M = Integer.valueOf(tmp[1]);
		
		for (int i=0; i<N; i++)
		{
			String zip = br.readLine();
			City c = new City();
			c.zipcode = Integer.valueOf(zip);
			tc.c.add(c);
		}
		
		for (int i=0; i<M; i++)
		{
			String[] f = br.readLine().split(" ");
			Integer from = Integer.valueOf(f[0]);
			Integer to = Integer.valueOf(f[1]);
			tc.c.get(from - 1).n.add(tc.c.get(to - 1));
			tc.c.get(to - 1).n.add(tc.c.get(from - 1));
		}
		
		return tc;
	}
	
	public List<TestCase> slv(TestCase tc, City c) throws Exception
	{
		List<TestCase> r = new ArrayList<TestCase>();
		r.add(tc);
		for (int i=0; i<c.n.size(); i++)
			if (!tc.visited.contains(c.n.get(i)))
			{
				TestCase tmp = tc.clone();
				tmp.zipcode += c.n.get(i).zipcode+"";
				tmp.visited.add(c.n.get(i));
				List<TestCase> local = slv(tmp, c.n.get(i));
				for (TestCase testCase : local)
				{
					List<TestCase> res = slv(testCase, c);
					for (TestCase rc : res) 
					{
						TestCase dupl = null;
						
						for (TestCase etc : r)
							if (rc.visited.equals(etc.visited))
								dupl = etc;
						
						if (dupl != null)
						{
							if (dupl.zipcode.compareTo(rc.zipcode) > 0)
							{
								r.remove(dupl);
								r.add(rc);
							}
						} else
							r.add(rc);
					}
				}
			}
		return r;
	}
	
	public void writeTestResult(BufferedWriter bw, TestCase tc) throws Exception
	{
		City minZip = tc.c.get(0);
		
		for (int i=1; i<tc.c.size(); i++)
			if (tc.c.get(i).zipcode < minZip.zipcode)
				minZip = tc.c.get(i);
		
		tc.zipcode += minZip.zipcode+"";
		tc.visited.add(minZip);
		
		List<TestCase> r = slv(tc, minZip);
		
		String minStr = null;
		for (TestCase tz : r)
		{
			if (tz.visited.size() < tz.c.size())
				continue;
			if (minStr == null || minStr.compareTo(tz.zipcode) > 0)
				minStr = tz.zipcode;
		}
		bw.write(minStr);
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
		GCJ_1B_B jam = new GCJ_1B_B();
		jam.solve();
	}
}
