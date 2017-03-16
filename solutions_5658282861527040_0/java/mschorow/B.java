import java.util.*;

public class B {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int t = s.nextInt();

		for (int testCase = 1; testCase <= t; testCase++) {
			int result = 0;
			int a = s.nextInt();
			int b = s.nextInt();
			int k = s.nextInt();
			for(int i=0;i<a;i++){
				for(int j=0;j<b;j++){
					if((i&j) < k){
						result++;
					}
				}
			}
			System.out.println("Case #" + testCase + ": "+result);
		}

	}

	private static int traverse(int index, int set, int origin, int n,
			boolean[][] adjacent) {
		int numAdjacent = 0;
		int nodes = 0;
		for (int x = 0; x < n; x++) {
			if (!isInSet(set, x) || !adjacent[x][index])
				continue;
			if (x == origin) {
				continue;
			}
			numAdjacent++;
			if (numAdjacent > 2) {
				return -1;
			}
			int rest = traverse(x, set, index, n, adjacent);
			nodes += rest;
			if (rest < 0) {
				return -1;
			}
		}
		if(numAdjacent == 0 || numAdjacent == 2){
			return 1+nodes;
		}
		return -1;
	}

	private static int countOnes(int set) {
		int answer = 0;
		while (set > 0) {
			answer += set % 2;
			set /= 2;
		}
		return answer;
	}

	private static boolean isInSet(int set, int flag) {
		set = set >> flag;
		return set % 2 == 1;
	}
}
