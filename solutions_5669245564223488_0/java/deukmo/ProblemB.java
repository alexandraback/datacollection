import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.BitSet;
import java.util.Scanner;

public class ProblemB {
    private static final String INPUT_FILENAME = "B-small-attempt0.in";
    private static final String OUTPUT_FILENAME = "B-small-attempt0.out";
    
    private static final int MOD = (int) 1e9 + 7;

	public static void main(String[] args) throws Exception {
		Scanner input = new Scanner(new FileReader(INPUT_FILENAME));
        PrintWriter output = new PrintWriter(new FileWriter(OUTPUT_FILENAME));
            
        int numberOfTestCase = input.nextInt();
        for (int caseNum=1; caseNum<=numberOfTestCase; caseNum++) {
        	int[] occur = new int[26];
        	Arrays.fill(occur, 0);
        	
        	int N = input.nextInt();
        	String[] sets = new String[N];
        	for (int i=0; i<N; i++) {
        		sets[i] = input.next();
        		for(int j=0; j<sets[i].length(); j++) {
        			occur[sets[i].charAt(j) - 'a']++;
        		}
        	}
        	
        	int res = 0;
        	BitSet s = new BitSet();
        	res += getCnt(sets, "", s, occur, 0, N);
        	
        	output.format("Case #%d: %d\n", caseNum, res, N);
        }
        
        input.close();
        output.close();
	}
	
	public static int getCnt(String[] sets, String str, BitSet s, int[] occur, int cnt, int N) {
		if (cnt == N) {
			char c;
			for (int i=0; i<str.length();) {
				c = str.charAt(i);
				for (int j=1; j<occur[c - 'a']; j++) {
					if (str.charAt(i+j) != c) {
						return 0;
					}
				}
				i += occur[c - 'a'];
			}
			
			return 1;
		}
		
		int res = 0;
		for (int i=0; i<N; i++) {
			if (!s.get(i)) {
				s.set(i);
				res = (res + getCnt(sets, str + sets[i], s, occur, cnt + 1, N)) % MOD;
				s.clear(i);
			}
		}
		return res % MOD;
	}
}
