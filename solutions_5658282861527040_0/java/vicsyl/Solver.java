package google.jam.newlotterry;

import google.jam.template.Template;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;

public class Solver {

	
	static long solve(long a, long b, long k) {
		
		if(a <= k || b <= k) {
			return a * b;
		}
				
		long ret = a * k + b * k - k * k;
		
		for(long i = k; i < a; i++) {
			for(long j = k; j < b; j++) {
			
				if((i & j) < k) {
					ret++;
				}
				
			}
		}

		return ret;
	}
	
public static void main(String[] args) throws IOException {
		
		File file = new File(args[0]);
		File outFile = new File(Solver.class.getName() + ".txt");
		
		BufferedReader bufferedReader = null;
		PrintWriter printWriter = null;
		
		try {
		
		bufferedReader = new BufferedReader(new InputStreamReader(new FileInputStream(file)));
			
		printWriter = new PrintWriter(outFile);
		
		String line = bufferedReader.readLine();
		int numberOfTestCases = Integer.parseInt(line);
		
				
		
		
			for(int i = 0; i < numberOfTestCases; i++) {
				
				String numbers[] = bufferedReader.readLine().split(" ");
				long a = Long.parseLong(numbers[0]);
				long b = Long.parseLong(numbers[1]);
				long k = Long.parseLong(numbers[2]);
					
				long ret = solve(a, b, k);
					
					printWriter.println("Case #" + (i+1) + ": " + ret);
					
			}
			
		} finally {
			if(bufferedReader != null) {
				bufferedReader.close();
			}
			if(printWriter != null) {
				printWriter.close();
			}

		}
		
	}


	
}
