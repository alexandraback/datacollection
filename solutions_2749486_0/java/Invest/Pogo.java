import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
import java.util.Set;

public class Pogo {

	public static class Move {
		int count;
		int x;
		int y;
		String dirs;

		public Move(int x, int y, int count, String dirs) {
			this.x = x;
			this.y = y;
			this.count = count;
			this.dirs = dirs;
		}

		public void addDir(char ch) {
			dirs += ch;
		}

		@Override
		public int hashCode() {
			final int prime = 31;
			int result = 1;
			result = prime * result + x;
			result = prime * result + y;
			return result;
		}

		@Override
		public boolean equals(Object obj) {
			if (this == obj) return true;
			if (obj == null) return false;
			if (getClass() != obj.getClass()) return false;
			Move other = (Move) obj;
			if (x != other.x) return false;
			if (y != other.y) return false;
			return true;
		}
	}

	private String getMovesCount(int x, int y) {
		String dir = "";
		if (x > 0) {
			for (int i = 0; i < x; i++) {
				dir += "WE";
			}
		} else {
			for (int i = 0; i < Math.abs(x); i++) {
				dir += "EW";
			}
		}

		if (y > 0) {
			for (int i = 0; i < y; i++) {
				dir += "SN";
			}
		} else {
			for (int i = 0; i < Math.abs(y); i++) {
				dir += "NS";
			}
		}
		return dir;
	}

	public static final String INPUT_FILE_PATH = "C://DiskD//CodeJamInput.txt";
	public static final String OUTPUT_FILE_PATH = "C://DiskD//CodeJamOutput.txt";

	public static void main(String[] args) {
		Scanner in = null;
		PrintWriter writer = null;
		try {
			System.out.println("start");

			in = new Scanner(new File(INPUT_FILE_PATH));
			writer = new PrintWriter(new FileWriter(OUTPUT_FILE_PATH));
			int testCount = in.nextInt();

			for (int i = 0; i < testCount; i++) {
				int x = in.nextInt();
				int y = in.nextInt();

				System.out.println(i);
				writer.println("Case #" + (i + 1) + ": " + new Pogo().getMovesCount(x, y));
			}
			writer.flush();

			System.out.println("end");
		} catch (IOException ex) {
			ex.printStackTrace();
		} finally {
			if (in != null) in.close();
			if (writer != null) writer.close();
		}
	}
}
