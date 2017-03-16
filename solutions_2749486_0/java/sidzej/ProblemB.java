package round13_b;

import java.io.BufferedWriter;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Iterator;
import java.util.List;
import java.util.Scanner;

public class ProblemB {

	//static String filePath = "src/round13_b/test.in"; 
	static String filePath = "src/round13_b/B-small-attempt0.in";
	//static String filePath = "src/round13_b/B-large.in";
	static StringBuffer fullResult = new StringBuffer();
	public static void main(String[] args) throws IOException {
		Scanner s = new Scanner(new FileReader(filePath));
		int noTestCases = s.nextInt();
		for (int i = 0; i < noTestCases; i++) {
			String result = "";			
			long x = s.nextLong();
			long y = s.nextLong();
			long directionX = (x < 0)? -1 : 1;
			long directionY = (y < 0)? -1 : 1;
			long currentX = 0;
			long currentY = 0;
			long currentJump = 1;
			boolean jumpX = false;
			boolean jumpY = false;
			while (currentX != x || currentY != y) {
				long nextJump = currentJump + 1;
				if (jumpX == false) {
					jumpX = true;
					jumpY = false;
				} else {
					jumpX = false;
					jumpY = true;
				}
				if (currentX == x) {
					jumpX = false;
					jumpY = true;
				}
				if (currentY == y) {
					jumpX = true;
					jumpY = false;
				}
				if (jumpX) {
					if (currentJump + Math.abs(currentX) > Math.abs(x)) {
						if (directionX == 1) {
							result += "WE";
						} else {
							result += "EW";
						}
						currentX = currentX + directionX;
						currentJump++;
					} else {
						//we move though x
						currentX = currentX + currentJump * directionX;
						if (directionX == 1) {
							result += "E";
						} else {
							result += "W";
						}
					}
				}
				if (jumpY) {
					if (currentJump + Math.abs(currentY) > Math.abs(y)) {
						if (directionY == 1) {
							result += "SN";
						} else {
							result += "NS";
						}
						currentY = currentY + directionY;
						currentJump++;
					} else {
						//we move though y
						currentY = currentY + currentJump * directionY;
						if (directionY == 1) {
							result += "N";
						} else {
							result += "S";
						}
					}
				}
				currentJump++;
			}
			fullResult.append("Case #" + (i + 1) + ": " + result + "\n");
		}
		writeFile();
	}

	static void writeFile() throws IOException {
		String path = filePath.replace(".in", ".out");
		BufferedWriter out = new BufferedWriter
			    (new OutputStreamWriter(new FileOutputStream(path),"UTF-8"));
		out.write(fullResult.toString());
		out.close();
		System.out.println(fullResult);
	}
}
