import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.util.Arrays;
import java.util.Scanner;

public class RecycledNumbersSmall {

	public static void main(String[] args) {

		File file = new File("/Users/NoK/Desktop/C-small-attempt0.in");
		int counter = 1;

		try {
			Scanner sc = new Scanner(file);

			int numOfCases = sc.nextInt();

			sc.nextLine();

			for (int i = 0; i < numOfCases; i++) {
				int integerN = sc.nextInt();
				int integerM = sc.nextInt();
				int numOfRecPairs = 0;
				for (int m = integerN; m <= integerM; m++) {
					String stringM = Integer.toString(m);
					int[] checkerArray = new int[stringM.length()-1];
					for (int j = 0; j < checkerArray.length; j++) {
						checkerArray[j] = -1;
					}
					int index = 0;
					for (int n = 0; n < stringM.length()-1; n++) {
						char tmpChar = stringM.charAt(stringM.length()-1);
						stringM = Character.toString(tmpChar) + stringM.substring(0, stringM.length()-1);
						if (stringM.charAt(0) != '0') {
							int newIntegerM = Integer.parseInt(stringM);
							if ((newIntegerM >= integerN) && (newIntegerM <= integerM)) {
								if (newIntegerM > m) {
									int k = 0;
									boolean exists = false;
									while (k < checkerArray.length) {
										if (checkerArray[k] == newIntegerM) {
											exists = true;
										}
										k++;
									}
									if (exists == false) {
										checkerArray[index] = newIntegerM;
										index++;
										numOfRecPairs++;
									}
								}
							}
						}
					}
				}

				try { 
					FileWriter fw = new FileWriter("/Users/NoK/Desktop/C-small-attempt0.out", true);
					BufferedWriter bw = new BufferedWriter(fw);
					System.out.println("Case #" + counter + ": " + numOfRecPairs);
					bw.write("Case #" + counter + ": " + numOfRecPairs);
					bw.newLine();
					bw.close();
					counter++;
				} catch (Exception e){
					System.err.println("Error: " + e.getMessage());
				}

			}

		} catch (FileNotFoundException e ) {
			e.printStackTrace();
		}

	}

}