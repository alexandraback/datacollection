package Round1B;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.util.HashMap;

public class EqualSums {

	public static void main(String[] args) throws Exception {
		System.setIn(new FileInputStream("equalsums.in"));
		System.setOut(new PrintStream("equalsums.out"));
		
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		
		int T = Integer.parseInt(bf.readLine().trim());
		for(int t = 1; t <= T; t++) {
			System.out.println("Case #" + t + ": ");
			
			String[] parts = bf.readLine().trim().split("[ ]+");
			int N = Integer.parseInt(parts[0]);
			int[] value = new int[N];
			for(int i = 0; i < N; i++) {
				value[i] = Integer.parseInt(parts[i + 1]);
			}
			
			int firstMask = -1, secondMask = -1;
			HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
			for(int mask = 1; mask < (1 << N); mask++) {
				int sum = 0;
				for(int i = 0; i < N; i++) {
					if((mask & (1 << i)) == 0) continue;
					sum += value[i];
				}
				
				if(map.containsKey(sum)) {
					firstMask = map.get(sum);
					secondMask = mask;
					break;
				}
				
				map.put(sum, mask);
			}
			
			if(firstMask == -1) {
				System.out.println("Impossible");
				continue;
			}
			
			StringBuilder sb = new StringBuilder();
			for(int i = 0; i < N; i++) {
				if((firstMask & (1 << i)) != 0) {
					sb.append(value[i] + " ");
				}
			}
			System.out.println(sb.toString().trim());
			
			sb = new StringBuilder();
			for(int i = 0; i < N; i++) {
				if((secondMask & (1 << i)) != 0) {
					sb.append(value[i] + " ");
				}
			}
			System.out.println(sb.toString().trim());
		}

	}

}
