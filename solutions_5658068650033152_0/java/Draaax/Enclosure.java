import java.util.Scanner;


public class Enclosure {
	public static void main(String[] args) {
		Scanner kb = new Scanner(System.in);
		
		int cases = kb.nextInt();
		
		for(int c = 1; c <= cases; c++) {
			
			int height = kb.nextInt();
			int width = kb.nextInt();
			int enclosed = kb.nextInt();
			
			System.out.println("Case #" + c + ": " + solve(height,width, enclosed));
		}
	}

	private static int solve(int height, int width, int enclosed) {
		int minStones = enclosed;
		for(int w = 3; w <= width; w++ ) {
			for(int h = 3; h <= height; h++) {
				int newEnclosed = getEnclosed(w,h);
				
				if(newEnclosed > enclosed) continue;
				
				int newTry = getStones(h,w) + (enclosed - getEnclosed(h,w));
				minStones = Math.min(minStones, newTry);
			}
		}		
		return minStones;
	}
	
	private static int getEnclosed(int height, int width) {
		return (width * height) - 4;
	}
	
	private static int getStones(int height, int width) {
		return ((width - 2) * 2) + ((height - 2) * 2);
	}

}
