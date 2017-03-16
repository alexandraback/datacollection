import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class C {

	public static void main(String[] args) {
		try {
			new C();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	Scanner sc = new Scanner(System.in);
	BufferedWriter w = new BufferedWriter(new FileWriter("outputC"));
	int C, D, V;
	ArrayList<Integer> denominations;

	public C() throws IOException {
		long s = System.currentTimeMillis();

		int t = Integer.parseInt(sc.nextLine());
		String output = null;
		String[] line;
		for (int i = 0; i < t; i++) {
			line = sc.nextLine().split(" ");
			C = Integer.parseInt(line[0]);
			D = Integer.parseInt(line[1]);
			V = Integer.parseInt(line[2]);
			line = sc.nextLine().split(" ");
			denominations = new ArrayList<>();
			for (int j = 0; j < line.length; j++) {
				denominations.add(Integer.parseInt(line[j]));
			}
			output = Integer.toString(solve());
			writeOutput(i + 1, output);
		}
		System.out.println(System.currentTimeMillis() - s);
		sc.close();
		w.close();
	}

	public int solve() {
		int minimal = 0;
		for (int i = 1; i <= V; i++) {
			if (denominations.contains(i)) {
				continue;
			}
			if (!makeValue(-1, 0, i)) {
				denominations.add(i);
				Collections.sort(denominations);
				minimal++;
			}
		}

		return minimal;
	}

	public boolean makeValue(int minIndex, int currentValue, int max) {
		for (int i = 0; i < denominations.size(); i++) {
			if (minIndex > i) {
				continue;
			}
			if (denominations.get(i) + currentValue == max) {
				return true;
			} else if (denominations.get(i) + currentValue < max) {
				if (makeValue(i + 1, currentValue + denominations.get(i), max)) {
					return true;
				}
			} else {
				return false;
			}
		}
		return false;
	}

	public void writeOutput(int casenr, String output) throws IOException {
		w.write("Case #" + Integer.toString(casenr) + ": " + output + "\n");
		System.out.println("Case #" + Integer.toString(casenr) + ": " + output
				+ "\n");
	}

}