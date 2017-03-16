import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigDecimal;
import java.util.Scanner;

public class ProblemB {
	public static void main(String[] args) throws IOException {
		Scanner in = new Scanner(new FileReader("B-small-attempt1.in"));
		FileWriter fstream = new FileWriter("B-small-attempt1.out");
		BufferedWriter out = new BufferedWriter(fstream);
		int numCases = in.nextInt();
		in.nextLine();
		for (int i = 0; i < numCases; i++) {
			int E = in.nextInt(), R = in.nextInt(), N = in.nextInt();
			in.nextLine();
			int[] values = new int[N];
			String s = in.nextLine();
			String[] strs = s.split(" ");
			for (int j = 0; j < N; j++) {
				values[j] = Integer.valueOf(strs[j]);
			}
			out.write("Case #" + String.valueOf(i + 1) + ": "
					+ String.valueOf(maxGain(E, E, R, values, 0, 0)) + "\n");
		}
		out.close();
		in.close();
	}

	public static int maxGain(int maxEnerge, int curEnerge, int reEnerge,
			int[] values, int index, int curValue) {
		if (index == values.length) {
			return curValue;
		}
		int max = 0, temp = 0;
		//System.out.println(maxEnerge + " " + curEnerge + " " + index + " " + curValue);
		for (int i = 0; i <= curEnerge; i++) {
			temp = maxGain(maxEnerge,
					Math.min(curEnerge - i + reEnerge, maxEnerge), reEnerge,
					values, index + 1, curValue + i * values[index]);
			max = Math.max(temp, max);
		}
		return max;
	}
}
