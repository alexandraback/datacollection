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

public class Problem1CA {

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
				String fraction = br.readLine();
				int p = Integer.parseInt(fraction.substring(0, fraction.indexOf('/')));
				int q = Integer.parseInt(fraction.substring(fraction.indexOf('/') + 1));
				int qcopy = q;
				int multiplesOf2 = 0;
				while(qcopy % 2 == 0){
					qcopy /= 2;
					multiplesOf2++;
				}
				if(p % qcopy != 0){
					printAnswer("impossible", caseNum, writer);
				} else {
					int exponent = 0;
					while(q > p * Math.pow(2, exponent)){
						exponent++;
					}
					printAnswer("" + exponent, caseNum, writer);
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
