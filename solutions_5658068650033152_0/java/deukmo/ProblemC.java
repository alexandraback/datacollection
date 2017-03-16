import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Scanner;

public class ProblemC {
    private static final String INPUT_FILENAME = "C-small-attempt2.in";
    private static final String OUTPUT_FILENAME = "C-small-attempt2.out";

	public static void main(String[] args) throws Exception {
		Scanner input = new Scanner(new FileReader(INPUT_FILENAME));
        PrintWriter output = new PrintWriter(new FileWriter(OUTPUT_FILENAME));
            
        int numberOfTestCase = input.nextInt();
        for (int caseNum=1; caseNum<=numberOfTestCase; caseNum++) {
        	int N = input.nextInt();
        	int M = input.nextInt();
        	int K = input.nextInt();
        	
        	int s = Math.min(N, M);
        	int l = Math.max(N, M);
        	
        	int res = 0;
        	int stone = 0;
        	int points = 0;
        	if (s <= 2 || K <= 4) {
        		res = K;
        	} else {
        		int n = 1;
        		int m = 1;
        		stone = 4;
        		points = 5;
        		while (K > points) {
        			if (n >= m) {
        				if (m+3 <= l) {
        					stone += 1;
        					points += n;
        					if (K > points) {
        						stone += 1;
        						points += 2;
        					}
        					m++;
        				} else if (n+3 <= s) {
        					stone += 1;
        					points += m;
        					if (K > points) {
        						stone += 1;
        						points += 2;
        					}
        					n++;
        				} else {
        					stone = (N + M - 4) * 2;
        					stone = stone + Math.max(K-((N-2)*(M-2)+stone), 0);
        					points = K;
        				}
        			} else {
        				if (n+3 <= s) {
        					stone += 1;
        					points += m;
        					if (K > points) {
        						stone += 1;
        						points += 2;
        					}
        					n++;
        				} if (m+3 <= l) {
        					stone += 1;
        					points += n;
        					if (K > points) {
        						stone += 1;
        						points += 2;
        					}
        					m++;
        				} else {
        					stone = (N + M - 4) * 2;
        					stone = stone + Math.max(K-((N-2)*(M-2)+stone), 0);
        					points = K;
        				}
        			}
        		}
        		res = stone;
        	}
        	output.format("Case #%d: %d\n", caseNum, res);
        }
        
        input.close();
        output.close();
	}
}
