package codejam2015;
import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class ProblemB {

	public static void main(String[] args) throws NumberFormatException, IOException {
		FileWriter writer = new FileWriter("C:\\Users\\mchang\\workspace\\Google Code Jam\\src\\output.txt");
		String filename = "C:\\Users\\mchang\\workspace\\Google Code Jam\\src\\input.txt";
		try {
			BufferedReader br = new BufferedReader(new FileReader(filename));
			int numCases = Integer.parseInt(br.readLine());
			for (int caseNum = 1; caseNum <= numCases; caseNum++) {
				String line = br.readLine();
				boolean[] arr = new boolean[line.length()];
				for(int i = 0; i < line.length(); i++){
					if(line.charAt(i) == '+'){
						arr[i] = true;
					}
				}
				int flips = 0;
				for(int i = line.length() - 1; i >= 0; i--){
					if(!arr[i]){
						if(i == 0){
							flips++;
							arr[i] = true;
						} else {
							if(arr[0]){
								for(int j = 0; j <= i; j++){
									if(arr[j]){
										arr[j] = false;
									} else {
										break;
									}
								}
								flips++;
							}
							boolean[] temp = new boolean[i + 1];
							for(int j = 0; j <= i; j++){
								temp[j] = !arr[i - j];
							}
							for(int j = 0; j <= i; j++){
								arr[j] = temp[j];
							}
							flips++;
						}
						
					}
				}
				printAnswer("" + flips, caseNum, writer);
			}
			br.close();
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		writer.close();
	}

	public static int badSolve(ArrayList<Integer> arr){
		if(arr.size() == 0) return 0;
		if(arr.get(arr.size() - 1) < 4){
			return arr.get(arr.size() - 1);
		}
		ArrayList<Integer> next = new ArrayList<Integer>();
		for(int i = 0; i < arr.size(); i++){
			if(arr.get(i) != 1){
				next.add(arr.get(i) - 1);
			}
		}
		int max = arr.remove(arr.size() - 1);
		int part1 = max/2;
		int part2 = max - part1;
		arr.add(part1); 
		arr.add(part2);
		Collections.sort(arr);
		return Math.min(badSolve(next), badSolve(arr)) + 1; 
	}
	public static void printAnswer(String answer, int caseNumber,
			FileWriter writer) throws IOException {
		writer.write("Case #" + caseNumber + ": " + answer + "\n");
	}
}
