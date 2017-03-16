package codejam2015;
import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class ProblemA {

	public static void main(String[] args) throws NumberFormatException, IOException {
		FileWriter writer = new FileWriter("C:\\Users\\mchang\\workspace\\Google Code Jam\\src\\output.txt");
		String filename = "C:\\Users\\mchang\\workspace\\Google Code Jam\\src\\input.txt";
		try {
			BufferedReader br = new BufferedReader(new FileReader(filename));
			int numCases = Integer.parseInt(br.readLine());
			for (int caseNum = 1; caseNum <= numCases; caseNum++) {
				String line = br.readLine();
				Scanner sc = new Scanner(line);
				int maxS = Integer.parseInt(sc.next());
				int maxNeeded = 0;
				int totalStanding = 0;
				String digitString = sc.next();
				for(int i = 0; i < maxS + 1; i++){
					int digit = digitString.charAt(i) - '0';
					if(totalStanding < i){
						int additionalNeeded = i - totalStanding;
						if(additionalNeeded > maxNeeded){
							maxNeeded = additionalNeeded;
						}
					}
					totalStanding += digit;
				}
				printAnswer("" + maxNeeded, caseNum, writer);
			}
			br.close();
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		writer.close();
	}

	public static void printAnswer(String answer, int caseNumber,
			FileWriter writer) throws IOException {
		writer.write("Case #" + caseNumber + ": " + answer + "\n");
	}
}
