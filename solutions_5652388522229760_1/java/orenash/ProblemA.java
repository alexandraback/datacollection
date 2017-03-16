

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.Set;

public class ProblemA {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	
	public static void main(String[] args) throws Exception {
		
		int cases = readInt();
		
		for (int caseNum=0; caseNum<cases; caseNum++) {
			
			int N = readInt();
			
			if (N==0) {
				System.out.println(String.format("Case #%d: %s", caseNum+1, "INSOMNIA"));
				continue;
			}
			
//			int length = 0, pow = 1;
//			while (N>=pow) {
//				pow *= 10;
//				length++;
//			}
			
			Set<Integer> digs = new HashSet<>();
			
			long cur = 0;
			while (digs.size() < 10) {
				cur += N;
				String s = String.valueOf(cur);
				s.chars().forEach(c -> digs.add(c));
			}
			
			System.out.println(String.format("Case #%d: %d", caseNum+1, cur));
		}

	}
	
	private static int readInt() throws IOException {
		return Integer.parseInt(br.readLine());
	}
	
}
