import java.io.BufferedWriter;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Scanner;



public class Pogo {
	public static void main(String[] args) throws IOException {
		BufferedWriter bw;
		FileOutputStream fos = new FileOutputStream("C:\\Users\\Administrator\\Downloads\\codejam.out");
		bw = new BufferedWriter(new OutputStreamWriter(fos));
		Scanner reader = new Scanner (System.in);
		int nCases = reader.nextInt();
		reader.nextLine();

		for(int i=1; i<=nCases; i++) {
			int X = reader.nextInt();
			int Y = reader.nextInt();
			int curX = 0;
			int curY = 0;
			int nStep = 1;
			String result = "";
			while(curX != X || curY != Y) {
				if(curX != X) {
					if(X > 0) {
						if(curX < X && X - curX >= nStep) {
							curX +=nStep++;
							result += "E";
						} else {
							while(curX < X) {
								curX -= nStep++;
								result += "W";
								curX += nStep++;
								result += "E";
							}
						}
					} else {
						if(Math.abs(curX) < Math.abs(X) && Math.abs(X) - Math.abs(curX) >= nStep) {
							curX -= nStep++;
							result += "W";
						} else {
							while(Math.abs(curX) < Math.abs(X)) {
								curX += nStep++;
								result += "E";
								curX -= nStep++;
								result += "W";
							}
						}
					}
				} else {
					if(Y > 0) {
						if(curY < Y && Y - curY > nStep) {
							curY +=nStep++;
							result += "N";
						} else {
							while(curY < Y) {
								curY -= nStep++;
								result += "S";
								curY += nStep++;
								result += "N";
							}
						}
					} else {
						if(Math.abs(curY) < Math.abs(Y) && Math.abs(Y) - Math.abs(curY) > nStep) {
							curY -= nStep++;
							result += "S";
						} else {
							while(Math.abs(curY) < Math.abs(Y)) {
								curY += nStep++;
								result += "N";
								curY -= nStep++;
								result += "S";
							}
						}
					}
				}
			}
			String line ="Case #" + i + ": " + result;
			System.out.println(line);

			bw.write(line);
			bw.newLine();
			reader.nextLine();
			//System.out.println();
		}
		bw.close();
	}
}
