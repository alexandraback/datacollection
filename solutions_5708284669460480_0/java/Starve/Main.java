import java.util.Scanner;


public class Main {

	private class Solver {
		private int maxBanana = 0;
		
		String keys = null;
		String target = null;
		int typesCount = 0;
		
		private char[] keyCount = new char[26];
		
		public Solver(String keys, String target, int typesCount) {
			this.keys = keys;
			this.target = target;
			this.typesCount = typesCount;
		}
		
		private void createKeyCount() {
			for (int i=0; i<keyCount.length; i++) {
				keyCount[i] = 0;
			}
			for (int i=0; i<keys.length(); i++) {
				char key = keys.charAt(i);
				keyCount[key-'A']++;
			}
		}
		
		public double solve() {
			createKeyCount();
			
			double allCaseCount = Math.pow(keys.length(), typesCount);
			long score = getScore();
			
			double result = maxBanana - (score / allCaseCount);
			
			return result;
		}

		private int checkScore(String str) {
			int score = 0;
			
			for (int i=0; i<str.length(); i++) {
				String subStr = str.substring(i);
				
				if (subStr.startsWith(target)) {
					score++;
				}
			}
			
			if (maxBanana < score) {
				maxBanana = score;
			}
			
			return score;
		}
		

		private long getScore() {
			return createStr("");
		}
		
		private long createStr(String now) {
			if (now.length() >= typesCount) {
				return checkScore(now);
			}
			
			long score = 0;
			
			for (int i=0; i<keyCount.length; i++) {
				int times = keyCount[i];
				if (times > 0) {
					char key = (char)('A' + i);
					
					long score1 = createStr(now + key);
				
					score += score1 * times;
				}
			}
			
			return score;
		}
	}
	
	public void solve() {
		Scanner scanner = new Scanner(System.in);
		
		int num = scanner.nextInt();
		
		for (int i=0; i<num; i++) {
			int keys = scanner.nextInt();
			int target = scanner.nextInt();
			int types = scanner.nextInt();
			
			String keysStr = scanner.next();
			String targetStr = scanner.next();
			
			Solver solver = new Solver(keysStr, targetStr, types);
			double result = solver.solve();
			
			System.out.println("Case #" + (i+1) + ": " + result);
		}
		
		scanner.close();
	}
	
	public static void main(String[] args) {
		Main main = new Main();
		main.solve();

	}

}
