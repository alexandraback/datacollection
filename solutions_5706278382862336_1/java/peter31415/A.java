import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

public class A {
	static String file = "A-large(1)";	
	
	static String solve(long n, long d) {
		
		if (n == d) {
			return "0";			
		}
		
		boolean possible = false;
		for (int i = 40; i >= 1 ; i--) {
			long fraction = (long)Math.pow(2,i);			
			if (d % fraction == 0 && (n % (d/fraction) == 0)) {
				//return "" + i;				
				n = n / (d/fraction);
				d = fraction;
				possible = true;
				break;
			}
		}
		
		if (!possible)
			return "impossible";
				
		for (int i = 1; i <= 40; i++) {			
			long cc = 1;
			for (int j = 0; j < i; j++) {
				cc *= 2;
			}			
			
			long u = 1;
			while(cc < d) {
				cc *= 2;
				u *= 2;
			}
			
			if (cc == d && n >= u)
				return "" + i;
		}
		
		return "impossible";
	}	
	
	public static void main(String[] args) throws IOException {	
				
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
		int currentIndex = 1;
		for (int i = 0; i < problemCount; i++) {
			String c = lines.get(currentIndex++);
			String[] vals = c.split("/");
			long n = Long.parseLong(vals[0]);
			long d = Long.parseLong(vals[1]);
			
			String r = "Case #" + (i+1) + ": " + solve(n,d);
						
			bw.write(r);
			bw.newLine();
		}

		if (bw != null)
			bw.close();

		if (br != null)
			br.close();			
	}
}
