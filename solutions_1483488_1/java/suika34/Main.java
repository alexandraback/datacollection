import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashSet;


public class Main {

	public static void main(String[] args) {
		Main main = new Main();
		try {
			BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
			String line = bf.readLine();
			int T = Integer.parseInt(line);
			for (int testcaseIndex=0; testcaseIndex<T; testcaseIndex++) {

				String testCase = bf.readLine();
				String[] array = testCase.split(" ");
				int A = Integer.parseInt(array[0]);
				int B = Integer.parseInt(array[1]);
						
				int out  = main.solve(A,B);
				
				System.out.print("Case #"+(testcaseIndex+1)+": ");
				System.out.println(out);
				
			}
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	
	private int solve(int A, int B) {
		HashSet<Pair> set = new HashSet<Pair>();		
		for (int num=A; num<=B; num++) {
			String numStr = String.valueOf(num);
			for (int i=1; i<numStr.length(); i++) {
				String tempStr = numStr.substring(i) + numStr.substring(0,i);
				int temp = Integer.valueOf(tempStr);
				if ( A <= temp && temp <= B && num != temp) {
					set.add(new Pair(num, temp));
				}
			}
		}
		return set.size();
	}

	private class Pair {
		int small;
		int large;
		
		Pair(int s, int l) {
			if (s > l) {
				int t = s;
				s = l;
				l = t;
			}
			small = s;
			large = l;
		}
		
		@Override
		public boolean equals(Object o) {
			if (o instanceof Pair) {
				Pair pair = (Pair)o;
				return this.small == pair.small && this.large == pair.large;
			}
			return false;
		}
		
		@Override
		public int hashCode() {
			return small * 23 + large;
		}
	}
	
	
}
