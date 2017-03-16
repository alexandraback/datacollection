import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.Iterator;
import java.util.StringTokenizer;

public class Problem1CC {

	public static void main(String[] args) throws NumberFormatException,
			IOException {
		FileWriter writer = new FileWriter(
				"C:\\Users\\mchang\\workspace\\Google Code Jam\\src\\output.txt");
		String filename = "C:\\Users\\mchang\\workspace\\Google Code Jam\\src\\input.txt";
		long startTime = System.currentTimeMillis();
		try {
			BufferedReader br = new BufferedReader(new FileReader(filename));
			int numCases = Integer.parseInt(br.readLine());
			for (int caseNum = 1; caseNum <= numCases; caseNum++) {
				StringTokenizer st = new StringTokenizer(br.readLine());
				int n = Integer.parseInt(st.nextToken());
				int m = Integer.parseInt(st.nextToken());
				int k = Integer.parseInt(st.nextToken());
				int min = Math.min(m, n);
				int max = Math.max(m, n);
				if(min <= 2){
					printAnswer("" + k, caseNum, writer);
				} else if (min == 3){
					if(max == 3){
						if(k < 5){
							printAnswer("" + k, caseNum, writer);
						} else {
							printAnswer("" + (k - 1), caseNum, writer);
						}
					} else if(max == 4){
						if(k < 5){
							printAnswer("" + k, caseNum, writer);
						} else if(k < 8){
							printAnswer("" + (k - 1), caseNum, writer);
						} else {
							printAnswer("" + (k - 2), caseNum, writer);
						}
					} else if(max == 5){
						if(k < 5){
							printAnswer("" + k, caseNum, writer);
						} else if(k < 8){
							printAnswer("" + (k - 1), caseNum, writer);
						} else if(k < 11){
							printAnswer("" + (k - 2), caseNum, writer);
						} else {
							printAnswer("" + (k - 3), caseNum, writer);
						}
					} else {
						if(k < 5){
							printAnswer("" + k, caseNum, writer);
						} else if(k < 8){
							printAnswer("" + (k - 1), caseNum, writer);
						} else if(k < 11){
							printAnswer("" + (k - 2), caseNum, writer);
						} else if(k < 14){
							printAnswer("" + (k - 3), caseNum, writer);
						} else {
							printAnswer("" + (k - 4), caseNum, writer);
						}
					}
				} else {
					if(max == 4){
						if(k < 5){
							printAnswer("" + k, caseNum, writer);
						} else if(k < 8){
							printAnswer("" + (k - 1), caseNum, writer);
						} else if(k < 10){
							printAnswer("" + (k - 2), caseNum, writer);
						} else if(k < 12){
							printAnswer("" + (k - 3), caseNum, writer);
						} else {
							printAnswer("" + (k - 4), caseNum, writer);
						}
					} else {
						if(k < 5){
							printAnswer("" + k, caseNum, writer);
						} else if(k < 8){
							printAnswer("" + (k - 1), caseNum, writer);
						} else if(k < 10){
							printAnswer("" + (k - 2), caseNum, writer);
						} else if(k < 12){
							printAnswer("" + (k - 3), caseNum, writer);
						} else if(k < 14){
							printAnswer("" + (k - 4), caseNum, writer);
						} else if(k < 16){
							printAnswer("" + (k - 5), caseNum, writer);
						} else {
							printAnswer("" + (k - 6), caseNum, writer);
						}
					}
				}
			}
			br.close();
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		writer.close();
		System.out.println(System.currentTimeMillis() - startTime);
	}

	public static void printAnswer(String answer, int caseNumber,
			FileWriter writer) throws IOException {
		writer.write("Case #" + caseNumber + ": " + answer + "\n");
	}

	
}
