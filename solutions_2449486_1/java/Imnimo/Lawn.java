import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;


public class Lawn {
	public static void main(String[] args) {
		try {
			Scanner s = new Scanner(new File("input.txt"));
			int numCases = Integer.parseInt(s.nextLine());
			for(int c = 1;c<=numCases;c++) {
				String sizeLine = s.nextLine();
				String[] sizes = sizeLine.split(" ");
				int n = Integer.parseInt(sizes[0]);
				int m = Integer.parseInt(sizes[1]);
				int[][] lawn = new int[n][m];
				for(int row = 0;row<n;row++) {
					String rowLine = s.nextLine();
					String[] items = rowLine.split(" ");
					for(int col = 0;col<m;col++) {
						lawn[row][col] = Integer.parseInt(items[col]);
					}
				}
				boolean valid = isValid(lawn);
				System.out.println("Case #" + c +": " +(valid?"YES":"NO"));
			}
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	public static boolean isValid(int[][] lawn) {
		for(int x = 0;x<lawn.length;x++) {
			for(int y = 0;y<lawn[x].length;y++) {
				int val = lawn[x][y];
				boolean validA = true;
				for(int i = 0;i<lawn.length;i++) {
					if(lawn[i][y]>lawn[x][y]) {
						validA = false;
					}
				}
				if(validA) {
					continue;
				}
				
				boolean validB = true;
				for(int j = 0;j<lawn[x].length;j++) {
					if(lawn[x][j]>lawn[x][y]) {
						validB = false;
					}
				}
				if(validB) {
					continue;
				}
				return false;
				
			}
		}
		return true;
	}
}
