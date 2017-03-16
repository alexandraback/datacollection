package jck.codejam.cj2014.qualification;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.text.DecimalFormat;
import java.text.NumberFormat;
import java.util.Arrays;
import java.util.Locale;

public class ProblemD {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		//String filenameInput = "D-sample.in";
		//String filenameOutput = "D-sample.out";
		 String filenameInput = "D-small-attempt0.in";
		 String filenameOutput = "D-small-attempt0.out";
		// String filenameInput = "D-large.in";
		// String filenameOutput = "D-large.out";

		Class currentClass = ProblemD.class;
		try {

			String path = "src/"
					+ currentClass.getPackage().getName().replace(".", "/");
			BufferedReader input = new BufferedReader(new FileReader(new File(
					path + "/" + filenameInput)));
			BufferedWriter output = new BufferedWriter(new FileWriter(new File(
					path + "/" + filenameOutput)));
			int numOfTestcases = Integer.parseInt(input.readLine());
			System.out.println("Number of Testcases: " + numOfTestcases);
			NumberFormat nf = NumberFormat.getNumberInstance(Locale.ENGLISH);
			DecimalFormat df = (DecimalFormat) nf;
			df.setMinimumFractionDigits(6);

			for (int i = 0; i < numOfTestcases; i++) {
				// System.out.println("Testnumber : " + i);
				int numberOfBlocks = Integer.parseInt(input.readLine());
				String[] naomiStrings = input.readLine().split(" ");
				String[] kenStrings = input.readLine().split(" ");
				double[] naomi = new double[numberOfBlocks];
				double[] ken = new double[numberOfBlocks];
				for (int j = 0; j < numberOfBlocks; j++) {
					ken[j] = Double.parseDouble(kenStrings[j]);
					naomi[j] = Double.parseDouble(naomiStrings[j]);
				}
				Arrays.sort(ken);
				Arrays.sort(naomi);
				//System.out.println("naomi: " + Arrays.toString(naomi));
				//System.out.println("ken: " + Arrays.toString(ken));
				int fair = 0;
				//int jkenlower = 0;
				int jkenhigher = numberOfBlocks-1;
				for (int j = numberOfBlocks-1; 0<=j  ; j--) {
					if (naomi[j] > ken[jkenhigher]) {
						fair++;
						//jkenlower++;
					}else{
						jkenhigher--;
					}
				}
				int deceitful = 0;
					int jk=0;
					for(int jn =0;jn<numberOfBlocks;jn++){
						if(naomi[jn]>ken[jk]){
							deceitful++;
							jk++;
						}
					}

				String outputString = "Case #" + (i + 1) + ": " + deceitful
						+ " " + fair;
				System.out.println(outputString);

				if (i + 1 != numOfTestcases) {
					outputString += "\n";
				}
				output.write(outputString);

			}

			output.flush();
			output.close();
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

	}

}
