import java.util.Scanner;

public class Diamond {
	int[][] arr;
	public Diamond(int[][] arr) {
		this.arr = arr;
	}

	public static void main(String[] args) {
		Scanner reader = new Scanner(System.in);
		int T = reader.nextInt();
		for (int nc = 1; nc <= T; nc++) {
			int n = reader.nextInt();
			int[][] arr = new int[n][];
			for(int i = 0 ; i < n ; i ++) {
				int m = reader.nextInt();
				arr[i] = new int[m];
				for(int j = 0 ; j < m ; j ++) {
					arr[i][j] = reader.nextInt() - 1;
				}
			}
			Diamond d= new Diamond(arr);
			boolean res = d.solve();
			System.out.printf("Case #%d: %s\n", nc, res ? "Yes" : "No");
		}
	}

	int[] visited;
	int n;
	private boolean solve() {
		n = arr.length;
		for(int i = 0 ; i < n ; i++) {
			visited = new int[n];
			if(go(i)) {
				return true;
			}
		}
		
		return false;
	}

	private boolean go(int i) {
		if(visited[i] == 1) {
			return true;
		}
		visited[i] = 1;
		for(int j : arr[i]) {
			if(go(j)) {
				return true;
			}
		}
		return false;
	}
}
