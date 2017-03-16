package codejam2015;
import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class ProblemD {

	public static void main(String[] args) throws NumberFormatException, IOException {
		FileWriter writer = new FileWriter("C:\\Users\\mchang\\workspace\\Google Code Jam\\src\\output.txt");
		String filename = "C:\\Users\\mchang\\workspace\\Google Code Jam\\src\\input.txt";
		try {
			BufferedReader br = new BufferedReader(new FileReader(filename));
			int numCases = Integer.parseInt(br.readLine());
			for (int caseNum = 1; caseNum <= numCases; caseNum++) {
				String line = br.readLine();
				Scanner sc = new Scanner(line);
				long k = Long.parseLong(sc.next());
				long c = Long.parseLong(sc.next());
				long s = Long.parseLong(sc.next());
				if(c == 1){
					if(s >= k){
						String answer = "";
						for (int i = 1; i <= k; i++){
							answer += i + " ";
						}
						printAnswer(answer.trim(), caseNum, writer);
					} else {
						printAnswer("IMPOSSIBLE", caseNum, writer);
					}
				} else {
					if(2*s >= k){
						String answer = "";
						for(long i = 1; i <= k; i++){
							if(i % 2 == 1){
								long group = i;
								long pos = (i % k) + 1;
								answer += getPosition(group, pos, k, c) + " ";
							}
						}
						printAnswer(answer.trim(), caseNum, writer);
					} else {
						printAnswer("IMPOSSIBLE", caseNum, writer);
					}
				}
			}
			br.close();
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		writer.close();
	}

	public static long getPosition(long group, long pos, long k, long c){
		return (group - 1) * (long) Math.pow(k, c - 1) + pos;
	}
	
	public static void printAnswer(String answer, int caseNumber,
			FileWriter writer) throws IOException {
		writer.write("Case #" + caseNumber + ": " + answer + "\n");
	}
}
