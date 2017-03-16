package qualify;

import java.util.Scanner;

public class B {

	private static int n, m;
	private static int [][] data;
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		
		for (int i=0;i<t;i++) {
			n = sc.nextInt();
			m = sc.nextInt();
			data = new int[n][m];
			for(int j=0;j<n;j++) {
				for(int k=0;k<m;k++) {
					data[j][k] = sc.nextInt();
				}
			}
			
			int maxRow[] = new int[n];
			int maxColumn[] = new int[m];
			boolean processedRow[] = new boolean[n];
			boolean processedColumn[] = new boolean[m];
			for(int j=0;j<n;j++) {
				processedRow[j] = false;
				maxRow[j] = 0;
				for(int k=0;k<m;k++) {
					if (data[j][k] > maxRow[j]) maxRow[j] = data[j][k];
				}
			}

			for(int k=0;k<m;k++) {
				maxColumn[k] = 0;
				processedColumn[k] = false;
				for(int j=0;j<n;j++) {
					if (data[j][k] > maxColumn[k]) maxColumn[k] = data[j][k];
				}
			}
			
			int remainColumns = m;
			int remainRows = n;
			boolean ok = true;
			while (remainColumns > 0 && remainRows > 0) {
				int minY = -1, minX = -1;
				int minValue = 1000;
				for(int j=0;j<n;j++) {
					if (!processedRow[j]) {
						for(int k=0;k<m;k++) {
							if (!processedColumn[k] && data[j][k] < minValue) {
								minValue = data[j][k];
								minX = k;
								minY = j;
							}
						}
					}
				}
				
				if (maxColumn[minX] > minValue && maxRow[minY] > minValue) {
					ok = false;
					break;
				}
				
				if (maxColumn[minX] == minValue) {
					processedColumn[minX] = true;
					remainColumns--;
				} else {
					processedRow[minY] = true;
					remainRows--;
				}
			}
			
			System.out.println("Case #" + (i + 1) + ": " + (ok ? "YES" : "NO"));
		}
		sc.close();
	}
}
