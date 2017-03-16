import java.util.Scanner;


public class Diamond {
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int t = in.nextInt();
		for (int i = 0; i < t; i++){
			int n = in.nextInt();
			boolean[][] map = new boolean[n + 1][n + 1];
			for (int j = 1; j <= n; j++){
				int mi = in.nextInt();
				for (int k = 0; k < mi; k++){
					map[j][in.nextInt()] = true;
				}
			}
			boolean get = false;
			for (int j = 1; j <= n; j++){
				boolean[] visited = new boolean[n + 1];
				if (dfs(map, visited, j)){
					get = true;
					break;
				}
			}
			System.out.printf("Case #%d: ", i + 1);
			if (get)
				System.out.printf("YES%n");
			else
				System.out.printf("NO%n");
				
		}
	}
	
	private static boolean dfs(boolean[][] map, boolean[] visited, int s){
		if (visited[s]) return true;
		visited[s] = true;
		for (int i = 0; i < map[s].length; i++){
			if (map[s][i]&&dfs(map, visited, i))
				return true;
		}
		return false;
	}

}
