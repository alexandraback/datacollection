import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;

public class ProblemA {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	
	public static void main(String[] args) throws Exception {
		
		Scanner s  = new Scanner(System.in);
		
		int T = s.nextInt();
		
		for (int caseNum=1; caseNum<=T; caseNum++) {
			
			String S = s.next();
			
			String res = solve(S);
			
			
			System.out.printf("Case #%d: %s\n", caseNum, res);
		}
	}
	
	static String solve(String S) {
		
		if ("".equals(S)) return "";
		
		char max = 'A' - 1;
		int pos = -1;
		
		for (int i=0; i<S.length(); i++) {
			if (S.charAt(i)>max) {
				max = S.charAt(i);
				pos = i;
			}
		}
		
		String r = solve(S.substring(0, pos));
		
		for (int i = pos; i<S.length(); i++) {
			if (S.charAt(i)==max) {
				r = max + r;
			} else {
				r = r + S.charAt(i);
			}
		}
		return r;
	}
}
