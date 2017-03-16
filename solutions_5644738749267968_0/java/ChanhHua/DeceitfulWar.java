package Qualification;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class DeceitfulWar {
	
	private static String WORKING_DIR = "D:\\Working\\CodeJam\\Qualification\\";

	static double[] naoNiBlock;
	static double[] kenBlock;
	
	public static void main(String[] args) {

		try {
			Scanner sc = new Scanner(new File(WORKING_DIR + "input.txt"));
			PrintWriter pw = new PrintWriter(new File(WORKING_DIR + "output.txt"));
			int numCase = sc.nextInt();
			for (int i = 0 ; i<numCase ; i++) {
				
				int numBlock = sc.nextInt();
				
				naoNiBlock = new double[numBlock];
				for (int j=0; j<numBlock; j++) {
					naoNiBlock[j] = sc.nextDouble();
				}
				
				Arrays.sort(naoNiBlock);
				
				kenBlock = new double[numBlock];
				for (int j=0; j<numBlock; j++) {
					kenBlock[j] = sc.nextDouble();
				}
				
				Arrays.sort(kenBlock);
				
				int dWarRes = dWar();
				int warRes = war();
				
				pw.write("Case #" + (i+1) + ": " + dWarRes + " " + warRes + "\n");

			}
			pw.flush();
			pw.close();
			sc.close();
			System.out.println("Done!");
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}

	}

	private static int dWar() {
		int count = 0;
		int markN = 0;
		int markK = 0;
		
		while (markN < naoNiBlock.length && markK < kenBlock.length) {
			for (int i=markN; i<naoNiBlock.length; i++) {
				if (kenBlock[markK] < naoNiBlock[i]) {
					markN = i+1;
					count++;
					break;
				}
			}
			markK++;
		}
		return count;
	}
	
	private static int war() {
		int count = 0;
		int markN = 0;
		int markK = 0;
		
		while (markN < naoNiBlock.length && markK < kenBlock.length) {
			for (int i=markK; i<kenBlock.length; i++) {
				if (kenBlock[i] > naoNiBlock[markN]) {
					markK = i+1;
					count++;
					break;
				}
			}
			markN++;
		}
		return kenBlock.length - count;
	}

}
