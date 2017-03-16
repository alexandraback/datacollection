package jck.codejam.cj2016.qualification;

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
//		String filenameInput = "D-sample.in";
//		String filenameOutput = "D-sample.out";
		 String filenameInput = "D-small-attempt0.in";
		 String filenameOutput = "D-small-attempt0.out";
//		 String filenameInput = "D-large.in";
//		 String filenameOutput = "D-large.out";

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

			for (int i = 0; i < numOfTestcases; i++) {
				// System.out.println("Testnumber : " + i);
				String[] inputAsStrings = input.readLine().split(" ");
				int KInitialWidth  = Integer.parseInt(inputAsStrings[0]);
				int CIterations  = Integer.parseInt(inputAsStrings[1]);
				int SStudents  = Integer.parseInt(inputAsStrings[2]);

				// All this assumes SStudents > KInitialWidth!!! and in the code even SStudents = KInitialWidth
				
				long KToTheC = 1;
				for(int j=0;j<CIterations;j++){
					//O(CIterations) instead of O(log(CIterations)) via squaring, but doesn't matter much here.
					KToTheC  *= KInitialWidth;
				}
				
				long distance = 0;
				if(SStudents>1){
					distance = (KToTheC-1)/(SStudents-1);
				}
				String positions = "";
				long currentPosition = 1;
				for(int j=0;j<SStudents;j++){
					positions += " " + currentPosition;
					currentPosition += distance;
				}
				String outputString = "Case #" + (i + 1) + ": " + positions;
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
