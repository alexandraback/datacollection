 import java.io.BufferedOutputStream;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class A {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		

		Scanner sc = null;
		if (args != null && args.length > 0) {
			
			try {
				sc = new Scanner(new File(args[0]));
					
				if (args.length > 1) {
					System.setOut(new PrintStream(new BufferedOutputStream(new FileOutputStream(new File(args[1])), 128)));
				}
			} catch (FileNotFoundException e) {
				
				// e.printStackTrace();
				sc = new Scanner(System.in);
			}
			
		} else {
			
			sc = new Scanner(System.in);
		}

		int T = Integer.valueOf(sc.nextLine());
		
		for (int i = 0; i < T; i++) {
			
			int N = sc.nextInt();
			int[][] map = new int[N][];
			for (int j = 0; j < N; j++) {
				int M = sc.nextInt();
				map[j] = new int[M];
				for (int k = 0; k < M; k++) {
					map[j][k] = sc.nextInt();
				}
				
			}
			boolean answer = solve(N, map);
			
			if (answer) {
				
				System.out.printf("Case #%d: Yes\n", i + 1);
				
			} else {
				
				System.out.printf("Case #%d: No\n", i + 1);
			}
		}
		System.out.close();

	}
	
	public static boolean find(int num, int[][] map) {
		int[] fathers = map[num];
		for (int i = 0; i < fathers.length; i++) {
			int f = fathers[i] - 1;
			if (have.get(f) != null) {
				
				return true;
			} else {
				
				have.put(f, true);
				
				if (find(f, map))
					return true;
			}
			
		}
		
		return false;
	}
	static Map<Integer, Boolean> have;
	public static boolean solve(int N, int[][] map) {
		
		boolean answer;
		for (int i = 0; i < N; i++) {
			
			have = new HashMap<Integer, Boolean>();
			answer = find(i, map);
			if (answer) {
			 
				return true;
			}
			
		}
		
		return false;
	}
	
}
