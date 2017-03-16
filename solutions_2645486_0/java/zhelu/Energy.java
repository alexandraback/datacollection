import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class Energy {

	static void readInInputWriteOutput(String input, String output)
			throws IOException {
		Scanner sc = new Scanner(new File(input));
		BufferedWriter bw = new BufferedWriter(new FileWriter(output));
		int cases = sc.nextInt();
		for (int i = 1; i <= cases; i++) {
			int start = sc.nextInt();
			int regain = sc.nextInt();
			int numActivities = sc.nextInt();
			int values[] = new int[numActivities];
			for (int j = 0; j < numActivities; j++) {
				values[j] = sc.nextInt();
			}
			int score = maxEnergy(start, regain, values);
			System.out.println("Case #" + i + ": " + score);
			bw.write("Case #" + i + ": " + score);
			if (i != cases)
				bw.newLine();
		}
		sc.close();
		bw.close();
	}


	static int search(int amount, int regain, int[] values, int activity,
			int score, int max) {
		if (activity == values.length - 1) {
			return score + amount * values[activity];
		} else {
			int best = 0;
			for (int e = 0; e <= amount; e++) {
				int newA = amount - e + regain;
				int s;
				if (newA > max)
					newA = max;
				if (newA == 0) {
					s = score + values[activity] * e;
				} else {
					s = search(newA, regain, values,
							activity + 1, score + values[activity] * e, max);
				}
				if (s > best) {
					best = s;
				}
			}
			return best;
		}
	}


	static int maxEnergy(int start, int regain, int[] values) {
		return search(start, regain, values, 0, 0, start);
	}


	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		readInInputWriteOutput("Energy-small.in", "Energy-small-out.txt");
	}

}
