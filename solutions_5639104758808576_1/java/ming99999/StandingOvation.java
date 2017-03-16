import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;


public class StandingOvation {

	
	
	public static void solution(String inputFile, String outputFile) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader(new File(inputFile)));
		PrintWriter pw = new PrintWriter(new FileWriter(new File(outputFile)));
		String line = br.readLine();
		int N = Integer.parseInt(line);
		int id = 1;
		while ((line = br.readLine()) != null) {
			String[] lineSplit = line.split(" ");
			int shyMax = Integer.parseInt(lineSplit[0]);
			int []shyNum = new int[shyMax+1];
			for (int i = 0; i <= shyMax; ++i) {
				shyNum[i] = Character.getNumericValue(lineSplit[1].charAt(i));
			}
			int sup = calculate(shyNum);
			pw.println("Case #"+id+": "+sup);
			id++;
		}
		br.close();
		pw.close();
	}
	
	public static int calculate(int[] shyNum) {
		int sup = 0;
		int sum = 0;
		for (int i = 0; i < shyNum.length; ++i) {
			if (shyNum[i] == 0) continue;
			if (sum < i) {
				sup += (i-sum);
				sum += (i-sum);
			}
			sum += shyNum[i];
			
		}
		return sup;
	}
	
	public static void main(String[] args) throws IOException {
		String inputFile = "src/StandingOvation.in";
		String outputFile = "src/StandingOvation.out";
		StandingOvation.solution(inputFile, outputFile);
	}
}
