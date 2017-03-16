import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


public class Round1BPB {

	/**
	 * @param args
	 * @throws IOException 
	 * @throws NumberFormatException 
	 */
	public static void main(String[] args) throws NumberFormatException, IOException {
//		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedReader br = new BufferedReader(new FileReader("input.txt"));
		int numberOfTestCases = Integer.valueOf(br.readLine());
		for(int testCase = 1; testCase <= numberOfTestCases; testCase++) {
			int a,b,k;
			StringTokenizer st = new StringTokenizer(br.readLine());
			a = Integer.valueOf(st.nextToken());
			b = Integer.valueOf(st.nextToken());
			k = Integer.valueOf(st.nextToken());
			int total = 0;
			for(int a1 = 0; a1 < a; a1++) {
				for(int b1 = 0; b1 < b; b1++) {
					int result = a1 & b1;
					if(result < k) {
						total++;
					}
				}
			}
			System.out.println("Case #" + testCase + ": " + total);
		}
	}

}
