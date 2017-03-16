package round1;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class PartElf {
static String inFileName, outFileName;
	
	public static void main(String[] args) {
		inFileName = "A-small-attempt1.in";
//		inFileName = "test.txt";
		outFileName = inFileName + ".out"; 
		
		try {
			BufferedReader in = new BufferedReader(new FileReader("PartElf\\" + inFileName));
			solveProblem(in);
		} catch (FileNotFoundException e1) {
			e1.printStackTrace();
		}
		catch (IOException e2) {
			e2.printStackTrace();
		}
	}
	private static void solveProblem(BufferedReader in) throws IOException {
		BufferedWriter out = new BufferedWriter(new FileWriter("PartElf\\" + outFileName));
		
		int numCases = Integer.parseInt(in.readLine());
		int i;
		for (i = 0; i < numCases; i++) {
			String[] fraction = in.readLine().split("/");
			int numGen = -1;
			int minNumGen = -1;
			int numerator, denominator;
			numerator = Integer.parseInt(fraction[0]);
			denominator = Integer.parseInt(fraction[1]);
			
			if (denominator%2 == 0) {
				for (numGen = 0; numGen < 41; numGen++) {
					if (numerator < denominator/2) {
						numerator *= 2;
					}
					else if (numerator > denominator/2){
						if (minNumGen == -1)
							minNumGen = numGen + 1;
						numerator = numerator - denominator/2;
					}
					else {
						numGen++;
						if (minNumGen == -1)
							minNumGen = numGen;
						break;
					}
				}
			}
			
			if (numGen > 0 && numGen <= 40)
				out.write("Case #" + (i + 1) + ": " + minNumGen + "\n");
			else
				out.write("Case #" + (i + 1) + ": impossible\n");
		}
		
		in.close();
		out.close();
	}
	
}
