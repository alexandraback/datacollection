package pd;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;
import java.util.List;

public class pd {
	static String INPUT_FILE = "D-large.in";
	static String OUTPUT_FILE = "pd_large.out";
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		try {
			BufferedReader in = new BufferedReader(new FileReader(INPUT_FILE));
			BufferedWriter out = new BufferedWriter(new FileWriter(OUTPUT_FILE, true));
			
			int caseNumber = Integer.valueOf(in.readLine());
			
			for (int i = 1; i <= caseNumber; i++) {
				int n = Integer.valueOf(in.readLine());
				
				String[] tempArr = in.readLine().split(" ");
				double[] boxList1 = new double[tempArr.length];
				for (int j = 0; j < tempArr.length; j++) {
					boxList1[j] = Double.parseDouble(tempArr[j]);
				}
				
				tempArr = in.readLine().split(" ");
				double[] boxList2 = new double[tempArr.length];
				for (int j = 0; j < tempArr.length; j++) {
					boxList2[j] = Double.parseDouble(tempArr[j]);
				}
				
				Arrays.sort(boxList1);
				Arrays.sort(boxList2);
				System.out.println();
				
				out.write("Case #" + i + ": ");
				int a, b, count;
				for (a = b = count = 0; a < boxList1.length ; a++) {
					if (boxList1[a] > boxList2[b]) {
						count++;
						b++;
					}
				}
				out.write(count + " ");
				
				for (a = b = count = 0; a < boxList1.length ; a++) {
					if (boxList2[a] > boxList1[b]) {
						count++;
						b++;
					}
				}
				out.write((boxList1.length - count) + "\n");
			}
			out.close();
			in.close();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
	}

}
