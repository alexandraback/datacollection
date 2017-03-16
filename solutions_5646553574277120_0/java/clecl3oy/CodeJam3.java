import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;

public class CodeJam3 {
	
	public static void main(String[] args) {
		// Template starts here
		BufferedReader br = null;
		try {
			br = new BufferedReader(new FileReader("input.txt"));
			int numTestCase = Integer.valueOf(br.readLine());
			for(int testCase=1; testCase<=numTestCase; testCase++)
			{
				System.out.print("Case #" + testCase + ": ");
				
				// Read each test case
				
				// Array
				String[] qArray = br.readLine().split(" ");
				// Do you need to use long or double?
				int c = Integer.valueOf(qArray[0]);
				int d = Integer.valueOf(qArray[1]);
				long v = Long.valueOf(qArray[2]);
				
				String[] qArray2 = br.readLine().split(" ");
				ArrayList<Long> dList = new ArrayList<Long>();
				for(int i=0; i<d; i++)
				{
					dList.add(new Long(qArray2[i]));
				}
				
				
				long ansl = 0;
				
				ArrayList<Long> newList = new ArrayList<Long>();
				// Logic goes here
				for(long i=1; i<=v; i++)
				{
					if(!dList.isEmpty())
					{
						Long minFromD = dList.get(0);
						if(i == minFromD)
						{
							dList.remove(0);
							newList.add(minFromD);
							continue;
						}
					}
					Long sumFromAll = sum(newList);
					if(i > sumFromAll)
					{
						newList.add(i);
						ansl++;
					}
				}
				
				// Print output
				System.out.println(ansl);
			}
		} catch (IOException e) {
			e.printStackTrace();
		}
		// Template ends here
	}
	
	public static long sum(ArrayList<Long> l)
	{
		long sum = 0;
		for(int i=0; i<l.size(); i++){
		    sum += l.get(i);
		}
		return sum;
	}
	
	public static long min(ArrayList<Long> l)
	{
		long min = Long.MAX_VALUE;
		for(int i=0; i<l.size(); i++){
		    if(min<l.get(i))
		    {
		    	min = l.get(i);
		    }
		}
		return min;
	}
	
}
