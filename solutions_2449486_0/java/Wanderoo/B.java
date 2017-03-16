import java.io.*;

public class B {
	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new FileReader(args[0]));
		try {
			int testCount = Integer.parseInt(br.readLine());
			
			for (int t = 1; t <= testCount; t++) {
				
				int[] sizes = parse(br.readLine());
				int n = sizes[0];
				int m = sizes[1];
				
				int[][] grass = new int[n][];
				for (int i = 0; i < n; i++){
					grass[i] = parse(br.readLine());
				}
				
				boolean possible = true;
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < m; j++) {
						possible &= isPossible(grass, i, j);
					}
				}
				
				if (possible) {
					print ("Case #" + t + ": YES");
				} else {				
					print ("Case #" + t + ": NO");
				}
			}
		} finally {
			br.close();
		}
	}
	
	public static boolean isPossible(int[][] grass, int x, int y) {
		int height = grass[x][y];
		
		boolean across = true;
		for (int i = 0; i < grass.length; i++) {
			if (grass[i][y] > height) {
				across = false;
			}
		}
		
		boolean down = true;
		for (int j = 0; j < grass[0].length; j++) {
			if (grass[x][j] > height) {
				down = false;
			}
		}
		return across || down;
	}
	
	public static int[] parse(String line) {
		String[] s = line.split(" ");
		int[] ints = new int[s.length];
		for (int i = 0; i < ints.length; i++) {
			ints[i] = Integer.parseInt(s[i]);
		}
		return ints;
	}
	
	public static void print(String s) {
		System.out.println(s);
	}
}