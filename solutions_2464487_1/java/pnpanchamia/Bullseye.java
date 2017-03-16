package bullseye;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.List;

public class Bullseye {

	static int testCases;

	static List<String> output = new ArrayList<String>();
	
	public static void main(String[] args) throws IOException{
		final String filename = "A-large.in";
		FileReader fileReader;
		fileReader = new FileReader(filename);
		BufferedReader bufferedReader = new BufferedReader(fileReader);
		List<String> lines = new ArrayList<String>();
		String line = null;
		while ((line = bufferedReader.readLine()) != null) {
			lines.add(line);
		}
		bufferedReader.close();

		testCases = Integer.parseInt(lines.get(0));
		int linecount = 1;

		for (int i = 0; i < testCases; i++) {
			String[] values = lines.get(linecount).split(" ");
			linecount++;
			String out = "Case #" + (i+1) + ": " + calculate(values[0], values[1]);
			System.out.println(out);
			output.add(out);
		}

		FileWriter writer = new FileWriter("output.txt"); 
		for(String str: output) {
		  writer.write(str + "\n");
		}
		writer.close();
	}

	
	private static long calculate(String radius, String thickness) {
		long count = 0;
		
		BigInteger r = new BigInteger(radius);
		BigInteger t = new BigInteger(thickness);
		
		BigInteger r1 = r.multiply(BigInteger.valueOf(2)).subtract(BigInteger.ONE);
		BigInteger a = (sqrt(r1.multiply(r1).add(t.multiply(BigInteger.valueOf(8)))).subtract(r1));
		count = a.longValue();
		count /= 4;
		return count;
	}
	
	public static BigInteger sqrt(BigInteger n) {
		BigInteger a = BigInteger.ONE;
		BigInteger b = new BigInteger(n.shiftRight(5).add(new BigInteger("8"))
				.toString());
		while (b.compareTo(a) >= 0) {
			BigInteger mid = new BigInteger(a.add(b).shiftRight(1).toString());
			if (mid.multiply(mid).compareTo(n) > 0)
				b = mid.subtract(BigInteger.ONE);
			else
				a = mid.add(BigInteger.ONE);
		}
		return a.subtract(BigInteger.ONE);
	}
}
	
