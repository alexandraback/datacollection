import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;


public class Pogo {

	public static void main(String[] args) {
		try {
			BufferedReader in = new BufferedReader(new FileReader(args[0]));
			BufferedWriter out = new BufferedWriter(new FileWriter(args[1]));
			int cases = Integer.valueOf(in.readLine());
			String line;
			String[] tmp;
			for (int c = 1; c <= cases; c++) {
				line = in.readLine();
				tmp = line.split(" ");
				int x = Integer.valueOf(tmp[0]);
				int y = Integer.valueOf(tmp[1]);
				int step = 1;
				int disX = Math.abs(x);
				int disY = Math.abs(y);
				int[] path = new int[500];
				if (disX > disY) {
					while (disY > step) {
						path[step - 1] = 2;
						disY -= step;
						step++;
					}
					while (disX > step) {
						path[step - 1] = 1;
						disX -= step;
						step++;
					}
				} else {
					while (disX > step) {
						path[step - 1] = 1;
						disX -= step;
						step++;
					}
					while (disY > step) {
						path[step - 1] = 2;
						disY -= step;
						step++;
					}
				}
				String xP, xN, yP, yN;
				if (x > 0) {
					xP = "E";
					xN = "W";
				} else {
					xP = "W";
					xN = "E";
				}
				if (y > 0) {
					yP = "N";
					yN = "S";
				} else {
					yP = "S";
					yN = "N";
				}
				StringBuffer pathStr = new StringBuffer();
				for (int i = 0; i < 500; i++) {
					if (path[i] == 0)
						break;
					if (path[i] == 2)
						pathStr.append(yP);
					if (path[i] == 1)
						pathStr.append(xP);
				}
				while (disX > 0) {
					disX--;
					pathStr.append(xN + xP);
				}
				while (disY > 0) {
					disY--;
					pathStr.append(yN + yP);
				}
				out.write("Case #" + c + ": " + pathStr.toString() + "\n");
			}
			in.close();
			out.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

}
