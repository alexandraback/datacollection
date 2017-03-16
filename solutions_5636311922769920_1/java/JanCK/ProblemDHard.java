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

public class ProblemDHard {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
//		String filenameInput = "D-sample.in";
//		String filenameOutput = "D-sample-hard.out";
//		 String filenameInput = "D-small-attempt0.in";
//		 String filenameOutput = "D-small-attempt0-hard.out";
		 String filenameInput = "D-large.in";
		 String filenameOutput = "D-large-hard.out";

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

				String positions = "";
				
				if(CIterations * SStudents  < KInitialWidth  ){
					positions = "IMPOSSIBLE";
				}else{
					int cDepth = 0;
					System.out.println("K = " + KInitialWidth + " C = " + CIterations + " S = " + SStudents);
					System.out.println("number of students to use " + Math.ceil(((double)KInitialWidth)/CIterations ));
					int counter = 0;
					for(int j = 0;j<((double)KInitialWidth/CIterations );j++){
						System.out.println("current student " + (j+1));
						long powerOfK = 1;
						long position = 0;
						for(int k = 0;k<CIterations;k++){
							position += (counter>KInitialWidth-1?KInitialWidth-1:counter) * powerOfK;
							powerOfK  *= KInitialWidth;
							counter++;
						}
						positions += " " + (position+1);
					}
					
					
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
