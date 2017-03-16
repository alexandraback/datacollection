import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.util.Scanner;
import java.util.TreeMap;
import java.util.TreeSet;


public class Recycled {
	private File file = new File("D:\\Sources\\GoogleCodeJam\\files\\C-large.in");
	private File outFile = new File("D:\\Sources\\GoogleCodeJam\\files\\result.out");
	
	private Long[] results;
	private Integer solved = 0;
	
	public void readData() {
		boolean first = true;
		Scanner scanner;
		try {
			scanner = new Scanner(file);
			while (scanner.hasNextLine()) {
				String line = scanner.nextLine();
				Scanner scan = new Scanner(line);
				if (first) {
					results = new Long[scan.nextInt()];
					first = false;
				} else {
					long min = scan.nextLong();
					long max = scan.nextLong();
					results[solved] = solveProblem(min, max);
					solved++;
				}
			}
			printResult();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	private Long solveProblem(long min, long max) {
		long sum = 0;
		TreeSet<Double> res = new TreeSet<Double>();
		for (long val = min; val <= max; val++) {
			res.clear();
			String number = String.valueOf(val);
			int len = number.length();
			for (int i = 1; i < number.length(); i++) {
				 String newVal = number.substring(i, len) + number.substring(0, i);
				 long recycled = Long.valueOf(newVal);
				 if(recycled > val && recycled <= max && res.add(val + recycled * Math.pow(10, len))) {
					 sum++;
				 }
			}
		}
		return sum;
	}

	private void printResult() {
		try {
			FileWriter fstream = new FileWriter(outFile);
			BufferedWriter out = new BufferedWriter(fstream);
			for (int i = 0; i < results.length; i++) {
				out.write("Case #" + (i + 1) + ": " + results[i]);
				out.newLine();
			}
			out.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}
