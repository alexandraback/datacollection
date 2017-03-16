package round1;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class TrainCars {
static String inFileName, outFileName;
	
	public static void main(String[] args) {
//		inFileName = "D-large.in";
		inFileName = "B-small-attempt0.in";
		outFileName = inFileName + ".out"; 
		
		try {
			BufferedReader in = new BufferedReader(new FileReader("TrainCars\\" + inFileName));
			solveProblem(in);
		} catch (FileNotFoundException e1) {
			e1.printStackTrace();
		}
		catch (IOException e2) {
			e2.printStackTrace();
		}
	}
	private static void solveProblem(BufferedReader in) throws IOException {
		BufferedWriter out = new BufferedWriter(new FileWriter("TrainCars\\" + outFileName));
		
		int numCases = Integer.parseInt(in.readLine());
		int i;
		for (i = 0; i < numCases; i++) {
			int[][] cars = new int[26][26];
			for (int n = 0; n < 26; n++) {
				for (int j = 0; j < 26; j++) {
					cars[n][j] = 0;
				}
			}
			int numCars = Integer.parseInt(in.readLine());
			String[] carStrs = in.readLine().split(" ");
			
			for (String carStr : carStrs) {
				char carStart = carStr.charAt(0);
				char carEnd = carStr.charAt(carStr.length() - 1);
				System.out.println(carStart + " " + carEnd);
				cars[carStart - 'a'][carEnd - 'a']++;
			}
			
			int carLength = 0;
			for (int n = 0; n < 26; n++) {
				for (int j = 0; j < 26; j++) {
					if (cars[n][j] > 0) {
						for (int k = 0; k < 26; k++) {
							if (cars[j][k] > 0) {
								if (carLength == 0) {
									carLength = cars[j][k] * cars[n][j];
								}
								else {
									carLength = carLength * cars[j][k] * cars[n][j];
								}
							}
						}
					}
				}
			}
			
			out.write("Case #" + (i + 1) + ": " + carLength + "\n");
		}
		
		in.close();
		out.close();
	}
}
