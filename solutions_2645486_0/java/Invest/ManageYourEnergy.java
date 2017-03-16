import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class ManageYourEnergy {

	private int regain;
	private int[] activities;
	private int energy;

	// LONG!
	private long getMaxGain(int energy, int regain, int[] activities) {
		this.energy = energy;
		this.regain = regain;
		this.activities = activities;
		return rec(energy, 0, 0);
	}

	public int rec(int en, int actNum, int currentProfit) {
		if (actNum == activities.length) {
			return currentProfit;
		}
		int res = 0;
		for (int i = 0; i <= en; i++) {
			if (en - i >= 0) {
				res = Math.max(res, rec(Math.min(en - i + regain, energy), actNum + 1, currentProfit + i * activities[actNum]));
			}
		}
		return res;
	}

	public static final String INPUT_FILE_PATH = "C://DiskD//CodeJamInput.txt";
	public static final String OUTPUT_FILE_PATH = "C://DiskD//CodeJamOutput.txt";

	public static void main(String[] args) {
		Scanner input = null;
		PrintWriter writer = null;
		try {
			System.out.println("start");

			input = new Scanner(new File(INPUT_FILE_PATH));
			int testCount = input.nextInt();
			String[] output = new String[testCount];

			for (int i = 0; i < testCount; i++) {
				int energy = input.nextInt();
				int regain = input.nextInt();
				int[] activities = new int[input.nextInt()];
				for (int j = 0; j < activities.length; j++) {
					activities[j] = input.nextInt();
				}

				System.out.println(i);
				output[i] = "Case #" + (i + 1) + ": " + new ManageYourEnergy().getMaxGain(energy, regain, activities);
			}

			writer = new PrintWriter(new FileWriter(OUTPUT_FILE_PATH));
			for (String line : output) {
				writer.println(line);
			}
			writer.flush();

			System.out.println("end");
		} catch (IOException ex) {
			ex.printStackTrace();
		} finally {
			if (input != null) input.close();
			if (writer != null) writer.close();
		}
	}

}
