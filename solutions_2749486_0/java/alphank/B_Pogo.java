package round1C2013;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class B_Pogo {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		try {
			BufferedReader br = new BufferedReader(new FileReader("aSample.txt"));
			BufferedWriter bw = new BufferedWriter(new FileWriter("aOutput.txt"));

			Scanner in = new Scanner(br);

			int T = in.nextInt();
			for (int t = 0; t < T; t++) {

				int dstX = in.nextInt();
				int dstY = in.nextInt();

				int x = 0;
				int y = 0;

				char[] path = new char[500];
				path[0] = ' ';
				int step = 1;

				if(x < dstX) {
					while(x + step <= dstX) {
						x += step;
						path[step++] = 'E';
						continue;
					}
					if(x != dstX) {
						int diff = dstX - x;
						for (int i = 0; i < diff; i++) {
							x -= step;
							path[step++] = 'W';
							x += step;
							path[step++] = 'E';
						}
					}
				}
				else if(x > dstX) {
					while(x - step >= dstX) {
						x -= step;
						path[step++] = 'W';
						continue;
					}
					if(x != dstX) {
						int diff = x - dstX;
						for (int i = 0; i < diff; i++) {
							x += step;
							path[step++] = 'E';
							x -= step;
							path[step++] = 'W';
						}
					}
				}
				
				if(y < dstY) {
					while(y + step <= dstY) {
						y += step;
						path[step++] = 'N';
						continue;
					}
					if(y != dstY) {
						int diff = dstY - y;
						for (int i = 0; i < diff; i++) {
							y -= step;
							path[step++] = 'S';
							y += step;
							path[step++] = 'N';
						}
					}
				}
				else if(y > dstY) {
					while(y - step >= dstY) {
						y -= step;
						path[step++] = 'S';
						continue;
					}
					if(y != dstY) {
						int diff = y - dstY;
						for (int i = 0; i < diff; i++) {
							y += step;
							path[step++] = 'N';
							y -= step;
							path[step++] = 'S';
						}
					}
				}
				

				String sPath = new String(path);
				String result = sPath.substring(1, step);

				bw.write("Case #" + (t + 1) + ": " + result + "\n");
				System.out.println("Case #" + t + ": " + result);
			}
			in.close();
			br.close();
			bw.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (NumberFormatException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

}
