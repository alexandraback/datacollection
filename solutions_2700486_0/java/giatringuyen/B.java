import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.util.Scanner;


public class B {
	
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner (new File("B-small-attempt1.in"));
		FileWriter fstream = new FileWriter("B-small-attempt1-out.in");
		BufferedWriter out = new BufferedWriter(fstream);
		
//		Scanner sc = new Scanner (System.in);
		
		int tstSz = sc.nextInt();
		for (int t = 1; t <= tstSz; ++t) {
			int n = sc.nextInt();
			int desX = sc.nextInt();
			int desY = sc.nextInt();
			
			int size = (int)Math.floor(Math.sqrt(n) + 1)*2;
			boolean[][] arr = new boolean[2*size+1][2*size+1];
			double ans = 0.0;
			
			if (Math.abs(desX) < size && Math.abs(desY) < size) {
				int[] tmp = rec(arr, size, 0, size, 0, desX+size, desY, n);
				ans = 1.0*tmp[0]/tmp[1];
			}
			
//			System.out.println("Case #" + t + ": " + ans);
			out.write("Case #" + t + ": " + ans + "\n");
		}
		
		out.close();
	}
	
	public static int[] rec (boolean[][] arr, int topX, int topY, int curX, int curY, int desX, int desY, int n) {
		
		if (n == 0)
			if (arr[desX][desY])
				return new int[] {1, 1};
			else
				return new int[] {0, 1};
		else {
			if (	curY == 0 ||
					(arr[curX-1][curY-1] && arr[curX+1][curY-1])) {
				arr[curX][curY] = true;
				
				if (curX == topX && curY == topY)
					topY += 2;
				return rec(arr, topX, topY, topX, topY, desX, desY, n-1);
			} else {
				int[] res = new int[2];

				boolean[][] arr2 = new boolean[arr.length][arr[0].length];
				for (int i = 0; i < arr.length; ++i)
					for (int j = 0; j < arr[0].length; ++j)
						arr2[i][j] = arr[i][j];
				
				if (!arr[curX-1][curY-1]) {
					int[] tmp = rec(arr, topX, topY, curX-1, curY-1, desX, desY, n);
					res[0] += tmp[0];
					res[1] += tmp[1];
				}
				arr=null;
				if (!arr2[curX+1][curY-1]) {
					int[] tmp = rec(arr2, topX, topY, curX+1, curY-1, desX, desY, n);
					res[0] += tmp[0];
					res[1] += tmp[1];
				}
				return res;
			}
		}
	}
}
