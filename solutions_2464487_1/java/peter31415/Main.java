import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.List;

public class Main { 
	static String file = "A-large";
	//static String file = "d";

	public static void main(String[] args) throws IOException {

		FileInputStream fis = new FileInputStream(file + ".in");
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
			long r = Long.parseLong(v[0]);
			long t = Long.parseLong(v[1]);

			String solution = getSolutionLarge(r, t);
					
			String res = "Case #" + (i + 1) + ": " + solution;

			System.out.println(res);
			bw.write(res);
			bw.newLine();
		}

		if (bw != null)
			bw.close();

		if (br != null)
			br.close();
	}
	
	public static String getSolutionLarge(long r, long t) {
		BigInteger min = new BigInteger("1");
		String maxB = "1";
		for (int i = 0; i < 100; i++) {
			maxB +="0";
		}
		BigInteger max = new BigInteger(maxB);
		
		while(max.subtract(min).compareTo(new BigInteger("1"))>0)
		{
			BigInteger middle = max.add(min).divide(new BigInteger("2"));
			
			BigInteger needed = needed(r, middle);
			if (needed.compareTo(BigInteger.valueOf(t)) < 0)
			{
				min = middle;
			} else if (needed.compareTo(BigInteger.valueOf(t)) > 0)
			{
				max = middle;
			} else
			{
				return "" + middle;
			}
					
		}		
		
		long minL = min.longValue();
		long maxL = max.longValue();
		long lastOK = minL;
		for (long i = minL; i <= maxL; i++) {
			if(needed(r, BigInteger.valueOf(i)).compareTo(BigInteger.valueOf(t)) <=0)
			{
				lastOK = i;
			}
		}
		
		return "" + lastOK;
	}
	
	static BigInteger needed(long r, BigInteger circles)
	{
		BigInteger tmp = circles.multiply(circles).multiply(new BigInteger("2")).subtract(circles);
		
		return BigInteger.valueOf(r).multiply(circles).multiply(new BigInteger("2")).add(tmp); 
	}
}
