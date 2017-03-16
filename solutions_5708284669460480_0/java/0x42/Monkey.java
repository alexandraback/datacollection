import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Monkey {

	public static void main(String[] args) throws Exception {
		Monkey object = new Monkey();
		String className = object.getClass().getSimpleName();

		FileReader fileReader = new FileReader(new File(className.toLowerCase() + ".in"));
		Scanner scanner = new Scanner(new BufferedReader(fileReader));

		FileWriter wr = new FileWriter(className.toLowerCase() + ".out");

		int testCases = scanner.nextInt();

		for (int tc = 1; tc <= testCases; tc++) {

			int k = scanner.nextInt();
			int l = scanner.nextInt();
			int s = scanner.nextInt();
			String keyboard = scanner.next();
			String target = scanner.next();

			double result = object.solve(keyboard, target, s);

			DecimalFormat df = new DecimalFormat("0.000000000");
			wr.write("Case #" + tc + ": " + df.format(result) + "\r\n");
		}

		scanner.close();
		wr.close();
	}

	List<String> created;
	private double solve(String keyboard, String target, int s) throws Exception {
		created = new ArrayList<>();
		
		generate(keyboard, "", s);
		
		int maxToBring = 0, sum = 0;
		
		for (String word : created) {
			int bring = getBring(word, target);
			maxToBring = Math.max(maxToBring, bring);
			sum += bring;
		}
		
		double average = (sum + 0.0) / created.size();
		return maxToBring - average;		
	}
	private int getBring(String word, String target) {
		int count = 0;
		for (int st=0; st<word.length(); st++)
			if (word.indexOf(target, st) == st) {
				count++;
			}
		
		return count;
	}
	private void generate(String keyboard, String current, int s) {
		if (current.length() == s) {
			created.add(current);
			return ;
		}
		
		for (char ch : keyboard.toCharArray()) {
			generate(keyboard, current + ch, s);
		}
	}

	

}
