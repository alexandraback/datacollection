import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;


public class Pogo {

	public static void main(String[] args) throws IOException {
		Scanner sc;
		FileWriter writer = new FileWriter("output.txt");
		sc = new Scanner(new File("B-small-attempt0.in"));

//		String test = sc.next();
		int cases = sc.nextInt();
		
		for (int c = 1; c <= cases; c++) {
			int x = sc.nextInt();
			int y = sc.nextInt();
			writer.write("Case #" + c + ": ");
			int curX = 0;
			int curY = 0;
			int i = 0;
			
			while(++i < 500) {
				int disX = x-curX;
				int disY = y-curY;
				if (disX < 0) {
					// if point is west
					if(Math.abs(disX) >= i) {
						// and right distance or too far -> jump towards
						writer.write("W");
						curX -= i;
						continue;
					} else {
						// too close -> jump away
						writer.write("E");
						curX += i;
						continue;
					}
				} else if (disX > 0) {
					// east
					if(Math.abs(disX) >= i) {
						// and right distance or too far -> jump towards
						writer.write("E");
						curX += i;
						continue;
					} else {
						// too close -> jump away
						writer.write("W");
						curX -= i;
						continue;
					}
				
			    }
				if (disY < 0) {
					// if point is north
					if(Math.abs(disY) >= i) {
						// and right distance or too far -> jump towards
						writer.write("S");
						curY -= i;
						continue;
					} else {
						// too close -> jump away
						writer.write("N");
						curY += i;
						continue;
					}
				} else if (disY > 0) {
					// south
					if(Math.abs(disY) >= i) {
						// and right distance or too far -> jump towards
						writer.write("N");
						curY += i;
						continue;
					} else {
						// too close -> jump away
						writer.write("S");
						curY -= i;
						continue;
					}
			   
			    }
				if(curX == x && curY == y) {
					writer.write("\r\n");
					break;
				
				}
				
			}
			
			
		}
		sc.close();
		writer.close();
	}
}
