import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Calendar;
import java.util.Date;
import java.util.List;

public class A {
	static String file = "A-small-attempt1";
	
	public static void main(String[] args) throws IOException {	
		
		Calendar cal = Calendar.getInstance();
		Date start = cal.getTime();
		
		FileInputStream fis = new FileInputStream(file+ ".in");
		InputStreamReader isr = new InputStreamReader(fis);
		BufferedReader br = new BufferedReader(isr);

		FileOutputStream fos = new FileOutputStream(file + ".out");
		OutputStreamWriter isw = new OutputStreamWriter(fos);
		BufferedWriter bw = new BufferedWriter(isw);

		String line = null;
		List<String> lines = new ArrayList<String>();
		while ((line = br.readLine()) != null) {
			lines.add(line);
		}

		int problemCount = Integer.parseInt(lines.get(0));
		int currentIndex = 0;
		for (int i = 0; i < problemCount; i++) {
			String[] v = lines.get(++currentIndex).split(" ");
			long a = Long.parseLong(v[0]);
			int n = Integer.parseInt(v[1]);
			int[] motes = new int[n];
			v = lines.get(++currentIndex).split(" ");
			for (int j = 0; j < motes.length; j++) {
				motes[j] = Integer.parseInt(v[j]);
			}
			
			Arrays.sort(motes);
			long solution = getSolution(a, motes, 0);
			String r = "Case #" + (i+1) + ": " + solution;
						
			System.out.println(r);
			bw.write(r);
			bw.newLine();
		}

		if (bw != null)
			bw.close();

		if (br != null)
			br.close();
		
		cal = Calendar.getInstance();
		Date end = cal.getTime();

		System.out.println("T = " + (end.getTime() - start.getTime()));
	}
	
	public static long getSolution(long a, int[] motes, int cur)
	{		
		if (cur >= motes.length)
			return 0;
		
		long s = 0;					
		while(cur < motes.length)
		{
			if (motes[cur] < a)
				a+=motes[cur++];
			else
				break;
		}
		
		if (cur>=motes.length)
			return 0;
		
		int howmany = howmany(a, motes[cur]);
		if (motes.length-(cur) <= howmany)
			return motes.length-cur;
		
		// pridavame
		long s1 = getSolution(add(a, howmany), motes, cur);
		long s2 =motes.length-(cur);
		
		s = Math.min(s1+howmany,s2);				
		
		return s;
	}
	
	
	static long add(long a, int howmany)
	{
		for (int i = 0; i < howmany; i++) {
			a+=(a-1);
		}
		
		return a;
	}
			
	static int howmany(long a, int nearest)
	{
		int s = 0;
		if (a > nearest)
			return 0;
				
		long t = a;
		if (t==1)
			return Integer.MAX_VALUE;
		while(t<=nearest)
		{
			t += (t-1);
			s++;
		}
				
		return s;
	}
	
	
	
}
