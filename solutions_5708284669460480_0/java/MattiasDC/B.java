import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class B {

	public static void main(String[] args) {
		try {
			new B();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	Scanner sc = new Scanner(System.in);
	BufferedWriter w = new BufferedWriter(new FileWriter("outputB"));
	int K, L, S;
	ArrayList<Character> chars;
	String goal;
	long count, max = 0;

	public B() throws IOException {
		long s = System.currentTimeMillis();

		int t = Integer.parseInt(sc.nextLine());
		String output = null;
		String line[];
		String sline;
		for (int i = 0; i < t; i++) {
			count = 0;
			max = 0;
			line = sc.nextLine().split(" ");
			K = Integer.parseInt(line[0]);
			L = Integer.parseInt(line[1]);
			S = Integer.parseInt(line[2]);

			sline = sc.nextLine();
			chars = new ArrayList<>();
			for (int j = 0; j < sline.length(); j++) {
				chars.add(sline.charAt(j));
			}
			goal = sc.nextLine();

			double chance = solve();
			output = Double.toString(chance);
			writeOutput(i + 1, output);
		}
		System.out.println(System.currentTimeMillis() - s);
		sc.close();
		w.close();
	}

	private double solve() {
		makeString(new StringBuilder());
		return Math.max(max - ((double) count / (Math.pow(K, S))), 0);
	}

	private void makeString(StringBuilder builder) {
		if (builder.length() == S) {
			checkString(builder);
		} else {
			for (int i = 0; i < chars.size(); i++) {
				builder.append(chars.get(i));
				makeString(builder);
				builder.deleteCharAt(builder.length() - 1);
			}
		}
	}

	private void checkString(StringBuilder builder) {
		Pattern p = Pattern.compile(goal);
		Matcher m = p.matcher(builder.toString());
		int localMax = 0;
		while (m.find()) {
			count += 1;
			localMax++;
		}
		if (localMax > max) {
			max = localMax;
		}
	}

	public void writeOutput(int casenr, String output) throws IOException {
		w.write("Case #" + Integer.toString(casenr) + ": " + output + "\n");
		System.out.println("Case #" + Integer.toString(casenr) + ": " + output
				+ "\n");
	}

}
