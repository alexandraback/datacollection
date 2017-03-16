import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;


public class Problem2 {
	public static void main (String[] args) throws IOException {
		File file = new File("input.txt");
		Scanner scan = null;
		try {
			scan = new Scanner(file);
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		FileWriter fstream = null;
		try {
			fstream = new FileWriter("output.txt");
		} catch (IOException e) {
			e.printStackTrace();
		}
		BufferedWriter out = new BufferedWriter(fstream);
		
		int lineNumber;
		lineNumber = Integer.parseInt(scan.nextLine());
		for (int i = 0; i < lineNumber; i++) {
			Scanner lineScan = new Scanner(scan.nextLine());
			out.write("Case #" + (i + 1) + ": ");
			int n = lineScan.nextInt();
			int s = lineScan.nextInt();
			int p = lineScan.nextInt();
			
			int[] scores = new int[n];
			for (int j = 0; j < n; j++) {
				scores[j] = lineScan.nextInt();
			}
			
			int total = 0;
			for (int j = 0; j < n; j++) {
				if (scores[j] == 0) { 
					if (p == 0) {
						total ++; 
					}
					continue;
				}
				
				if (scores[j]/3 >= p) {
					total++;
				} else if (scores[j]/3 == p-1) {
					if (scores[j]%3 >= 1) {
						total++;
					} else {
						if (s > 0) {
							s--;
							total++;
						}
					}
					
				} else if (scores[j]/3 == p-2) {
					if (scores[j]%3 >= 2) {
						if (s > 0) {
							s--;
							total++;
						}
					}
				}
			}
			
			out.write(total + " \n");
		}
		out.close();
		
	}

}
