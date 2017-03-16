package amazon;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader fileIn = new BufferedReader(new FileReader("B-small-attempt0.in"));
		PrintWriter fileOut = new PrintWriter(new FileWriter("result"));
		int caseNum = Integer.parseInt(fileIn.readLine());
		for (int k = 1; k <= caseNum; k++) {
			String[] mp = fileIn.readLine().split(" ");
			
			fileOut.println("Case #" + k + ": " + solve(Double.parseDouble(mp[0]), Double.parseDouble(mp[1]), Double.parseDouble(mp[2])));
		}
		fileOut.close();
        fileIn.close();
	}
	
	public static double solve(double c, double f, double x) {
		double minTime = x / 2;
		double sum = 0.0;
		for (int k = 1; k <= x; k++) {
			sum += c / (2 + (k - 1) * f);
			minTime = Math.min(minTime, sum + x / (f * k + 2));
		}
		return minTime;
	}

}
