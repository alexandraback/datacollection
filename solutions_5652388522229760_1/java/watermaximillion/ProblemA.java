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
				int n = Integer.parseInt(line);
				boolean[] seen = new boolean[10];
				int value = 0;
				int checkedOff = 0;
				if(n == 0){
					printAnswer("INSOMNIA", caseNum, writer);
					continue;
				}
				while(checkedOff < 10){
					value += n;
					String s = "" + value;
					for(int i = 0; i < 10; i++){
						if(!seen[i]){
							if(s.contains("" + i)){
								seen[i] = true;
								checkedOff++;
							}
						}
					}
				}
				
				printAnswer("" + value, caseNum, writer);
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
