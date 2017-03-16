import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;


public class D {
	
	public static void main(String[] args) throws IOException {
//		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
//		BufferedReader in = new BufferedReader(new FileReader("d_test.in"));
		BufferedReader in = new BufferedReader(new FileReader("D-small-attempt0.in"));
		PrintWriter pw = new PrintWriter(System.out);
		
		int T = Integer.parseInt(in.readLine());
		for (int t = 1; t <= T; t++) {
			String[] pls = in.readLine().split(" ");
			int x,r,c;
			x = Integer.parseInt(pls[0]);
			r = Integer.parseInt(pls[1]);
			c = Integer.parseInt(pls[2]);
			
			if (r > c) {
				int temp = r;
				r = c;
				c = temp;
			}
			
			switch (x) {
			case 1:
				pw.format("Case #%d: GABRIEL\n", t);
				break;
			case 2:
				switch (c) {
				case 4:
					pw.format("Case #%d: GABRIEL\n", t);
					break;
				case 3:
					if (r == 2) {
						pw.format("Case #%d: GABRIEL\n", t);
					} else {
						pw.format("Case #%d: RICHARD\n", t);
					}
					break;
				case 2:
					pw.format("Case #%d: GABRIEL\n", t);
					break;
				case 1:
					pw.format("Case #%d: RICHARD\n", t);
					break;
				}
				break;
			case 3:
				switch(c) {
				case 4:
					if (r == 3) {
						pw.format("Case #%d: GABRIEL\n", t);
					} else {
						pw.format("Case #%d: RICHARD\n", t);
					}
					break;
				case 3:
					if (r == 1) {
						pw.format("Case #%d: RICHARD\n", t);
					} else {
						pw.format("Case #%d: GABRIEL\n", t);
					}
					break;
				case 2:
				case 1:
					pw.format("Case #%d: RICHARD\n", t);
					break;
				}
				break;
			case 4:
				switch (c) {
				case 4:
					if (r == 1 || r == 2) {
						pw.format("Case #%d: RICHARD\n", t);
					} else {
						pw.format("Case #%d: GABRIEL\n", t);
					}
					break;
				case 3:
				case 2:
				case 1:
					pw.format("Case #%d: RICHARD\n", t);
					break;
				}
				break;
			}
		}
		
		pw.close();
		in.close();
	}
}
