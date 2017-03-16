import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.util.Scanner;


public class Energy {
	
	public static void main(String[] args) {
		long start = System.currentTimeMillis();
		String inputFilename = "B-small-attempt0.in";
		StringBuilder answer = new StringBuilder();
		try {
			FileInputStream fis = new FileInputStream(inputFilename);
			Scanner sc = new Scanner(fis);
			int testCases = sc.nextInt();
			for (int i=1; i<=testCases; i++) {
				int maxE = sc.nextInt();
				int regain = sc.nextInt();
				int numOfActivities = sc.nextInt();
				int[] activities = new int[numOfActivities];
				for (int j=0; j<numOfActivities; j++) {
					activities[j] = sc.nextInt();
				}
				String ans = solve(maxE, regain, activities);
				answer.append("Case #" + i + ": " + ans + System.lineSeparator());
			}
			sc.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
		writeOutput(answer.toString());
		System.out.println("in " + (System.currentTimeMillis() - start));
	}
	
	
	private static String solve(int maxE, int regain, int[] activities) {
		int result = 0;
		if (maxE <= regain) {
			int sum = 0;
			for (int i=0; i<activities.length; i++) {
				sum += activities[i];
			}
			result = maxE * sum;
		}
		else {
			result = solve(maxE, maxE, regain, activities, 0, 0);
		}
		return "" + result;
	}


	private static int solve(int maxE, int currE, int regain, int[] activities, int index, int acc) {
		if (index == activities.length-1) return (acc + (currE * activities[index]));
		int max = 0;
		int startFrom = 0;
		if (maxE < (currE + regain))
			startFrom = (currE + regain) - maxE;
		for (int j=startFrom; j<=currE; j++) {
			int result = solve(maxE, currE+regain-j, regain, activities, index+1, (j*activities[index]) + acc);
			if (result > max)
				max = result;
		}
		return max;
	}


	private static void writeOutput(String string) {
		try {
			String outputFilename = "output.txt";
			BufferedWriter bw = new BufferedWriter(new FileWriter(outputFilename));
			bw.write(string);
			bw.close();
			System.out.println("success!");
		} catch (Exception e) {
			System.out.println("error!");
		}
	}
}
