import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.StringTokenizer;

import javax.swing.text.DefaultEditorKit.CutAction;


public class Pogo {

	int x;
	int y;
	StringBuffer lol;

	public Pogo(String s) {
		StringTokenizer st = new StringTokenizer(s, " ");
		x = Integer.parseInt(st.nextToken());
		y = Integer.parseInt(st.nextToken());
		lol = new StringBuffer();
	}

	/**
	 * @param args
	 * @throws Exception 
	 * @throws  
	 */
	public static void main(String[] args) throws Exception {
		FileWriter f = new FileWriter("output.out");
		BufferedWriter b = new BufferedWriter(f);
		
		FileReader f1 = new FileReader("B-small-attempt0 (1).in");
		BufferedReader b1 = new BufferedReader(f1);
		
		int cas = Integer.parseInt(b1.readLine());
		for (int i = 1; i <= cas; i++) {
			Pogo c = new Pogo(b1.readLine());
			c.find();
			System.out.println("Case #" + i + ": " + c.lol.toString() + " : " + c.lol.toString().length());
			b.write("Case #" + i + ": " + c.lol.toString());
			b.newLine();
		}
		b.close();
		
	}

	private void find() {
		int jump = 1;
		int cuX = 0, cuY = 0;

		jump = x < 0 ? -jump : jump;
		while(x != cuX) {
			boolean app = Math.abs(cuX) + Math.abs(jump) < Math.abs(x);
			jump = (app && x > 0 && jump > 0) || (app && x < 0 && jump < 0) ? (jump) : -jump;

			cuX += jump;

			jump = jump < 0 ? jump - 1 : jump + 1;

			if(jump < 0) {
				lol.append('W');
			} else {
				lol.append('E');
			}
		}

		jump = (y < 0 && jump > 0) || (y > 0 && jump < 0) ? -jump : jump;
		while(y != cuY) {
			boolean app = Math.abs(cuY) + Math.abs(jump) < Math.abs(y);
			jump = app ? (jump) : -jump;

			cuY += jump;

			jump = jump < 0 ? jump - 1 : jump + 1;

			if(jump < 0) {
				lol.append('S');
			} else {
				lol.append('N');
			}
		}
	}
}
