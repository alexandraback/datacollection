package cookie;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class CookieClicker {

	
	
	public static void main(String[] agrv) throws NumberFormatException, IOException {
		
		File file = new File("./src/cookie/input.text");
		FileInputStream fis = new FileInputStream(file);
		BufferedReader br = new BufferedReader(new InputStreamReader(fis));
				
		int num = Integer.parseInt(br.readLine());
		
		String[] line = new String[3];
		
		for (int i = 0; i < num; i++) {
			line = br.readLine().split(" ");
			System.out.printf("Case #%d: %.7f\n", (i+1), getResult(line));
		}
	}
	
	public static double getResult(String[] line) {
		double C = Double.parseDouble(line[0]);
		double F = Double.parseDouble(line[1]);
		double X = Double.parseDouble(line[2]);
		
		int m = (int)(X / C);
		double minTime = Float.MAX_VALUE;
		double tmpTime = 0; 
		
		for (int i = 0; i <= m; i++) {
			tmpTime = 0;
			for (int j = 1; j <= i; j++) {
				tmpTime += C / (2.0 + (j - 1) * F);
			}
			tmpTime += X / (2.0 + i * F);
			if (tmpTime < minTime)
				minTime = tmpTime;
		}
		return minTime;
	}
}
