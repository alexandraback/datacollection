import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.math.BigInteger;
import java.util.Scanner;


public class Bullseye {
	
	public static void main(String[] args) {
		long start = System.currentTimeMillis();
		String inputFilename = "A-small-attempt0.in";
		StringBuilder answer = new StringBuilder();
		try {
			FileInputStream fis = new FileInputStream(inputFilename);
			Scanner sc = new Scanner(fis);
			int testCases = sc.nextInt();
			for (int i=1; i<=testCases; i++) {
				long firstRad = sc.nextLong();
				long paintML = sc.nextLong(); 
				String ans = solve(firstRad, paintML);
				answer.append("Case #" + i + ": " + ans + System.lineSeparator());
			}
			sc.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
		writeOutput(answer.toString());
		System.out.println("in " + (System.currentTimeMillis() - start));
	}
	
	private static String solve(long firstRad, long paintML) {
		int numOfRings = 0;
		while (paintML > 0) {
			long areaOfBlackRing = (firstRad + 1) * (firstRad + 1) - (firstRad * firstRad); 
			if (paintML >= areaOfBlackRing) {
				numOfRings++;
				firstRad = firstRad + 2;
			}
			paintML = paintML - areaOfBlackRing;
		}
		return "" + numOfRings;
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
