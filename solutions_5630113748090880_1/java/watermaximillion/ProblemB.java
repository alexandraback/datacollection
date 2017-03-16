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
				int n = Integer.parseInt(line);
				boolean[] odd = new boolean[2501];
				boolean[] used = new boolean[2501];
				for(int i = 0; i < 2*n - 1; i++){
					line = br.readLine();
					Scanner sc = new Scanner(line);
					while(sc.hasNext()){
						int num = Integer.parseInt(sc.next());
						used[num] = true;
						odd[num] = !odd[num];
					}
				}
				String result = "";
				for(int i = 0; i < 2501; i++){
					if(used[i] && odd[i]){
						result += i + " ";
					}
				}
				result = result.trim();
				printAnswer(result, caseNum, writer);
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
