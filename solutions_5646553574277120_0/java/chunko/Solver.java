package codejam;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;

public class Solver {

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader reader = new BufferedReader(new FileReader("input.in"));
		BufferedWriter writer = new BufferedWriter(new FileWriter("output.out"));

		int t = Integer.parseInt(reader.readLine());

		for (int c = 1; c <= t; ++c) {
			long result = 0;
			
			String[] values = reader.readLine().split(" ");
			int c2 = Integer.parseInt(values[0]);
			int d = Integer.parseInt(values[1]);
			long v = Integer.parseInt(values[2]);
			
			String[] coinValues = reader.readLine().split(" ");
			//int[] coins = new int[coinValues.length];
			ArrayList<Long> coins = new ArrayList<Long>();
			for (int i = 0; i < coinValues.length; ++i) {
				coins.add(Long.parseLong(coinValues[i]));
			}
			
			for (long n = 1; n <= v; n++) {
				long current = n;
				
				for (int j = coins.size() - 1; j >= 0; j--) {
					if (coins.get(j) <= current) {
						current -= coins.get(j);
					}
				}
				
				if (current != 0) {
					coins.add(n);
					Collections.sort(coins);
					result++;
				}
			}
			
			System.out.println("Case #" + c + ": " + result);
			writer.write("Case #" + c + ": " + result);
			writer.newLine();	
		}
		
		writer.flush();
		writer.close();
		reader.close();
	}

}
