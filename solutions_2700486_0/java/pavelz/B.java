package round1b;

import java.util.Scanner;

public class B {

	
	private static int x, y;
	
	private static int MIDDLE = 20000;
	private static int height[] = new int[40000];
	private static int totalCount = 0;
	private static int success = 0;
	
	private static void drop(int level, int pos) {
		if (level == 0) {
			if (height[x + MIDDLE] >= y) success++;
			totalCount++;
		} else {
			int h = height[pos + MIDDLE];
			int l = height[pos + MIDDLE - 1];
			int r = height[pos + MIDDLE + 1];
			if (l > h && r > h) {
				height[pos + MIDDLE] += 2;
				drop(level - 1, 0);
				height[pos + MIDDLE] -= 2;
			} else if (l > h && r < h) {
				drop(level, pos + 1);
			} else if (l < h && r > h) {
				drop(level, pos - 1);
			} else {
				drop(level, pos - 1);
				drop(level, pos + 1);
			}
		}
		
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for(int tt = 0;tt<t;tt++) {
			int n = sc.nextInt();
			x = sc.nextInt();
			y = sc.nextInt();
			for(int i=0;i<height.length;i++) height[i] = i % 2 == 0 ? -1 : 0;
			totalCount = 0;
			success = 0;
			drop(n, 0);
			double res = success;
			res /= totalCount;
			//System.out.println("" + totalCount + ", " + success);
			System.out.println("Case #" + (tt + 1) + ": " + res);
		}
		sc.close();
	}

}
