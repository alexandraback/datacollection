package gcj14;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.Set;

public class Enclosure {

	private int getAnswer(int n, int m, int k) {
		if (n == 1 || m == 1 || n == 2 || m == 2) return k;
		
		if (n == 3 && m == 3) {
			if (k <= 4) return k;
			if (k == 5) return 4;
			
			return 4 + k - 5;
		}
		
		if ((n == 3 && m == 4) || (n == 4 && m == 3)) {
			if (k <= 4) return k;
			if (k == 5) return 4;
			if (k == 6) return 5;
			if (k == 7 || k == 8) return 6; 
			
			return 6 + k - 8;
		}
		
		if ((n == 3 && m == 5) || (n == 5 && m == 3)) {
			if (k <= 4) return k;
			if (k == 5) return 4;
			if (k == 6) return 5;
			if (k == 7 || k == 8) return 6; 
			if (k == 9) return 7;
			if (k == 10 || k == 11) return 8;
			if (k == 12) return 9;
			if (k == 13 || k == 14) return 10;
			return 10 + k - 14;
		} 
		
		if (n == 4 && m == 4) {
			if (k <= 4) return k;
			if (k == 5) return 4;
			if (k == 6) return 5;
			if (k == 7 || k == 8) return 6; 
			if (k == 9) return 7;
			if (k == 10 || k == 11 || k == 12) return 8;
			
			return 8 + k - 12;
		}
		
		if (k <= 4) return k;
		if (k == 5) return 4;
		if (k == 6) return 5;
		if (k == 7 || k == 8) return 6; 
		if (k == 9) return 7;
		if (k == 10 || k == 11 || k == 12) return 8;
		if (k == 13) return 9;
		if (k == 14 || k == 15 || k == 16) return 10;
		
		return 10 + k - 16;
	}


	public static final String INPUT_FILE_PATH = "C://DiskD//CodeJamInput.txt";
	public static final String OUTPUT_FILE_PATH = "C://DiskD//CodeJamOutput.txt";

	public static void main(String[] args) {
		Scanner in = null;
		PrintWriter writer = null;
		try {
			System.out.println("start");

			in = new Scanner(new File(INPUT_FILE_PATH));
			writer = new PrintWriter(new FileWriter(OUTPUT_FILE_PATH));
			int testCount = in.nextInt();

			for (int i = 0; i < testCount; i++) {
				int n = in.nextInt();
				int m = in.nextInt();
				int k = in.nextInt();

				System.out.println(i);
				writer.println("Case #" + (i + 1) + ": " + new Enclosure().getAnswer(n, m, k));
			}
			writer.flush();

			System.out.println("end");
		} catch (IOException ex) {
			ex.printStackTrace();
		} finally {
			if (in != null) in.close();
			if (writer != null) writer.close();
		}
	}

}
