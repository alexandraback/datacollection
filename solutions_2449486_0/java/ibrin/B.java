import java.io.*;
import java.util.*;

public class B
{
	private static void print(int[][] array) {
		for(int i = 0; i < array.length; i++) {
			for(int j = 0; j < array[i].length; j++) {
				System.out.print(array[i][j] + ", ");
			}
			System.out.println();
		}
	}

	private static boolean anyBiggerInRow(int[][] lawn, int r, int val) {
		for(int i = 0; i < lawn[r].length; i++) {
			if(lawn[r][i] > val) {
				return true;
			}
		}
		return false;
	}
	
	private static boolean anyBiggerInCol(int[][] lawn, int c, int val) {
		for(int i = 0; i < lawn.length; i++) {
			if(lawn[i][c] > val) {
				return true;
			}
		}
		return false;
	}
	
	
	private static boolean impossible(int[][] lawn, int r, int c) {
		int val = lawn[r][c];
		if(anyBiggerInRow(lawn, r, val) && anyBiggerInCol(lawn, c, val)) {
			//System.out.println("impossible at "+r+", "+c);
			return true;
		}
		return false;
	}
	
	private static boolean possible(int[][] lawn) {
		for(int i =0; i < lawn.length; i++) {
			for(int j=0;j<lawn[i].length;j++) {
				if(impossible(lawn, i, j)) {
					return false;
				}
			}
		}
		return true;
	}
	
	private static void solve(int num, int[][] lawn) {
		//print(lawn);
		System.out.println("Case #"+num+": "+(possible(lawn) ? "YES": "NO"));
	}

	public static void main(String[] args) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int numCases = Integer.parseInt(br.readLine());
		for(int i = 0; i < numCases; i++) {
			String line = br.readLine();
			String[] parts = line.split(" ");
			int length = Integer.parseInt(parts[0]);
			int width = Integer.parseInt(parts[1]);
			int[][] lawn = new int[length][width];
			for(int j = 0; j < length; j++) {
				line = br.readLine();
				parts = line.split(" ");
				for (int k = 0; k < width; k++) {
					lawn[j][k] = Integer.parseInt(parts[k]);
				}
			}
			solve(i+1, lawn);
		}
	}

}