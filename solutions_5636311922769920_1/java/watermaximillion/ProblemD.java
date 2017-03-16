import java.io.*;
import java.util.*;

public class ProblemD {

	public static void main(String[] args) throws NumberFormatException, IOException {		
		Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
		int numCases = Integer.parseInt(in.nextLine());
		for (int caseNum = 1; caseNum <= numCases; caseNum++) {
			String line = in.nextLine();
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
					printAnswer(answer.trim(), caseNum);
				} else {
					printAnswer("IMPOSSIBLE", caseNum);
				}
			} else {
				if(c*s >= k){
					String answer = "";
					for(long i = 0; i < k; i++){
						if(i % c == 0){
							answer += getPosition(i, k, c) + " ";
						}
					}
					printAnswer(answer.trim(), caseNum);
				} else {
					printAnswer("IMPOSSIBLE", caseNum);
				}
			}
			//printOptions(k, c);
		}
	}

	public static long getPosition(long start, long k, long c){
		long result = 0;
		for(int i = 0; i < c; i++){
			long pos = ((start + i) % k);
			result += pos*Math.pow(k, i);
		}
		return result + 1;
	}
	
	public static void printAnswer(String answer, int caseNumber) throws IOException {
		System.out.println("Case #" + caseNumber + ": " + answer);
	}
	
	public static void printOptions(long k, long c){
		System.out.println(k + " " + c);
		for(int i = 0; i < Math.pow(2, k); i++){
			String s = Integer.toBinaryString(i);
			while(s.length() < k){
				s = "0" + s;
			}
			String seed = "";
			String gold = "";
			for(int j = 0; j < k; j++){
				if(s.charAt(j) == '0'){
					seed += "G";
				} else {
					seed += "L";
				}
				gold += "G";
			}
			String result = seed;
			for(int level = 1; level < c; level++){
				String newResult = "";
				for(int j = 0; j < result.length(); j++){
					if(result.charAt(j) == 'G'){
						newResult += gold;
					} else{
						newResult += seed;
					}
				}
				result = newResult;
			}
			System.out.println(result);
		}
	}
}
