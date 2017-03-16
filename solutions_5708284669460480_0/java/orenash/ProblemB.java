import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;


public class ProblemB {
static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	
	
	static int total = 0;
	static int count = 0;
	static int max = 0;
	
	public static void main(String[] args) throws Exception {
		
		int T = readInt();
		
		for (int caseNum=1; caseNum<=T; caseNum++) {
			int[] prm = readInts();
			int K = prm[0];
			int L = prm[1];
			int S = prm[2];
			
			String letters = br.readLine();
			String word = br.readLine();
			
			total = count = max = 0;
			tryAll("", letters, word, S);
			
			double result = max - (double)count/total;
			
			System.out.println(String.format("Case #%d: %f", caseNum, result));
		}

	}
	

	private static void tryAll(String str, String letters, String word, int S) {
		if (str.length() < S) {
			for (int i=0; i<letters.length(); i++) {
				String str2 = str + letters.charAt(i);
				tryAll(str2, letters, word, S);
			}
		} else {
			total++;
			int c = 0;
			int i=-1;
			do {
				i = str.indexOf(word,i+1);
				if (i>=0) c++;
			} while(i>=0);
			count+=c;
			max = Math.max(max,c);
		}
		
	}


	private static int readInt() throws IOException {
		return Integer.parseInt(br.readLine());
	}
	
	private static int[] readInts() throws IOException {
		return Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
	}
}
