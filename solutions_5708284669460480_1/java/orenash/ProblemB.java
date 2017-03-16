import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;


public class ProblemB {
static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	
	

	
	public static void main(String[] args) throws Exception {
		
		int T = readInt();
		
		for (int caseNum=1; caseNum<=T; caseNum++) {
			int[] prm = readInts();
			int K = prm[0];
			int L = prm[1];
			int S = prm[2];
			
			String letters = br.readLine();
			String word = br.readLine();
			
			double total = Math.pow(K, S);
			
			int wordPos = 1;
			Map<Character, Integer> charCounts = new HashMap<Character, Integer>();
			for (int i=0; i<letters.length(); i++) {
				char c = letters.charAt(i);
				if (!charCounts.containsKey(c)) {
					charCounts.put(c, 1);
				} else {
					charCounts.put(c, charCounts.get(c)+1);
				}
			}
			for (int i=0; i<word.length(); i++) {
				char c = word.charAt(i);
				if (!charCounts.containsKey(c)) {
					wordPos = 0;
					break;
				} else {
					wordPos *= charCounts.get(c);
				}
			}
			
			double count = (S-L+1) * Math.pow(K, S-L) * wordPos;

			
			
			int max = 0;
			int i;
			if (wordPos>0) {
				for (i=1; i<word.length(); i++) {
					if (word.startsWith(word.substring(i)))
						break;
				}
				while (S>=L) {
					S-=i;
					max++;
				}
			}
			
			double result = max - (double)count/total;
			
			System.out.println(String.format("Case #%d: %f", caseNum, result));
		}

	}
	


	private static int readInt() throws IOException {
		return Integer.parseInt(br.readLine());
	}
	
	private static int[] readInts() throws IOException {
		return Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
	}
}
