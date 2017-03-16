package qualifierFun;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class MaxEnergy {
	public static void main(String[] args) {
		try {
			PrintWriter out = new PrintWriter(new FileWriter("output2.txt")); 
			BufferedReader in  = new BufferedReader(new FileReader("input.txt"));
			int answer =1;
			String strLine = in.readLine();
			int totalCases = Integer.parseInt(strLine);
			for(int i = 0; i < totalCases; i++) {
				strLine = in.readLine();
				String inputs[] = strLine.split(" ");
			    long initial = Long.parseLong(inputs[0]);
			    long refuel = Long.parseLong(inputs[1]);
			    long activities = Long.parseLong(inputs[2]);
			    strLine = in.readLine();
				inputs = strLine.split(" ");
				List<Long> values = new ArrayList<Long>();
				for(String input : inputs) {
					values.add(Long.parseLong(input));
				}
			    long gain = getMaxGain(initial, refuel, 0, values, initial);
				System.out.print(String.format("Case #%s: %s\n", answer, gain));
				out.write(String.format("Case #%s: %s\n", answer, gain));
				answer++;
			}
			out.close();
			in.close();
		} catch (FileNotFoundException e) {
			System.out.println("I'd want to know");
		} catch (IOException e) {
			System.out.println("I'd want to know io");
		}
		System.out.println("done");
	}
	
	private static long getMaxGain(long current, long refuel, int place, List<Long> activities, long maxFuel) {
		if(current > maxFuel) {
			current = maxFuel;
		}
		if(place == activities.size() - 1) {
			return current * activities.get(place);
		}
		long max = 0;
		for (long i = 0; i <= current; i++) {
			long gain = i * activities.get(place) + getMaxGain(current - i + refuel, refuel, place + 1, activities, maxFuel);
			if(gain > max) {
				max = gain;
			}
		}
		return max;
	}
}
