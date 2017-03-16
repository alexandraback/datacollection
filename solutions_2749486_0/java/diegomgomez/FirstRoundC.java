import java.io.FileNotFoundException;
import java.util.Scanner;

public class FirstRoundC {
	
	public static void main(String args[]) throws FileNotFoundException {
		Scanner input = new Scanner(System.in);
		String line;
			
		int ntests = Integer.valueOf(input.nextLine());
		
		for (int i = 1; i <= ntests; i++) {
			StringBuilder out = new StringBuilder();
			
			int destX = input.nextInt();
			int destY = input.nextInt();

			out.append("Case #").append(i).append(": ");
			reachXY(destX, destY, out);
			
			System.out.println(out);
			if (input.hasNext()) input.nextLine();
		}
			
	}
	
	private static void reachXY(int destX, int destY, StringBuilder out) {
		
		int curX = 0;
		int curY = 0;
		int pogoVal = 1;
		int i = 0;
		
		int toEast = destX >= 0 ? 1 : -1;
		int toNorth = destY >= 0 ? -1 : 1;
		
		while (curX != destX) {
			curX += pogoVal * toEast;
			pogoVal++;
			if (toEast > 0) {
				out.append("E");
			} else {
				out.append("W");
			}
			toEast *= -1;
		}
		
		while (curY != destY) {
			curY += pogoVal * toNorth;
			pogoVal++;
			if (toNorth > 0) {
				out.append("N");
			} else {
				out.append("S");
			}
			toNorth *= -1;
		}
	}
}