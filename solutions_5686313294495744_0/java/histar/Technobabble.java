package jam16.technobabble;


import java.io.*;
import java.util.*;

public class Technobabble {
	
	public static void main(String[] args) throws IOException {
		Scanner input = new Scanner(new File(args[0]));
		PrintWriter output = new PrintWriter(new File(args[1]));
		
		int t = input.nextInt();
		input.nextLine();
		
		
		for (int i = 0; i < t; ++i) {
			int n = input.nextInt();
			input.nextLine();
			String[][] titles = new String[n][2];
			for (int j = 0; j < n; ++j) {
				String line = input.nextLine();
				titles[j] = line.trim().split("\\s+");
			}
			output.printf("Case #%d: %d%n", (i + 1), maxFakeCount(titles));
			
		}
		
		input.close();
		output.close();
	}
	
	private static int maxFakeCount(String[][] titles) {
		int maxFakes = 0;
		for (int s = 1; s < 1 << titles.length; ++s) {
			List<String[]> fakes = new ArrayList<>();

			Set<String> originalFirsts = new HashSet<>();
			Set<String> originalSeconds = new HashSet<>();
			for (int i = 0; i < titles.length; ++i) {
				if (((1 << i) & s) != 0) {
					originalFirsts.add(titles[i][0]);
					originalSeconds.add(titles[i][1]);
				} else fakes.add(titles[i]);
			}
			
			boolean impossible = false;
			for (String[] fake : fakes) {
				if (!originalFirsts.contains(fake[0]) || !originalSeconds.contains(fake[1])) {
					impossible = true;
					break;
				}
			}
			if (!impossible) maxFakes = Math.max(maxFakes, fakes.size());
		}
		
		
		return maxFakes;
	}

}
