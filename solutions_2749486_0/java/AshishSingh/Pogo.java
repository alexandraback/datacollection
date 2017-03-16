package example;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.Scanner;

public class Pogo {
	private Scanner reader;
	private PrintStream writer;

	public Pogo(String fname) {
		File f = new File(fname);
		try {
			reader = new Scanner(f);
			this.writer = new PrintStream(f.getParent() + "\\" + f.getName()
					+ "Solved.OUT");
			start();
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

	private void start() {
		int numberOfCases = reader.nextInt();
		int x, y;
		for (int i = 1; i <= numberOfCases; i++) {
			x = reader.nextInt();
			y = reader.nextInt();
			writer.println("Case #"+i+": "+solve(x, y));
			writer.flush();
		}
		writer.close();

	}

	private String solve(int x, int y) {
		System.out.println(x + " " + y);
		String path = "";
		int x0, y0, move;
		x0 = y0 = 0;
		move=1;
		boolean isXDirection = true,conditin=true;
		while (conditin) {
			if (x0 == x && y0 == y) {
				return path;
			}
			System.out.println(move);
			if (isXDirection) {
				if (x0 == x) {
					move--;
					isXDirection = false;
				} else if (x0+move> x) {
					path = path + "W";
					x0 -= move;
				} else {
					path = path + "E";
					x0 += move;
				}
//				isXDirection = false;
			} else {
				if (y0 == y) {
					move--;
					isXDirection = true;
				} else if (y0+move > y) {
					path = path + "S";
					y0 -= move;
				} else {
					path = path + "N";
					y0 += move;
				}
//				isXDirection = true;
			}
			move++;
		}
		System.out.println(path);
		return path;
	}

	public static void main(String[] args) {
		new Pogo("C:\\Users\\Ashish Singh\\Desktop\\google\\B-small-attempt1.in");
	}
}
