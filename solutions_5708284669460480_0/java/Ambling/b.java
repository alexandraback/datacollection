package round1C;


import java.util.*;

public class b {
	
	static int getM(String target, int S){
		int tail = target.length();
		for (int i = 1; i < target.length(); i++) {
			String sub = target.substring(i);
			if (target.startsWith(sub)) {
				tail = i;
				break;
			}
		}
		
		return (S - target.length()) / tail + 1;
	}
	
	static void count(String the, String target, int[] result) {
		int cnt = 0;
		for (int i = 0; i < the.length(); i++) {
			if (the.substring(i).startsWith(target))
				cnt ++;
		}
//		System.out.println("the: " + the + " target: " + target + " cnt: " + cnt);
		result[cnt] ++;
	}
	
	static void generate(int S, int choose, String now, String keys, String target, int[] result, int M) {
		String the = now + keys.charAt(choose);
//		System.out.println("the: " + the + " target: " + target);
		if (the.length() == S) {
			result[M+1] ++;
			count(the, target, result);
		} else {
			generate(S, 0, the, keys, target, result, M);
		}
		if (choose != keys.length()-1) {
			generate(S, choose+1, now, keys, target, result, M);
		}
	}
	
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);

		int T = in.nextInt();
		for (int t = 1; t <= T; t++) {
			// TODO
			int K = in.nextInt();
			int L = in.nextInt();
			int S = in.nextInt();
			
			in.nextLine();
			String keys = in.nextLine();
			String target = in.nextLine();
			
//			System.out.println("keys: " + keys + " target:" + target);
			
			int M = getM(target, S);
			
//			System.out.println(M);
			
			int[] result = new int[M+2];
			
			generate(S, 0, "", keys, target, result, M);

			double exp = 0;
			int most = 0;
			for (int i = 1; i <= M; i++) {
				if (result[i] != 0) {
					most = i;
					exp += 1.0 * i * result[i] / result[M+1];
				}
			}
			
//			System.out.println(most);
			if (exp != 0)
				exp = most - exp;
			
			System.out.printf("Case #%d: %.7f\n", t, exp);
		}
	}
}
