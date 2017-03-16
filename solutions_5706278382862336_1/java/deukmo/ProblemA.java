import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Scanner;

public class ProblemA {
    private static final String INPUT_FILENAME = "A-large.in";
    private static final String OUTPUT_FILENAME = "A-large.out";

	public static void main(String[] args) throws Exception {
		Scanner input = new Scanner(new FileReader(INPUT_FILENAME));
        PrintWriter output = new PrintWriter(new FileWriter(OUTPUT_FILENAME));
            
        int numberOfTestCase = input.nextInt();
        for (int caseNum=1; caseNum<=numberOfTestCase; caseNum++) {
        	String[] nums = input.next().split("/");
        	long P = Long.parseLong(nums[0]);
        	long Q = Long.parseLong(nums[1]);

        	long p = P * 2;
        	int res = 1;
        	while (p < Q) {
        		p *= 2;
        		res++;
        	}
        	
        	boolean isPossible = false;
        	int limit = 40;
        	p = P * 2;
        	while (limit > 0) {
        		if (p >= Q) p = p - Q;
        		if (p == 0) {
        			isPossible = true;
        			break;
        		}
        		p *= 2;
        		limit--;
        	}
        	
        	if (isPossible) {
        		output.format("Case #%d: %d\n", caseNum, res);
        	} else {
        		output.format("Case #%d: impossible\n", caseNum);
        	}
        }
        
        input.close();
        output.close();
	}
}
