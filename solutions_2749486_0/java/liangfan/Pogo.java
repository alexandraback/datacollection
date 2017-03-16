/**
 * TODO
 * 
 * @version 1.0.0 2013 May 12, 2013<br>
 * @author Fan Liang <br>
 */
package jam;

import java.io.BufferedWriter;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.Scanner;

public class Pogo {
	static String getOperN(int x, int y) {
		System.out.println(x + " " + y);
		StringBuilder sb = new StringBuilder();
		if (x > 0) {
			for (int i = 0; i < x; i++) {
				sb.append("WE");
			}
		} else {
			for (int i = 0; i < -x; i++) {
				sb.append("EW");
			}
		}
		if (y > 0) {
			for (int i = 0; i < y; i++) {
				sb.append("SN");
			}
		} else {
			for (int i = 0; i < -y; i++) {
				sb.append("NS");
			}
		}
		return sb.toString();
	}

	public static void main(String[] args) throws IOException {
		int case_num = 0, cnt = 1;
		Scanner scn = new Scanner(System.in);
		Integer x, y;
		case_num = scn.nextInt();
		FileOutputStream fos = new FileOutputStream("out");
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(fos));
		while (cnt <= case_num) {
			x = scn.nextInt();
			y = scn.nextInt();
			bw.write(String.format("Case #%d: %s\n", cnt++, getOperN(x, y)));
			// System.out.println(String.format("Case #%d: %s\n", cnt++,
			// getOperN(x, y)));
		}
		bw.close();
		fos.close();
	}

}
