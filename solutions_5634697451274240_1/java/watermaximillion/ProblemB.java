import java.io.*;
import java.util.*;

public class ProblemB {

	public static void main(String[] args) throws NumberFormatException, IOException {
		Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
		int numCases = Integer.parseInt(in.nextLine());
		for (int caseNum = 1; caseNum <= numCases; caseNum++) {
			String line = in.nextLine();
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
			printAnswer("" + flips, caseNum);
		}
	}

	public static void printAnswer(String answer, int caseNumber) throws IOException {
		System.out.println("Case #" + caseNumber + ": " + answer);
	}
}
