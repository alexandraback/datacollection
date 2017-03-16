import java.io.File;
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.Scanner;


public class ProblemB {
	public static void main(String[] args) throws FileNotFoundException {
		Scanner sc = new Scanner(new File("B-small-attempt1.in"));
//		Scanner sc = new Scanner(new File("B-large.in"));
//		Scanner sc = new Scanner(new File("B.in"));
		int casses = sc.nextInt();
		int count = 1;
		
		while(casses --> 0) {
			int x = sc.nextInt();
			int y = sc.nextInt();
			String result = "";
			
			result += solve(x, y);
			
			System.out.println("Case #" + count + ": " + result);
			count++;
		}
	}
	
	public static String solve(int x, int y) {
		String result = "";
		result += solveX(x);
		result += solveY(y);
		
		return result;
	}
	
	public static String solveX(int x) {
		boolean reached = false;
		int position = 0;
		boolean flip = true;
		String path = "";
		
		while(!reached) {
			if(position == x)
				reached = true;
			else if(flip) {
				position = position * -1 - 1;
				flip = false;
				path += "W";
			}
			else {
				position = position * -1;
				path += "E";
				flip = true;
			}
		}
		
		return path;
	}
	
	public static String solveY(int y) {
		boolean reached = false;
		int position = 0;
		boolean flip = true;
		String path = "";
		
		while(!reached) {
			if(y > 0) {
				if(position == y)
					reached = true;
				else if(flip) {
					position = position * -1 - 1;
					path += "S";
					flip = false;
				}
				else {
					position = position * -1;
					path += "N";
					flip = true;
				}
			} else {
				if(position == y)
					reached = true;
				else if(flip) {
					position = position * -1 + 1;
					path += "N";
					flip = false;
				}
				else {
					position = position * -1;
					path += "S";
					flip = true;
				}
			}
		}
		
		return path;
	}
}
