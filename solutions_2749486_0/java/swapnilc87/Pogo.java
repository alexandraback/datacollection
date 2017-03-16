import java.awt.Point;
import java.util.Scanner;

/**
 * 
 */

public class Pogo {

	public static void main(String[] args) {

		int a, b;
		Scanner scanner = new Scanner(System.in);
		int noOfTestCases = scanner.nextInt();

		for (int k = 0; k < noOfTestCases; k++) {
			String output = "";
			a = scanner.nextInt();
			b = scanner.nextInt();
//			Point dest = new Point(a, b);
			Point point = new Point(0, 0);
			boolean xReached = false;
			boolean yReached = false;
			boolean flipX = false;
			boolean flipY = false;
			if (a < 0) {
				// move towards right first
				flipX = false;
			} else {
				flipX = true;
			}
			if (b < 0) {
				flipY = false;
			} else {
				flipY = true;
			}
			for (int j = 0; j < 500; j++) {
				if (point.x == a) {
					xReached = true;
				}
				if (!xReached) {
					
					if (!flipX) {
						point.move(point.x + j, point.y);
						output+="E";
						flipX = true;
					} else {
						point.move(point.x - j, point.y);
						output+="W";
						flipX = false;
					}
					
				} else if (xReached) {
					if (point.y == b) {
						yReached = true;
						break;
					}
					if (!flipY) {
						point.move(point.x, point.y + j);
						output+="N";
						flipY = true;
					} else {
						point.move(point.x, point.y - j);
						output+="S";
						flipY = false;
					}
				}

			}
//			if(!xReached|!yReached) {
//				System.out.println("Error");
//			}
			System.out.print("\nCase #" + (k + 1) + ": " + output);
//			System.out.println(output.length());
		}

	}

}
