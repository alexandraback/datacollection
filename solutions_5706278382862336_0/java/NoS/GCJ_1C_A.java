import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Calendar;

public class GCJ_1C_A {
	
	static final String path = ".";
	
	
	class TestCase
	{
		long p, q;
	}
	
	public long gcd(long a, long b) 
	{
        if (b == 0) return a;
        long x = a % b;
        return gcd(b, x);
    }
	
	public boolean pow2(long a)
	{
		long z = a;
		while (z > 1)
		{
			if (z % 2 == 0)
			{
				z /= 2;
			}
			else
			{
				if (z == 1)
					return true;
				else
					return false;
			}
		}
		return true;
	}
	
	public TestCase readTestCase(BufferedReader br) throws Exception
	{
		TestCase tc = new TestCase();
		String s = br.readLine();
		String[] p = s.split("/");
		tc.p = Long.valueOf(p[0]);
		tc.q = Long.valueOf(p[1]);
		return tc;
	}
	

	public void writeTestResult(BufferedWriter bw, TestCase tc) throws Exception
	{
		long gcd = gcd(tc.p, tc.q);
		tc.p /= gcd;
		tc.q /= gcd;
		
		if (tc.p == tc.q)
		{
			bw.write("0");
			return;
		}
		
		if (!pow2(tc.q))
		{
			bw.write("impossible");
			return;
		}
		
		long tmp = tc.q / 2;
		int counter = 1;
		
		while (tmp > tc.p)
		{
			counter++;
			tmp /= 2;
		}
		
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
		GCJ_1C_A jam = new GCJ_1C_A();
		jam.solve();
	}
}
