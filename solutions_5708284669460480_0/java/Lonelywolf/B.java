package jam2015.round1c.b;

import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class B {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int T = scanner.nextInt();
		
		for(int t = 0; t<T; t++) {
			int K = scanner.nextInt();
			int L = scanner.nextInt();
			int S = scanner.nextInt();
			
			scanner.nextLine();
			String KEY = scanner.nextLine();
			String GOAL = scanner.nextLine();
			
			Double MAX = 0.0;
			Double prob = 1.0;
			
			Map<Character, Double> map = new HashMap<>();
			
			for(int idx = 0; idx < K; idx++) {
				Character c = KEY.charAt(idx);
				Double val = map.get(c);
				if(val == null) {
					val = 1.0;
				} else {
					val += 1.0;
				}
				map.put(c, val);
			}
			
			
			for(Character c : map.keySet()) {
				Double val = map.get(c);
				val /= (double)K;
				map.put(c, val);
			}
			
			// 1. possible?
			boolean possible = true;
			for(int idx = 0; idx < L; idx++) {
				Character c = GOAL.charAt(idx);
				if(!map.containsKey(c)) {
					System.out.println(String.format("Case #%d: 0.0", t+1));
					possible = false;
					break;
				}
			}
			if(!possible) {
				continue;	
			}
			
			// 2. maximum?
			int min = L;
			
			int loop = L/2;
			for(int i=1; i<=loop; i++) {
				if(L%i == 0) {
					boolean isAns = true;
					String seed = GOAL.substring(0, i);
					for(int j=1; j<(L/i); j++) {
						int pos = j*i;
						if(!GOAL.substring(pos, pos+i).equals(seed)) {
							isAns = false;
							break;
						}
					}
					if(isAns) {
						min = i;
						break;
					}
				}
			}
			
			int maxBanana = (S/min) - (L/min - 1);
			
			for(int idx = 0; idx < L; idx++) {
				Character c = GOAL.charAt(idx);
				prob *= map.get(c);
				
				if(prob < 0.000001) {
					prob = 0.0;
					break;
				}
			}
			
			MAX = maxBanana - (maxBanana * prob);
			
			System.out.println(String.format("Case #%d: %f", t+1, MAX));
		}
		
	}
	
}
